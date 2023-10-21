#include "STD_TYPES.h"
#include "built_Functions.h"
#include <stdio.h>
#include <stdlib.h>
extern sint8 mode;

int main()
{
	sint8 Again=1;
	while (Again == 1)
	{
		system("cls");
		printf("\t\t\t\t\t\033[36m Welcome in Tic Tac Toe Game\n\033[0m");
		printf("\n");
		printf("\t\t\t\t\033[34m   ______________________________________\n\033[0m");
	    printf("\t\t\t\t\033[34m   ______________________________________\n\033[0m");
		printf("\n");
	    printf("\t\t\t\t\t\033[36m Choose an option:\n\033[0m");
		printf("\n");
	    printf("\t\t\t\t\t\033[36m 1:Multi_Mode\n\033[0m");
		printf("\n");
	    printf("\t\t\t\t\t\033[36m 2:Single_Mode\n\033[0m");
		printf("\n");
	    printf("\t\t\t\t\t\033[36m 3:Exit\n\033[0m");
	    while (1)
	    {
	    	if (scanf("%d",&mode) && (mode ==1 || mode ==2 || mode ==3))
	    	{
	    		break;
	    	}
	    	else
	    	{
	    		while(getchar()!='\n');
	    		printf("Enter a vaild option:");
	    	}
	    }
		if (mode == 2)
		{
	        Intial();
	        Printing_Elements();
	        Computer_Mode();
	        Printing_Elements();
	        Displaying_Results();
	        printf("Do you want to play again ?\n1: Yes.\n2: No.\n");
	        while (1)
	        {
	        	if(scanf("%d",&Again) && ( Again ==1 || Again==2 ) )
	        	{
	        		break;
	        	}
	        	else
	        	{
	        		while(getchar()!='\n');
	        		printf("Invalid Input,please choose one of the available:");
	        	}
	        }
		    system("cls");
		    Reset_Game ();
		}
		else if (mode==1)
		{
			Intial();
	        Printing_Elements();
	        Replacing_Elements();
	        Printing_Elements();
	        Displaying_Results();
	        printf("Do you want to play again ?\n1: Yes.\n2: No.\n");
	        while (1)
	        {
	        	if(scanf("%d",&Again) && ( Again ==1 || Again==2 ) )
	        	{
	        		break;
	        	}
	        	else
	        	{
	        		while(getchar()!='\n');
	        		printf("Invalid Input,please choose one of the available:");
	        	}
	        }
		    system("cls");
		    Reset_Game ();
		}
		else
		{
			printf("Game ended,have a good day!!\n");
			exit(0);
		}
	}
	printf("Game ended,have a good day!!\n");
}
