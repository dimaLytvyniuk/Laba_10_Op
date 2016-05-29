// Laba_10.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"
#include<iomanip>
#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <string.h>
#include "resultive.h"
#include "stack.h"
#include "queue.h"

using namespace std;

void textOutput();

int main()
{
	setlocale(LC_CTYPE, "RUSSIAN");

	
	while (true)
	{
		textOutput();
		char ch = _getch();
		
		system("cls");
		switch (ch)
		{
		case '1': {
			CraeteFile();
			PrintFile();
			CreateResult();
		}break;
		case '2': {PrintFile();CreateResult();break;}
		case 'e':return 0;
		case 'E':return 0;
		default: printf("Не коректное значение!\n");
		}

		printf("\n");
		_getch();
	}


	system("pause");

    return 0;
}

void textOutput()
{
	system("cls");

	printf("Виберiть дiю:\n");
	printf("1: Створити файл для виконання завдання\n");
	printf("2: Використовувати створений файл для виконання завдання\n");
	printf("E: Вихiд\n");
}