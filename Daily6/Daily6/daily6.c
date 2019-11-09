/*
Author: Kerry O'Neill
Date: 5/24/19
Purpose: In this assignment, we are supposed to create two functions to count up and down from zero.
We practice creating functions, and using recursion in this assignment. 
Answer to question: When i entered in the number 500,000 as the input from the keyboard, it stopped at value 495242.
The reason why it stopped is because of stack overflow. The reason it is a stack overflow because there is not enough memory allocated for int number, and it runs out of space in memory.
*/

#include <stdio.h>

int recursive_down_to_zero(int number);
int recursive_up_to_int(int number);

int main(int argc, char* argv[]) {
	int number = 100;
	recursive_down_to_zero(number);
	printf("****");
	printf("\n");
	recursive_up_to_int(number);
}

int recursive_down_to_zero(int number) {
	if (number >= 0) {
		printf("%d\n", number);
		recursive_down_to_zero(number-1);
	}
	//return number;
}

int recursive_up_to_int(int number) {

	if (number >= 0) {
		recursive_up_to_int(number - 1);
		printf("%d\n", number);
	}
}