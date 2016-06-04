// Laba_11.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "tree.h"
#include<iomanip>
#include <stdio.h>
#include <iostream>
#include <conio.h>

using namespace std;



void textOutput();//меню
void CreateTree(TREE** head);//створення дерева

int main()
{
	setlocale(LC_CTYPE, "RUSSIAN");

	TREE* head = NULL;

	while (true)
	{
		textOutput();
		char ch = _getch();

		system("cls");
		switch (ch)
		{
		case '1'://створення дерева
		{
			CreateTree(&head);
			PrintTree(head);
		}break;
		case '2': PaintTree(head);  _getch(); break;//вивід дерева
		case '3'://пошук максимального
		{
			printf("\n\nMax= %d", SearchMax(head));
			_getch();
		}break;
		case 'E':return 0;//вихід
		case 'e':return 0;
		default: printf("Не коректное значение!\n");
		}
	}

	printf("\n");
	system("pause");
    return 0;
}

void textOutput()
{
	system("cls");

	printf("Виберiть дiю:\n");
	printf("1: Створити дерево\n");
	printf("2: Вивести дерево\n");
	printf("3: Знайти максимальне\n");
	printf("E: Вихiд");
}

void CreateTree(TREE** head)
{
	cout << "Input data to tree\n\n";
	int value = 0;
	cin >> value;

	while(cin.good())
	{
		AddToTree(head, value);
		cout << endl;
		cin >> value;
	}

	cin.ignore();
}