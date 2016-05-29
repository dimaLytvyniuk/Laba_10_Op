#pragma once



struct TREE
{
	int value;
	TREE* left;
	TREE* right;
};

bool AddToTree(TREE** head, int value);
void PrintTree(TREE* head);
void PainTree(TREE* head);
int SearchRozr(int value);
void PainTreeFinish(TREE* head, int pos);