#include "stdafx.h"
#include "queue.h"
#include<iomanip>
#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

void AddQueue(TQueue **head,TQueue** tail, TREE* c)
{
	TQueue *current = new TQueue;
	current->value = c;
	current->next = NULL;

	if (*tail)
		(*tail)->next = current;
	else
	{
		(*head) = current;
	}

	(*tail) = current;
}

TREE* PopQueue(TQueue** head,TQueue** tail)
{
	TREE* ch;

	if (*head)
	{
		ch = (*head)->value;
		TQueue *temp = (*head);
		(*head) = (*head)->next;
		delete temp;

		if (!(*head))
			(*tail) = NULL;

		return ch;
	}
	else
		return NULL;
}

/*
void PrintQueue(TQueue* head)
{
	while (head)
	{
		cout << head->value;
		head = head->next;
	}

	cout << endl;
}
*/