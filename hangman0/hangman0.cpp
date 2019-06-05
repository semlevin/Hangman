// hangman0.cpp : This file contains the 'main' function. Program execution begins and ends there.
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>


const char* Words[] = {
	"kitchen",
	"table",
	"chair",

};

#define MAXWORD 50

int StringLength(const char* str)
{
	for (int i = 0; i < MAXWORD; i++)
	{
		if (str[i] == 0)
			return i;
	}

	return 0;
}



int main()
{
	
	char HiddenWord[MAXWORD];
	int IndexWord = 1;
	int LengthWord;
	char Letter;
	int RemTry;



	int two = 2;
	int one = 1;



	printf("\n  Hangman V0.1\n");
	printf("  2019 Semen Levin\n\n ");
	printf("\n                                                       HANGMAN \n");
	printf("\n                                                        MENU \n");

	printf(" \n new game (press 1) \n");
	printf(" rules (press 2) \n");
	printf(" quit game (press 0)");

	printf(" \n Input");
	scanf_s("%d", &one);


	switch (one)
	{
		case 0:
		{
			printf("Goodbye");
			return 0;
		}
			break;
			
		case 1:
			goto start;
			

		case 2:
			printf(" \nHangman is a simple word guessing game.");
			printf(" \nPlayer try to figure out an unknown word by guessing letters.");
			printf(" \nIf too many letters which do not appear in the word are guessed, the player is lose");
			break;
		
		default:
			printf("I dont know this command");
			break;
	
	}
	
	

start:
	RemTry = 5;
	LengthWord = StringLength(Words[IndexWord]);

	for (int i = 0; i < LengthWord; i++)
		HiddenWord[i] = '*';
	HiddenWord[LengthWord] = 0;


NextStep:
	printf("Try %d\n", RemTry);
	printf("\nHidden Word: %s", HiddenWord);
	printf("\n Input letter: ");
	scanf_s("\n%c", &Letter);

	bool GoodTry = false;

	for (int i = 0; i < LengthWord; i++)
	{
		if (Words[IndexWord][i] == Letter)
		{
			HiddenWord[i] = Letter;
			GoodTry = true;
		
		}

	}

	if (GoodTry == false)
		RemTry--;

	if (RemTry == 0)
	{
		printf("You lose\n");
		printf("Maybe Try? (y/n): ");
		scanf_s("\n %c", &Letter);
		if (Letter == 'y')
			goto start;
		return 0;

	}
	goto NextStep;


}