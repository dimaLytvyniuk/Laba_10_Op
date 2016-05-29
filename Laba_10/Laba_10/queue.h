#pragma once


struct TQueue
{
	TQueue(){

	}

	char value;
	TQueue* next;
};

void AddQueue(TQueue **head, TQueue** tail, char c);
char PopQueue(TQueue** head, TQueue** tail);
void PrintQueue(TQueue* head);