// Laba_12.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#include <stdarg.h> //��� �������� ����������� ������ ����������
#include <iostream>
#include <time.h>

#define RANDOM_RANGE 20//����������� ��� ���������
#define RANDOM_NUMBER (rand() % RANDOM_RANGE + 1)//��������� �����

using namespace std;

void Stones(int n, ...)//������� ���������� ���
{
	va_list par;
	va_start(par, n);

	int* mass=new int[n],//����� ���
		*cucha1 = (int*)malloc(sizeof(int)),//���� �1
		*cucha2 = (int*)malloc(sizeof(int)),//���� �2
		val = 0,
		size = 0,//����� mass
		weight1 = 0,//����  ���� �1
		weight2 = 0,//����  ���� �2
		size1 = 0,//����� ���� �1
		size2 = 0;//����� ���� �2
    
	for (int i = 0;i < n;i++)//����� ������� ����� � mass
	{
		val = va_arg(par, int);
		mass[i] = val;
		cout << val << " ";
		size++;
	}

	cout << endl;

	for (int i = 0;i < size - 1;i++)//���������� �������� ������
	{
		for (int j = 0;j < size - 1 - i;j++)
		{
			if(mass[j]<mass[j+1])
			{
				int b = mass[j];
				mass[j] = mass[j + 1];
				mass[j + 1] = b;
			}
		}
	}

	for (int i = 0;i < n;i++)//���������� ���
	{
		if (weight1 > weight2)
		{
			cucha2= (int*)realloc((void*)cucha2, (sizeof(int)*(size2 + 1)));
			cucha2[size2] = mass[i];
			size2++;
			weight2 += mass[i];
		}
		else
		{
			cucha1 = (int*)realloc((void*)cucha1, (sizeof(int)*(size1 + 1)));
			cucha1[size1] = mass[i];
			size1++;
			weight1 += mass[i];
		}
	}

	cout << "Cucha 1:" << endl;

	for (int i = 0;i < size1;i++)//���� ���� �1
		cout << cucha1[i] << " ";

	cout << endl;

	cout << "Cucha 2:" << endl;
	for (int i = 0;i < size2;i++)//���� ���� �2
		cout << cucha2[i] << " ";

	cout << endl;

	va_end(par);
}

int main()
{
	srand(time(NULL));

	Stones(8,RANDOM_NUMBER, RANDOM_NUMBER, RANDOM_NUMBER, RANDOM_NUMBER, RANDOM_NUMBER, RANDOM_NUMBER, RANDOM_NUMBER, RANDOM_NUMBER);
	cout << endl;

	Stones(10, RANDOM_NUMBER, RANDOM_NUMBER, RANDOM_NUMBER, RANDOM_NUMBER, RANDOM_NUMBER, RANDOM_NUMBER, RANDOM_NUMBER, RANDOM_NUMBER, RANDOM_NUMBER, RANDOM_NUMBER);
	cout << endl;

	system("pause");
    return 0;
}

