/*
 Author Kerry O'Neill
 Course: CCOMP1010, Computing I
 Date: Today’s 7/2/29
 Description: This file implements the
 functionality required by program 3.
 Program 3.
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define SIZE 20

char* read_string(FILE* quiz_input, char word[], int size);
int* quiz_average(FILE* quiz_input, int* count, int arr[], double* avg);

int main(int argc, char* argv[]) {
	FILE* fp1;
	FILE* fp2;
	FILE* fp3;
	char first_name[SIZE];
	char last_name[SIZE];
	int quiz[SIZE];
	int count = 0, i = 0, space = 20;
	double average = 0;
	char c;

	fp1 = fopen("quiz.txt", "r");
	fp2 = fopen("average.txt", "w");

	if (fp1 == NULL) {
		printf("Failed to open file");
		exit(1);
	}

	if (fp2 == NULL) {
		printf("Failed to open file");
		exit(1);
	}

	fprintf(fp2, "Name");
	fprintf(fp2, "%-24s", " ");
	for (int j = 1; j <= 10; j++) {
		fprintf(fp2, "%d  ", j);
	}
	
	fprintf(fp2, "         Average");
	fprintf(fp2, "\n");
	fprintf(fp2, "----------------------------------------------------------------------------------");
	fprintf(fp2, "\n");

	//Get first and last name

	while ((read_string(fp1, first_name, SIZE)) != NULL && read_string(fp1, last_name, SIZE) != NULL) {

		quiz_average(fp1, &count, quiz, &average);

		fprintf(fp2, "%s, %-20s", last_name, first_name);

		for (int i = 0; i < count; i++) {
			fprintf(fp2, "%d ", quiz[i]);
		}

		fprintf(fp2, "%-10s", " ");
		fprintf(fp2, "%-   4lf\n", average);
		fprintf(fp2, "\n");


	}

	fclose(fp1); fp1 = NULL;
	fclose(fp2); fp2 = NULL;

	fp1 = fopen("quiz.txt", "w");
	fp2 = fopen("average.txt", "r");

	if (fp1 == NULL) {
		printf("Failed to open file");
		exit(1);
	}

	if (fp2 == NULL) {
		printf("Failed to open file");
		exit(1);
	}

	while ( (c = fgetc(fp2)) != EOF) {
		fputc(c, fp1);
	}

	fclose(fp1); fp1 = NULL;
	fclose(fp2); fp2 = NULL;

}

char* read_string(FILE* quiz_input, char word[], int size) {
	char c;
	int noc, i = 0;
	//throw away leading whitespace

	noc = fscanf(quiz_input, " %c", &c);
	if (size < 2 || noc != 1) {
		return NULL;
	}

	word[i] = c;
	i++;
	noc = fscanf(quiz_input, "%c", &c);
	while (noc == 1 && i < size - 1 && !isspace(c)) {

		word[i] = c;
		//checks if first char is lowercase, if is makes it uppercase
		if (islower(word[0])) {
			word[0] = toupper(word[0]);
		}

		i++;
		noc = fscanf(quiz_input, "%c", &c);

	}
	if (noc == 1) {
		ungetc(c, quiz_input);
	}
	word[i] = '\0';

	return word;
}

int* quiz_average(FILE* quiz_input, int* count, int arr[], double* avg) {
	int noc, n, i, sum = 0;
	*count = 0;

	noc = fscanf(quiz_input, "%d", &n);
		
	for (i = 0; noc == 1; i++) {
		arr[i] = n; 
		sum += n;
		noc = fscanf(quiz_input, "%d", &n); 
		*count = *count + 1;
	}

	*avg = sum / 10;

	return arr;
}