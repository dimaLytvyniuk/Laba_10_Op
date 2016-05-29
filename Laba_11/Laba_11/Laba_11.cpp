// Laba_11.cpp: ���������� ����� ����� ��� ����������� ����������.
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
		default: printf("�� ��������� ��������!\n");
		}
	}

	printf("\n");
	system("pause");
    return 0;
}

void textOutput()
{
	system("cls");

	printf("�����i�� �i�:\n");
	printf("1: �������� ������\n");
	printf("2: ������� ������\n");
	printf("3: ������ �����������\n");
	printf("E: ���i�");
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