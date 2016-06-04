#pragma once


struct TStack//структура стеку
{
	char value;//ключове поле
	TStack* prev;//покажчик на попередній елемент у стеці
};

void AddToStack(TStack** tail, char ch);//додавання стеку
char PopStack(TStack** tail);//видалення зі стеку, та повернення цього елементу
void PrintStack(TStack* tail);//вивід стеку
char PeekStack(TStack* tail);//останій елемент у стеці