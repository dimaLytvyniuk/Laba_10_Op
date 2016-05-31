// Laba_12.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#include <stdarg.h> //для макросов переменного списка параметров
#include <iostream>
#include <time.h>

#define RANDOM_RANGE 20 
#define SOME_NUMBER (rand() % RANDOM_RANGE + 1)

using namespace std;

void Stones(int n, ...)
{
	va_list par;
	va_start(par, n);

	int* mass=new int[n],
		*cucha1 = (int*)malloc(sizeof(int)),
		*cucha2 = (int*)malloc(sizeof(int)),
		val = 0,
		size = 0,
		weight1 = 0,
		weight2 = 0,
		size1 = 0,
		size2 = 0;
    

	while (val = va_arg(par, int))
	{
		mass[size] = val;
		cout << val << " ";
		size++;
	}

	cout << endl;

	for (int i = 0;i < size - 1;i++)
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

	for (int i = 0;i < n;i++)
	{
		if (weight1 > weight2)
		{
			cucha2= (int*)realloc((void*)cucha2, sizeof(int)*(size2 + 1));
			cucha2[size2] = mass[i];
			size2++;
		}
		else
		{
			cucha1 = (int*)realloc((void*)cucha1, sizeof(int)*(size1 + 1));
			cucha1[size1] = mass[i];
			size1++;
		}
	}

	cout << "Cucha 1:" << endl;

	for (int i = 0;i < size1;i++)
		cout << cucha1[i] << " ";

	cout << endl;

	for (int i = 0;i < size2;i++)
		cout << cucha2[i] << " ";

	cout << endl;

	va_end(par);
}

int main()
{
	srand(time(NULL));

	Stones(8,SOME_NUMBER, SOME_NUMBER, SOME_NUMBER, SOME_NUMBER, SOME_NUMBER, SOME_NUMBER, SOME_NUMBER);

	cout << endl;
	system("pause");
    return 0;
}

