#include<stdio.h>
char Convert(int Turn);
char Convert(int Turn)/*Putting X or O*/{
	if (Turn % 2 == 1)
		return 'X';
	return 'O';
}
void PrintTable(char Table[]);/*Printing the table*/
void PrintTable(char Table[]) {
	printf("   |   |   |   |\n   | %c | %c | %c |\n   |___|___|___|\n   |   |   |   |\n   | %c | %c | %c |\n   |___|___|___|\n   |   |   |   |\n   | %c | %c | %c |\n   |___|___|___|\n", Table[0], Table[1], Table[2], Table[3], Table[4], Table[5], Table[6], Table[7], Table[8]);
}
int PlayGame(int turn,char Table[]);
int PlayGame(int turn, char Table[]) {/*Game rules and inputs*/
	char Input, TrashInput;
	int TrashNumber = 0, Wrong = 0, i = 1, Win = 0;
	if (turn > 9) {
		printf("The game is over!\nNo one has won the game!\n");
	}
	else {
		printf("Player %d's turn:\nPlease choose a number from 1 to 9:", (turn % 2) ? 1 : 2);
		scanf("%c%c", &Input, &TrashInput);
		while (TrashInput != '\n') {
			if (TrashInput != ' ' && TrashInput != '\n') {
				TrashNumber++;
			}
			scanf("%c", &TrashInput);
		}
		if (TrashNumber > 0) {
			Wrong = 1;
		}
		TrashNumber = 0;
		if (Input == '1'&& Table[0] == '1'&& Wrong == 0)
			Table[0] = Convert(turn);
		else if (Input == '2'&& Table[1] == '2'&&Wrong == 0)
			Table[1] = Convert(turn);
		else if (Input == '3'&& Table[2] == '3'&&Wrong == 0)
			Table[2] = Convert(turn);
		else if (Input == '4'&& Table[3] == '4'&&Wrong == 0)
			Table[3] = Convert(turn);
		else if (Input == '5'&& Table[4] == '5'&&Wrong == 0)
			Table[4] = Convert(turn);
		else if (Input == '6'&& Table[5] == '6'&&Wrong == 0)
			Table[5] = Convert(turn);
		else if (Input == '7'&& Table[6] == '7'&&Wrong == 0)
			Table[6] = Convert(turn);
		else if (Input == '8'&& Table[7] == '8'&&Wrong == 0)
			Table[7] = Convert(turn);
		else if (Input == '9'&& Table[8] == '9'&&Wrong == 0)
			Table[8] = Convert(turn);
		else {
			Wrong = 1;
			while (Wrong == 1) {
				printf("Wrong Input!Please enter a number from remaining numbers according to the map above:");
				scanf("%c%c", &Input, &TrashInput);
				while (TrashInput != '\n') {/*This takes a string until the Enter key is pressed*/
					if (TrashInput != ' '&&TrashInput != '\n') {
						TrashNumber++;
					}
					scanf("%c", &TrashInput);
				}
				if (Input == '1'&& Table[0] == '1'&& TrashNumber == 0) {
					Table[0] = Convert(turn);
					Wrong = 0;
				}
				else if (Input == '2'&& Table[1] == '2'&& TrashNumber == 0) {
					Table[1] = Convert(turn);
					Wrong = 0;
				}
				else if (Input == '3'&& Table[2] == '3'&&TrashNumber == 0) {
					Table[2] = Convert(turn);
					Wrong = 0;
				}
				else if (Input == '4'&& Table[3] == '4'&&TrashNumber == 0) {
					Table[3] = Convert(turn);
					Wrong = 0;
				}
				else if (Input == '5'&& Table[4] == '5'&&TrashNumber == 0) {
					Table[4] = Convert(turn);
					Wrong = 0;
				}
				else if (Input == '6'&& Table[5] == '6'&&TrashNumber == 0) {
					Table[5] = Convert(turn);
					Wrong = 0;
				}
				else if (Input == '7'&& Table[6] == '7'&&TrashNumber == 0) {
					Table[6] = Convert(turn);
					Wrong = 0;
				}
				else if (Input == '8'&& Table[7] == '8'&&TrashNumber == 0) {
					Table[7] = Convert(turn);
					Wrong = 0;
				}
				else if (Input == '9'&& Table[8] == '9'&&TrashNumber == 0) {
					Table[8] = Convert(turn);
					Wrong = 0;
				}
				TrashNumber = 0;
			}
		}
		PrintTable(Table);
		if (Table[0] == Table[1] && Table[1] == Table[2])/*The winning points*/
			Win = 1;
		if (Table[3] == Table[4] && Table[4] == Table[5])
			Win = 1;
		if (Table[6] == Table[7] && Table[7] == Table[8])
			Win = 1;
		if (Table[0] == Table[3] && Table[3] == Table[6])
			Win = 1;
		if (Table[1] == Table[4] && Table[4] == Table[7])
			Win = 1;
		if (Table[2] == Table[5] && Table[5] == Table[8])
			Win = 1;
		if (Table[0] == Table[4] && Table[4] == Table[8])
			Win = 1;
		if (Table[2] == Table[4] && Table[4] == Table[6])
			Win = 1;
		if (Win == 1)
			printf("Congratulations!\nPlayer %d has won the game!\n", (turn % 2) ? 1 : 2);
		return Win;
	}
}
void InitializeGame(char Table[]);
void InitializeGame(char Table[]) {/*Starting a game*/
	printf("Welcome to TIC TAC TOE!Here is the table of the game:\n");
	printf("   |   |   |   |\n   | %c | %c | %c |\n   |___|___|___|\n   |   |   |   |\n   | %c | %c | %c |\n   |___|___|___|\n   |   |   |   |\n   | %c | %c | %c |\n   |___|___|___|\n",Table[0],Table[1],Table[2],Table[3],Table[4],Table[5],Table[6],Table[7],Table[8]);/*The Table of the game*/
	printf("Player 1 is shown as X and Player 2 is shown as O in the table\n");
}
int CheckEndGame(char Table1[],char Table2[],int* turn,int* Win);
int CheckEndGame(char Table1[],char Table2[],int* turn,int* Win) {/*Checking the end of game*/
	char Check, TrashInput;
	int i = 1;
	printf("Press c if you want to start a new game.Otherwise, press e.\n");
	scanf("%c%c", &Check, &TrashInput);
	if (Check == 'c') {
		for (i = 0; i <= 8; i++) {
			Table1[i] = Table2[i];
		}
		*turn = 1;
		*Win = 0;
		return 1;
	}
	return 0;
}
int main() {
	char TableValuesMain[9] ="123456789";
	char TableValues[9]= "123456789";
	int Turn = 1;
	int Check = 1;
	int Win = 0;
	while (Check == 1) {
		InitializeGame(TableValues);
		while (Win == 0) {
			Win = PlayGame(Turn, TableValues);
			Turn++;
		}
		Check = CheckEndGame(TableValues, TableValuesMain, &Turn, &Win);
	}
	return 0;
}