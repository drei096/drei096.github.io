/* Programmed by: Aldrey D. Gaurana
This is the beta/final version of Minesweeper
Last modified: 9/21/2020
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include "interface.h"
#include <time.h>
#include <string.h>

typedef struct mspFile
{
	int rowDim;
	int columnDim;
	int levelcount;
	char board[15][15];
}mspFile;

typedef struct node
{
	mspFile level;
	struct node *nextNode;
}node;

void initializeGame();
void mainMenu(node **currentSet, char setName[]);
void createLevel();
void loadLevel();
void saveLevel(node **currentSet);
void playGame(node **loadedSet, node **initSet, int roomNo, int isTutorial);
bool isValidTile(int x, int y, int row, int column);
bool isMine(char board[][15], int x, int y);
void actionInput(int *x, int *y, char *decis, int row, int column, int isTutorial);
void quitGame(node *loadedSet);
void displayBoard(char board[][15], int row, int column, int roomNo);
int adjMineCount(char board[][15], int x, int y, int row, int column);
bool minesweep(char refboard[][15], char gameboard[][15], int x, int y, int row, int column);
void levelInputs(int *tilerow, int *tilecolumn, char creationBoard[][15], int *roomNo);
void addRoom(node **roomSet, int *roomNo);
bool isAllRevealed(char board[][15], int row, int column, int mines);

int main()
{
	initializeGame();
	return 0;
}

/* This function initializes the game with the text intro, and the level set node is init. to NULL
@ return void
*/
void initializeGame()
{
	node *currentSet = NULL;
	
	iHideCursor();
	
	iClear(0,0,100,30);
	iMoveCursor(10,5);
	printf("You are standing in front of a house that is feared by even the most adventurous explorers.");
	sleep(2);
	iMoveCursor(10,7);
	printf("You look to your ring, even Sir Francis Drake kept it as a secret over the many years.");
	sleep(2);
	iMoveCursor(10,9);
	printf("'Sic parvis magna' it says. It is now too late to turn back, especially with the sandstorm outside.");
	sleep(2);
	iMoveCursor(10,11);
	printf("You open the door.");
	sleep(3);
	iMoveCursor(10,13);
	printf("And a worn out note falls off. It says...");
	sleep(3);
	iClear(0,0,130,30);
	iMoveCursor(48,10);
	printf("The Floor is A Bomb!");
	sleep(3);
	iMoveCursor(52,12);
	printf("Version 1.4");
	sleep(3);
	iClear(0,0,130,30);
	
	mainMenu(&currentSet,"temp");
}

/* This function displays the main menu, the level, and the level set present
@ param (struct) node currentSet holds the loaded level set into the mainMenu fxn, whether be NULL or a loaded/created save
@ param (char) setName holds the name for the level set/name of the savegame file to be displayed in the mainMenu
@ return void
*/
void mainMenu(node **currentSet ,char setName[])
{
	node *loadedSet;
	loadedSet = *currentSet;
	  
	int playerChoice, roomNo = 1;
	
	iClear(0,0,130,30);
	iShowCursor();
	iMoveCursor(45,1);
	iSetColor(I_COLOR_RED);
	printf(" The Floor is A Bomb!");
	iMoveCursor(45,3);
	iSetColor(I_COLOR_GREEN);
	printf("     Main Menu");
	iSetColor(I_COLOR_GREEN);
	if(loadedSet != NULL)
	{
		iMoveCursor(15,5);
		iSetColor(I_COLOR_YELLOW);
		printf("     Current Room: %d", roomNo);
		iMoveCursor(55,5);
		iSetColor(I_COLOR_YELLOW);
		printf("     Current Room Set: %s", setName);
	}
	else
	{
		iMoveCursor(15,5);
		iSetColor(I_COLOR_YELLOW);
		printf("     Current Room: No Loaded Room");
		iMoveCursor(55,5);
		iSetColor(I_COLOR_YELLOW);
		printf("     Current Room Set: No Room Set");
	}
		
	iMoveCursor(45,7);
	iSetColor(I_COLOR_GREEN);
	printf("[1] Create a Room Set");
	iMoveCursor(45,9);
	iSetColor(I_COLOR_GREEN);
	printf("[2] Load a Room Set");
	iMoveCursor(45,11);
	iSetColor(I_COLOR_GREEN);
	printf("[3] Save current Room Set");
	iMoveCursor(45,13);
	iSetColor(I_COLOR_GREEN);
	printf("[4] Explore!");
	iMoveCursor(45,15);
	iSetColor(I_COLOR_GREEN);
	printf("[5] Guided Exploration! (Tutorial)\n");
	iMoveCursor(45,17);
	iSetColor(I_COLOR_GREEN);
	printf("[6] Quit Game!\n");
	
	do{
		iMoveCursor(35,19);
		printf("\n Pro Tip: If you are not familiar with Minesweeper,\n then load a room set and play the tutorial!");
		iMoveCursor(75,21);
		printf("What is your choice? ");
		scanf("%d",&playerChoice);
	
		if(playerChoice >6 || playerChoice <1)
		{
			iMoveCursor(30,23);
			printf("Invalid entry, use arrow keys and backspace to erase the entry.");
		}
	}
	while (playerChoice >6 || playerChoice <1);
	
	if (playerChoice == 1) //CREATE LEVEL
		createLevel();
	else if (playerChoice == 2) //LOAD LEVEL
		loadLevel();
	else if (playerChoice == 3) //SAVE LEVEL
	{
		if(loadedSet == NULL)
		{
			printf("\n You cannot save without creating a room set!\n");
			printf(" Redirecting please wait...\n");
			sleep(2);
			iClear(0,0,130,30);
			mainMenu(&loadedSet, "No Loaded Room Set");
		}
		else
			saveLevel(&loadedSet);
	}
		
	if (playerChoice == 4) //PLAY GAME
	{
		if(loadedSet == NULL)
		{
			printf("\n You cannot explore without creating a room set!\n");
			printf(" Redirecting please wait...\n");
			sleep(2);
			iClear(0,0,130,30);
			mainMenu(&loadedSet, "No Loaded Room Set");
		}
		else
			playGame(&loadedSet, &loadedSet, roomNo, 0);
	}
	if (playerChoice == 5) //TUTORIAL
	{
		if(loadedSet == NULL)
		{
			printf("\n You cannot explore without creating a room set!\n");
			printf(" Redirecting please wait...\n");
			sleep(2);
			iClear(0,0,130,30);
			mainMenu(&loadedSet, "No Loaded Room Set");
		}
		else
			playGame(&loadedSet, &loadedSet, roomNo, 1);
	}
	
	if (playerChoice == 6) //QUIT
		quitGame(loadedSet);
}	

/* This function takes row,column and location inputs for creating a level. The actual create a level is performed here.
@ param (int *) tilerow holds a ptr var for the number of rows in the board, to be returned to addRoom to be inserted into the node
@ param (int *) tilecolumn holds a ptr var for the number of columns in the board, to be returned to addRoom to be inserted into the node
@ param (char [][]) creationBoard holds the game board and the x,y locations of mines. to be returned to addRoom to be inserted into the node
@ param (int *) roomNo holds the cardinal order of the room being created. to be returned to createLevel to be inserted into the node 
@ return void
*/
void levelInputs(int *tilerow, int *tilecolumn, char creationBoard[][15], int *roomNo)
{
	int maxMines, i,j, xPos = 1, yPos =1, minecount = 0;
	char decis;
	int altrow, altcolumn; 
	
	//ROW INPUT
	do{
		iMoveCursor(0,6);
		printf("\nHow many rows of tiles do you want? (min. 5, max. 15): ");
		scanf("%d",tilerow);
		if(*tilerow >15 || *tilerow <5)
		{
			iMoveCursor(0,8);
			printf("\nInvalid entry, use arrow keys and backspace to erase the entry.");
		}
	}
	while (*tilerow >15 || *tilerow <5);
	//COLUMN INPUT
	do{
		iMoveCursor(0,10);
		printf("How many columns of tiles do you want? (min. 5, max. 15): ");
		scanf("%d",tilecolumn);
		if(*tilecolumn >15 || *tilecolumn <5)
		{
			iMoveCursor(0,12);
			printf("\nInvalid entry, use arrow keys and backspace to erase the entry.");
		}
	}
	while (*tilecolumn >15 || *tilecolumn <5);
		
	//initialize creation board
	for(i=0;i<*tilerow;i++)
	{
		for(j=0;j<*tilecolumn;j++)
		{
			creationBoard[i][j] = '_';
		}
	}
	
	iClear(0,0,100,30);
	iMoveCursor(48,1);
	printf("Creating Room...");
	sleep(2);
	iClear(0,0,100,30);
	
	maxMines = *tilerow * *tilecolumn;
	printf("\n");

	//MINE PLACEMENT INPUT
	do{
		decis = 'q';
		do{
			iClear(0,0,130,30);
			if((xPos<0 || xPos>=tilerow) || (yPos<0 || yPos>=tilecolumn))
				printf(" \nError input. Delete your selection and input again.");
		
			displayBoard(creationBoard,*tilerow,*tilecolumn,*roomNo);
			printf("  \nWhere do you want to place a bomb? Enter the number pair: ");
			scanf("%d %d",&xPos,&yPos);
			creationBoard[xPos][yPos] = 'X';
			iClear(0,0,100,30);
			displayBoard(creationBoard,*tilerow,*tilecolumn,*roomNo);
		}
		while((xPos<0 || xPos>=*tilerow) || (yPos<0 || yPos>=*tilecolumn));
		
		printf(" \nAdd another mine? (Y/N): ");
		while(decis != 'y' && decis != 'Y' && decis != 'n' && decis != 'N')
			decis = getch();
		
		tolower(decis);
		iClear(0,0,100,30);
	}
	while((xPos<0 || xPos>=*tilerow) || (yPos<0 || yPos>=*tilecolumn) || decis == 'y');
	
	iClear(0,0,100,30);
	displayBoard(creationBoard,*tilerow,*tilecolumn,*roomNo);
	
	//MINE DELETE
	decis = 'a';
	printf(" \nRemember, a board must HAVE AT LEAST ONE BOMB.\n");
	printf(" \nIf a created board has zero bombs, create level set will reset to zero.\n");
	printf("  \nDo you want to delete a bomb? (Y/N): ");
	while(decis != 'y' && decis != 'Y' && decis != 'n' && decis != 'N')
		decis = getch();
		
	tolower(decis);
	
	if(decis == 'y')
	{
		iClear(0,0,100,30);
		do{
			decis = 'q';
			do{
				iClear(0,0,130,30);
				if((xPos<0 || xPos>=tilerow) || (yPos<0 || yPos>=tilecolumn))
					printf(" \nError input. Delete your selection and input again.");
		
				displayBoard(creationBoard,*tilerow,*tilecolumn,*roomNo);
				printf("  \n Where do you want to delete a bomb? Enter the number pair: ");
				scanf("%d %d",&xPos,&yPos);
				creationBoard[xPos][yPos] = '_';
				iClear(0,0,100,30);
				displayBoard(creationBoard,*tilerow,*tilecolumn,*roomNo);
			}
			while((xPos<0 || xPos>=*tilerow) || (yPos<0 || yPos>=*tilecolumn));
			
			printf(" \nDelete another bomb? (Y/N): ");
			while(decis != 'y' && decis != 'Y' && decis != 'n' && decis != 'N')
				decis = getch();
		
			tolower(decis);
			iClear(0,0,100,30);
		}
		while((xPos<0 || xPos>=*tilerow) || (yPos<0 || yPos>=*tilecolumn) || decis == 'y');
	}
	
	for(i = 0; i<*tilerow; i++)
	{
		for(j=0;j<*tilecolumn;j++)
		{
			if(creationBoard[i][j] == 'X')
				minecount++;
		}
	}
	
	if(minecount == 0)
	{
		printf("\n You cannot have a level without a mine!\n");
		printf("\n Restarting...\n");
		sleep(2);
		iClear(0,0,100,30);
		createLevel();
	}
	
	displayBoard(creationBoard,*tilerow,*tilecolumn,*roomNo);
}

/* This function creates a node instance for creating also a linked list of levels, whenever Y is selected in createLevel
@ param (struct **) node roomSet holds the linked list for the level set
@ param (int *) roomNo holds the cardinal order of the room being created
@ return void
*/
void addRoom(node **roomSet, int *roomNo)
{
	node *runner;
	node *temp;
	char creationBoard[15][15];
	int *tilerow, *tilecolumn, i, j;
	
	if(*roomSet == NULL)
	{
		*roomSet = malloc(sizeof(node));
		if(*roomSet == NULL)
		{
			printf("\n There was an error in making a level, exiting.");
			sleep(2);
			exit(1);
		} 
		
		levelInputs(&tilerow, &tilecolumn, creationBoard, roomNo);
		(*roomSet)->level.rowDim = tilerow;
		(*roomSet)->level.columnDim = tilecolumn;
	
		printf("\n");
		
		for(i=0;i<(*roomSet)->level.rowDim;i++)
		{
			for(j=0;j<(*roomSet)->level.columnDim;j++)
			{
				(*roomSet)->level.board[i][j] = creationBoard[i][j];
			}
		}
		
		(*roomSet)->nextNode = NULL;	
	} //end of if
	
	else //linked list aint empty
	{
		runner = *roomSet;
		while(runner->nextNode != NULL)
		{
			runner = runner->nextNode;
		}
		temp = malloc(sizeof(node));
		if(temp == NULL)
		{
			printf("\n There was an error in making a level, exiting.");
			sleep(2);
			exit(1);
		} 
		
		levelInputs(&tilerow, &tilecolumn, creationBoard, roomNo);
		(temp)->level.rowDim = tilerow;
		(temp)->level.columnDim = tilecolumn;
		
		for(i=0;i<(temp)->level.rowDim;i++)
		{
			for(j=0;j<(temp)->level.columnDim;j++)
			{
				(temp)->level.board[i][j] = creationBoard[i][j];
			}
		}
		
		temp->nextNode = NULL;	
		runner->nextNode = temp;
	}
}

/* This function acts as the main() for creating linked lists for level sets. A do while loop is implemented to ensure that the
player is able to create a level as long as he/she presses 'Y'
@ return void
*/
void createLevel() //ACT AS MAIN
{
	char tempName[101] = "Temporary Level Set (Save it if You Want!)";
	char goBack, create;
	int i,j, levelcount = 0, roomNo = 1;
	node *runner;
	
	//node inits
	node *roomSet = NULL; //whole roomset

	iSetColor(I_COLOR_CYAN);
	iClear(0,0,130,30);
	
	iMoveCursor(48,1);
	printf("Create A Room Set!\n");
	iMoveCursor(48,3);
	printf("==================");
	//add room, if roomset list is empty, call again if user wants to create again
	do{
		create = 'q';
		addRoom(&roomSet,&roomNo);
		
		iClear(0,0,100,30);
		printf("\n Do you want to create another room? (Y/N): ");
		while(create != 'y' && create != 'Y' && create != 'n' && create != 'N')
		{
			create = getch();
		}
		tolower(create);
		iClear(0,0,100,30);
		printf("\n");
		levelcount++;
		roomNo++;
	}
	while(create == 'y' || create == 'Y');
	
	roomSet->level.levelcount = levelcount;
	
	iClear(0,0,100,30);
	
	mainMenu(&roomSet, tempName);
}

/* This function takes the level set linked list for saving into txt file acc. to the format in the specs
@ param (struct **) node currentSet holds the currently loaded/created level set  
@ return void
*/
void saveLevel(node **currentSet)
{
	FILE *savegame;
	node *runner;
	char name[101];
	int i,j;
	
	runner = *currentSet;
	iClear(0,0,130,30);
	iSetColor(I_COLOR_YELLOW);
	iMoveCursor(48,1);
	
	printf("Save A Room Set!\n");
	iMoveCursor(48,3);
	printf("================");
	printf("\n\n What will be the name of your savegame? (max 100 chars): ");
	getchar();
	gets(name);
	strcat(name, ".txt");
	savegame = fopen(name, "w");
	
	fprintf(savegame,"%d\n", runner->level.levelcount);
	
	do
	{
		fprintf(savegame,"%d\n", runner->level.rowDim);
		fprintf(savegame,"%d\n", runner->level.columnDim);
	
		for(i=0;i<runner->level.rowDim; i++)
		{
			for(j=0;j<runner->level.columnDim; j++)
			{
				fprintf(savegame,"%c", runner->level.board[i][j]);
			}
			fprintf(savegame,"\n");
		}
		runner = runner->nextNode;
	}
	while(runner != NULL);
	
	fclose(savegame);
	
	runner = *currentSet;
	iClear(0,0,130,30);
	mainMenu(&runner, name);
}

/* This function freads and fscans the data written in the txt files into a level set linked list, to be passed to the mainMenu
@ return void
*/
void loadLevel()
{
	FILE *savegame;
	node *runner;
	node *temp;
	node *currentSet;
	char name[101];
	char board[15][15];
	char dummy;
	int i,j,levelcount,firstline;
	int row, column;
	
	currentSet = NULL;
	iClear(0,0,130,30);
	iSetColor(I_COLOR_YELLOW);
	iMoveCursor(48,1);
	
	printf("Load A Room Set!\n");
	iMoveCursor(48,3);
	printf("================");
	printf("\n\n What save would you like to load? (max 100 chars): ");
	fflush(stdin);
	gets(name);
	strcat(name, ".txt");
	savegame = fopen(name, "r");
	if(savegame == NULL)
	{
		printf("\n\n\tThe save could not be found!\n");
		sleep(1);
		printf("\n\tReturning to main menu...");
		sleep(1);
		mainMenu(&currentSet, "No Loaded Room Set");
	}
	
	fscanf(savegame, "%d", &firstline);
	
	while(!feof(savegame))
	{
		if(currentSet == NULL)
		{
			currentSet = malloc(sizeof(node));
			
			(currentSet)->level.levelcount = firstline;
			fscanf(savegame, "%d", &row);
			(currentSet)->level.rowDim = row;
			fscanf(savegame, "%d", &column);
			(currentSet)->level.columnDim = column;
			
			fscanf(savegame,"%c",&dummy);
			for(i=0;i<row;i++)
			{
				for(j=0;j<column;j++)
				{
					fscanf(savegame,"%c\n", &board[i][j]);
					(currentSet)->level.board[i][j] = board[i][j];
				}
			}
			
			(currentSet)->nextNode = NULL;	
		} //end of if
		
		else //linked list aint empty
		{
			runner = currentSet;
			while(runner->nextNode != NULL)
			{
				runner = runner->nextNode;
			}
			temp = malloc(sizeof(node));
			if(temp == NULL)
			{	
				printf("\n There was an error in making a level, exiting.");
				sleep(2);
				exit(1);
			} 
		
			fscanf(savegame, "%d", &row);
			(temp)->level.rowDim = row;
			fscanf(savegame, "%d", &column);
			(temp)->level.columnDim = column;
			
			fscanf(savegame,"%c",&dummy);
			for(i=0;i<row;i++)
			{
				for(j=0;j<column;j++)
				{
					fscanf(savegame,"%c\n", &board[i][j]);
					(temp)->level.board[i][j] = board[i][j];
				}
			}
			
			(temp)->nextNode = NULL;	
			(runner)->nextNode = temp;
		}
	}
	
	printf("\n   Loading...\n");
	sleep(2);
	printf("\n   Load complete!");
	fclose(savegame);
	sleep(1);
	mainMenu(&currentSet, name);
} 

/* This function performs a check if a x,y location passed to the function is within the boundaries of the row,column
@ param (int) x is the row location of the player entered in the board
@ param (int) y is the column location of the player entered in the board 
@ param (int) row is the max row dimension of the current game board
@ param (int) column is the max column dimension of the current game board
@ returns (bool) true if the x,y location is within the boundaries of the board, false if otherwise
*/
bool isValidTile(int x, int y, int row, int column) // Returns true if row number and column number is in range
{ 
    return (x >= 0) && (x < row) && 
           (y >= 0) && (y < column); 
} 

/* This function detects if the passed x,y location is a mine or not
@ param (char[][]) board is the game board, whether be the current updating game board, or the reference board (usually reference board)
@ param (int) x is the row index being passed
@ param (int) y is the column index being passed
@ returns (bool) true if the passed x,y position in the board is a mine, false if otherwise
*/
bool isMine(char board[][15], int x, int y) 
{ 
    if (board[x][y] == 'X') 
        return true; 
    else
        return false; 
} 

/* This function takes input from the player from the playGame fxn
@ param (int *) x is the desired row index of the player in the board
@ param (int *) y is the desired column index of the player in the board
@ param (char *) decis is the decision of the player whether to step, flag, or back after entering the x,y positions
@ param (int) row is the max row dimension of the current game board
@ param (int) column is the max column dimension of the current game board
@ param (int) isTutorial indicates whether the game mode selected is "Explore" or "Tutorial" 
@ return void
*/
void actionInput(int *x, int *y, char *decis, int row, int column, int isTutorial) //takes input, using ptrs
{
	*decis = 'q'; //dummy val for reset
	fflush(stdin);
	do{
		if((*x<0 || *x>=row) || (*y<0 || *y>=column))
		{
			iMoveCursor(3,row+5);
			printf("    Error! Please input again.");
			iMoveCursor(3,row+6);
			printf("    Redirecting...");
			sleep(2);
			iClear(0,row+2,60,1);
			iClear(0,row+3,60,5);
		}	
		
		iMoveCursor(3,row+2);
		printf("\n   Choose two numbers from the floor to attack/flag: ");
		scanf("%d %d",x,y);
	}
	while((*x<0 || *x>=row) || (*y<0 || *y>=column));
	
	fflush(stdin);
	
	if(isTutorial == 1)
	{
		iClear(0,row+5,120,8);
		printf("   Stepping means to step on (inspect) the tile.\n");
		printf("   Flagging means to place a marker on the tile.\n");
		printf("      Flagging means it may be a bomb!\n");
		printf("\n	Step ('s') or Flag ('f')? ('b') for Back: ");
		while(*decis != 's' && *decis != 'f' && *decis != 'S' && *decis != 'F' && *decis != 'B' && *decis != 'b')
		{
			*decis = getch();
		}
		tolower(*decis);
		
	}
	else
	{
		printf("\n	Step ('s') or Flag ('f')? ('b') for Back: ");
		while(*decis != 's' && *decis != 'f' && *decis != 'S' && *decis != 'F' && *decis != 'B' && *decis != 'b' )
		{
			*decis = getch();
		}
		tolower(*decis);
	}
}

/* This function displays the current state of the board
@ param (char [][]) board is the game board/reference board/creation board being displayed
@ param (int) row is the max row dimension of the passed board
@ param (int) column is the max column dimension of the passed board
@ param (int) roomNo holds the cardinal order of the level at present
@ return void
*/
void displayBoard(char board[][15], int row, int column, int roomNo) //displays current state of gameboard
{
	int i,j;
	
	iSetColor(I_COLOR_CYAN);
	printf("\t\t\t\t\t\t Current Room: %d \n",roomNo);
	iSetColor(I_COLOR_YELLOW);
	for(i=0;i<column;i++)
	{
		if(i==0)
			printf("      %d",i);
		else if(i>0 && i<=9)
			printf("     %d",i);
		else
			printf("    %d",i);
	}
	printf("\n");
	iSetColor(I_COLOR_CYAN);
	for(i = 0; i<row; i++)
	{
		iSetColor(I_COLOR_YELLOW);
		if(i>9)
			printf("  %d",i);
		else
			printf("   %d",i);
		for(j = 0; j<column; j++)
		{
			if(i>9)
			{
				iSetColor(I_COLOR_CYAN);
				printf(" |%c| ", board[i][j]);
				iSetColor(I_COLOR_YELLOW);
				printf("|");
			}
			else
			{
				iSetColor(I_COLOR_CYAN);
				printf(" |%c|", board[i][j]);
				iSetColor(I_COLOR_YELLOW);
				printf(" |");
			}
		}
		printf("\n");
	}
}

/* This function counts the adjacent mines on a passed x,y position in the board
@ param (char[][]) board is the passed game board from the playGame fxn (whether game board/reference board)
@ param (int) x is the current row index in the board 
@ param (int) y is the current column index in the board
@ param (int) row is the max row dimension of the passed board
@ param (int) column is the max column dimension of the passed board
@ return (int) the number of adjacent mines in the passed x,y position
*/
int adjMineCount(char board[][15], int x, int y, int row, int column)
{
	int i, minecount = 0;
	
	if(isValidTile(x-1,y,row,column) == true)  //N
		if(isMine(board,x-1,y) == true)
			minecount++;
			
	if(isValidTile(x+1,y,row,column) == true)  //S
		if(isMine(board,x+1,y) == true)
			minecount++;
			
	if(isValidTile(x,y+1,row,column) == true)  //E
		if(isMine(board,x,y+1) == true)
			minecount++;
			
	if(isValidTile(x,y-1,row,column) == true)  //W
		if(isMine(board,x,y-1) == true)
			minecount++;
			
	if(isValidTile(x-1,y+1,row,column) == true)  //NE
		if(isMine(board,x-1,y+1) == true)
			minecount++;
			
	if(isValidTile(x-1,y-1,row,column) == true)  //NW
		if(isMine(board,x-1,y-1) == true)
			minecount++;
			
	if(isValidTile(x+1,y+1,row,column) == true)  //SE
		if(isMine(board,x+1,y+1) == true)
			minecount++;
			
	if(isValidTile(x+1,y-1,row,column) == true)  //SW
		if(isMine(board,x+1,y-1) == true)
			minecount++;
			
	return minecount;
}

/* This function performs the recursive act of checking if the player has stepped on a mine, or stepped on a safe tile, or on a zero tile
@ param (char[][]) refboard is the reference board of the board in-game, holds all locations of the mines 
@ param (char[][]) gameboard is the current board being displayed to the player in-game, displays the adjacent mine counts and unchecked tiles
@ param (int) x is the current row index entered by the player at actionInputs fxn  
@ param (int) y is the current column index entered by the player at actionInputs fxn
@ param (int) row is the max row dimension of the passed board in the fxn
@ param (int) column is the max column dimension of the passed board in the fxn
@ return (bool) false if the player entered a dimension not stepping on a mine, true if otherwise
*/
bool minesweep(char refboard[][15], char gameboard[][15], int x, int y, int row, int column)
{
	int i, j, minecount;
	
	if(gameboard[x][y] != '_') //paulit ulit lang sa fxn
		return false; 
	
	//ELSE
	minecount = adjMineCount(refboard, x, y, row, column);
	gameboard[x][y] = minecount + '0';
	
	//CASCADE
	if (gameboard[x][y] == '0')
	{
		if(isValidTile((x)-1,y,row,column) == true && gameboard[x-1][y] == '_')
		{
			minesweep(refboard, gameboard, x-1,y, row, column); //N
		}
	
		if(isValidTile((x)+1,y,row,column) == true && gameboard[x+1][y] == '_')
		{
			minesweep(refboard, gameboard, x+1,y, row, column); //S
		}
		
		if(isValidTile(x,(y)+1,row,column) == true && gameboard[x][y+1] == '_')
		{
			minesweep(refboard, gameboard, x,y+1, row, column); //E
		}
		
		if(isValidTile(x,(y)-1,row,column) == true && gameboard[x][y-1] == '_')
		{
			minesweep(refboard, gameboard, x,y-1, row, column); //W
		}
		
		if(isValidTile((x)-1,(y)+1,row,column) == true && gameboard[x-1][y+1] == '_')
		{
			minesweep(refboard, gameboard, x-1,y+1, row, column); //NE
		}
		
		if(isValidTile((x)-1,(y)-1,row,column) == true && gameboard[x-1][y-1] == '_')
		{
			minesweep(refboard, gameboard, x-1,y-1, row, column); //NW
		}
		
		if(isValidTile((x)+1,(y)+1,row,column) == true && gameboard[x+1][y+1] == '_')
		{
			minesweep(refboard, gameboard, x+1,y+1, row, column); //SE
		}
		
		if(isValidTile((x)+1,(y)-1,row,column) == true && gameboard[x+1][y-1] == '_')
		{
			minesweep(refboard, gameboard, x+1,y-1, row, column); //SW
		}
	}
	
	//IF STEPPED ON MINE
	if(refboard[x][y] == 'X')
	{
		gameboard[x][y] = 'X';
			
		for(i=0;i<row;i++) //7 = number of mines
		{
			for(j=0;j<column;j++)
			{
				if(refboard[i][j] == 'X')
					gameboard[i][j] = 'X';
			}
		}
		return true;
	}	
	//END OF IF STEPPED ON MINE
	return false;
}

/* This function performs a check if all safe tiles are inspected (safe means not flagged and not bombs)
@ param (char[][]) board holds the passed game board from playGame fxn 
@ param (int) row is the max row dimension of the passed board
@ param (int) column is the max column dimension of the passed board 
@ param (int) mines is the max number of mines present in the passed board
@ return (bool) true if the number of revealed tiles matches the number of the max dim. subtracted by the no. of mines,
  false if otherwise meaning di pa tapos ang game
*/
bool isAllRevealed(char board[][15], int row, int column, int mines)
{
	int i,j,dim, revNo=0;
	
	dim = row*column;
	
	for(i = 0; i<row; i++)
	{
		for(j=0; j<column; j++)
		{
			if(board[i][j] != '_' && board[i][j] != 'F')
				revNo++;
		}
	}
	if(revNo == dim-mines)
		return true;
		
	return false;
}

/* This function performs the main functions of the minesweeper game
@ param (struct **) node loadedSet is the loaded/created level set that is passed from the mainMenu
@ param (struct **) node initSet holds the first (unchanged) node and linked list of loadedSet
@ param (int) roomNo holds the cardinal order of the room being currently played
@ param (int) isTutorial indicates whether the game mode selected is "Explore" or "Tutorial"
@ return void
*/
void playGame(node **loadedSet, node **initSet, int roomNo, int isTutorial)
{
	int x=0,y=0,movesMade = 0, i, j, count, mines = 0; 
	int allowable, namelen;
	int row, column, flagcount =0;
	char decis,endchoice;
	char gameboard[15][15];
	char refboard[15][15];
	bool isGameOver = false;
	bool isWon = false;
	node *first;
	node *runner;
	first = *initSet;
	runner = *loadedSet;
	
	while(runner != NULL)
	{
		row = runner->level.rowDim;
		column = runner->level.columnDim;
	
		for(i=0;i<row;i++)
		{
			for(j=0;j<column;j++)
			{
				refboard[i][j] = runner->level.board[i][j];
				gameboard[i][j] = '_';
			}
		}

		iClear(0,0,130,30);
	
		//FOR COUNTING MINES
		for(i=0;i<row;i++) //i<row dim ; j<col dim
		{
			for(j=0;j<column;j++)
			{
				if(refboard[i][j] == 'X')
					mines++;
			}	
		}
		allowable = row*column - mines;
		//FOR COUNTING MINES
		
		if(isTutorial == 1 && roomNo == 1)
		{
			iClear(0,0,100,30);
			printf("\n\n\n\tIn this game, you will be given with a board of a certain dimension.\n");
			sleep(2);
			printf("\n\tYour goal is to inspect all the tiles in the room without stepping on a bomb!\n");
			sleep(2);
			printf("\n\tBut how can you inspect all tiles if there are bombs among them?\n");
			sleep(2);
			printf("\n\tFlag them! You will see that later!\n");
			sleep(2);
			printf("\n\tIf you have flagged all that you think are bombs and inspected all tiles,\n");
			sleep(2);
			printf("\n\tThen you passed the challenge of the room!\n");
			sleep(2);
			printf("\n\tIf not, then unfortunately a bomb has exploded and the room is destroyed. :(\n");
			sleep(2);
			printf("\n\tAre you ready to enter your first room?\n");
			sleep(3);
			printf("\n\tPress any key to continue:\n");
			getch();
			iClear(0,0,100,30);
		}
		
		//GAME LOOP
		while(isGameOver == false)
		{
			displayBoard(gameboard,row,column,roomNo);
			printf("\n\n\n\n\n\n");
			printf("   Moves Made: %d :)\n",movesMade);
			iSetColor(I_COLOR_GREEN);
			
			if(isTutorial == 1)
			{
				iSetColor(I_COLOR_CYAN);
				if(movesMade < 1)
				{
					printf(" \n\tEnter the pair of numbers that align with the grid numbers. Separate them with a space!\n");
					printf(" \tThe number on the left of the grid should be entered first, then the number on top of the grid.\n");
				}
				else
				{
					printf(" \n\tThe numbers that appear represent the number of adjacent bombs at the tile \n");
					printf(" \twhere you previously entered. Adjacent means the North,South,East,West, and diagonal tiles.\n");
				}
				iSetColor(I_COLOR_GREEN);
				actionInput(&x,&y,&decis, row, column, isTutorial);
				
				if(decis == 's') //step
				{
					movesMade++;
					allowable--;
					isGameOver = minesweep(refboard, gameboard, x, y, row, column);
				}
		
				if(decis == 'f') //flag
				{	
					movesMade++;
					if(gameboard[x][y] == 'F') //removing flag
					{
						movesMade--;
						gameboard[x][y] = '_';
						flagcount--;
						isGameOver = false;
					}
					else
					{
						gameboard[x][y] = 'F';
						flagcount++;
						isGameOver = false;
					}
				}
		
				if(decis == 'b') //back
				{
					isGameOver = false;
				}
				
				// past ref: allowable<=0
				if (isGameOver == false && flagcount == mines && isAllRevealed(gameboard, row, column, mines) == true) //game won
        		{ 
         	   		isGameOver = true;
					isWon = true; 
        		}
			}
			
			else
			{
				actionInput(&x,&y,&decis, row, column, isTutorial);
				printf("\n\n\n\n\n");
				printf("   Moves Made: %d\n",movesMade);
				printf("   Press 'P' to pause the game.\n");
				if(decis == 's') //step
				{
					movesMade++;
					allowable--;
					isGameOver = minesweep(refboard, gameboard, x, y, row, column);
				}
		
				if(decis == 'f') //flag
				{	
					movesMade++;
					if(gameboard[x][y] == 'F') //removing flag
					{
						movesMade--;
						gameboard[x][y] = '_';
						flagcount--;
						isGameOver = false;
					}
					else
					{
						gameboard[x][y] = 'F';
						flagcount++;
						isGameOver = false;
					}
				}
		
				if(decis == 'b') //back
				{
					isGameOver = false;
				}
			
				// allowable<=0
				if (isGameOver == false && flagcount == mines && isAllRevealed(gameboard, row, column, mines) == true) //game won
        		{ 
         	   		isGameOver = true;
					isWon = true; 
        		}
			}
			
			iClear(0,0,100,30);
		} //END OF WHILE
	
		if(isGameOver == true && isWon == true) //game is won
		{
			iClear(0,0,100,30);
			displayBoard(refboard, row, column, roomNo);
			iMoveCursor(42,10);
			printf("!===== You won! =====!\n");
			sleep(4);
			iMoveCursor(45,12);
			printf("Going to the next room...\n");
			sleep(2);
			runner = runner->nextNode;
			roomNo++;
			playGame(&runner,&first,roomNo,isTutorial);
		}
	
		else if(isGameOver == true && isWon == false) //if player stepped on mine AT ANY POINT
		{
			iClear(0,0,100,30);
			displayBoard(gameboard, row, column, roomNo);
			iSetColor(I_COLOR_RED);
			printf("\n   :( You stepped on a bomb! Game Over! ):\n");
			sleep(1);
			printf("\n   Would you like to play again? (Y)(N) ");
			printf("\n   Selecting 'N' means exiting the game! : ");
			while(endchoice != 'y' && endchoice != 'n' && endchoice != 'Y' && endchoice != 'N')
			{
				endchoice = getch();
			}
			tolower(endchoice);
		
			if(endchoice == 'y')
			{
				runner = first;
				mainMenu(&runner, "Previous Created/Loaded Room Set");
			}
			else
			{
				quitGame(first);
			}
		}
	} //END OF WHILE != NULL
	
	iClear(0,0,100,30);
	iMoveCursor(50,10);
	iSetColor(I_COLOR_YELLOW);
	printf("==================================================");
	iSetColor(I_COLOR_GREEN);
	printf("\t\t\t\t ===Congratulations! YOU COMPLETED ALL OF THE ROOMS!=== \n");
	iSetColor(I_COLOR_CYAN);
	printf("=======================================================================");
	iSetColor(I_COLOR_GREEN);
	printf("\n\n   Would you like to play again? (Y)(N) \n");
	printf("\n     Selecting 'N' means exiting the game! : ");
	while(endchoice != 'y' && endchoice != 'n' && endchoice != 'Y' && endchoice != 'N')
	{
		endchoice = getch();
	}
	tolower(endchoice);
	if(endchoice == 'y')
	{
		iClear(0,0,130,30);
		runner = *loadedSet; //runner becomes NULL here
		mainMenu(&runner, "No Loaded Room Set");
	}
	else
	{
		quitGame(first);
	}
}

/* This function deallocates the loaded linked list ng level set, and quits the game
@ param (struct *) node loadedSet holds the loaded/created level set 
@ return void
*/
void quitGame(node *loadedSet)
{
	//deallocation
	node *runner;
	node *trail;
	
	trail = loadedSet;
	while(trail != NULL)
	{
		runner = trail->nextNode;
		free(trail);
		trail = runner;
	}
	//end of dealloc
	
	iClear(0,0,130,30);
	iMoveCursor(15,1);
	printf("     You are now free from the challenges that live in this complicated house.");
	sleep(2);
	iMoveCursor(15,3);
	printf("     You open the door.");
	sleep(2);
	iSetColor(I_COLOR_YELLOW);
	iMoveCursor(15,5);
	printf("     Sunlight.");
	iMoveCursor(15,7);
	sleep(2);
	iMoveCursor(15,9);
	printf("     You live to tell the story another day.");
	sleep(3);
	iClear(0,0,130,30);
	iMoveCursor(45,1);
	printf("     Thank you for playing!\n\n");
	printf("     Created by: Aldrey Gaurana");
	sleep(1);
	exit(0);
}
