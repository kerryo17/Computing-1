/***********************************************
Author: Kerry O'Neill
Date: 6/25/19
Purpose: The program does the fibonacci sequence, which is 1, 1, 3, 5, 8... it asks the amount of days from user, and size, and depending on both inputs it will return how long it will take depending on the input.
Asha helped me with my fib_calculation function, as the way I was doing it did not work at all. 
Time Spent: 3/4 hours
***********************************************/
#include <stdio.h>

enum boolean { FALSE, TRUE };
typedef enum boolean Boolean;

Boolean user_wishes_to_continue(void);
int fib_calculation(int population, int num_days);
clear_keyboard_buffer(void);

int main(int argc, char* argv[]) {
	int noc, population, num_days, calculation;

	do {
		do {
			printf("Please enter the initial size of the green crud: ");
			noc = scanf("%d", &population);
			clear_keyboard_buffer();

			if (noc == 0 || population < 0) {
				printf("I'm sorry, that value is unrecognized, or is negative.\n");
			}

		} while (noc == 0 || population < 0);

		do {
			printf("Please enter in the number of days: ");
			noc = scanf("%d", &num_days);
			clear_keyboard_buffer();

			if (noc == 0 || num_days < 0) {
				printf("I'm sorry, that value is unrecognized, or is negative.\n");
			}
		} while (noc == 0 || num_days < 0);

		calculation = fib_calculation(population, num_days);
		printf("With an initial population of %d pound of crud growing for %d days,\nthe final population would be %d pounds\n", population, num_days, calculation);

	} while (user_wishes_to_continue() == TRUE);

	return 0;
}

int fib_calculation(int population, int num_days) {
	 
	int pounds, start_pounds, end_pounds, count = 0;

	for (int i = 0; i <= num_days; i += 5){

		if (count <= 1){
			pounds = population;
			start_pounds = population;
			count++;
		}
		else
		{
			end_pounds = pounds;
			pounds = start_pounds + end_pounds;
			start_pounds = end_pounds;
		}
	}

	return pounds;
}

clear_keyboard_buffer(void) {
	char c;
	scanf("%c", &c);
	while (c != '\n') {
		scanf("%c", &c);
	}
}

Boolean user_wishes_to_continue() {

	char answer;
	printf("Do you wish to continue? (y/n)\n");

	scanf(" %c", &answer);
	clear_keyboard_buffer();

	while (answer != 'Y' && answer != 'y' && answer != 'N' && answer != 'n') {
		printf("I do not understand.\n");
		scanf(" %c", &answer);
	}

	if (answer == 'y' || answer == 'Y') {
		return TRUE;
	}

	if (answer == 'n' || answer == 'N') {
		return FALSE;
	}


}