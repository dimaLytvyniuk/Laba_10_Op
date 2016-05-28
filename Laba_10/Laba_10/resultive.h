#pragma once
#include<iomanip>
#include <stdio.h>
#include <iostream>
#include "stack.h"
#include "queue.h"
#include <string.h>

using namespace std;

const int n = 20;

struct arryass
{
	char value[100];

	arryass* next;
};

void CreateTXT(arryass**);