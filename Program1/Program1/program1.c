/*
Author: Kerry O'Neill
Date: 6/8/19
Purpose: The purpose of Program 1 is to take two inputs from the user(starting and endpoint) and to count the steps of the oneness method. 
Then we print out the number of steps for each number and format it into 7 columns.
Time spent: 5 hours
*/

#include <stdio.h>

clear_keyboard_buffer(void);
int step(int number);

int main(int argc, char* argv[]) {

	int input1, input2, j=0;

	//prompts user for input1
	printf("Enter a starting point: ");

	do {
		scanf("%d", &input1);
		clear_keyboard_buffer();

		if (input1 < 1 || input1 > 1000) {
			printf("I'm sorry, please enter a number less than 1000");
			scanf("%d", &input1);
			clear_keyboard_buffer();
		}

	} while (input1 < 1 || input1 > 1000);

	//prompts user for input 2
	printf("Enter an ending point: ");

	do{
		scanf("%d", &input2);
		clear_keyboard_buffer();

		if (input2 < input1 || input2 > 10000) {
			printf("I'm sorry, please enter a number less than 10000");
			scanf("%d", &input2);
			clear_keyboard_buffer();
		}

	} while (input2 < input1 || input2 > 10000);

	//prints out numbers
	for (int i = input1; i <= input2; i++) {

		printf("%5d:%-5d", i, step(i));
		j++;

		if (j % 7 == 0) {
			printf("\n");
		}
	}

	return 0;
}

int step(int number) {

	int count = 0;

	while(number != 1){

		if (number % 2 == 0) {
			number = number / 2;
		}

		else {
			number = (number * 3) + 1;
		}

		count++;
	} 

	return count;
	
}


clear_keyboard_buffer(void) {
	char c;
	scanf("%c", &c);
	while (c != '\n') {
		scanf("%c", &c);
	}
}

