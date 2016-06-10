#pragma once



struct TREE
{
	int value;
	int level=0;
	int positionX = 0;
	int positionY = 0;
	TREE* left;
	TREE* right;
};

bool AddToTree(TREE** head, int value);
//void PrintTree(TREE* head);
void PaintTree(TREE* head);
int SearchRozr(int value);
void PainTreeFinish(TREE* head, int pos);
int SearchMax(TREE* head);
int SearchRozr(int value);
void CreateTreeFile();
void AddProgressive(TREE** head, int value);