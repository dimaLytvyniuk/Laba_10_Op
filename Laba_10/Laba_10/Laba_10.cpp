// Laba_10.cpp: ���������� ����� ����� ��� ����������� ����������.
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
		default: printf("�� ��������� ��������!\n");
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

	printf("�����i�� �i�:\n");
	printf("1: �������� ���� ��� ��������� ��������\n");
	printf("2: ��������������� ��������� ���� ��� ��������� ��������\n");
	printf("E: ���i�\n");
}