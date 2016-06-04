#pragma once


struct TQueue//структура чергчи
{
	TQueue(){

	}

	char value;//ключове поле
	TQueue* next;//покажчик на наступний елемент у черзі
};

void AddQueue(TQueue **head, TQueue** tail, char c);//додавання у кінець черги
char PopQueue(TQueue** head, TQueue** tail);// видалення з черги, та повернення цього елементу
void PrintQueue(TQueue* head);//друкування черги