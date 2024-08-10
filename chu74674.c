/****************************************************************************** 
 
	This is to certify that this project is my own work, based on my personal 
	fforts in studying and applying the concepts learned.  I have constructed  
	the functions and their respective algorithms and corresponding code by  
	myself.  The program was run, tested, and debugged by my own efforts.  I  
	further certify that I have not copied in part or whole or otherwise  
	plagiarized the work of other students and/or persons. 
 
	Alisha Stephanie Chua - 12274674 - S12B 
 
******************************************************************************/ 

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <ctype.h>

/*********************************************************************
	Description: This function scans and validates number of games
	@param: int numG
	@return: numgames if it is even and within 2-10 range
**********************************************************************/

int validNumberofGames(int numG)
{
	do
	{
		printf("\n\n\n\n\n                   > ENTER EVEN NUMBER OF GAMES (2-10):");
		scanf("%d", &numG);
		
		if (numG<2||numG>10 || numG%2!=0)
			printf("                           Invalid Input!");
			

	}while (numG<2||numG>10 || numG%2!=0);
		printf("\n\n                      --------------------------------\n");
		printf("                           STARTING GAME OF %d......",numG);
		printf("\n                      --------------------------------\n\n\n");
	return numG;
}

/*************************************************************************
	Description: This function checks if first peg is in correct position
	or part of the sequence
	@param: char guessA, char a, char b, char c, char d
	@return: pegA; B is correct position and peg; W if correct peg;
				'\0' is peg not part of code
*************************************************************************/

char codeValidationA(char guessA, char a, char b,char c, char d)
{
	char pegA;
	
	if (guessA==a)
		pegA='B';
	
	else if (guessA==b || guessA==c || guessA==d )
		pegA='W';
		
	else 
		pegA='\0';
	
	return pegA;
		
}

/*************************************************************************
	Description: This function checks if second peg is in correct position
	or part of the sequence
	@param: char guessB, char a, char b, char c, char d
	@return: pegB; B is correct position and peg; W if correct peg;
				'\0' is peg not part of code
**************************************************************************/

char codeValidationB(char guessB, char a, char b,char c, char d)
{
	char pegB;
	
	if (guessB==b)
		pegB='B';
	
	else if (guessB==a || guessB==c || guessB==d )
		pegB='W';
		
	else 
		pegB='\0';
		
	return pegB;
}

/*************************************************************************
	Description: This function checks if third peg is in correct position
	or part of the sequence
	@param: char guessC, char a, char b, char c, char d
	@return: pegC; B is correct position and peg; W if correct peg;
				'\0' is peg not part of code
*************************************************************************/

char codeValidationC(char guessC, char a, char b,char c, char d)
{
	char pegC;
	
	if (guessC==c)
		pegC='B';
	
	else if (guessC==a || guessC==b || guessC==d )
		pegC='W';
		
	else 
		pegC='\0';
		
	return pegC;
}

/*************************************************************************
	Description: This function checks if fourth peg is in correct position
	or part of the sequence
	@param: char guessD, char a, char b, char c, char d
	@return: pegD; B is correct position and peg; W if correct peg;
				'\0' is peg not part of code
*************************************************************************/

char codeValidationD(char guessD, char a, char b,char c, char d)
{
	char pegD;
	
	if (guessD==d)
		pegD='B';
	
	else if (guessD==a || guessD==b || guessD==c )
		pegD='W';
		
	else 
		pegD='\0';
		
	return pegD;
}


int main()
{
	int numgames;
	numgames=0;
	
	//INTRO SCREEN AND GAME PRELIMINARIES OF THE GAME

	printf("                                                 \n\n\n");
	printf("                                                 ----------------\n");
	printf("                                                 |  WELCOME TO  |\n");
	printf("                                                 |  MASTERMIND! |  \n");
	printf("                                                 ----------------  \n\n\n");
	
	printf ("\nGAME PLENIMINARIES: \n");
	printf ("Two players agree to an EVEN number of games from 2-10 (Max).\nThe role of codemaker and codebreaker is switched between the players.\nA pattern of FOUR code pegs is selected by the codemaker with no repetition of pegs.\n");
	printf ("\nPEGS AVAILABLE: A B C D E F \n");
	
	printf ("  -WHITE (W) key pegs mean that the peg is part of the code but misplaced.\n");
	printf("  -BLACK (B) key pegs mean that the peg is accurate in position and color.\n");
	
	printf("\nOnce feedback is provided, another guess is made; guesses and feedback continue to alternate\nuntil either the codebreaker guesses correctly, or all attempts have been used.\n");
	printf ("\n-----------------------------------------------------------------------------------------------------------------------\n");

	printf ("\n                                             > PRESS ANY KEY TO START...\n");
	
	getch();
	system("cls");

	numgames=validNumberofGames(numgames);

	system("cls");
	
	int i;
	int attempts;                  //attempts for codebreaker part 
	int attempts1;                 //attempts for codemaker part
	
	int a=0;
	int b=0;
	int *pointsHuman=&a;          //accumulated points for human player
	int *pointsAI=&b;             //accumulated points for AI player


	for(i=2; i<=numgames; i+=2){	//LOOPING OF THE GAME
	char a,b,c,d;
	
	//RANDOMIZATION OF CODE: Pseudo-AI Code Maker (PEGS: A B C D E F )
	int upper= 70;
	int lower= 65;
	
	srand(time(NULL));
	
	do
	{
		a= rand()% (upper - lower + 1) + lower;
		b= rand()% (upper - lower + 1) + lower;
		c= rand()% (upper - lower + 1) + lower;
		d= rand()% (upper - lower + 1) + lower;
		
	}while(a==b||a==c||a==d||b==c||b==d||c==d);

	//CODEBREAKER GAMEPLAY
	char guessA, guessB, guessC, guessD;
	
	printf("YOUR TURN\n");
	printf("(Use A B C D E F for the pegs)\n");
	printf("Enter a FOUR peg code to guess\n");
	printf("---------------------------------------------\n");
	
	

	char pegA,pegB,pegC,pegD;
	attempts=1;
	
		do
		{
			printf("\nAttempt %d (use spaces in between):", attempts); 

			scanf(" %c %c %c %c", &guessA, &guessB, &guessC, &guessD);
			printf("Checking pegs........... done!\n");
			
			attempts++;     // counts number of attempts
			*pointsAI+=1;  //keeps track of AI's score
			
			guessA=toupper(guessA);  //accepts lowercase letters and reads it as uppercase for first input
			guessB=toupper(guessB);  //accepts lowercase letters and reads it as uppercase for second input
			guessC=toupper(guessC);  //accepts lowercase letters and reads it as uppercase for third input
			guessD=toupper(guessD);  //accepts lowercase letters and reads it as uppercase for fourth input

		
			pegA=codeValidationA(guessA,a,b,c,d);
			pegB=codeValidationB(guessB,a,b,c,d);
			pegC=codeValidationC(guessC,a,b,c,d);
			pegD=codeValidationD(guessD,a,b,c,d);
		
			printf ("Here are the results: %c %c %c %c", pegA, pegB, pegC, pegD);
			printf ("\n"); 
		
			
		}while ( attempts<=10 && (a!=guessA || b!=guessB || c!=guessC || d!=guessD));

		
		if (a==guessA && b==guessB && c==guessC && d==guessD)
		{
		printf ("\n-------------------------------------------------------");
		printf("\n         Congratulations! You got the code! ");
		printf ("\n-------------------------------------------------------\n");		
		}
		else
		{
		printf ("\n-------------------------------------------------------");
		printf ("\n  SORRY, YOU ARE OUT OF TRIES. BETTER LUCK NEXT TIME!");
		printf ("\n-------------------------------------------------------\n");
		}	
		
		printf ("\nPRESS ANY KEY TO PROCEED TO CONTINUE...."); //NEXT ROUND INDICATION


		
	getch();
	system("cls");
	
	//CODEMAKER GAMEPLAY
	char a1,b1,c1,d1;
	
	do
	{
		printf("You are now the CODEMAKER:\n");
		printf("> Use A B C D E F for the pegs\n");
		printf("> NO repetition of letters\n");
		printf("> Use spaces in between\n");
		printf("> Use CAPITAL LETTERS\n");
		printf("\nEnter FOUR Peg Code:");
		
		scanf(" %c %c %c %c", &a1, &b1, &c1, &d1);

	}while( (a1==b1||a1==c1||a1==d1||b1==c1||b1==d1||c1==d1) || ((a1!='A') && (a1!='B') && (a1!='C')&& (a1!='D') && (a1!='E') && (a1!='F')) || ((b1!='A')&& (b1!='B') && (b1!='C') && (b1!='D') && (b1!='E') && (b1!='F')) || ((c1!='A')&& (c1!='B')&& (c1!='C') && (c1!='D')&& (c1!='E') &&(c1!='F')) || ((d1!='A') && (d1!='B') && (d1!='C')&& (d1!='D') && (d1!='E')&& (d1!='F')));


	char guessA1, guessB1, guessC1, guessD1;
	
	printf("\nAI's turn\n");
	printf("(Use A B C D E F for the pegs)\n");
	printf("---------------------------------------------\n");
	
	

	char pegA1,pegB1,pegC1,pegD1;
	attempts1=1;
	srand(time(NULL));

	
		do
		{	
			printf("\nAttempt %d (use spaces in between):", attempts1); 

			do{
			int upper= 70;
			int lower= 65;
	
			//RANDOMIZATION OF CODE: Pseudo-AI Code Guesser (PEGS: A B C D E F )
			guessA1= rand()% (upper - lower + 1) + lower;
			guessB1= rand()% (upper - lower + 1) + lower;
			guessC1= rand()% (upper - lower + 1) + lower;
			guessD1= rand()% (upper - lower + 1) + lower;
			}
			while(guessA1==guessB1||guessA1==guessC1||guessA1==guessD1||guessB1==guessC1||guessB1==guessD1||guessC1==guessD1);
			printf(" %c %c %c %c", guessA1, guessB1, guessC1, guessD1);
			printf("\n");
			printf("Checking pegs........... done!\n");
			
			attempts1++;         //counts number of attempets
			*pointsHuman+=1;    //keeps track of player's score
			

			pegA1=codeValidationA(guessA1,a1,b1,c1,d1);
			pegB1=codeValidationB(guessB1,a1,b1,c1,d1);
			pegC1=codeValidationC(guessC1,a1,b1,c1,d1);
			pegD1=codeValidationD(guessD1,a1,b1,c1,d1);
		
			printf ("Here are the results: %c %c %c %c", pegA1, pegB1, pegC1, pegD1);
			printf ("\n"); 
			

		}while ( attempts1<=10 && (a1!=guessA1 || b1!=guessB1 || c1!=guessC1 || d1!=guessD1));

		
		if (a1==guessA1 && b1==guessB1 && c1==guessC1 && d1==guessD1)
		{
		printf ("\n-------------------------------------------------------");
		printf("\n         Congratulations! You got the code! ");
		printf ("\n-------------------------------------------------------\n");		
		}
		else
		{
		printf ("\n-------------------------------------------------------");
		printf ("\n  SORRY, YOU ARE OUT OF TRIES. BETTER LUCK NEXT TIME!");
		printf ("\n-------------------------------------------------------\n");
		}	

		printf ("\nPRESS ANY KEY TO PROCEED TO CONTINUE...."); //NEXT ROUND INDICATION


	getch();
	system("cls");
		
}

	//FOR POINTING SYSTEM CONDITIONS
	if (*pointsHuman%10==0)
		*pointsHuman= *pointsHuman+(*pointsHuman/10);
		
	if (*pointsAI==10)
		*pointsAI= *pointsAI+(*pointsAI/10);

	//SCOREBOARD
	printf("                                                                          \n\n\n");
	printf("                                                 ----------------             \n");
	printf("                                                 |    SCORE     |             \n");
	printf("                                                 |    BOARD     |             \n");
	printf("                                                 ----------------         \n\n\n");
	
	printf("                                                 YOUR POINTS: %d\n", *pointsHuman);
	printf("                                                 AI's POINTS: %d\n", *pointsAI);


	getch();
	system("cls");
	
	//ENDING SCREEN OF THE GAME	
	if (pointsHuman>pointsAI) //Ending Screen (Player Win)
	{
	
	printf("                                                                             \n\n\n");
	printf("                                               ---------------------------       \n");
	printf("                                               |       THANKS FOR        |       \n");
	printf("                                               |        PLAYING!         |       \n");
	printf("                                               |                         |       \n");
	printf("                                               |        -YOU WON-        |       \n");
	printf("                                               ---------------------------   \n\n\n");
	printf("                                               game created by Alisha Chua   \n\n\n");
	printf("                                                                             \n\n\n");
	}
	
	else{ //Ending Screen (AI Win)
	printf("                                                                             \n\n\n");
	printf("                                               ---------------------------       \n");
	printf("                                               |       THANKS FOR        |       \n");
	printf("                                               |        PLAYING!         |       \n");
	printf("                                               |                         |       \n");
	printf("                                               |       -YOU LOSE-        |       \n");
	printf("                                               ---------------------------   \n\n\n");
	printf("                                               game created by Alisha Chua   \n\n\n");
	printf("                                                                             \n\n\n");
	}

	return 0;
	
}

