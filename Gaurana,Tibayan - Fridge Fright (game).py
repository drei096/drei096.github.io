
#Gaurana,Aldrey and Tibayan,Joshua STEM 11-G

import time
import os
from random import randint

#basic choice error checker
def choices():
    choicePick=6
    while choicePick!='1':
        choicePick=input()
        if choicePick=='1':
            print('Luna: Okay!')
        elif choicePick!='1':
            print('Luna: I do not know that, please choose again!')
            
#error checker in battle UI
def choiceBattle(lunaAction):
    while lunaAction!='Q' and lunaAction!='W' and lunaAction!='E' and lunaAction!='R' and lunaAction!='I':
        lunaAction=str.upper(input('Luna: I do not know that, please choose again! :'))
        if lunaAction=='Q' or lunaAction=='W' or lunaAction=='E' or lunaAction=='R' or lunaAction=='I' :
            print('Luna: Okay!\n')
    return lunaAction

#error checker in items UI
def choiceItems(itemInput):
    while itemInput!='M' and itemInput!='C' and itemInput!='B':
        itemInput=str.upper(input('Luna: I do not know that, please choose again! :'))
        if itemInput=='M' or itemInput=='C' or itemInput=='B':
            print('Luna: Great! Now I feel reenergized!\n')
    return itemInput

            
#main combat system
def combat(LunaHP,LunaCP,LunaEnergy,monsterName,monsterHP,monsterCP,amountMilk,amountCookies):
    print('A monster appeared!')
    print('@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@')
    print(monsterName,'=================')
    print('HP',monsterHP,'======================')
    print('@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n')
    time.sleep(4)
    
    while LunaHP>0 and monsterHP>0:
        print('        BATTLE STATS          ')
        print('==============================')
        print(monsterName,'=========================')
        print('HP',monsterHP,'==================')
        print('==============================')
        
        print('==============================')
        print('Luna =========================')
        print('HP',LunaHP,'==================')
        print('Energy',LunaEnergy,'================')
        print('===============================')
        
        print('\nWhat will Luna do?')
        time.sleep(1)
        print('//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//')
        print('Q - "Pillow Fight!"  Energy:10')
        print('(Hits the enemy with your super pillow), Impact Damage +30\n')
        print('W - "Sugary Shield"  Energy:15')
        print('(Gives you +200 additional in-battle health)\n')
        print('E - "I Still Rule!"  Energy:10')
        print('(Punctures the enemy with your sharp ruler), Puncture Damage +30\n')
        print('R - "Give me my Milk!"  Energy:50')
        print('(Deals massive damage with your pillow and ruler), Impact Damage +30 and\nPuncture Damage +30\n')
        print('I- Items')
        print('//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//')
        #input action
        lunaAction=str.upper(input('\nEnter your action:'))
        lunaAction=choiceBattle(lunaAction)
        #end
        if lunaAction=='Q' and LunaEnergy >= 10:
            damage=LunaCP+30
            #effective and non effective additionals
            if monsterName=='Leftover Pizza':
                damage=damage/2
                print('Your attack is NOT VERY EFFECTIVE')
            elif monsterName=='A Big Block of Cheese':
                damage=damage*2
                print('Your attack is SUPER EFFECTIVE!')
            elif monsterName=='Grape Nation':
                damage=damage*1.5
                print('Your attack is SLIGHTLY EFFECTIVE!')
            #end of additionals    
            monsterHP=monsterHP-damage
            LunaEnergy=LunaEnergy-10
            print('Damage dealt:',damage)
        elif lunaAction=='Q' and LunaEnergy < 10:
            time.sleep(2)
            print('\nYou dont have enough energy!')

        if lunaAction=='W'and LunaEnergy >= 15:
            LunaHP=LunaHP+200
            LunaEnergy=LunaEnergy-15
            print('+200 health!')
        elif lunaAction=='W' and LunaEnergy < 15:
            time.sleep(2)
            print('\nYou dont have enough energy!')

        if lunaAction=='E' and LunaEnergy >= 10:
            damage=LunaCP+30
            if monsterName=='Grape Nation':
                damage=damage*1.5
                print('Your attack is SLIGHTLY EFFECTIVE!')    
            elif monsterName=='Milk Carton - First Form':
                damage=damage*1.5
                print('Your attack is SLIGHTLY EFFECTIVE!')
            monsterHP=monsterHP-damage
            LunaEnergy=LunaEnergy-10
            print('Damage dealt:',damage)
        elif lunaAction=='E' and LunaEnergy < 15:
            time.sleep(2)
            print('\nYou dont have enough energy!')

        if lunaAction=='R' and LunaEnergy >= 50:
            damage=LunaCP+60
            if monsterName=='A Very Long and Huge Sausage':
                damage=damage*2
                print('Your attack is SUPER EFFECTIVE!')
            monsterHP=monsterHP-damage
            LunaEnergy=LunaEnergy-50
            print('Damage dealt:',damage)
        elif lunaAction=='R'and LunaEnergy < 50 :
            time.sleep(2)
            print('\nYou dont have enough energy!')

        elif lunaAction=='I':
            print('/~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~/')
            print('\nItems\n')
            print('(M)Milk (restores health) -',amountMilk)
            print('(C)Cookies (restores full energy) -',amountCookies)
            print('(B)Go Back\n\n')
            itemInput=str.upper(input('What do you want to use? :'))
            itemInput=choiceItems(itemInput)
            print('/~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~/')
            if itemInput=='M' and amountMilk>=1:
                HPAdd=300-LunaHP
                LunaHP=LunaHP+HPAdd
                amountMilk-=1
            elif itemInput=='M' and amountMilk<1:
                print('YOU NEED MORE MILK. YOU RAN OUT!')
                
            
            if itemInput=='C' and amountCookies>=1:
                EnergyAdd=100-LunaEnergy
                LunaEnergy=LunaEnergy+EnergyAdd
                amountCookies-=1
            elif itemInput=='C' and amountCookies<1:
                print('NO MORE COOKIES FROM MOM :(')
                
            if itemInput=='B':
                print('*** Luna took too long searching for her items... ***\n')
            print('Milk Left=',amountMilk)
            print('Cookies Left=',amountCookies)

        if monsterName=='Milk Carton - First Form':
            if monsterHP<=5000:
                monsterName='MILK - FINAL LOW-FAT FORM'
                monsterCP=30
                time.sleep(3)
                print('\n\nMilk:OMAE WA MOU SHINDEIRU!\n')
                time.sleep(3)
                print('Luna: I WANT MY MILK!!!!!!!!!!!')

        if monsterHP>0:
            time.sleep(2)
            print('\nThe monster attacked you!')
            damageMonster=monsterCP+randint(0,9)
            LunaHP=LunaHP-damageMonster
            time.sleep(2)
            print('Damage dealt:',damageMonster,'\n')
            time.sleep(2)   
                
            
    if monsterHP<0:
        print('\nThe monster fainted!')
        time.sleep(2)
        print('You won!\n')
    elif LunaHP<0:
        print('YOU DIED')
        quit()
        
    return LunaHP,LunaCP,LunaEnergy,amountMilk,amountCookies
    

#game initiation
gameStart=6
print('Are you ready to play?')
while gameStart!='1':
    gameStart=input('1 if Yes, 0 if No. \n')
    if gameStart=='1':
        print("Welcome. The game will start shortly.")
    elif gameStart=='0':
        quit()
    else:
        print('Luna: I do not know that, please try again! :)')

#INTRO
#variable initiations for combat
LunaHP=300
LunaCP=500
LunaEnergy=100
monsterName='Chocolate'
monsterHP=3000
monsterCP=10
amountMilk=4
amountCookies=9

time.sleep(3)
print('\nYou are Luna. A 6 year old who likes sugar, spice, and everything nice.\nYour mom just closed the lights and you are about to sleep.')
time.sleep(4)
print('Then Suddenly...\n')
time.sleep(4)
print('''


                                                .,.MNNDD8OOZ$7I?++=======+==+M:,
                                              , .M++++++++++++++++++++++++=N7.  
                                              .,N++++++++++++++++++++++++~M.....
                                           ...D=+++++++++++++++++++++++=M...    
                                           .8O+=+++++++++++++++++++++=M=...     
                                         ,.N~+++++++++++++++++++++++?M......    
                                     ....DZ+++++++++++++++++++++++=M....  .     
                                     ...M=+++++++++++++++++++++++DO,..          
                                     .M$+++++++++++++++++++++++7N.....          
                                   .N$++++++++++++++++++++++++M.... ..          
                          ...  ....N=+++++++++++++++++++++++N7...               
                                ,M7?+++++++++++++++++++++=M8.....               
                             ...N=++++++++++++++++++++++IM..... .               
                     .. .  ...M7++++++++++++++++++++++~M..... .                 
                       . ...+N=+++++++++++++++++++++~M......                    
                     ..  ..N?+++++++++++++++++++++=ZN.......                    
                      ...IN+++++++++++++++++++++++M.........                    
                 .......M?=+++++++++++++++++++++N+. ...........  . ...          
               .. .. .7N++++++++++++++++++++++8MMMMMMMMMMMMMMMMMMMN=..          
               ..  ..N=++++++++++++++++++++++++++++++++++++++===N.   .          
               ....$D=++++++++++++++++++++++++++++++++++++++++N7.    .          
               ..$MMNMMMMMMMNNDD8OOZ$++++++++++++++++++++++=N:...               
                ........  ......:.N7=++++++++++++++++++++$M,.,...               
                ...........  ....N~+++++++++++++++++++++M........               
                          . ...M+=+++++++++++++++++++?M.....                    
                          ....M=+++++++++++++++++++=N:......                    
                          ..M++++++++++++++++++++=M.........                    
                     ... .DZ++++++++++++++++++=IN                               
                     ....N=++++++++++++++++++=N:.                               
                     ..NI++++++++++++++++++=M...                                
                     .M=+++++++++++++++++=M?....                                
                ....M?+++++++++++++++++~N:.                                     
                ..N8+++++++++++++++++ON....                                     
              . :N=++++++=+++++++=+=M. ....                                     
          . ...N++++++++++++++++=IM. ...........                                
          ...=M++++++++++++++++?N...............                                
           .N==++++++++++++++=DDNMMMMMMMMMMMMMMM.                               
      ....MI++++++++++++++++=++++++++++++++~NN...                               
     ....M=+=+++++=++++++++++++++++++++++?MI...                                 
     ..NNNNNMMMMMMMN8++++++++++++++++=8M+... ..                                 
     ............+D+++++++++++++++=DM.......   ..                               
          .. ...8$+++++++++++++++M$...                                          
          .....N=+++++++++=++?MI. ....                                          
          ...IN?+++++++++++8M.........                                          
     .. . . N=+++++++++=NN............                                          
     .....$O++++++++~NN....                                                     
     ....M++++=+==DM?......                                                     
     ..~M++++==DM..... ....                                                     
. ....OO++=+?M$.                                                                
....,M+++?M7....                                                                
...D$?IM+.......                                                                
..N=DM..........                                      

''')
print('*BOOM!*')
time.sleep(3)
print('You wake up to a loud cracking sound.')
time.sleep(3)
print('''
      ___ ___ ___ ___ _____ _   _  _  ___ ___    ___                   
  _ _| __/ __|_ _/ __|_   _/_\ | \| |/ __| __|  / __|__ _ _ __  ___ ___
 | '_| _|\__ \| |\__ \ | |/ _ \| .` | (__| _|  | (_ / _` | '  \/ -_|_-<
 |_| |___|___/___|___/ |_/_/ \_\_|\_|\___|___|  \___\__,_|_|_|_\___/__/
  ___                    _                                             
 | _ \_ _ ___ ______ _ _| |_                                           
 |  _/ '_/ -_|_-< -_) ' \  _|  _ _ _                                   
 |_| |_| \___/__|___|_||_\__| (_|_|_)                                  
                                      
''')
time.sleep(4)
print('''

MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM+~,~,~7NMNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM+~.~,=II777777MMZMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM88OZI?+++++????IZDMMD+~.~.~II777777777$7$MMNNMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMM888888ZII .~IZZ77$ZOZZZ::+~.~.~III77777777777$$$$MMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMM8888888888OO$ +:,,,,::~===,,,+~.~.~IIII7777777777$7D$MMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMM8888888888ODZ II?+======++,,,+~.:.~IIII7777777777$7$$MMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMM88888888888DO.III??+++++++,,,=~.:.~IIIIII7777777777$$MMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMM88888888888DO.II?====~~~==,,,+~.:.~IIIIII7777777777$$MMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMD8888888888DO ??+==~~~~~~~,,,=~.:.~IIIII7I777777777$$MMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMD8888888888DZ II+===~~====,,,=~.:.~IIIIIIII77777777$$MMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMD8888888888DZ.I?+======+I?,,,=:.:.~?IIIIIIII7777777$$MMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMD88888888888Z II+====~+=++,,,=: :.~??IIIIIII7777777$$MMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMD88888888888O.??+8OO$$$I=$,,,=: :.~???IIIIII77777777$MMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMD88888888888O II?88D8OD88O,,,=: :.~???IIIIIIII777777$MMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMD88888888888O.7I?8OO$7,=?$,,,=: :.~???IIIIIIIII77777$MMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMD8888888888DO.888888I8DNNN,,,=: :.~???IIIIIIIIII7777$MMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMD8888888888DO.?:,,,,$ZZZZOOO$=: :.~???IIIIIIIIII7777$MMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMDD8888888888O .....,:::~=+I7$=: :.~??Z7IIIIIIIII7I77$MMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMDD888888888ZOZOO88DDDDNNNNNNNMO78$OMMNMMMMMMMMMMMMOM$MMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMDD888888888IZ7Z$ZZ8ZZZZOOOOOONZ?DI8NMMMMNDOZ? .7,?~,MMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMDDD88888888ZO....,::~=+?I7$ZO~, :.:??OODDNNMMMMMMMMM7MMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMDDD888888888O+???++++++??????~, :.:?????I?IIIIIIIIII7MMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMDD8888888888O???++=========:,~: :.~?????IIIIIIIIIIII7MMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMDDD88888888DO???++======++=,,=: :.~?????IIIIIIIIIIII7MMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMDDDDD888888D8???++++++++++,,,=: :.~?????IIIIIIIIIII77MMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMDDDD8888888DO87+ZO$ZNNZNN?,,,=: :.~??????IIIIIIIIII77MMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMDDDDD888888DO7$7ZOODNNNMMN,,,=: :.~?????IIIIIIIIIII77MMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMDDDD8888888DOOZ7$OON88,~?8,,,=: :.~?????IIIIIIIIII777MMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMDDDD8888888DOZ77I=ZN,~=??$,,,=: :.~??I?IIIIIIIIIII777MMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMDDDDDDD8888DOO8I==ZN=,,:~Z,,,=: :.~????IIIIIIIIIII777MMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMDDDDDD88888DO8Z7OOON=~=:?8,,,=: :.~??IIIIIIIIIIIII777MMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMDDDDDDDD888DO8O777ONNNNNNN,,,=: :.~??IIIIIIIIIIIII777MMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMDDDDDD88888DO$II7ZOO8DZO88,,,=: :.~??IIIIIIIIIIII7777MMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMDDDDDDDDDD8DOO8888MOOO8888,,,=:.:.~??IIIIIIIIII7I7777MMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMDDDDDDDD8D88O8ND8DDOZNDD8D,,,=~.:.=?IIIIIIIIIIII77777MMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMDDDDDDDDDD88OD88DNOO778DND,,,+~.:.=?IIIIIIIIIIII77777MMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMDDDDDDDDDD88OOND8Z$OOOD88O,,,+~.:.=IIIIIIIIIIII777777MMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMDDDDDDDDDD88O8D777II$DD7$$,,,+~.:.=IIIIIIIIIIII777777MMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMDDDDDDDDDDD8OII?+======+++,,,+~.~,=IIIIIIII777777777IMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMDDDDDDDDDDDDOII+==~~~~~===,,,+~.~,=IIIIIIII777777777IMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMDDDDDDDDDDDDO?I+======~~~=,,,+~.~,=IIIIII7I777777777IMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMDDDDDDDDDDDDZ~I+=~~~~~~~~~,,,+~.~,=IIIII77777777777$IMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMDDDDDDDDDDDDZ=I?===~+7?+?I,,,+~.~,=I77777777777777$$IMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMDDDDDDDDDD8DZ$DZ7+?777Z$?+,,,?~.~,+II777777777777$$$IMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMDDNDDDDDDDDDZZZ$7OO7??77ZN,,,?~.~,+I777777777777$$$$IMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMDDDDDDDDDD8D$8O$7ID8O8$$Z$,,,?~,=,+777777777777$$$$$IMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMNNNNNNDDNN8D$8Z77?8?778O$I,,,?=,=,+77777777$$$$$$$$$7MMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMNNNNNNNNNN8D$8ZI7?$ZZ8OZ$Z,,,?=,=,?777777$$$$$$$$$$$7MMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMNNNNNNNNNODI8O$I:~~=+I~77,,,?=,=:?77$7$$$$$$77777777MMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMNNNNNNZ8I?~===~,,,,,::,,,?=,+:?77$$$7777777777777MMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMDNNN$O7=7O888DDNNNNN,,,?=,+:?77777777777777777DMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMD7IZO8DDNNNMD8MMMM:,I+:+~I777777777777INDMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMOI+:?~I7777III7NNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMOI+:?=I777IODOMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMI?~I+7DD7MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
 _______ ______________________  _______ _______    _______ _______________________        __________ 
(  ____ (  ____ )__   __(  __  \(  ____ (  ____ \  (  ____ (  ____ )__   __(  ____ \\     /\__   __( )
| (    \/ (    )|  ) (  | (  \  ) (    \/ (    \/  | (    \/ (    )|  ) (  | (    \/ )   ( |  ) (  | |
| (__   | (____)|  | |  | |   ) | |     | (__      | (__   | (____)|  | |  | |     | (___) |  | |  | |
|  __)  |     __)  | |  | |   | | | ____|  __)     |  __)  |     __)  | |  | | ____|  ___  |  | |  | |
| (     | (\ (     | |  | |   ) | | \_  ) (        | (     | (\ (     | |  | | \_  ) (   ) |  | |  (_)
| )     | ) \ \____) (__| (__/  ) (___) | (____/\  | )     | ) \ \____) (__| (___) | )   ( |  | |   _ 
|/      |/   \__|_______(______/(_______|_______/  |/      |/   \__|_______(_______)/     \|  )_(  (_)
                                                                                                      
''')

time.sleep(4)
print('Luna, still sleepy, rubs her eyes and gets out of bed, startled by the noise.\n')
time.sleep(2)
print('*****[Luna: Ugh, why is it so cold?]*****\n')
time.sleep(2)
print('You begin to walk towards the door while reaching for the handle.')
time.sleep(2)
print('*Enter 1 to open the door*')
choices()
time.sleep(2)
print('You opened the door, and the coldness you felt intensified.\n')
time.sleep(3)
print('*****[Luna: What is this place? Why is it so cold here?]*****\n')
time.sleep(2)
print('You look around and you see your leftover pizza from lunch earlier.')
time.sleep(2)
print('You saw your chocolates, your cookies, your favorite vegetables and fruits.')
time.sleep(2)
print('It was only then, you knew, you are in..')
time.sleep(2)
print('a refrigerator!.\n')
time.sleep(2)
print('As you gaze upon your surroundings, you heard a loud boom from behind.')
time.sleep(4)
print('You looked behind and you see your favorite cocoa bar.\n')
time.sleep(3)
print('*****[Luna: What do I do,what do I do,what do I do?!?!?!]*****')
time.sleep(3)
print('The monster started to run towards you.\n')
time.sleep(3)
print('It was then you remembered that you have your trusty pillow, your reliable steel ruler...')
time.sleep(3)
print('and your favorite cookies and milk that your mom made.\n')
time.sleep(3)
print('*****[Luna: Oh well, I guess it can'"t be avoided.]*****\n")
time.sleep(3)
print('*****[Luna: I have to fight you then. :( ]*****\n\n')
time.sleep(4)



#first battle
combat1=combat(LunaHP,LunaCP,LunaEnergy,monsterName,monsterHP,monsterCP,amountMilk,amountCookies)
print('You completed the tutorial!\n\n')

#after first battle
time.sleep(2)
print('Luna: Is everything alive?')
time.sleep(3)
print('The Creators: YES!')
time.sleep(3)
print('Luna: What?!')
time.sleep(3)
print('The Creators: Nothing. Just keep on walking.')
time.sleep(3)
print('Johnny W. : What?')
time.sleep(3)
print('The Creators: Alright, back to the game.\n\n')
time.sleep(3)
print('As you try to comprehend everything from that... minor setback, you soon notice that there is another...')
time.sleep(3)
print('monster in front of you!')
time.sleep(3)
print('Oozing with cheese, filled with ham and.... oh my god pineapple!')
time.sleep(3)
print('As you hear echoes, though vague, you recognized what it was saying')
time.sleep(3)
print('WHERES THE LAMB SAUCE?')
time.sleep(3)
print('Trying to ignore these sounds, you ready up for the next battle.battle..battle...\n\n')
time.sleep(3)



#pizza battle initiation and exe
LunaHP=combat1[0]
LunaCP=combat1[1]
LunaEnergy=combat1[2]
monsterName='Leftover Pizza'
monsterHP=5000
monsterCP=15
amountMilk=combat1[3]
amountCookies=combat1[4]
combat2=combat(LunaHP,LunaCP,LunaEnergy,monsterName,monsterHP,monsterCP,amountMilk,amountCookies)

time.sleep(3)
print('\nAs the huge pile of dough stumbles on the ground, you noticed it drops an unknown figure. Curious, but unsure...') 
time.sleep(3)

#cheese battle
choicePick=6
print('\nDo you want to inspect the unknown figure?')
print('1 for Yes, 0 for No.')
time.sleep(2)
print('Enter your choice:')
while choicePick!=1 and choicePick!=0:
    choicePick=int(input())
    if choicePick==1:
        LunaHP=combat2[0]
        LunaCP=combat2[1]
        LunaEnergy=combat2[2]
        monsterName='A Big Block of Cheese'
        monsterHP=6000
        monsterCP=20
        amountMilk=combat2[3]
        amountCookies=combat2[4]
        combat3=combat(LunaHP,LunaCP,LunaEnergy,monsterName,monsterHP,monsterCP,amountMilk,amountCookies)
    elif choicePick==0:
        print('You did not inspect the figure.')
        time.sleep(8)
        print('AND THEN THE UNKNOWN FIGURE LEAPED TOWARDS YOU!\n\n')
        time.sleep(3)
        LunaHP=combat2[0]
        LunaCP=combat2[1]
        LunaEnergy=combat2[2]
        monsterName='A Big Block of Cheese'
        monsterHP=6000
        monsterCP=20
        amountMilk=combat2[3]
        amountCookies=combat2[4]
        combat3=combat(LunaHP,LunaCP,LunaEnergy,monsterName,monsterHP,monsterCP,amountMilk,amountCookies)

time.sleep(3)
print('After that CHEESY battle, you continue on your journey for answers.')
time.sleep(3)
print('You noticed a really huge, long... ')
time.sleep(3)
print('Luna: SAAAAUUSAAAAGE.')
time.sleep(3)
print('As Luna ran happily towards the sausage, she noticed that the sausage has a really funny face.')
time.sleep(3)
print('Luna: Sausage?')
time.sleep(3)
print('Luna got scared, and panicked. So she drew out her weapon in fear and prepared for battle.\n')
time.sleep(3)

#sausage battle initiation and exe

LunaHP=combat3[0]
LunaCP=combat3[1]
LunaEnergy=combat3[2]
monsterName='A Very Long and Huge Sausage'
monsterHP=6500
monsterCP=25
amountMilk=combat3[3]
amountCookies=combat3[4]
combat4=combat(LunaHP,LunaCP,LunaEnergy,monsterName,monsterHP,monsterCP,amountMilk,amountCookies)

time.sleep(3)
print('After that traumatic experience, she continues on her journey.')
time.sleep(3)
print('Luna: Ah, I remember where this is!')
time.sleep(3)
print('Luna: This is where mom keeps vegetables!')
time.sleep(3)
print('As she says this, a pack of vegetables that mom bought earlier started to move.')
time.sleep(3)
print('Unaware, Luna gets caught by surprise.')
time.sleep(3)
print('But in the nick of time, notices and evades the surprise attack.')
time.sleep(3)
print('Knowing what to do, she prepares to joust!')
time.sleep(3)
print('Luna: En garde!\n')
time.sleep(3)

#vege-able battle initiation and exe
LunaHP=combat4[0]
LunaCP=combat4[1]
LunaEnergy=combat4[2]
monsterName='Vege-Able'
monsterHP=6000
monsterCP=15
amountMilk=combat4[3]
amountCookies=combat4[4]
combat5=combat(LunaHP,LunaCP,LunaEnergy,monsterName,monsterHP,monsterCP,amountMilk,amountCookies)

time.sleep(3)
print('After the exhuastive battle, she has no time to rest.')
time.sleep(3)
print('After that encounter, here comes the next!')
time.sleep(3)



#grape nation battle initiation and exe
LunaHP=combat5[0]
LunaCP=combat5[1]
LunaEnergy=combat5[2]
monsterName='Grape Nation'
monsterHP=7000
monsterCP=20
amountMilk=combat5[3]
amountCookies=combat5[4]
combat6=combat(LunaHP,LunaCP,LunaEnergy,monsterName,monsterHP,monsterCP,amountMilk,amountCookies)

time.sleep(3)
print('After the barrage of attacks by the Grape Nation, she has little time to rest again.')
time.sleep(3)
print('Still tired from all that, she catches her breath.')
time.sleep(3)
print('And she remembers what she wanted all this time.')
time.sleep(3)
print('She WANTED SOME MILK!')
time.sleep(3)
print('Rushing to where the milk is, she does not expect the impending doom.')
time.sleep(3)
print('Like everything she encountered before, it was alive.')
time.sleep(3)
print('A carton filled with milk, alive.')
time.sleep(3)

#final boss battle initiation and exe
LunaHP=combat6[0]
LunaCP=combat6[1]
LunaEnergy=combat6[2]
monsterName='Milk Carton - First Form'
monsterHP=10000
monsterCP=20
amountMilk=combat6[3]
amountCookies=combat6[4]
combat7=combat(LunaHP,LunaCP,LunaEnergy,monsterName,monsterHP,monsterCP,amountMilk,amountCookies)

time.sleep(3)
print('After all that has happened, she FINALLY GETS HER MILK.')
time.sleep(3)
print('This is what she wanted, a sip of dairy goodness.')
time.sleep(3)
print('Luna: I feel dizzy.....')
time.sleep(5)
print('Luna wakes up.')
time.sleep(3)
print('She checks her window, and its sunny outside.')
time.sleep(3)
print('She goes downstairs and checks the refrigerator.')
time.sleep(3)
print('She instantly checked what is inside and noticed that everything is not moving.')
time.sleep(3)
print('As she closes the refrigerator, she found a milk carton placed right on the table beside her.')
time.sleep(3)
print('Luna: Oh no...')
time.sleep(5)
print('The end?')

time.sleep(4)
print('''
 _______ ______________________  _______ _______    _______ _______________________        __________ 
(  ____ (  ____ )__   __(  __  \(  ____ (  ____ \  (  ____ (  ____ )__   __(  ____ \\     /\__   __( )
| (    \/ (    )|  ) (  | (  \  ) (    \/ (    \/  | (    \/ (    )|  ) (  | (    \/ )   ( |  ) (  | |
| (__   | (____)|  | |  | |   ) | |     | (__      | (__   | (____)|  | |  | |     | (___) |  | |  | |
|  __)  |     __)  | |  | |   | | | ____|  __)     |  __)  |     __)  | |  | | ____|  ___  |  | |  | |
| (     | (\ (     | |  | |   ) | | \_  ) (        | (     | (\ (     | |  | | \_  ) (   ) |  | |  (_)
| )     | ) \ \____) (__| (__/  ) (___) | (____/\  | )     | ) \ \____) (__| (___) | )   ( |  | |   _ 
|/      |/   \__|_______(______/(_______|_______/  |/      |/   \__|_______(_______)/     \|  )_(  (_)
                                                                                                      
''')

quit()

