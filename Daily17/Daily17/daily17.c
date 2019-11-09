/***********************************************
Author: Kerry O'Neill
Date: 6/26
Purpose: The program scans through two files, sorts the numbers in the file from smallest to larger, than outputs to another file
Sources of Help: 
I used this website for the format of how to open a file, close a file, etc:
https://www.geeksforgeeks.org/basics-file-handling-c/
I got help from Thanh Ly, he helped me debug my function scan_file, as I was using a do-while and it was not a good idea to use it. I also got help from Dr.Adams regarding the do-while, and advised me to change it.
 Time Spent: Roughly 5/6 hours, I lost track of time to be honest
***********************************************/

#include <stdio.h>

void scan_file(FILE* fp1, FILE* fp2, FILE* fp3);

int main(int argc, char* argv[]) {
	FILE* fp1;
	FILE* fp2;
	FILE* fp3;

	//first bookend
	fp1 = fopen("numbers1.txt", "r");//creates numbers1.txt
	fp2 = fopen("numbers2.txt", "r");//creates numbers2.txt
	fp3 = fopen("output.txt", "w");//creates number3.txt

	//checks if file1 opened, if not, exit
	if (fp1 == NULL) {
		printf("Failed to open file 1");
		exit(0);//exits with error
	}

	//checks if file 2 opened
	if (fp2 == NULL) {
		printf("Failed to open file 2");
		exit(0);//exits with error
	}

	//checks if file three is created
	if (fp3 == NULL) {
		printf("Failed to open file 3");
		exit(0);
	}

	scan_file(fp1, fp2, fp3);

	//second bookend
	fclose(fp1); fp1 = NULL;//closes file 1
	fclose(fp2); fp2 = NULL;//closes file 2
	fclose(fp3); fp3 = NULL;//closes file 3

	return 0;
}

void scan_file(FILE* fp1, FILE* fp2, FILE* fp3) {
	int n1, n2, smaller_of_two, noc1, noc2;

	noc1 = fscanf(fp1, "%d", &n1);//scans through first file
	noc2 = fscanf(fp2, "%d", &n2);//scans through second file

	while (noc1 == 1 && noc2 == 1) {

		if (n1 <= n2){
			smaller_of_two = n1;//if n1 is smaller than n2, smaller_of_two = n1
			noc1 = fscanf(fp1, "%d", &n1);//continues to scan until EOF
		}
		else{
			smaller_of_two = n2;//if n2 is smaller than n1, smaller_of_two = n2
			noc2 = fscanf(fp2, "%d", &n2);//continues to scan until EOF
		}

		fprintf(fp3, "%d\n", smaller_of_two);//puts smaller number in output.txt until EOF

	}

	//checks if anything is left in file, prints it out
	while (noc1 == 1) {
		fprintf(fp3, "%d\n", n1);
		noc1 = fscanf(fp1, "%d", &n1);
	}

	//checks if anything is left in file, prints it out
	while (noc2 == 1) {
		fprintf(fp3, "%d\n", n2);
		noc2 = fscanf(fp2, "%d", &n2);
	}
}