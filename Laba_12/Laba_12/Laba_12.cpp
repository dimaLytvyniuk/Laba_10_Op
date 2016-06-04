// Laba_12.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#include <stdarg.h> //для макросов переменного списка параметров
#include <iostream>
#include <time.h>

#define RANDOM_RANGE 20//максимальне для генерації
#define RANDOM_NUMBER (rand() % RANDOM_RANGE + 1)//випадкове число

using namespace std;

void Stones(int n, ...)//функція формування Куп
{
	va_list par;
	va_start(par, n);

	int* mass=new int[n],//вхідні дані
		*cucha1 = (int*)malloc(sizeof(int)),//куча №1
		*cucha2 = (int*)malloc(sizeof(int)),//куча №2
		val = 0,
		size = 0,//розмір mass
		weight1 = 0,//вага  купи №1
		weight2 = 0,//вага  купи №2
		size1 = 0,//розмір купи №1
		size2 = 0;//розмір купи №2
    
	for (int i = 0;i < n;i++)//запис вхідних даних у mass
	{
		val = va_arg(par, int);
		mass[i] = val;
		cout << val << " ";
		size++;
	}

	cout << endl;

	for (int i = 0;i < size - 1;i++)//сортування вхідного масиву
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

	for (int i = 0;i < n;i++)//формування куп
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

	for (int i = 0;i < size1;i++)//вивід купи №1
		cout << cucha1[i] << " ";

	cout << endl;

	cout << "Cucha 2:" << endl;
	for (int i = 0;i < size2;i++)//вивід купи №2
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

