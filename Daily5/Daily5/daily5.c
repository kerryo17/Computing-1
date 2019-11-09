/*
Author: Kerry O'Neill
Date: 5/23/19
Purpose:
To get familiar with functions, we are asked to create a smile() function in which you 
make a smiley face, then call it three times in main.
*/

#include <stdio.h>

int smile();

int main(int argc, char* argv[]) {
	smile();
	printf("\n\n");
	smile();
	printf("\n\n");
	smile();
}

int smile() {
	printf("  ****   \n");
	printf(" * . .* \n");
	printf("*      *\n");
	printf("*  \\_/ *\n");
	printf(" *    *\n");
	printf("  **** ");

}