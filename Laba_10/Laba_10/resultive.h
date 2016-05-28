#pragma once
#include<iomanip>
#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;


struct arryass
{
	char value[100];

	arryass* next;
};

void CreateTXT(arryass**);