/*
Author: Kerry O'Neill
Date: 6/5/19
Purpose: Prompt the user to enter a number 1-79, and print out how many asteriks are entered by user.
If number inputted is out of bounds, or is not even a number, prompt the user again until a number
1-79 is inputted. Also create a function to print out how many asteriks are inputted.
Time spent: 30 minutes
*/

#include <stdio.h>

int draw_line(int number);
clear_keyboard_buffer(void);

int main(int argc, char* argv[]) {

	int number;

	printf("Please enter the number of asterisks you want in your line: ");
	scanf("%d", &number);
	clear_keyboard_buffer();

		do {
			printf("I'm sorry, that number is unrecognized or out of range. try [1-79]: ");
			scanf("%d", &number);
			clear_keyboard_buffer();
		} while (number < 1 || number > 79);

	draw_line(number);

	return 0;
}

int draw_line(int number) {
	for (int i = 0; i < number; i++) {
		printf("*");
	}
}

clear_keyboard_buffer(void) {
	char c;
	scanf("%c", &c);
	while (c != '\n') {
		scanf("%c", &c);
	}
}