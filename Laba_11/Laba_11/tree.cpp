#include "stdafx.h"
#include "tree.h"
#include<iomanip>
#include <stdio.h>
#include <iostream>
#include <conio.h>

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

/*
void PrintTree(TREE* head)
{
	if (head != NULL)
	{
		printf("%4d",head->value);
		PrintTree(head->left);
		PrintTree(head->right);
	}
}



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