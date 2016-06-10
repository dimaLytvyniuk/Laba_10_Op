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
void CreateProgressiveTree(TREE** head);

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
			CreateTreeFile();
		}break;
		case '2': PaintTree(head);  _getch(); break;
		case '3':
		{
			printf("\n\nMax= %d", SearchMax(head));
			_getch();
		}break;
		case '4':
		{
			//CreateTree(&head);
			CreateProgressiveTree(&head);
		}break;
		case 'E':return 0;break;
		case 'e':return 0;break;
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
	printf("4: Зчитати дерево с файлу\n");
	printf("E: Вихiд");
}
/*
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
*/

void CreateTree(TREE** head)
{
	FILE* f;
	fopen_s(&f, "in.bin", "rb");
	int value=0;

	while (!feof(f))
	{
		fread_s(&value, sizeof(int), sizeof(int), 1, f);
		AddToTree(head, value);
	}

	fclose(f);
}

void CreateProgressiveTree(TREE** head)
{
	cout << "Input data to tree\n\n";
	int value = 0;
	cin >> value;

	AddProgressive(head, value);

	cout << "Copletre!";
	_getch();
}

