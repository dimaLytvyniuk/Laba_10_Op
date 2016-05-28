#include "stdafx.h"
#include "stack.h"

void AddToStack(TStack** tail,char ch)
{
	TStack* current =new TStack;

	current->value = ch;

	if (!(*tail))
		current->prev = NULL;
	else
		current->prev = (*tail);

	(*tail) = current;
}

char PopStack(TStack** tail)
{
	char ch;

	if ((*tail))
	{
		TStack* current = new TStack;
		current = (*tail);
		ch = current->value;

		(*tail) = (*tail)->prev;
		delete current;

		return ch;
	}
	else
		return NULL;
}

void PrintStack(TStack* tail)
{
	while (tail)
	{
		cout << tail->value;
		tail = tail->prev;
	}

	cout << endl;
}