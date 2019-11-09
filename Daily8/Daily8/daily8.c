/*
Author: Kerry O'Neill
Date: 5/29/19
Purpose: To get familiar with scanf, and get more comfortable with if statements.
The program takes an input from the user, and if it is even or odd, depending on what
the number is, the number outputted is either divided by 2 if even. If odd, int number
is multiplied by 3 and then plus 1.

*/

#include <stdio.h>

int main(int argc, char* argv[]) {

	int number = 0;

	printf("Please enter a positive integer: ");
	scanf("%d", &number);


	if (number % 2 == 0) {
		number /= 2;
		printf("The next value of the number is: %d", number);
	}

	else {
		number = number * 3 + 1;
		printf("The next value of the number is: %d", number);
	}
	return 0;
}

