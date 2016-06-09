#include "stdafx.h"
#include "tree.h"
#include<iomanip>
#include <stdio.h>
#include <iostream>
#include <conio.h>
#include "queue.h"

using namespace std;

const int start = 39;

bool AddToTree(TREE** head,int value)
{
	bool res=true;
	TREE* current = new TREE;
	
	current->value = value;
	current->left = NULL;
	current->right = NULL;

	if ((*head))
	{
		if ((*head)->value == value)
			return false;
		else
		{
			if ((*head)->value > value)
				res=AddToTree(&((*head)->left), value);
			else
				res=AddToTree(&((*head)->right), value);
		}
	}
	else
	{
		(*head) = current;
	}

	return res;
}

void CreateTreeFile()
{
	FILE* f;

	fopen_s(&f, "in.bin", "wb");

	cout << "Input data to tree\n\n";
	int value = 0;
	cin >> value;

	while (cin.good())
	{
		fwrite(&value, sizeof(int), 1, f);
		//fprintf_s(f, "%d", value);
		cin >> value;
	}

	cin.ignore();
	fclose(f);
}

void PaintTree(TREE* head)
{
	int lenY = 0,
		lenX,
		level = 0,
		maxLevel = 0,
		rozr = 0,
		topLevel = 0,
		*levels;
	TQueue* headQ = NULL,
		*tail = NULL;
	TREE* prom;
	char** mass,
		num[4] = "";

	head->level = level;

	AddQueue(&headQ, &tail, head);

	while (headQ)
	{
		prom = PopQueue(&headQ, &tail);

		if (prom->level != level)
		{
			level++;
		}

		if (prom->left)
		{
			prom->left->level = level + 1;
			AddQueue(&headQ, &tail, prom->left);
		}

		if (prom->right)
		{
			prom->right->level = level + 1;
			AddQueue(&headQ, &tail, prom->right);
		}
	}

	headQ = NULL;
	tail = NULL;
	maxLevel = level;
	level = 0;

	//topLevel = (maxLevel - 1) * 3 + 1;
	levels = new int[maxLevel];

	levels[maxLevel-1] = 1;

	

	for (int i = maxLevel - 2;i >= 0;i--)
	{
		levels[i] = levels[i + 1] * 2;
	}

	int sum = 5, j = maxLevel-1;

	for (int i = 0;i <maxLevel-1;i++)
	{
		levels[i]+=j;
		sum += levels[i];
		j--;
	}

	levels[0]+=2;

	lenY = (sum + maxLevel) * 2 + 1;
	lenX = sum+ maxLevel + maxLevel * 3 + 3;

	
		mass = new char*[lenY];

		for (int i = 0;i < lenY;i++)
			mass[i] = new char[lenX + 1];

		for (int i = 0;i < lenY;i++)
			mass[i][0] = 0;

		for (int i = 0;i < lenY;i++)
			for (int j = 0;j < lenX;j++)
			{
				int strl = strlen(mass[i]);
				mass[i][strl] = ' ';
				mass[i][strl + 1] = 0;
			}

		AddQueue(&headQ, &tail, head);

		head->positionY = lenY / 2;
		head->positionX = 0;

		while (headQ)
		{
			prom = PopQueue(&headQ, &tail);

			if (prom->level != level)
			{
				level++;
			}

			if (prom->left)
			{
				prom->left->positionY = prom->positionY + levels[level] + 1;
				prom->left->positionX = prom->positionX + levels[level] + 3;
				AddQueue(&headQ, &tail, prom->left);
			}

			if (prom->right)
			{
				prom->right->positionY = prom->positionY - levels[level] - 1;
				prom->right->positionX = prom->positionX + levels[level] + 3;
				AddQueue(&headQ, &tail, prom->right);
			}
		}

		headQ = NULL;
		tail = NULL;
		level = 0;

		AddQueue(&headQ, &tail, head);

		cin.ignore();
		_itoa_s(head->value, num, 4, 10);

		for (int i = 0;i < strlen(num);i++)
			mass[head->positionY][i] = num[i];

		num[0] = 0;

		while (headQ)
		{
			prom = PopQueue(&headQ, &tail);

			if (prom->level != level)
			{
				level++;
			}

			if (prom->left)
			{
				for (int i = 1;i <= levels[level];i++)
				{
					mass[prom->positionY + i][prom->positionX + 2 + i] = '\\';
				}

				_itoa_s(prom->left->value, num, 4, 10);

				for (int i = 0;i < strlen(num);i++)
					mass[prom->left->positionY][prom->left->positionX + i] = num[i];

				num[0] = 0;

				AddQueue(&headQ, &tail, prom->left);
			}

			if (prom->right)
			{
				for (int i = 1;i <= levels[level];i++)
				{
					mass[prom->positionY - i][prom->positionX + 2 + i] = '/';
				}

				_itoa_s(prom->right->value, num, 4, 10);

				for (int i = 0;i < strlen(num);i++)
					mass[prom->right->positionY][prom->right->positionX + i] = num[i];

				num[0] = 0;

				AddQueue(&headQ, &tail, prom->right);
			}
		}

		

	if (lenX <= 80)
	{
		for (int i = 0;i < lenY;i++)
		{
			cout << mass[i] << endl;
		}
	}
	else
	{
		cout << "TO MANY VERTEX, SO TREE IN FILE";
		FILE* f;

		fopen_s(&f, "tree.txt", "wt");

		for (int i = 0;i < lenY;i++)
		{
			fputs(mass[i], f);
			fputs("\n", f);
		}
		fclose(f);

		system("notepad.exe tree.txt");
	}
}

int SearchMax(TREE* head)
{
	int res = head->value;

	if (head->right != NULL)
	{
		res = SearchMax(head->right);
	}

	return res;
}

int SearchRozr(int value)
{
	int res = 0;

	if (value < 0)
		res++;

	while (value > 0)
	{
		value = value / 10;
		res++;
	}

	return res;
}