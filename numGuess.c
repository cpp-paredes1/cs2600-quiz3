#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int maxNum;

void numGuess(int target){
	// track game state with boolean
	bool guessed = false;
	// while number isnt guessed, keep asking user for inputs

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
		sscanf("> ", &answer);
		switch(answer){
			case 1:
				numGuess((rand()%maxNum)+1);
				break;
			case 2:
				sscanf("What would you like the new max to be?: ", &maxNum);
				break;
			case 3:
				gameFinished = true;
				break;
		}
	}
}