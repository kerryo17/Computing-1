/*
Author: Kerry O'Neill
Date: 5/29/19
Answer to question: If you type in the number 500000, the program does not crash unlike Daily 6.
I believe the reason why is because all of the numbers are being loaded into a stack,
and the while loop goes through every single one, so there is no stack overflow.

*/

#include <stdio.h>

int loop_down_to_zero(int number);

int loop_up_to_int(int number);

int main(int argc, char* argv[]) {

	int number = 0;

	printf("Please enter a positive number: ");
	scanf_s("%d", &number);

	loop_down_to_zero(number);
	printf("****\n");
	loop_up_to_int(number);

	return 0;
}

int loop_down_to_zero(int number) {
	while (number >= 0) {
		printf("%d\n", number);
		number--;
	}
}

int loop_up_to_int(int number) {
	int x = number;
	number = 0;
	
	while (number <= x) {
		printf("%d\n", number);
		number++;
	}

	
}
