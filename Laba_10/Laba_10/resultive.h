#pragma once
#include "stdafx.h"
#include "stack.h"
#include "queue.h"


void CraeteFile();//створення файлу
void PrintFile();//друкування файлу
bool Proverka();//перевірка на відповідність дужок
void CreateResult();//вивід тексту між кожними дужками
int AnalizStrok(char input[100], int pos, char out[100]);//текст між дужок
