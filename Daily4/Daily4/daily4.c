/*
Author: Kerry O'Neill
Date: 5/22/19
Purpose: Create a program in which you
take the number 3.141.59 and use the placeholders
to get different outputs.
*/

#include <stdio.h>

int main(int argc, char* argv[]) {
	printf("%d is an integer and can be printed using %%d.\n\n", 42);
	printf("The character '%c' can be printed using %%c.\n\n", 'J');
	printf("Floating point numbers use %%f. %f is an example.", 3.14159);

	return 0;
}