#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int maxNum;
char newLineHolder;

void printMenu(){
	printf("Press 1 to play a game\nPress 2 to change the max number\nPress 3 to quit\n");
}

void numGuess(int target){
	// printf("%i", target);
	// track game state with boolean
	bool guessed = false;
	// create int to hold user input
	int userguess;
	// create int to hold return value of scanf
	int valid;
	// while number isnt guessed, keep asking user for inputs
	while(!guessed){
		// clear newline character which is left behind in the buffer
		scanf("%c", &newLineHolder);

		printf("Input a guess: ");
		// valid = 1 if input is an int. valid = 0 if it is not
		valid = scanf("%i", &userguess);
		// if input was not an int, exit
		if(valid == 0){
			guessed = true;
		} else {
			if(userguess == target){
				printf("You got the right number!\n");
				guessed = true;
			}
			else if(userguess > target){
				printf("Your guess was too high.\n");
			} else{
				printf("Your guess was too low.\n");
			}
		}
	}
	// once they are done, exit the function
	// user may choose to play again 
}


int main(){
	// set maximum number to some constant
	maxNum = 10;
	// set a boolean to check if exit game condition
	bool gameFinished = false;
	// set up a variable to get user menu selection
	int answer;
	// init random
	time_t t;
	srand((unsigned)time(&t));
	// keep playing while game not finished
	while(!gameFinished){
		printMenu();
		printf("> ");
		scanf("%i", &answer);
		switch(answer){
			case 1:
				numGuess((rand()%maxNum)+1);
				break;
			case 2:
				printf("What would you like the new max to be: ");
				scanf("%i", &maxNum);
				scanf("%c", &newLineHolder);
				break;
			case 3:
				gameFinished = true;
				break;
			default:
				break;
		}
	}
	return EXIT_SUCCESS;
}