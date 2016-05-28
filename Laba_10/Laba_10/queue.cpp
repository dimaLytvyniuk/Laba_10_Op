#include "stdafx.h"
#include "queue.h"

void AddQueue(TQueue **head,TQueue** tail, char c)
{
	TQueue *current = new TQueue;
	current->value = c;
	current->next = NULL;

	if (*tail)
		(*tail)->next = current;
	else
		(*head) = current;

	(*tail) = current;
}

char PopQueue(TQueue** head,TQueue** tail)
{
	char ch;

	if (*head)
	{
		ch = (*head)->value;
		TQueue *temp = (*head);
		(*head) = (*head)->next;
		delete temp;

		if (!(*head))
			tail = NULL;

		return ch;
	}
	else
		return NULL;
}

void PrintQueue(TQueue* head)
{
	while (head)
	{
		cout << head->value;
		head = head->next;
	}

	cout << endl;
}