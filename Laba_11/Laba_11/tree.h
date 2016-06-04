#pragma once



struct TREE//структура дерева
{
	int value;//ключове поле
	int level=0;//рівень у дереві
	int positionX = 0;//позиція по горизонталі
	int positionY = 0;//позиція по вертикалі
	TREE* left;//покажчик на ліве піддерево
	TREE* right;//покажчик на праве піддерево
};

bool AddToTree(TREE** head, int value);//додавання до дерева
void PrintTree(TREE* head);//вивід дерева
void PaintTree(TREE* head);//друкування дерева
int SearchRozr(int value);//пошук розрядності числа
int SearchMax(TREE* head);//пошук максимального елемента у дереві
