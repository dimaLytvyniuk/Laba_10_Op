#pragma once
#include "tree.h"

struct TQueue
{
	TQueue(){

	}

	TREE* value;
	TQueue* next;
};

void AddQueue(TQueue **head, TQueue** tail, TREE* c);
TREE* PopQueue(TQueue** head, TQueue** tail);
void PrintQueue(TQueue* head);