#pragma once

#include "resultive.h"
#include "stdafx.h"
#include<iomanip>
#include <stdio.h>
#include <iostream>

struct TStack
{
	char value;
	TStack* prev;
};

void AddToStack(TStack** tail, char ch);
char PopStack(TStack** tail);
void PrintStack(TStack* tail);