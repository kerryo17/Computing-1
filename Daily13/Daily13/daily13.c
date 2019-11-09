/***********************************************
Author: Kerry O'Neill
Date: 6/12/19
Purpose: To make a rock, paper, scissor game. The game takes input froma  player 1 and 2, and it asks them if they would like r, p, or s. If they pick r and r it would be a draw, etc.
Time Spent: 8 hours
***********************************************/
#include <stdio.h>

enum Choice { ROCK, PAPER, SCISSOR };
typedef enum Choice choice;

enum boolean { FALSE, TRUE };
typedef enum boolean Boolean;

choice player_choice();
Boolean user_wishes_to_continue(void);
clear_keyboard_buffer(void);

int main(int argc, char* argv[]) {

	choice p1, p2;

	do {
		printf("Player 1 it is your turn! \n");
		p1 = player_choice();

		printf("Player 2 it is your turn! \n");
		p2 = player_choice();

		if (p1 == ROCK && p2 == ROCK) {
			printf("Draw, nobody wins.\n");
		}

		if (p1 == PAPER && p2 == PAPER) {
			printf("Draw, nobody wins.\n");
		}

		if (p1 == SCISSOR && p2 == SCISSOR) {
			printf("Draw, nobody wins.\n");
		}

		//p and r = paper covers rock
		if (p1 == ROCK && p2 == PAPER) {
			printf("Player 2 wins! Paper covers rock.\n");
		}

		//p and r = paper covers rock
		if (p1 == PAPER && p2 == ROCK) {
			printf("Player 1 wins! Paper covers rock.\n");
		}

		if (p1 == ROCK && p2 == SCISSOR) {
			printf("Player 1 wins! Rock breaks scissors.\n");
		}

		if (p1 == SCISSOR && p2 == ROCK) {
			printf("Player 2 wins! Rock breaks scissors.\n");
		}

		if (p1 == SCISSOR && p2 == PAPER) {
			printf("Player 1 wins! Scissors cut paper.");
		}

		if (p1 == PAPER && p2 == SCISSOR) {
			printf("Player 2 wins! Scissors cut paper.");
		}

	} while (user_wishes_to_continue() == TRUE);

	return 0;
}

choice player_choice() {
	char c;
	int noc;

	do {
		noc = scanf(" %c", &c);
		clear_keyboard_buffer();

		if ((noc == 0 || (c != 'r' && c != 'R' && c != 'p' && c != 'P' && c != 's' && c != 'S'))) {
			printf("I'm sorry, but this is not a valid input\n");
		}
	} while ((noc == 0 || (c != 'r' && c != 'R' && c != 'p' && c != 'P' && c != 's' && c != 'S')));

	switch (c) {
	case 'r':
	case 'R':
		return ROCK;
		break;
	case 'p':
	case 'P':
		return PAPER;
		break;
	case 's':
	case 'S':
		return SCISSOR;
		break;
	}

}

clear_keyboard_buffer(void) {
	char c;
	scanf("%c", &c);

	while (c != '\n') {
		scanf("%c", &c);
	}
}

Boolean user_wishes_to_continue() {

	char answer;
	printf("Do you wish to continue? (y/n)\n");

	scanf(" %c", &answer);
	clear_keyboard_buffer();

	while (answer != 'Y' && answer != 'y' && answer != 'N' && answer != 'n') {
		printf("I do not understand.\n");
		scanf(" %c", &answer);
	}

	if (answer == 'y' || answer == 'Y') {
		return TRUE;
	}

	if (answer == 'n' || answer == 'N') {
		return FALSE;
	}


}