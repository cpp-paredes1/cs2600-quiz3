#include <stdio.h>
#include<stdlib.h> 
#include<time.h> 

// notes:
// argv[0] = filepath
// argv[1] = first argument (space separated)
// atof(char *string) = converts char array (string) to double

int main(int argc, char *argv[]){
	// init random object
	time_t t;
	srand((unsigned)time(&t));
	// generate food array
	double food[] = {9.95, 4.55, 13.25, 22.35};
	char *foodNames[] = {"Salad", "Soup", "Sandwich", "Pizza"};
	// generate random food
	int foodIndex = rand()%4;
	double price = food[foodIndex];
	// parse user tax
	double tax = 1 + atof(argv[1]);
	// parse user tip
	double tip = 1 + atof(argv[2]);
	// total = price * (1 + tax) * (1 + tip);
	printf("You ordered a %s, which was $%.2f. You paid a %.0f%% tip and a %.0f%% tax.\n", foodNames[foodIndex], price, 100*(tip-1), 100*(tax-1));
	printf("Your total was: $%.2f.", price * tax * tip);
	return EXIT_SUCCESS;
}