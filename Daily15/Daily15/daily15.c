/***********************************************
Author: Kerry O'Neill
Date: 6/12/19
Purpose: This prorgram is a continuation of daily 14, and we add more stub functions to the program.
Sources of Help: I based my code off of Dr Adams lecture from June 10, and used my code from daily 14.
Time Spent: 45 mins
***********************************************/

#include <stdio.h>

void convert_lengths(void);
void convert_weights(void);
void length_to_metric(void);
void length_to_us(void);
void weight_to_metric(void);
void weight_to_us(void);
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

void convert_lengths(void) {
	int noc;
	char c;

	printf("You have selected to convert to lengths!\n");

	do {
		do {
			printf("Enter 1 to convert lengths from US to metric, 2 for to convert lengths from metric to US, 0 to quit\n");
			noc = scanf(" %c", &c);
			clear_keyboard_buffer();

			if (noc == 0 || c != '1' && c != '2' && c != '0') {
				printf("I'm sorry, but you must enter a number between 0 and 2!\n");
			}

		} while (noc == 0 || c != '1' && c != '2' && c != '0');

		switch (c) {
		case '0':
			printf("Back to main menu! ");
			return;
		case '1':
			length_to_metric();
			break;
		case '2':
			length_to_us();
			break;
		}
	} while (c != '0');

}

void convert_weights(void) {
	int noc;
	char c;

	printf("You have selected to convert to weights!\n");

	do {
		do {
			printf("Enter 1 to convert weights from US to metric, 2 for to convert weights from metric to US, 0 to quit\n");
			noc = scanf(" %c", &c);
			clear_keyboard_buffer();

			if (noc == 0 || c != '1' && c != '2' && c != '0') {
				printf("I'm sorry, but you must enter a number between 0 and 2!\n");
			}

		} while (noc == 0 || c != '1' && c != '2' && c != '0');

		switch (c) {
		case '0':
			printf("Back to main menu! ");
			return;
		case '1':
			weight_to_metric();
			break;
		case '2':
			weight_to_us();
			break;
		}
	} while (c != '0');

}

void length_to_metric(void) {
	//stuff will go here
	printf("You have decided to convert length to metric!\n");
}

void length_to_us(void) {
	//stuff wil go here
	printf("You have decided to convert length to  US!\n");
}

void weight_to_metric(void) {
	//stuff will go here
	printf("You have decided to convert weight to metric!\n");
}

void weight_to_us(void) {
	//stuff will go here
	printf("You have decided to convert weight to US!\n");
}

clear_keyboard_buffer(void) {
	char c;
	scanf("%c", &c);
	while (c != '\n') {
		scanf("%c", &c);
	}
}