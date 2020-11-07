#include<stdio.h>     // Gaurana, Aldrey D. 1v1 pokemon battle simulator
#include<stdlib.h>
#include<windows.h>
#include<time.h>

//displays each Pokemon's movelist
void displayMoves(int nP1Pokemon,int *nPPSet,int *nBerries)
{
	if(nP1Pokemon==1)
	{
		printf("Entei Move Set\n");
		printf("1 - Fire Blast (30 BP - %d PP)\n",nPPSet[0]);
		printf("2 - Earthquake (30 BP - %d PP)\n",nPPSet[1]);
		printf("3 - Protect (0 BP - %d PP)\n",nPPSet[2]);
		printf("4 - Charge Up (0 BP - %d PP)\n",nPPSet[3]);
		printf("5 - Sitrus Berry (%d left) (Restores 25%% of total HP)\n",nBerries[0]);
		printf("6 - Leppa Berry (%d left) (Restores all PP)\n",nBerries[1]);
	}
	else if(nP1Pokemon==2)
	{
		printf(" Milotic Move Set\n");
		printf("1 - Scald (20 BP - %d PP)\n",nPPSet[0]);
		printf("2 - Ice Beam (20 BP - %d PP)\n",nPPSet[1]);
		printf("3 - Protect (0 BP - %d PP)\n",nPPSet[2]);
		printf("4 - Charge Up (0 BP - %d PP)\n",nPPSet[3]);
		printf("5 - Sitrus Berry (%d left) (Restores 25%% of total HP)\n",nBerries[0]);
		printf("6 - Leppa Berry (%d left) (Restores all PP)\n",nBerries[1]);
	}
	else if(nP1Pokemon==3)
	{
		printf("Torterra Move Set\n");
		printf("1 - Dig (20 BP - %d PP)\n",nPPSet[0]);	
		printf("2 - Leaf Storm (40 BP - %d PP)\n",nPPSet[1]);
		printf("3 - Protect (0 BP - %d PP)\n",nPPSet[2]);
		printf("4 - Charge Up (0 BP - %d PP)\n",nPPSet[3]);
		printf("5 - Sitrus Berry (%d left) (Restores 25%% of total HP)\n",nBerries[0]);
		printf("6 - Leppa Berry (%d left) (Restores all PP)\n",nBerries[1]);
	}
	else if(nP1Pokemon==4)
	{
		printf("Pikachu Move Set\n");
		printf("1 - Thunderbolt (10 BP - %d PP)\n",nPPSet[0]);
		printf("2 - Dig (20 BP - %d PP)\n",nPPSet[1]);
		printf("3 - Protect (0 BP - %d PP)\n",nPPSet[2]);
		printf("4 - Charge Up (0 BP - %d PP)\n",nPPSet[3]);
		printf("5 - Sitrus Berry (%d left) (Restores 25%% of total HP)\n",nBerries[0]);
		printf("6 - Leppa Berry (%d left) (Restores all PP)\n",nBerries[1]);
	}
	else if(nP1Pokemon==5)
	{
		printf("Groudon Move Set\n");
		printf("1 - Fissure (40 BP - %d PP)\n",nPPSet[0]);
		printf("2 - Fire Blast (30 BP - %d PP)\n",nPPSet[1]);
		printf("3 - Protect (0 BP - %d PP)\n",nPPSet[2]);
		printf("4 - Charge Up (0 BP - %d PP)\n",nPPSet[3]);
		printf("5 - Sitrus Berry (%d left) (Restores 25%% of total HP)\n",nBerries[0]);
		printf("6 - Leppa Berry (%d left) (Restores all PP)\n",nBerries[1]);
	}
	else if(nP1Pokemon==6)
	{
		printf("Lapras Move Set\n");
		printf("1 - Ice Beam (20 BP - %d PP)\n",nPPSet[0]);
		printf("2 - Scald (20 BP - %d PP)\n",nPPSet[1]);
		printf("3 - Protect (0 BP - %d PP)\n",nPPSet[2]);
		printf("4 - Charge Up (0 BP - %d PP)\n",nPPSet[3]);
		printf("5 - Sitrus Berry (%d left) (Restores 25%% of total HP)\n",nBerries[0]);
		printf("6 - Leppa Berry (%d left) (Restores all PP)\n",nBerries[1]);
	}
	else if(nP1Pokemon==7)
	{
		printf("Stunfisk Move Set\n");
		printf("1 - Water Gun (10 BP - %d PP)\n",nPPSet[0]);
		printf("2 - Earthquake (30 BP - %d PP)\n",nPPSet[1]);
		printf("3 - Protect (0 BP - %d PP)\n",nPPSet[2]);
		printf("4 - Charge Up (0 BP - %d PP)\n",nPPSet[3]);
		printf("5 - Sitrus Berry (%d left) (Restores 25%% of total HP)\n",nBerries[0]);
		printf("6 - Leppa Berry (%d left) (Restores all PP)\n",nBerries[1]);
	}
	printf("=================================\n");
}

//returns if type matchups are effective or nah
char p1M1TypeEffectiveness(char nP1Move1Type,char nP2TypeOne,char nP2TypeTwo)
{
	//n=not effective (x1/2) ; e=effective (x1) ; s=super effective (x2) ; m=minimum (x1/4) ; u=ultimate(x4) ; z=zero (x0)
	
	if(nP1Move1Type=='f')
	{
		if(nP2TypeOne=='f'||nP2TypeOne=='g'||nP2TypeOne=='w')
			return 'n';
		else if(nP2TypeOne=='e')
			return 'e';
		else if(nP2TypeOne=='r'||nP2TypeOne=='i')
			return 's';
		else
			printf("invalid");		
	}
	else if(nP1Move1Type=='w')
	{
		if(nP2TypeOne=='r'||nP2TypeOne=='w')
			return 'n';
		else if(nP2TypeOne=='e'||nP2TypeOne=='i')
			return 'e';
		else if(nP2TypeOne=='f'||nP2TypeOne=='g')
			return 's';
		else
			printf("invalid");
	}
	else if(nP1Move1Type=='g')
	{
		if(nP2TypeOne=='r'||nP2TypeOne=='i'||nP2TypeOne=='w')
			return 'n';
		else if(nP2TypeOne=='g')
			return 'e';
		else if(nP2TypeOne=='f'||nP2TypeOne=='e')
			return 's';
		else
			printf("invalid");
	}
	else if(nP1Move1Type=='e')
	{
		if(nP2TypeOne=='r')
			return 'n';
		else if(nP2TypeOne=='f'||nP2TypeOne=='e'||nP2TypeOne=='i')
			return 'e';
		else if(nP2TypeOne=='w')
			return 's';
		else if(nP2TypeOne=='g')
			return 'z';
		else
			printf("invalid");	
	}
	else if(nP1Move1Type=='i')
	{
		if(nP2TypeOne=='f')
			return 'n';
		else if(nP2TypeOne=='e'||nP2TypeOne=='i')
			return 'e';
		else if(nP2TypeOne=='w'||nP2TypeOne=='r'||nP2TypeOne=='g')
			return 's';
		else
			printf("invalid");
	}
	else if(nP1Move1Type=='r')
	{
		if(nP2TypeOne=='f'||nP2TypeOne=='r')
			return 'n';
		else if(nP2TypeOne=='w'||nP2TypeOne=='g')
			return 's';
		else if(nP2TypeOne=='e'||nP2TypeOne=='i')
			return 'z';
		else
			printf("invalid");
	}
	else
	{
		return 0;
	}
}

//RETURNS FINAL DAMAGE VALUES
float damageCalcu(int nP1Pokemon,int nP2Pokemon,int nP1Move,char nP1Move1Type,char nP1Move2Type,char nP2TypeOne,char nP2TypeTwo,float nAttackPts)
{
	float nFinalDamage1;
	char cEffect;
	if(nP1Move==1)
		nP1Move1Type=nP1Move1Type; //1st move type will be used here
	if(nP1Move==2)
		nP1Move1Type=nP1Move2Type; //switches to the 2nd move type to be used here
	switch(nP1Pokemon) //switch case for each pokemon
	{
		//ENTEI
		case 1:{
			if(nP1Move==4) //if CHARGE UP is used
				nAttackPts=nAttackPts*2;
			else if(nP1Move==1) //if STAB move
				nFinalDamage1=nAttackPts*1.5;
			else if(nP1Move==2)
				nFinalDamage1=nAttackPts*1;		
			if (nP2Pokemon==3) //SPECIAL CASES FOR 2 TYPE POKEMONS
			{
				if(nP1Move==1)
					return nFinalDamage1=nFinalDamage1*1;
				else if(nP1Move==2)
					return nFinalDamage1=nFinalDamage1*0.5;
				break;
			}	
			else if(nP2Pokemon==6)
			{
				if(nP1Move==1)
					return nFinalDamage1=nFinalDamage1*1;
				else if(nP1Move==2)
					return nFinalDamage1=nFinalDamage1*0.25;					
				break;
			}
			else if(nP2Pokemon==7)
			{
				if(nP1Move==1)
					return nFinalDamage1=nFinalDamage1*0.5;
				else if(nP1Move==2)
					return nFinalDamage1=nFinalDamage1*2;
				break;
			}
			else if(nP2Pokemon==1) //SPECIAL CASE FOR SAME POKEMON
			{
				if(nP1Move==1)
					return nFinalDamage1=nFinalDamage1*0.5;
				else if(nP1Move==2)
					return nFinalDamage1=nFinalDamage1*2;
				break;
			}	
			else //IF POKEMON IS SINGLE TYPE
			{
				//type effectiveness
				cEffect=p1M1TypeEffectiveness(nP1Move1Type,nP2TypeOne,nP2TypeTwo);
				if(cEffect=='n')
					return nFinalDamage1=nFinalDamage1*0.5;
				else if(cEffect=='e')
					return nFinalDamage1=nFinalDamage1*1;
				else if(cEffect=='s')
					return nFinalDamage1=nFinalDamage1*2;
				else if(cEffect=='m')
					return nFinalDamage1=nFinalDamage1*0.25;
				else if(cEffect=='u')
					return nFinalDamage1=nFinalDamage1*4;
				else{
					printf("The move does not affect the opposing Pokemon.");
					return nFinalDamage1=nFinalDamage1*0;
				}		
			}
			break;
			}
		//MILOTIC
		case 2:{	
			//if STAB move
			if(nP1Move==1)
				nFinalDamage1=nAttackPts*1.5;
			else if(nP1Move==2)
				nFinalDamage1=nAttackPts;	
			else if(nP1Move==4)
				nAttackPts=nAttackPts*2;
			else
				nFinalDamage1=0;
			//SPECIAL CASES FOR DOUBLE TYPE POKEMONS
			if (nP2Pokemon==3)
			{
				if(nP1Move==1)
					return nFinalDamage1=nFinalDamage1*1;
				else if(nP1Move==2)
					return nFinalDamage1=nFinalDamage1*4;
			}	
			else if(nP2Pokemon==6)
			{
				if(nP1Move==1)
					return nFinalDamage1=nFinalDamage1*0.5;
				else if(nP1Move==2)
					return nFinalDamage1=nFinalDamage1*2;
			}
			else if(nP2Pokemon==7)
			{
				if(nP1Move==1)
					return nFinalDamage1=nFinalDamage1*2;
				else if(nP1Move==2)
					return nFinalDamage1=nFinalDamage1*2;
			}
			//SPECIAL CASE FOR SAME POKEMON
			else if(nP2Pokemon==2)
			{
				if(nP1Move==1)
					return nFinalDamage1=nFinalDamage1*0.5;
				else if(nP1Move==2)
					return nFinalDamage1=nFinalDamage1*1;
				break;
			}		
			else
			{
				//type effectiveness
				cEffect=p1M1TypeEffectiveness(nP1Move1Type,nP2TypeOne,nP2TypeTwo);
				if(cEffect=='n')
					return nFinalDamage1=nFinalDamage1*0.5;
				else if(cEffect=='e')
					return nFinalDamage1=nFinalDamage1*1;
				else if(cEffect=='s')
					return nFinalDamage1=nFinalDamage1*2;
				else if(cEffect=='m')
					return nFinalDamage1=nFinalDamage1*0.25;
				else if(cEffect=='u')
					return nFinalDamage1=nFinalDamage1*4;
				else
					{
						printf("The move does not affect the opposing Pokemon.");
						return nFinalDamage1=nFinalDamage1*0;	
					}	
			}
			break;		
		}
		//TORTERRA
		case 3:{			
			//if STAB move
			if(nP1Move==1 || nP1Move==2)
				nFinalDamage1=nAttackPts*1.5;
			//SPECIAL CASES FOR DOUBLE TYPE POKEMONS
			if (nP2Pokemon==3)
			{
				if(nP1Move==1)
					return nFinalDamage1=nFinalDamage1*0.5;
				else if(nP1Move==2)
					return nFinalDamage1=nFinalDamage1*1;
				break;
			}	
			else if(nP2Pokemon==6)
			{
				if(nP1Move==1)
					return nFinalDamage1=nFinalDamage1*0.25;
				else if(nP1Move==2)
					return nFinalDamage1=nFinalDamage1*0;
				break;
			}
			else if(nP2Pokemon==7)
			{
				if(nP1Move==1)
					return nFinalDamage1=nFinalDamage1*2;
				else if(nP1Move==2)
					return nFinalDamage1=nFinalDamage1*0;
				break;
			}	
			else
			{
				//type effectiveness
				cEffect=p1M1TypeEffectiveness(nP1Move1Type,nP2TypeOne,nP2TypeTwo);
				if(cEffect=='n')
					return nFinalDamage1=nFinalDamage1*0.5;
				else if(cEffect=='e')
					return nFinalDamage1=nFinalDamage1*1;
				else if(cEffect=='s')
					return nFinalDamage1=nFinalDamage1*2;
				else if(cEffect=='m')
					return nFinalDamage1=nFinalDamage1*0.25;
				else if(cEffect=='u')
					return nFinalDamage1=nFinalDamage1*4;
				else
				{
					printf("The move does not affect the opposing Pokemon.");
					return nFinalDamage1=nFinalDamage1*0;
				}	
			}
			break;
			}
		//PIKACHU
		case 4:{
			//if STAB move
			if(nP1Move==1)
				nFinalDamage1=nAttackPts*1.5;
			else if(nP1Move==2)
				nFinalDamage1=nAttackPts*1;
			//SPECIAL CASES FOR DOUBLE TYPE POKEMONS
			if (nP2Pokemon==3)
			{
				if(nP1Move==1)
					return nFinalDamage1=nFinalDamage1*0;
				else if(nP1Move==2)
					return nFinalDamage1=nFinalDamage1*0.5;
				break;
			}	
			else if(nP2Pokemon==6)
			{
				if(nP1Move==1)
					return nFinalDamage1=nFinalDamage1*2;
				else if(nP1Move==2)
					return nFinalDamage1=nFinalDamage1*0.25;
				break;
			}
			else if(nP2Pokemon==7)
			{
				if(nP1Move==1)
					return nFinalDamage1=nFinalDamage1*0;
				else if(nP1Move==2)
					return nFinalDamage1=nFinalDamage1*2;
				break;
			}
			//SPECIAL CASE FOR SAME POKEMON
			else if(nP2Pokemon==4)
			{
				if(nP1Move==1)
					return nFinalDamage1=nFinalDamage1*1;
				else if(nP1Move==2)
					return nFinalDamage1=nFinalDamage1*2;
				break;
			}		
			else
			{
				//type effectiveness
				cEffect=p1M1TypeEffectiveness(nP1Move1Type,nP2TypeOne,nP2TypeTwo);
				if(cEffect=='n')
					return nFinalDamage1=nFinalDamage1*0.5;
				else if(cEffect=='e')
					return nFinalDamage1=nFinalDamage1*1;
				else if(cEffect=='s')
					return nFinalDamage1=nFinalDamage1*2;
				else if(cEffect=='m')
					return nFinalDamage1=nFinalDamage1*0.25;
				else if(cEffect=='u')
					return nFinalDamage1=nFinalDamage1*4;
				else
				{
					printf("The move does not affect the opposing Pokemon.");
					return nFinalDamage1=nFinalDamage1*0;		
				}	
			}
			break;
			}
		//GROUDON
		case 5:{	
			//if STAB move
			if(nP1Move==1)
				nFinalDamage1=nAttackPts*1.5;
			else if(nP1Move==2)
				nFinalDamage1=nAttackPts*1;
			//SPECIAL CASES FOR DOUBLE TYPE POKEMONS
			if (nP2Pokemon==3)
			{
				if(nP1Move==1)
					return nFinalDamage1=nFinalDamage1*0.5;
				else if(nP1Move==2)
					return nFinalDamage1=nFinalDamage1*1;
				break;
			}	
			else if(nP2Pokemon==6)
			{
				if(nP1Move==1)
					return nFinalDamage1=nFinalDamage1*0.25;
				else if(nP1Move==2)
					return nFinalDamage1=nFinalDamage1*1;
				break;
			}
			else if(nP2Pokemon==7)
			{
				if(nP1Move==1)
					return nFinalDamage1=nFinalDamage1*2;
				else if(nP1Move==2)
					return nFinalDamage1=nFinalDamage1*0.5;
				break;
			}
			//SPECIAL CASE FOR SAME POKEMON
			else if(nP2Pokemon==5)
			{
				if(nP1Move==1)
					return nFinalDamage1=nFinalDamage1*1;
				else if(nP1Move==2)
					return nFinalDamage1=nFinalDamage1*0.5;
				break;
			}	
			else
			{
				//type effectiveness
				cEffect=p1M1TypeEffectiveness(nP1Move1Type,nP2TypeOne,nP2TypeTwo);
				if(cEffect=='n')
					return nFinalDamage1=nFinalDamage1*0.5;
				else if(cEffect=='e')
					return nFinalDamage1=nFinalDamage1*1;
				else if(cEffect=='s')
					return nFinalDamage1=nFinalDamage1*2;
				else if(cEffect=='m')
					return nFinalDamage1=nFinalDamage1*0.25;
				else if(cEffect=='u')
					return nFinalDamage1=nFinalDamage1*4;
				else
				{
					printf("The move does not affect the opposing Pokemon.");
					return nFinalDamage1=nFinalDamage1*0;		
				}	
			}
			break;
			}
		//LAPRAS
		case 6:{
			//if STAB move
			if(nP1Move==1||nP1Move==2)
				nFinalDamage1=nAttackPts*1.5;
			//SPECIAL CASES FOR DOUBLE TYPE POKEMONS
			if (nP2Pokemon==3)
			{
				if(nP1Move==1)
					return nFinalDamage1=nFinalDamage1*4;
				else if(nP1Move==2)
					return nFinalDamage1=nFinalDamage1*1;
				break;
			}	
			else if(nP2Pokemon==6)
			{
				if(nP1Move==1)
					return nFinalDamage1=nFinalDamage1*2;
				else if(nP1Move==2)
					return nFinalDamage1=nFinalDamage1*0.5;
				break;
			}
			else if(nP2Pokemon==7)
			{
				if(nP1Move==1)
					return nFinalDamage1=nFinalDamage1*2;
				else if(nP1Move==2)
					return nFinalDamage1=nFinalDamage1*2;
				break;
			}	
			else
			{
				//type effectiveness
				cEffect=p1M1TypeEffectiveness(nP1Move1Type,nP2TypeOne,nP2TypeTwo);
				if(cEffect=='n')
					return nFinalDamage1=nFinalDamage1*0.5;
				else if(cEffect=='e')
					return nFinalDamage1=nFinalDamage1*1;
				else if(cEffect=='s')
					return nFinalDamage1=nFinalDamage1*2;
				else if(cEffect=='m')
					return nFinalDamage1=nFinalDamage1*0.25;
				else if(cEffect=='u')
					return nFinalDamage1=nFinalDamage1*4;
				else
				{
					printf("The move does not affect the opposing Pokemon.");
					return nFinalDamage1=nFinalDamage1*0;	
				}	
			}
			break;
			}
		//STUNFISK
		case 7:{
			// if STAB move
			if(nP1Move==1)
				nFinalDamage1=nAttackPts*1;
			else if(nP1Move==2)
				nFinalDamage1=nAttackPts*1.5;
			//SPECIAL CASES FOR DOUBLE TYPE POKEMONS
			if (nP2Pokemon==3)
			{
				if(nP1Move==1)
					return nFinalDamage1=nFinalDamage1*1;
				else if(nP1Move==2)
					return nFinalDamage1=nFinalDamage1*0.5;
				break;
			}	
			else if(nP2Pokemon==6)
			{
				if(nP1Move==1)
					return nFinalDamage1=nFinalDamage1*0.5;
				else if(nP1Move==2)
					return nFinalDamage1=nFinalDamage1*0.25;
				break;
			}
			else if(nP2Pokemon==7)
			{
				if(nP1Move==1)
					return nFinalDamage1=nFinalDamage1*2;
				else if(nP1Move==2)
					return nFinalDamage1=nFinalDamage1*2;
				break;
			}	
			else
			{
				//type effectiveness
				cEffect=p1M1TypeEffectiveness(nP1Move1Type,nP2TypeOne,nP2TypeTwo);
				if(cEffect=='n')
					return nFinalDamage1=nFinalDamage1*0.5;
				else if(cEffect=='e')
					return nFinalDamage1=nFinalDamage1*1;
				else if(cEffect=='s')
					return nFinalDamage1=nFinalDamage1*2;
				else if(cEffect=='m')
					return nFinalDamage1=nFinalDamage1*0.25;
				else if(cEffect=='u')
					return nFinalDamage1=nFinalDamage1*4;
				else
				{
					printf("The move does not affect the opposing Pokemon.");
					return nFinalDamage1=nFinalDamage1*0;	
				}	
			}
			break;
			}
	}
}

float ppDecrease(int nP1Move,int nP1Pokemon,int nAttackPts,int *nPPSet) //decreases PP values, returns atkpts
{
	if(nP1Move==1)
	{
		if(nPPSet[0]==0)
			return 1;
		switch(nP1Pokemon)
		{
			case 1:{
				nPPSet[0]=nPPSet[0]-1;
				return nAttackPts=30.0;
				break;
			}
			case 2:{
				nPPSet[0]=nPPSet[0]-1;
				return nAttackPts=20.0;
				break;
			}
			case 3:{
				nPPSet[0]=nPPSet[0]-1;
				return nAttackPts=20.0;
				break;
			}
			case 4:{
				nPPSet[0]=nPPSet[0]-1;
				return nAttackPts=10.0;
				break;
			}
			case 5:{
				nPPSet[0]=nPPSet[0]-1;
				return nAttackPts=40.0;
				break;
			}
			case 6:{
				nPPSet[0]=nPPSet[0]-1;
				return nAttackPts=20.0;
				break;
			}
			case 7:{
				nPPSet[0]=nPPSet[0]-1;
				return nAttackPts=10.0;
				break;
			}
			default:
				printf("Invalid");
		}
	}
	else if(nP1Move==2)
	{
		if(nPPSet[1]==0)
			return 1;
		switch(nP1Pokemon)
		{
			case 1:{
				nPPSet[1]=nPPSet[1]-1;
				return nAttackPts=30.0;
				break;
			}
			case 2:{
				nPPSet[1]=nPPSet[1]-1;
				return nAttackPts=20.0;
				break;
			}
			case 3:{
				nPPSet[1]=nPPSet[1]-1;
				return nAttackPts=40.0;
				break;
			}
			case 4:{
				nPPSet[1]=nPPSet[1]-1;
				return nAttackPts=20.0;
				break;
			}
			case 5:{
				nPPSet[1]=nPPSet[1]-1;
				return nAttackPts=30.0;
				break;
			}
			case 6:{
				nPPSet[1]=nPPSet[1]-1;
				return nAttackPts=20.0;
				break;
			}
			case 7:{
				nPPSet[1]=nPPSet[1]-1;
				return nAttackPts=30.0;
				break;
			}
			default:
				printf("Invalid");
		}
	}
	else if (nP1Move==3)
	{
		if(nPPSet[2]==0)
			return 1;
		switch(nP1Pokemon)
		{
			case 1:{
				nPPSet[2]=nPPSet[2]-1;
				return nAttackPts=0;
				break;
			}
			case 2:{
				nPPSet[2]=nPPSet[2]-1;
				return nAttackPts=0;
				break;
			}
			case 3:{
				nPPSet[2]=nPPSet[2]-1;
				return nAttackPts=0;
				break;
			}
			case 4:{
				nPPSet[2]=nPPSet[2]-1;
				return nAttackPts=0;
				break;
			}
			case 5:{
				nPPSet[2]=nPPSet[2]-1;
				return nAttackPts=0;
				break;
			}
			case 6:{
				nPPSet[2]=nPPSet[2]-1;
				return nAttackPts=0;
				break;
			}
			case 7:{
				nPPSet[2]=nPPSet[2]-1;
				return nAttackPts=0;
				break;
			}
			default:
				printf("Invalid");
		}
	}
	else if(nP1Move==4)
	{
		if(nPPSet[3]==0)
			return 1;	
		switch(nP1Pokemon)
		{
			case 1:{
				nPPSet[3]=nPPSet[3]-1;
				break;
			}
			case 2:{
				nPPSet[3]=nPPSet[3]-1;
				break;
			}
			case 3:{
				nPPSet[3]=nPPSet[3]-1;
				break;
			}
			case 4:{
				nPPSet[3]=nPPSet[3]-1;
				break;
			}
			case 5:{
				nPPSet[3]=nPPSet[3]-1;
				break;
			}
			case 6:{
				nPPSet[3]=nPPSet[3]-1;
				break;
			}
			case 7:{
				nPPSet[3]=nPPSet[3]-1;
				break;
			}
			default:
				printf("Invalid");
		}
	}
}

//main combat fxn
void combat(int nP1Pokemon,int nP2Pokemon,int nP1Health,int nP2Health,char nP1TypeOne,char nP1TypeTwo,char nP2TypeOne,char nP2TypeTwo,
char nP1Move1Type,char nP1Move2Type,char nP2Move1Type,char nP2Move2Type,int *nP1PPSet,int *nP2PPSet,int nMaxHealthP1,int nMaxHealthP2,
int *nP1PPMax,int *nP2PPMax,int nGameMode)
{
	//init array of pokemon names
	const char *pokemonNames[7]={"Entei","Milotic","Torterra","Pikachu","Groudon","Lapras","Stunfisk"};
	//init variable for max pokemon health,move PP's,P1 and P2 move
	int nP1Move,nP2Move,nP1Turn=0,nP2Turn=0,nProtP1,nProtP2,nPlayer=1,nChargeP1,nChargeP2;
	int dmgP1,dmgP2;
	int nBerriesP1[2]={2,2};
	int nBerriesP2[2]={2,2};
	
	int ppCtr,protP1Turn=0,protP2Turn=0;
	
	float nAttackPtsP1=0,nAttackPtsP2=0;
	
	while(nP1Health>0 && nP2Health>0)
	{
		nPlayer=(nPlayer%2==1) ? 1:2;
		
		if(nPlayer==1 && nP1Health>0) //player 1 move
		{
			printf("\n\n==========BATTLE STATS===========");
			printf("\n %s",pokemonNames[nP1Pokemon-1]);
			printf("\n ==========%d HP==========",nP1Health);
			printf("\n %s",pokemonNames[nP2Pokemon-1]);
			printf("\n ==========%d HP==========\n",nP2Health);
			printf("=================================\n");
			displayMoves(nP1Pokemon,nP1PPSet,nBerriesP1);
			displayMoves(nP2Pokemon,nP2PPSet,nBerriesP2);
			if(nP1PPSet[0]==0 && nP1PPSet[1]==0 && nP1PPSet[2]==0 && nP1PPSet[3]==0) //if ubos na pp
			{
				printf("\nNo moves left!\nYour Pokemon used Struggle!\n");
				nP1Health=nP1Health-5;
				nP2Health=nP2Health-10;
				nP1Turn++;
				nPlayer++;
			}
			
			else{
				do{
					printf("\nChoose your move PLAYER 1! = ");
					scanf("%d",&nP1Move);
				}
				while(nP1Move<1 || nP1Move>6);
				
				if(nP1Move==5 && nBerriesP1[0]>0 && nP1Health!=nMaxHealthP1) //sitrus berry is used and not zero
				{
					printf("\nYou used Sitrus Berry!!\n");
					Sleep(1000);
					printf("Restoring health...\n");
					nP1Health=nP1Health+(nMaxHealthP1*0.25);
					if(nP1Health>nMaxHealthP1)
						nP1Health=nMaxHealthP1; //if sobra yung restored health
					dmgP1=dmgP1*0;
					nAttackPtsP1=0;
					nBerriesP1[0]=nBerriesP1[0]-1;
				}
				else if(nP1Move==5 && nBerriesP1[0]<=0 || nP1Move==5 && nP1Health==nMaxHealthP1)
				{ //if sitrus berry is zero
					printf("\nInvalid move!!\n");
					Sleep(1000);
					printf("Please choose another move.\n");
					dmgP1=dmgP1*0;
					nAttackPtsP1=0;
					nP1Turn--;
					nPlayer--;
				}
			
				if(nP1Move==6 && nBerriesP1[1]>0 && nP1PPSet[0]<nP1PPMax[0] && nP1PPSet[1]<nP1PPMax[1] && nP1PPSet[2]<nP1PPMax[2] && nP1PPSet[3]<nP1PPMax[3]) //leppa berry is used and not zero
				{
					printf("\nYou used Leppa Berry!!\n");
					Sleep(1000);
					printf("Restoring PP...\n");
					for(ppCtr=0;ppCtr<4;ppCtr++)
					{
						nP1PPSet[ppCtr]=nP1PPMax[ppCtr]; //restores pp count
					}
					dmgP1=0;
					nAttackPtsP1=0;
					nBerriesP1[1]=nBerriesP1[1]-1;
				}
				else if(nP1Move==6 && nBerriesP1[1]<=0 || nP1Move==6 && nP1PPSet[0]==nP1PPMax[0] && nP1PPSet[1]==nP1PPMax[1] && nP1PPSet[2]==nP1PPMax[2] && nP1PPSet[3]==nP1PPMax[3])
				{ //if leppa berry is zero
					printf("\nInvalid move!!\n");
					Sleep(1000);
					printf("Please choose another move.\n");
					dmgP1=dmgP1*0;
					nAttackPtsP1=0;
					nP1Turn--;
					nPlayer--;
				}
				
				nAttackPtsP1=ppDecrease(nP1Move,nP1Pokemon,nAttackPtsP1,nP1PPSet); //returns the corresponding atkpts and decreases pp
				
				if(nAttackPtsP1==1)
				{
					printf("\nYou do not have enough PP!\nPlease choose another move.\n");
					printf("Redirecting...");
					nP1Turn--;
					nPlayer--;
				}
				
				nPlayer++; //makes player add 1 to itself
				
				if(nP1Move==1 || nP1Move==2)
				{
					protP1Turn++;
				}
					
				if (nP1Move==3 && nProtP1==1 && protP1Turn<=1 || nP1Move==3 && nProtP1==0 && protP1Turn<=1)
				{
					printf("\n\nPROTECT CANNOT BE USED TWICE!\n\n"); //if protect is used twice
					nP1Turn--; // bawas 1 sa turn
					nPlayer--; //bawas 1 sa player
					printf("\n\nRedirecting..."); //redirects to p1 move selection
					if(nProtP1==1)
						nProtP1==1;
					if (nProtP1==0)
						nProtP1==0;
				}
				else if(nP1Move==3)
				{
					protP1Turn=0;
					nProtP1=1; //protect for P1 becomes activated
				}
			
				if(nChargeP1==1) //if charge up is activated
				{
					if(nP1Move==1 || nP1Move==2) //if damaging move
					{
						nAttackPtsP1=nAttackPtsP1*2;
						nChargeP1=0; //charge up is deactivated
					}
					else
						nChargeP1=1; //cjarge up remains activated
				}
				
				dmgP1=damageCalcu(nP1Pokemon,nP2Pokemon,nP1Move,nP1Move1Type,nP1Move2Type,nP2TypeOne,nP2TypeTwo,nAttackPtsP1); //returns final computed dmg
				
				if(nProtP2==1) //if P2's protect is activated
				{
					if(nP1Move==1 || nP1Move==2)
					{
						printf("\nEnemy Pokemon used Protect! Damage is negated.\n");
						dmgP1=dmgP1*0; //damage is negated
						nProtP2=0; //protect for P2 is deactivated
					}	
					else
						nProtP2=1; //protect for P2 remains activated
				}
			
				if(nP1Move==4)
				{
					dmgP1=dmgP1*0; //no dmg dealt
					nChargeP1=1; //charge up becomes activated
					protP1Turn++;
				}
				printf("\n\nDamage dealt:%d\n\n",dmgP1);	
				nP2Health=nP2Health-dmgP1;
				nP1Turn++;	
			}
		}
		//end of player 1
		Sleep(2000);
		
		//start of player 2
		if(nPlayer==2 && nP2Health>0) //player 2 move
		{
			printf("\n\n==========BATTLE STATS===========");
			printf("\n %s",pokemonNames[nP1Pokemon-1]);
			printf("\n ==========%d HP==========",nP1Health);
			printf("\n %s",pokemonNames[nP2Pokemon-1]);
			printf("\n ==========%d HP==========\n",nP2Health);
			printf("=================================\n");
			displayMoves(nP1Pokemon,nP1PPSet,nBerriesP1);
			displayMoves(nP2Pokemon,nP2PPSet,nBerriesP2);
			if(nP2PPSet[0]==0 && nP2PPSet[1]==0 && nP2PPSet[2]==0 && nP2PPSet[3]==0) //if ubos na pp
			{
				printf("\nNo moves left!\nYour Pokemon used Struggle!\n");
				nP2Health=nP2Health-5;
				nP1Health=nP1Health-10;
				nP2Turn++;
				nPlayer++;
			}
			else{
				
				if(nGameMode==1)
				{
					nP2Move=( rand()%6 ) + 1;
					printf("\n\nPicking...\n\n");
					Sleep(2500);
				}
				
				if(nGameMode==2)
				{
					do{
						printf("\nChoose your move PLAYER 2! = ");
						scanf("%d",&nP2Move);
					}
					while(nP2Move<1 || nP2Move>6);
				}
			
				if(nP2Move==5 && nBerriesP2[0]>0 && nP2Health!=nMaxHealthP2) //sitrus berry is used and not zero
				{
					printf("\nYou used Sitrus Berry!!\n");
					Sleep(1000);
					printf("Restoring health...\n");
					nP2Health=nP2Health+(nMaxHealthP2*0.25);
					if(nP2Health>nMaxHealthP2)
						nP2Health=nMaxHealthP2; //if sobra yung restored health
					dmgP2=0;
					nAttackPtsP2=0;
					nBerriesP2[0]=nBerriesP2[0]-1;
				}
				else if(nP2Move==5 && nBerriesP2[0]<=0 || nP2Move==5 && nP2Health==nMaxHealthP2)
				{ //if sitrus berry is zero
					printf("\nInvalid move!!\n");
					Sleep(1000);
					printf("Please choose another move.\n");
					dmgP2=dmgP2*0;
					nAttackPtsP2=0;
					nP2Turn--;
					nPlayer--;
				}
			
				if(nP2Move==6 && nBerriesP2[1]>0 && nP2PPSet[0]<nP2PPMax[0] && nP2PPSet[1]<nP2PPMax[1] && nP2PPSet[2]<nP2PPMax[2] && nP2PPSet[3]<nP2PPMax[3]) //leppa berry is used and not zero
				{
					printf("\nYou used Leppa Berry!!\n");
					Sleep(1000);
					printf("Restoring PP...\n");
					for(ppCtr=0;ppCtr<4;ppCtr++)
					{
						nP2PPSet[ppCtr]=nP2PPMax[ppCtr]; //restores pp count
					}
					dmgP2=dmgP2*0;
					nAttackPtsP2=0;
					nBerriesP2[1]=nBerriesP2[1]-1;
				}
				else if(nP2Move==6 && nBerriesP2[1]<=0 || nP2Move==6 && nP2PPSet[0]==nP2PPMax[0] && nP2PPSet[1]==nP2PPMax[1] && nP2PPSet[2]==nP2PPMax[2] && nP2PPSet[3]==nP2PPMax[3])
				{ //if leppa berry is zero
					printf("\nInvalid move!!\n");
					Sleep(1000);
					printf("Please choose another move.\n");
					dmgP2=dmgP2*0;
					nAttackPtsP2=0;
					nP2Turn--;
					nPlayer--;
				}
		
				nAttackPtsP2=ppDecrease(nP2Move,nP2Pokemon,nAttackPtsP2,nP2PPSet); //attack pts corresponding to move
				
				if(nAttackPtsP2==1) //ubos na pp sa move
				{
					printf("\nYou do not have enough PP!\nPlease choose another move.\n");
					printf("Redirecting...");
					nP2Turn--;
					nPlayer--;
				}
				nPlayer++; //adds 1 to player
				
				if(nP2Move==1 || nP2Move==2) //if damaging move
					protP2Turn++;
			
				if(nP2Move==3 && nProtP2==1 && protP2Turn<=1 || nP2Move==3 && nProtP2==0 && protP2Turn<=1)
				{
					printf("\n\nPROTECT CANNOT BE USED TWICE!\n\n");
					nPlayer--;
					printf("\n\nRedirecting...");
					if(nProtP2==1)
						nProtP2==1;
					if (nProtP2==0)
						nProtP2==0;
				}
				else if(nP2Move==3)
				{
					protP2Turn=0;
					nProtP2=1; //protect for P2 is activated	
				}
			
				if(nChargeP2==1)//charge up is activated
				{
					if(nP2Move==1 || nP2Move==2)
					{
						nAttackPtsP2=nAttackPtsP2*2;
						nChargeP2=0;//charge up becomes deactivated
					}
					else
						nChargeP2=1;
				}
				dmgP2=damageCalcu(nP2Pokemon,nP1Pokemon,nP2Move,nP2Move1Type,nP2Move2Type,nP1TypeOne,nP1TypeTwo,nAttackPtsP2);
				
				if(nProtP1==1) //player 2 attacks with p1 protected
				{
					if(nP2Move==1 || nP2Move==2)
					{
						printf("\nEnemy Pokemon used Protect! Damage is negated.\n");
						dmgP2=dmgP2*0;
						nProtP1=0; //protect for P1 is deactivated
					}	
					else
						nProtP1=1; //protect remains activated
				}
				if(nP2Move==4)
				{
					dmgP2=dmgP2*0; //no dmg dealt
					nChargeP2=1; //charge up is activated
					protP2Turn++;
				}
				printf("\n\nDamage dealt:%d\n\n",dmgP2);	
				nP1Health=nP1Health-dmgP2;
				nP2Turn++;	
			}
		} //end of player 2
		
		Sleep(2000);
		//reduce health
		// will make the loop go again until one player dies
		//if one dies, goto endgame
		//ENDGAME
		if(nP2Health<=0)
		{
			printf("\n%s fainted!",pokemonNames[nP2Pokemon-1]);
			Sleep(1000);
			printf("\n\n\nPlayer 1 wins!!!\n");
			return;
		}
		else if(nP1Health<=0)
		{
			printf("\n%s fainted!",pokemonNames[nP1Pokemon-1]);
			Sleep(1000);
			printf("\n\n\nPlayer 2 wins!!!\n");
			return;
		}
		else
			continue; 
	}
}

int main()
{
	srand(time(0)); //for rand in 1p mode
	// variable init
	int nP1Pokemon,nP2Pokemon,nP1Health,nP2Health,nRepeat,nMaxHealthP1,nMaxHealthP2;
	char nP1TypeOne,nP1TypeTwo,nP2TypeOne,nP2TypeTwo,nP1Move1Type,nP1Move2Type,nP2Move1Type,nP2Move2Type;
	int nP1PPSet[4]={}; // pp set for p1
	int nP2PPSet[4]={}; // pp set for p2
	int nP1PPMax[4]={}; // max pp set for p1
	int nP2PPMax[4]={}; // max pp set for p2
	int nGameMode;

	/*POKEMON TYPE GUIDE -- FIRE='f' ; WATER='w' ; GRASS='r' ; GROUND='g' ;
	ELECTRIC='e'; ICE='i' ; 
	*/ 
	
	// game initialization
	printf("\t Welcome to the Pokemon 1v1 Battle Simulator!");
	printf("\n\n Please choose a game mode!\n\n");
	printf("[1] Single Player Mode\n");
	printf("[2] Two Player Mode\n");
	printf("[3] Exit\n");
	printf("\nPlease enter your choice: ");
	scanf("%d",&nGameMode);
	if(nGameMode<1 || nGameMode>3)
	{
		do{
			printf("Please enter another choice: ");
			scanf("%d",&nGameMode);
		}
		while(nGameMode<1 || nGameMode>3);
	}
	if(nGameMode==3)
		return 0;
	system("cls");
	
	printf("\n\n Choose 1 Pokemon Below!\n");
	printf("\n Enter 1 for Entei");
	printf("\n Enter 2 for Milotic");
	printf("\n Enter 3 for Torterra");
	printf("\n Enter 4 for Pikachu");
	printf("\n Enter 5 for Groudon");
	printf("\n Enter 6 for Lapras");
	printf("\n Enter 7 for Stunfisk\n");
	printf(" Enter 8 to go back\n");
	//Choosing P1 Pokemon
	do{
		printf("\n Player 1, please select your choice/Pokemon:");
		scanf("%d",&nP1Pokemon);
	}
	while(nP1Pokemon<1 || nP1Pokemon>8);
	
	//Switch Case for Player 1 Pokemon
	switch(nP1Pokemon)
	{
		case 1:{
			printf("Player 1 chose Entei!\n");
			nP1TypeOne='f';
			nP1Health=150;
			nMaxHealthP1=150;
			nP1PPSet[0]=5;
			nP1PPSet[1]=5;
			nP1PPSet[2]=5;
			nP1PPSet[3]=5;
			nP1PPMax[0]=5;
			nP1PPMax[1]=5;
			nP1PPMax[2]=5;
			nP1PPMax[3]=5;
			nP1Move1Type='f';
			nP1Move2Type='g';
			break;
		}
		case 2:{
			printf("Player 1 chose Milotic!\n");
			nP1TypeOne='w';
			nP1Health=200;
			nMaxHealthP1=200;
			nP1PPSet[0]=7;
			nP1PPSet[1]=7;
			nP1PPSet[2]=5;
			nP1PPSet[3]=5;
			nP1PPMax[0]=7;
			nP1PPMax[1]=7;
			nP1PPMax[2]=5;
			nP1PPMax[3]=5;
			nP1Move1Type='w';
			nP1Move2Type='i';
			break;
		}
		case 3:{
			printf("Player 1 chose Torterra!\n");
			nP1TypeOne='r';
			nP1TypeTwo='g';
			nP1Health=220;
			nMaxHealthP1=220;
			nP1PPSet[0]=7;
			nP1PPSet[1]=5;
			nP1PPSet[2]=5;
			nP1PPSet[3]=5;
			nP1PPMax[0]=7;
			nP1PPMax[1]=5;
			nP1PPMax[2]=5;
			nP1PPMax[3]=5;
			nP1Move1Type='g';
			nP1Move2Type='r';
			break;
		}
		case 4:{
			printf("Player 1 chose Pikachu!\n");
			nP1TypeOne='e';
			nP1Health=120;
			nMaxHealthP1=120;
			nP1PPSet[0]=10;
			nP1PPSet[1]=7;
			nP1PPSet[2]=5;
			nP1PPSet[3]=5;
			nP1PPMax[0]=10;
			nP1PPMax[1]=7;
			nP1PPMax[2]=5;
			nP1PPMax[3]=5;
			nP1Move1Type='e';
			nP1Move2Type='g';
			break;
		}
		case 5:{
			printf("Player 1 chose Groudon!\n");
			nP1TypeOne='g';
			nP1Health=150;
			nMaxHealthP1=150;
			nP1PPSet[0]=5;
			nP1PPSet[1]=5;
			nP1PPSet[2]=5;
			nP1PPSet[3]=5;
			nP1PPMax[0]=5;
			nP1PPMax[1]=5;
			nP1PPMax[2]=5;
			nP1PPMax[3]=5;
			nP1Move1Type='g';
			nP1Move2Type='f';
			break;
		}
		case 6:{
			printf("Player 1 chose Lapras!\n");
			nP1TypeOne='i';
			nP1TypeTwo='w';
			nP1Health=190;
			nMaxHealthP1=190;
			nP1PPSet[0]=7;
			nP1PPSet[1]=7;
			nP1PPSet[2]=5;
			nP1PPSet[3]=5;
			nP1PPMax[0]=7;
			nP1PPMax[1]=7;
			nP1PPMax[2]=5;
			nP1PPMax[3]=5;
			nP1Move1Type='i';
			nP1Move2Type='w';
			break;
		}
		case 7:{
			printf("Player 1 chose Stunfisk!\n");
			nP1TypeOne='g';
			nP1TypeTwo='e';
			nP1Health=130;
			nMaxHealthP1=130;
			nP1PPSet[0]=10;
			nP1PPSet[1]=5;
			nP1PPSet[2]=5;
			nP1PPSet[3]=5;
			nP1PPMax[0]=10;
			nP1PPMax[1]=5;
			nP1PPMax[2]=5;
			nP1PPMax[3]=5;
			nP1Move1Type='w';
			nP1Move2Type='g';
			break;
		}
		case 8:{
			system("cls");
			main();
			break;
		}
		default:
			printf("Invalid input. Try again!\n");
	}
	
	//Choosing P2 Pokemon
	
	if(nGameMode==1)
	{
		nP2Pokemon=( rand()%7 ) + 1;
		printf("\n\nPicking...\n\n");
		Sleep(2500);
	}
	
	if(nGameMode==2)
	{
		do{
			printf("\n Player 2, please select a Pokemon:");
			scanf("%d",&nP2Pokemon);
		}
		while(nP2Pokemon<1 || nP2Pokemon>8);
	}
	
	//Switch Case for Player 2 Pokemon
	switch(nP2Pokemon)
	{
		case 1:{
			printf("Player 2 chose Entei!\n");
			nP2TypeOne='f';
			nP2Health=150;
			nMaxHealthP2=150;
			nP2PPSet[0]=5;
			nP2PPSet[1]=5;
			nP2PPSet[2]=5;
			nP2PPSet[3]=5;
			nP2PPMax[0]=5;
			nP2PPMax[1]=5;
			nP2PPMax[2]=5;
			nP2PPMax[3]=5;
			nP2Move1Type='f';
			nP2Move2Type='g';
			break;
		}
		case 2:{
			printf("Player 2 chose Milotic!\n");
			nP2TypeOne='w';
			nP2Health=200;
			nMaxHealthP2=200;
			nP2PPSet[0]=7;
			nP2PPSet[1]=7;
			nP2PPSet[2]=5;
			nP2PPSet[3]=5;
			nP2PPMax[0]=7;
			nP2PPMax[1]=7;
			nP2PPMax[2]=5;
			nP2PPMax[3]=5;
			nP2Move1Type='w';
			nP2Move2Type='i';
			break;
		}
		case 3:{
			printf("Player 2 chose Torterra!\n");
			nP2TypeOne='r';
			nP2TypeTwo='g';
			nP2Health=220;
			nMaxHealthP2=220;
			nP2PPSet[0]=7;
			nP2PPSet[1]=5;
			nP2PPSet[2]=5;
			nP2PPSet[3]=5;
			nP2PPMax[0]=7;
			nP2PPMax[1]=5;
			nP2PPMax[2]=5;
			nP2PPMax[3]=5;
			nP2Move1Type='g';
			nP2Move2Type='r';
			break;
		}
		case 4:{
			printf("Player 2 chose Pikachu!\n");
			nP2TypeOne='e';
			nP2Health=120;
			nMaxHealthP2=120;
			nP2PPSet[0]=10;
			nP2PPSet[1]=7;
			nP2PPSet[2]=5;
			nP2PPSet[3]=5;
			nP2PPMax[0]=10;
			nP2PPMax[1]=7;
			nP2PPMax[2]=5;
			nP2PPMax[3]=5;
			nP2Move1Type='e';
			nP2Move2Type='g';
			break;
		}
		case 5:{
			printf("Player 2 chose Groudon!\n");
			nP2TypeOne='g';
			nP2Health=150;
			nMaxHealthP2=150;
			nP2PPSet[0]=5;
			nP2PPSet[1]=5;
			nP2PPSet[2]=5;
			nP2PPSet[3]=5;
			nP2PPMax[0]=5;
			nP2PPMax[1]=5;
			nP2PPMax[2]=5;
			nP2PPMax[3]=5;
			nP2Move1Type='g';
			nP2Move2Type='f';
			break;
		}
		case 6:{
			printf("Player 2 chose Lapras!\n");
			nP2TypeOne='i';
			nP2TypeTwo='w';
			nP2Health=190;
			nMaxHealthP2=190;
			nP2PPSet[0]=7;
			nP2PPSet[1]=7;
			nP2PPSet[2]=5;
			nP2PPSet[3]=5;
			nP2PPMax[0]=7;
			nP2PPMax[1]=7;
			nP2PPMax[2]=5;
			nP2PPMax[3]=5;
			nP2Move1Type='i';
			nP2Move2Type='w';
			break;
		}
		case 7:{
			printf("Player 2 chose Stunfisk!\n");
			nP2TypeOne='g';
			nP2TypeTwo='e';
			nP2Health=130;
			nMaxHealthP2=130;
			nP2PPSet[0]=10;
			nP2PPSet[1]=5;
			nP2PPSet[2]=5;
			nP2PPSet[3]=5;
			nP2PPMax[0]=10;
			nP2PPMax[1]=5;
			nP2PPMax[2]=5;
			nP2PPMax[3]=5;
			nP2Move1Type='w';
			nP2Move2Type='g';
			break;
		}
		case 8:{
			system("cls");
			main();
			break;
		}
		default:
			printf("Invalid input. Try again!\n");
	}

	//Battle initialization
	Sleep(2500);
	printf("\n\n Prepare to battle!");
	Sleep(1000);
	system("cls");
	
	//Battle Proper
	combat(nP1Pokemon,nP2Pokemon,nP1Health,nP2Health,nP1TypeOne,nP1TypeTwo,nP2TypeOne,nP2TypeTwo,nP1Move1Type,
	nP1Move2Type,nP2Move1Type,nP2Move2Type,nP1PPSet,nP2PPSet,nMaxHealthP1,nMaxHealthP2,nP1PPMax,nP2PPMax,nGameMode);
	
	//repeat game
	Sleep(3500);
	printf("\n\nDo you want to play again? \nEnter 1 for YES and 0 for NO:");
	scanf("%d",&nRepeat);
	if(nRepeat>1 || nRepeat<0)
	{
		do{
			printf("\n Enter 1 for YES and 0 for NO: ");
			scanf("%d",&nRepeat);
		}
		while(nRepeat>1 || nRepeat<0);
	}
	if(nRepeat==1)
	{
		system("cls");
		printf("\n\nRestarting...");
		Sleep(3000);
		system("cls");
		main();
	}	
	else
		return 0;
} //END OF PROGRAM
