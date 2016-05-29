// Laba_11.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "tree.h"
#include<iomanip>
#include <stdio.h>
#include <iostream>
#include <conio.h>

using namespace std;



void textOutput();
void CreateTree(TREE** head);

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
		case '1':
		{
			CreateTree(&head);
			PrintTree(head);
		}break;
		case '2': PrintTree(head); _getch(); break;
		case '3':PainTree(head,1);_getch(); break;
		case 'E':return 0;
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