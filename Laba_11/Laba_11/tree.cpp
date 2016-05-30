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

int SearchRozr(int value)
{
	int res = 0;

	if (value < 0)
		res++;

	while (value > 0)
	{
		value = value/10;
		res++;
	}
}
*/

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

int SearchMax(TREE* head)
{
	int res = head->value;

	if (head->right != NULL)
	{
		res = SearchMax(head->right);
	}

	return res;
}