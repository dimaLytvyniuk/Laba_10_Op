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
	
	current->value = value;//створення допоміжного вузла
	current->left = NULL;
	current->right = NULL;

	if ((*head))//якщо дерево не порожнє
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



void PrintTree(TREE* head)
{
	if (head != NULL)
	{
		printf("%4d",head->value);
		PrintTree(head->left);
		PrintTree(head->right);
	}
}


/*
void PainTreeFinish(TREE* head,int pos)
{
	if (head)
	{
		for (int i = 0;i < pos;i++)
		{
			printf(" ");
		}

		printf("%d", head->value);

	}
	
}


*/
/*
void PaintTree(TREE* head)
{
	FILE* f;
	fopen_s(&f, "main.txt", "wt");

	TQueue* headQ = NULL;
	TQueue* tail = NULL;
	TREE* prom;
	int level = 0,
		pos = 40,
		posLevel = pos - 1,
		startlevel = 0,
		startPosition = 0,
		currPos = 1,
		y = 0;
	head->level = level;
	head->position = 1;

	AddQueue(&headQ, &tail, head);

	while (headQ)
	{
		prom = PopQueue(&headQ, &tail);

		if (prom->level != level)
		{
			currPos = 1;
			fprintf(f, "\n");
			//printf("\n");
			level += 1;
			pos = pos - pow(2,level);

			startPosition = 0;

			for (int j = 1;j <= pow(2,level-1);j++)
			{
				for (int i = startPosition;i < pos;i++)
				{
					fprintf_s(f, " ");
					//printf(" ");
				}
				fprintf_s(f, "/   \\");
				//printf("/   \\");

				startPosition = pos-5;
			}

			//printf("\n");
			fprintf_s(f, "\n");
			posLevel = pos-2;
			startlevel = 0;
		}

		y = 0;

		for (int j = currPos;j <= prom->position;j++)
		{
			for (int i = startlevel;i < posLevel;i++)
			{	//printf(" ");
				fprintf_s(f, " ");		
			}
			y++;
			startlevel = posLevel;
			posLevel += 6;
		}

		currPos += y;

		//printf("%d", prom->value);
		fprintf_s(f, "%d", prom->value);
		

		if (prom->left)
		{
			prom->left->level = level + 1;
			prom->left->position = pow(2, prom->position)-1;
			AddQueue(&headQ, &tail, prom->left);
		}

		if (prom->right)
		{
			prom->right->level = level + 1;
			prom->right->position = pow(2, prom->position) + 1;
			AddQueue(&headQ, &tail, prom->right);
		}

	}

	_getch();

	fclose(f);
}
*/

void PaintTree(TREE* head)
{
	int len = 80,
		level = 0,
		maxLevel = 0,
		rozr = 0;
	TQueue* headQ = NULL,
		*tail = NULL;
	TREE* prom;
	char** mass = new char*[len];

	for (int i = 0;i < len;i++)
		mass[i] = new char[len];

	for (int i = 0;i < len;i++)
		mass[i][0] = 0;

	head->level = level;
	

	AddQueue(&headQ, &tail, head);

	while (headQ)
	{
		prom= PopQueue(&headQ, &tail);

		if (prom->level != level)
		{
			level++;
		}

		if (prom->left)
		{
			prom->left->level = level + 1;
			//prom->left->position = pow(2, prom->position) - 1;
			AddQueue(&headQ, &tail, prom->left);
		}

		if (prom->right)
		{
			prom->right->level = level + 1;
			//prom->right->position = pow(2, prom->position) + 1;
			AddQueue(&headQ, &tail, prom->right);
		}
	}

	headQ = NULL;
	tail = NULL;
	maxLevel = level;
	level = 0;

	maxLevel++;
	AddQueue(&headQ, &tail, head);


	head->positionY = len / 2 - 1;
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
			prom->left->level = level + 1;
			prom->left->positionY = prom->positionY + maxLevel - level;
			prom->left->positionX = prom->positionX - maxLevel + level;
			AddQueue(&headQ, &tail, prom->left);
		}

		if (prom->right)
		{
			prom->right->level = level + 1;
			prom->right->positionY = prom->positionY - maxLevel + level;
			prom->right->positionX = prom->positionX - maxLevel + level;
			AddQueue(&headQ, &tail, prom->right);
		}
	}

	headQ = NULL;
	tail = NULL;
	level = 0;
	char num[4]="";

	cin.ignore();

	_itoa_s(head->value, num, 3, 10);
	strcat_s(mass[head->positionY],len,num);
	num[0] = 0;
	rozr = SearchRozr(head->value);

	for (int i = rozr;i <= 3;i++)
	{
		int strl = strlen(mass[head->positionY]);
		mass[head->positionY][strl] = ' ';
		mass[head->positionY][strl + 1] = 0;
	}

	for (int i = 0;i < len;i++)
	{
		if (i != head->positionY)
		{
			for (int j = 0;j < 3;j++)
			{
				int strl = strlen(mass[i]);
				mass[i][strl] = ' ';
				mass[i][strl + 1] = 0;
			}
		}
	}

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
			for (int i = 0;i < maxLevel - level -1;i++)
			{
				for (int j = 0;j < i;j++)
				{
					int strl = strlen(mass[prom->positionY+1+i]);
					mass[prom->positionY + 1 + i][strl] = ' ';
					mass[prom->positionY + 1 + i][strl + 1] = 0;
				}

				int strl1= strlen(mass[prom->positionY + 1 + i]);
				mass[prom->positionY + 1 + i][strl1] = '\\';
				mass[prom->positionY + 1 + i][strl1 + 1] = 0;

				for (int j = i+1;j < maxLevel - level - 1;j++)
				{
					int strl = strlen(mass[prom->positionY + 1 + i]);
					mass[prom->positionY + 1 + i][strl] = ' ';
					mass[prom->positionY + 1 + i][strl + 1] = 0;
				}

				int strl2 = strlen(mass[prom->left->positionY]);
				mass[prom->left->positionY][strl2] = ' ';
				mass[prom->left->positionY][strl2 + 1] = 0;
			}
			cin.ignore();
			_itoa_s(prom->left->value, num,3, 10);
			strcat_s(mass[prom->left->positionY], len,num);
			num[0] = 0;
			rozr = SearchRozr(prom->left->value);

			for (int i = rozr;i <= 3;i++)
			{
				int strl = strlen(mass[prom->left->positionY]);
				mass[prom->left->positionY][strl] = ' ';
				mass[prom->left->positionY][strl + 1] = 0;
			}

			AddQueue(&headQ, &tail, prom->left);
		}

		if (prom->right)
		{
			for (int i = 0;i < maxLevel - level-1;i++)
			{
				for (int j = 0;j < i;j++)
				{
					int strl = strlen(mass[prom->positionY - 1 - i]);
					mass[prom->positionY - 1 - i][strl] = ' ';
					mass[prom->positionY - 1 - i][strl + 1] = 0;
				}

				int strl1 = strlen(mass[prom->positionY - 1 - i]);
				mass[prom->positionY - 1 - i][strl1] = '/';
				mass[prom->positionY - 1 - i][strl1 + 1] = 0;

				for (int j = i + 1;j < maxLevel - level;j++)
				{
					int strl = strlen(mass[prom->positionY - 1 - i]);
					mass[prom->positionY - 1 - i][strl] = ' ';
					mass[prom->positionY - 1 - i][strl + 1] = 0;
				}

				int strl2 = strlen(mass[prom->right->positionY]);
				mass[prom->right->positionY][strl2] = ' ';
				mass[prom->right->positionY][strl2 + 1] = 0;

			}

			_itoa_s(prom->right->value, num, 3, 10);
			strcat_s(mass[prom->right->positionY], len,num);
			num[0] = 0;
			rozr = SearchRozr(prom->right->value);

			for (int i = rozr;i <= 3;i++)
			{
				int strl = strlen(mass[prom->right->positionY]);
				mass[prom->right->positionY][strl] = ' ';
				mass[prom->right->positionY][strl + 1] = 0;
			}

			AddQueue(&headQ, &tail, prom->right);
		}

		for (int i = 0;i < len;i++)
		{
			if (prom->left && prom->right)
			{
				if (i != prom->left->positionY && i != prom->right->positionY)
				{
					for (int j = 0;j < 3;j++)
					{
						int strl = strlen(mass[i]);
						mass[i][strl] = ' ';
						mass[i][strl + 1] = 0;
					}
				}
			}
			else
			{
				if (prom->left)
				{
					if (i != prom->left->positionY)
					{
						for (int j = 0;j < 3;j++)
						{
							int strl = strlen(mass[i]);
							mass[i][strl] = ' ';
							mass[i][strl + 1] = 0;
						}
					}
				}

				if (prom->right)
				{
					if (i != prom->right->positionY)
					{
						for (int j = 0;j < 3;j++)
						{
							int strl = strlen(mass[i]);
							mass[i][strl] = ' ';
							mass[i][strl + 1] = 0;
						}
					}
				}
			}
		}

	}

	for (int i = 0;i < len;i++)
	{
		cout << mass[i] << endl;
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