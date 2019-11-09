/*
Author: Kerry O'Neill
Purpose: Program takes input from user, if number inputted is greater than 0,
program prompts user until negative number is inputted.
Time spent: 45 minutes
*/
#include <stdio.h>

clear_keyboard_buffer(void);

int main(int argc, char* argv[]) {
	
	int number, noc;

	printf("Please enter a negative integer: ");
	noc = scanf("%d", &number);
	clear_keyboard_buffer();

	while (noc == 0 || number >= 0) {
		printf("I'm sorry, you must enter a negative integer less than zero: \n");
		noc = scanf("%d", &number);
		clear_keyboard_buffer();
	}

	printf("The negative integer was: %d", number);
	return 0;
}

clear_keyboard_buffer(void) {
	char c;
	scanf("%c", &c);
	while (c != '\n') {
		scanf("%c", &c);
	}
}