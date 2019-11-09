/***********************************************
Author: Kerry O'Neill
Date: 6/11/19
Purpose: The program, depending on the value inputted, either exits, calls convert_weights, or convert_lengths
If the value inputted is not between 0-2, it prompts the user until it is inputted.
Sources of Help: Lecture of 6/10/19 - Dr Adams does a similar program
 Time Spent: 1 hour
***********************************************/


#include <stdio.h>

int convert_lengths(void);
int convert_weights(void);
clear_keyboard_buffer(void);

int main(int argc, char* argv[]) {

	int noc;
	char c;

	do {
		do {
			printf("Enter in if you want to convert values that are lengths or weights.\n");
			printf("Enter 1 for lengths, 2 for weights, and a 0 if you want to exit: ");
			noc = scanf(" %c", &c);
			clear_keyboard_buffer();

			if (noc == 0 || c != '1' && c != '2' && c != '0') {
				printf("I'm sorry, but you must enter a number between 0 and 2!\n");
			}

		} while (noc == 0 || c != '1' && c != '2' && c != '0');

		switch (c) {
		case '1':
			convert_lengths();
			break;
		case '2':
			convert_weights();
			break;
		}
	} while (c != '0');

	return 0;
}

int convert_lengths(void) {
	//stuff will go here eventually
	printf("You have selected to convert to lengths!\n");
}

int convert_weights(void) {
	//stuff will go here eventually
	printf("You have selected to convert to weights!\n");
}

clear_keyboard_buffer(void) {
	char c;
	scanf("%c", &c);
	while (c != '\n') {
		scanf("%c", &c);
	}
}