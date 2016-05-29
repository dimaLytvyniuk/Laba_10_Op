#pragma once


struct TStack
{
	char value;
	TStack* prev;
};

void AddToStack(TStack** tail, char ch);
char PopStack(TStack** tail);
void PrintStack(TStack* tail);
char PeekStack(TStack* tail);