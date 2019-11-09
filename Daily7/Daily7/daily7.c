/*
Author: Kerry O'Neill
Date: 5/26/19
Purpose: The purpose of this assignment is to convert a base 10 number to a base 2 number using
the repeated division method we were taught in class. Also to get more familiar with recursion, and binary.
*/

#include <stdio.h>

int print_binary(int number);

void main(int argc, char* argv[]) {

	int number = 15;

	print_binary(number);

	return 0;
}

void print_binary(int number) {

	int mod = number % 2;
	int div = number / 2;

	if (number > 0) {
		print_binary(div);
		printf("%d", mod);
	}

}