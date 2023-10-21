#include "STD_TYPES.h"
#include "built_Functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
sint8 mode ;
static uint8 Array[dimension][dimension]={Zero};/*This Array is the board */

static uint8 Player='X';/*The player name global as it changes over the replacements*/
static uint8 Situation;/*A var tells us the situation on the Board winning or Draw*/

void Reset_Game ()/*This made to reset this variable to the default turn so no conflicts in turns happens if the game to start again*/
{
	Player='X';/*Reseting the player to its original turn X*/
}
	


/*This Function is used to intialise a 2D Array Using D.M.A to make the Board and return a pointer to that Array*/

void Intial(void )
{
	uint8 Intializer=0u;/*This a variable that we use to assign the elemnts of the array i made its value from 1 to 3*3 */
	
	/*This loop is made to assign every element of the array*/
	for (int i=Zero ; i< dimension ; i++)
	{
		for(int j=Zero ; j < dimension ; j++)
		{
			Intializer++;/*Incrementing it by 1 to assign the relative index in the array*/
			Array[i][j]=Intializer;/*Intializer its value is between 1 and 3*3*/
			
		}
	}
	
}

/*Tis function is made to print the Board at first then Updated after every player's its parameter a ptr to ptr to int to print a 2D array*/

void Printing_Elements (void)
{
	system("cls");/*This Line is made to clear the screen at every update*/
	printf("\n\n");
	printf("\t\t\t\t\t\033[34m  The Game Table\n\033[0m");
	printf("\t\t\t\t\033[34m_________________________________\n\033[0m");
	printf("\t\t\t\t\033[34m_________________________________\n\033[0m");
	printf("\n");
	
	for (int i=Zero ; i < dimension ; i++)/*for loop to traverse in each row*/
	{
		printf("\t\t\t\t");
		for (int j=Zero ; j < dimension ; j++)/*for loop to traverse in each col*/
		{
			if (Array[i][j] == 'X')/*Considering X is a special Case to print I Assigned player at first with Ascii Value then assigning it to a %d , this makes it S.C*/
			{
				// Print 'X' in red color
				printf("\t\033[31m%c\033[0m", Array[i][j]);                  /*printing it as a letter not the Ascii of it like a number*/
				
				/*Here I print X such X is not a value when any index is occupied with x I no longer print this element as number but char X so i use %c to print*/
			}
			else if ( Array[i][j] == 'O' )/*Considering O is a special Case to print I Assigned player at first with Ascii Value then assigning it to a %d , this makes it S.C*/
			{
				// Print 'O' in green color
				printf("\t\033[32m%c\033[0m", Array[i][j]);/*printing it as a letter not the Ascii of it like a number*/
				/*Here I print O such O is not a value when any index is occupied with O I no longer print this element as number but char O so i use %c to print*/
			}
			else
			{
				// Print numbers in yellow color
			    printf("\t\033[33m%d\033[0m", Array[i][j]);/*printing numbers normally with %d if it is not a char like X or O*/
			}
			if (j != 2)
			{
			    printf("\033[36m   |\033[0m");
			}
		}
		printf("\n");/*this is made to make it readable for the user , So i made a newline between each row*/
		if (i != 2)
		{
			printf("\033[36m\t\t\t\t\t_________________\033[0m");
		    printf("\n");
		}
		
	}
	printf("\t\t\t\t\033[34m_________________________________\n\033[0m");
	printf("\t\t\t\t\033[34m_________________________________\n\033[0m");
	printf("\n");
}

/*This function is made to check the situation after every turn for every player , checking Draw or who Win , returning an indicator for this situation*/
uint8 Checking_Situation(void)
{
    uint8 Xc = 0u;/*This a counter made to count Xs on the BOARD*/
    uint8 Oc = 0u;/*This a counter made to count Os on the BOARD*/
    uint8 Win = 'D';/*This an Indicator to check if there is winning or draw*/

    /* Checking the Board vertically */
    for (int i = Zero; i < dimension; i++)/*This is made to iterate every row*/
    {
        for (int j = Zero; j < dimension; j++)/*This is made to iterate every col*/
        {
            if (Array[i][j] == 'X')/*Checking if the element on the Board equals X*/
            {
                Xc++;/*if true we Increment X counter with 1*/
            }
            else if (Array[i][j] == 'O')/*Checking if the element on the Board equals O*/
            {
                Oc++;/*if true we Increment O counter with 1*/
            }
        }
        if (Xc == dimension)/*if We really found a #number of X in a row on the Board then it is winning for X */
        {
            Win = 'X';/*Assigning the situation indicator for x as a sign of X won the game*/
            return Win;/*Returning this ending this function */
        }
        else if (Oc == dimension)/*if We really foun a #number of O in a row on the Board then it is winning for O */
        {
            Win = 'O';/*Assigning the situation indicator for o as a sign of O won the game*/
            return Win;/*Returning this ending this function */
        }
		/*This Assignment is made to begin from zero in the next row so we need counters to be zeros before entering a new Row*/
		Xc = 0u;
        Oc = 0u;
    }
	

    /* Checking the Board Horizontally */
    for (int i = Zero; i < dimension; i++)/*This is made to iterate every col*/
    {
        for (int j = Zero; j < dimension; j++)/*This is made to iterate every row*/
        {
            if (Array[j][i] == 'X')/*This arrangement of j before i makes us checking the cols and here we Checking if the element on the Board equals X */
            {
                Xc++;/*if true we Increment X counter with 1*/
            }
            else if (Array[j][i] == 'O')/*Checking if the element on the Board equals O*/
            {
                Oc++;/*if true we Increment O counter with 1*/
            }
        }
        if (Xc == dimension)/*if We really foun a #number of X in a Col on the Board then it is winning for X */
        {
            Win = 'X';/*Assigning the situation indicator for x as a sign of X won the game*/
            return Win;/*Returning this ending this function */
        }
        else if (Oc == dimension)/*if We really foun a #number of O in a col on the Board then it is winning for O */
        {
            Win = 'O';/*Assigning the situation indicator for o as a sign of O won the game*/
            return Win;/*Returning this ending this function */
        }
		/*This Assignment is made to begin from zero in the next col so we need counters to be zeros before entering a new col*/
        Xc = 0u;
        Oc = 0u;
    }
    /* Checking on First diagonal */
    for (int i = Zero; i < dimension; i++)/*This is made to iterate every row*/
    {
        if (Array[i][i] == 'X')/*This cod is made to check every element on the diagonal if equal X */
        {
            Xc++;/*if true we Increment X counter with 1*/
        }
        else if (Array[i][i] == 'O')/*This cod is made to check every element on the diagonal if equal O */
        {
            Oc++;/*if true we Increment O counter with 1*/
        }

        if (Xc == dimension)/*if We really foun a #number of X in a Col on the Board then it is winning for X */
        {
            Win = 'X';/*Assigning the situation indicator for x as a sign of X won the game*/
            return Win;/*Returning this ending this function */
        }
        else if (Oc == dimension)/*if We really foun a #number of O in a col on the Board then it is winning for O */
        {
            Win = 'O';/*Assigning the situation indicator for o as a sign of O won the game*/
            return Win;/*Returning this ending this function */
        }
		
    }
	/*These assignments is made to clear counters to check the next state from Zero cause may accidently there are x and o on the diagonals but won't equal Zero*/
	Xc = 0u;
    Oc = 0u;
   
    /* Checking on Second diagonal */
    int j = dimension;/*this is a var helps us indexing the second diameter*/
    for (int i = Zero; i < dimension; i++)/*This is made to iterate every row*/
    {
        if (Array[i][j - 1] == 'X')/*This cod is made to check every element on the diagonal if equal X */
        {
            Xc++;/*if true we Increment X counter with 1*/
        }
        else if (Array[i][j - 1] == 'O')/*This cod is made to check every element on the diagonal if equal O */
        {
            Oc++;/*if true we Increment O counter with 1*/
        }

        if (Xc == dimension)/*if We really foun a #number of X in a Col on the Board then it is winning for X */
        {
            Win = 'X';/*Assigning the situation indicator for x as a sign of X won the game*/
            return Win;/*Returning this ending this function */
        }
        else if (Oc == dimension)/*if We really foun a #number of O in a col on the Board then it is winning for O */
        {
            Win = 'O';/*Assigning the situation indicator for o as a sign of O won the game*/
            return Win;/*Returning this ending this function */
        }
        j--;/*this decrement is made to reach the next element on the diameter changing it to get the element in the col before*/
    }

    return Win;/*If no case from the above happened Draw has occured*/
}

/*This Function is used to Replace the position enterd by the player eith his Symbol X or O*/
void Replacing_Elements (void)
{
	Situation = Checking_Situation ();/*Before Doing any thing we check that the situation is draw before antering any symol if not we begin to Insert symbols */
	
	for ( int i=Zero ; (i < dimension*dimension) && (Situation !='X' ) && (Situation != 'O')  ; i++)/*for loop to insert X or O after checking that noone has won and there are replacements still available to make using cond i < d*d */
	{
	    uint8 position;/*the position the user choose to insert at*/
		
		uint8 Indicator = 0u;/*This is an Indiacator to check if the position entered by user is avaliable on the BOARD and not occupied or not*/
		
	    printf("Choose a position player %c :",Player);/*Asking the Players to Enter the position they want*/
		
	    while(1)/*A simple loop made to recieve the position and ends when it is valid and available on the Board*/
		{      
	        if(scanf(" %d",&position) )/*the cond comes true if the user enters a number not a char or sth else*/
			{
				/*The loop Coming is used to check the availablity of position on the Board */
				for (int i=Zero ; i < dimension ; i++)/*This loop is made to Iterate in every row*/
	            {
	            	for (int j=Zero ; j < dimension ; j++)/*This loop is made to Iterate in every col*/
	            	{
	            		if (Array[i][j]==position && Array[i][j] !='X' && Array[i][j] !='O' )/*checking the availablity of position on the Board or it is already occupied*/
	            		{
	            			Array[i][j]=Player;/*If true Assign the position wiht player Symbol*/
							Indicator = 1;/*If the cond is true Assign the Indicatoe wiht 1 as a reference for the position is existing*/
	            		}
	            	}
	            }
				if (Indicator == 1u)/*If the positon was available to insert in*/
				{
					break;/*Break the loop*/
				}
				else/*This is made to handle if the position was occupied or not in the array*/
			    {
			    	while(getchar()!='\n');/*Clear buffer input*/
			    	printf("Position Entered is not available Enter a valid position player %c please :" , Player);
			    }
			}
			else/*This is made to handle if the user enters anything else but not numbers*/
			{
				while(getchar()!='\n');/*Clear buffer input*/
				printf("Input Entered is not valid Enter a valid position player %c please :",Player);
			}
		}
	    
		/*followoing if is used to change the turn from X to O and vice versa*/
	    if (Player=='X')
	    {
	    	Player = 'O';
	    }
	    else
	    {
	    	Player='X';
	    }
		Situation = Checking_Situation ();/*Recheck the situation on the board again to know if the game ended and there is a winner or not*/
		Printing_Elements ();/*This Function is used to update the Board after every turn*/
	}
}

sint8 checkForWinningOpportunity()/*This function is made to handle if there is a crirical square will make the Computer win*/
{
	sint8 Ok = Zero;
	sint32 Xc = Zero;
    sint32 Oc = Zero;
	/*checking if there is a chance to win at first*/
	/* Checking the Board Horizintally */
    for (int i = Zero; i < dimension; i++)/*This is made to iterate every row*/
    {
        for (int j = Zero; j < dimension; j++)/*This is made to iterate every col*/
        {
            if (Array[i][j] == 'X')/*Checking if the element on the Board equals X*/
            {
                Xc++;/*if true we Increment X counter with 1*/
            }
            else if (Array[i][j] == 'O')/*Checking if the element on the Board equals O*/
            {
                Oc++;/*if true we Increment O counter with 1*/
            }
        }
        if (Oc == 2 && Xc == Zero )/*Attacking tactic*/
        {
            for (int j = Zero; j < dimension; j++) 
			{
                if (Array[i][j] != 'O') 
				{
                    Array[i][j]='O';
                    return Ok = 1;
                }
			}
        }
		/*This Assignment is made to begin from zero in the next row so we need counters to be zeros before entering a new Row*/
		Xc = Zero;
        Oc = Zero;
	}
	/* Checking the Board vertically */
    for (int i = Zero; i < dimension; i++)/*This is made to iterate every row*/
    {
        for (int j = Zero; j < dimension; j++)/*This is made to iterate every col*/
        {
            if (Array[j][i] == 'X')/*Checking if the element on the Board equals X*/
            {
                Xc++;/*if true we Increment X counter with 1*/
            }
            else if (Array[j][i] == 'O')/*Checking if the element on the Board equals O*/
            {
                Oc++;/*if true we Increment O counter with 1*/
            }
        }
        if (Oc == 2 && Xc == Zero )/*Attacking tactic*/
        {
           for (int j = Zero; j < dimension; j++) 
		    {
                if (Array[j][i] != 'O') 
		    	{
                    Array[j][i]='O';
                    return Ok = 1;
                }
		    }
        }
		/*This Assignment is made to begin from zero in the next row so we need counters to be zeros before entering a new Row*/
		Xc = Zero;
        Oc = Zero;
    }
	/*checking in first diameter*/
	for (int i = Zero; i < dimension; i++)/*This is made to iterate every row*/
    {
        if (Array[i][i] == 'X')/*This cod is made to check every element on the diagonal if equal X */
        {
            Xc++;/*if true we Increment X counter with 1*/
        }
        else if (Array[i][i] == 'O')/*This cod is made to check every element on the diagonal if equal O */
        {
            Oc++;/*if true we Increment O counter with 1*/
        }
	
        if (Oc == 2 && Xc == Zero )/*Attacking tactic*/
        {
           
            if (Array[i][i] != 'O') 
		    {
                Array[i][i]='O';
                return Ok = 1;
            }
		    
        }
    }

	/*These assignments is made to clear counters to check the next state from Zero cause may accidently there are x and o on the diagonals but won't equal Zero*/
	Xc = 0u;
    Oc = 0u;
	
	/*checking in second diameter*/
	/*checking in the secondary diagonal*/
    int j = dimension;
    for (int i = Zero; i < dimension; i++) 
	{
        if (Array[i][j - 1] == 'X') 
		{
            Xc++;
        } else if (Array[i][j - 1] == 'O') 
		{
            Oc++;
        }
        j--;
    }
    
    if (Oc == 2 && Xc == Zero) 
	{
        j = dimension;
        for (int i = Zero; i < dimension; i++) 
		{
            if (Array[i][j - 1] != 'O') 
			{
                Array[i][j - 1] = 'O';
                return Ok = 1;
            }
            j--;
        }
    }

	return Ok ;
}

sint8 blockingposition()/*This function is made to handle if there is a crirical square will make the user win*/
{
	int Ok=Zero;
	sint32 Xc = Zero;
    sint32 Oc = Zero;
	/*checking if there is a chance to win at first*/
	/* Checking the Board Horizintally */
    for (int i = Zero; i < dimension; i++)/*This is made to iterate every row*/
    {
        for (int j = Zero; j < dimension; j++)/*This is made to iterate every col*/
        {
            if (Array[i][j] == 'X')/*Checking if the element on the Board equals X*/
            {
                Xc++;/*if true we Increment X counter with 1*/
            }
            else if (Array[i][j] == 'O')/*Checking if the element on the Board equals O*/
            {
                Oc++;/*if true we Increment O counter with 1*/
            }
        }
        if (Xc == 2 && Oc == Zero )/*Defending tactic*/
        {
            for (int j = Zero; j < dimension; j++) 
			{
                if (Array[i][j] != 'X') 
				{
                    Array[i][j]='O';
					return Ok = 1;
                }
			}
        }
		/*This Assignment is made to begin from zero in the next row so we need counters to be zeros before entering a new Row*/
		Xc = Zero;
        Oc = Zero;
	}
	/* Checking the Board vertically */
    for (int i = Zero; i < dimension; i++)/*This is made to iterate every row*/
    {
        for (int j = Zero; j < dimension; j++)/*This is made to iterate every col*/
        {
            if (Array[j][i] == 'X')/*Checking if the element on the Board equals X*/
            {
                Xc++;/*if true we Increment X counter with 1*/
            }
            else if (Array[j][i] == 'O')/*Checking if the element on the Board equals O*/
            {
                Oc++;/*if true we Increment O counter with 1*/
            }
        }
        if (Xc == 2 && Oc == Zero )/*Blocking tactic*/
        {
           for (int j = Zero; j < dimension; j++) 
		    {
                if (Array[j][i] != 'X') 
		    	{
					Array[j][i]='O';
                    return Ok = 1;
                }
		    }
        }
		/*This Assignment is made to begin from zero in the next row so we need counters to be zeros before entering a new Row*/
		Xc = Zero;
        Oc = Zero;
    }
	/*checking in first diameter*/
	/*checking in first diameter*/
	for (int i = Zero; i < dimension; i++)/*This is made to iterate every row*/
    {
        if (Array[i][i] == 'X')/*This cod is made to check every element on the diagonal if equal X */
        {
            Xc++;/*if true we Increment X counter with 1*/
        }
        else if (Array[i][i] == 'O')/*This cod is made to check every element on the diagonal if equal O */
        {
            Oc++;/*if true we Increment O counter with 1*/
        }
	
        if (Xc == 2 && Oc == Zero )/*Attacking tactic*/
        {
           
            if (Array[i][i] != 'X') 
		    {
                Array[i][i]='O';
                return Ok = 1;
            }
		    
        }
    }

	/*These assignments is made to clear counters to check the next state from Zero cause may accidently there are x and o on the diagonals but won't equal Zero*/
	Xc = 0u;
    Oc = 0u;
	
	/*checking in second diameter*/
	// Checking in the second diagonal
    /*checking in second diameter*/
// Checking in the second diagonal
    int j = dimension;
    for (int i = Zero; i < dimension; i++) 
	{
        if (Array[i][j - 1] == 'X') 
		{
            Xc++;
        } 
        else if (Array[i][j - 1] == 'O') 
		{
            Oc++;
        }
        j--;
    }
    
    if (Xc == 2 && Oc == Zero)
	{
        j = dimension;
        for (int i = Zero; i < dimension; i++) 
		{
            if (Array[i][j - 1] != 'X')
			{
                Array[i][j - 1] = 'O';
                return Ok = 1;
				
            }
            j--;
        }
    }

	return Ok;
}

void randommove()/*This func is made to make any random mox=ve id there is no winning or losing is coming in the next step*/
{
	if (!checkForWinningOpportunity() && !blockingposition() )
	{
	    for (int i=Zero ; i < dimension ; i++)/*This loop is made to Iterate in every row*/
	    {
	    	int done = Zero;
	    	for (int j=Zero ; j < dimension ; j++)/*This loop is made to Iterate in every col*/
	    	{
	    		if (Array[i][j]!='X' && Array[i][j]!='O'  )/*checking the availablity of position on the Board or it is already occupied*/
	    		{
	    			Array[i][j]='O';/*If true Assign the position wiht player Symbol*/
	    			done = 1;
	    			break;
	    		}
	    	}
	    	if (done ==1)
	    	{
	    		break;
	    	}
	    }
	}
	
	
}
void Computer_Mode()
{
	Situation = Checking_Situation ();
	
	for ( int i=Zero ; (i < 5) && (Situation !='X' ) && (Situation != 'O')  ; i++)/*for loop to insert X or O after checking that noone has won and there are replacements still available to make using cond i < d*d */
	{
	    uint8 position;/*the position the user choose to insert at*/
			
	    printf("Choose a position player %c :",Player);/*Asking the Players to Enter the position they want*/
		
	    while(1)/*A simple loop made to recieve the position and ends when it is valid and available on the Board*/
		{     
            uint8 Indicator = 0u;/*This is an Indiacator to check if the position entered by user is avaliable on the BOARD and not occupied or not*/		
	        if(scanf(" %d",&position) )/*the cond comes true if the user enters a number not a char or sth else*/
			{
				/*The loop Coming is used to check the availablity of position on the Board */
				for (int i=Zero ; i < dimension ; i++)/*This loop is made to Iterate in every row*/
	            {
	            	for (int j=Zero ; j < dimension ; j++)/*This loop is made to Iterate in every col*/
	            	{
	            		if (Array[i][j]==position && Array[i][j] !='X' && Array[i][j] !='O' )/*checking the availablity of position on the Board or it is already occupied*/
	            		{
	            			Array[i][j]='X';/*If true Assign the position wiht player Symbol*/
							Indicator = 1;/*If the cond is true Assign the Indicatoe wiht 1 as a reference for the position is existing*/
	            		}
	            	}
	            }
				if (Indicator == 1u)/*If the positon was available to insert in*/
				{
					break;/*Break the loop*/
				}
				else/*This is made to handle if the position was occupied or not in the array*/
			    {
			    	while(getchar()!='\n');/*Clear buffer input*/
			    	printf("Position Entered is not available Enter a valid position player %c please :" , Player);
			    }
			}
			else/*This is made to handle if the user enters anything else but not numbers*/
			{
				while(getchar()!='\n');/*Clear buffer input*/
				printf("Input Entered is not valid Enter a valid position player %c please :",Player);
			}
		}
		Situation = Checking_Situation ();
		if ( (Situation !='X' ) && (Situation != 'O') && checkForWinningOpportunity())
		{
			Situation = Checking_Situation ();
		}
		else if( (Situation !='X' ) && (Situation != 'O') && blockingposition() )
		{
			Situation = Checking_Situation ();
		}
		else 
		{
			if ((Situation !='X' ) && (Situation != 'O') )
			{
			    randommove();
				Situation = Checking_Situation ();
			}
		}
		Printing_Elements ();
		
	}	
}
/*This Function is used to Display result */

void Displaying_Results(void)
{
	if (mode == 1)
	{
	    if (Situation == 'X')
	    {
			printf("\t\t\t\t\033[31mConglaulations Player X is the Winner\n\n\033[0m");
	    }
	    else if (Situation == 'O')
	    {
			printf("\t\t\t\t\033[31mConglaulations Player O is the Winner\n\n\033[0m");
	    }
	    else
	    {
	    	printf("\t\t\t\t\t\033[31m Game ended in draw\n\n\033[0m");
	    }
	}
	else
	{
		if (Situation == 'X')
	    {
			printf("\t\t\t\t\t\033[31m Conglaulations to you, U are the winner \n\n\033[0m");
	    }
	    else if (Situation == 'O')
	    {
			printf("\t\t\t\t\t\033[31m Game Over\n\n\033[0m");
	    }
	    else
	    {
			printf("\t\t\t\t\t\033[31m Game ended in draw\n\n\033[0m");
	    }
	}
}