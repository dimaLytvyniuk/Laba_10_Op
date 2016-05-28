#include "stdafx.h"
#include "resultive.h"


void CreateTXT(arryass** head)
{
	char str[100];
	(*head)->next = NULL;

	cout << "Input text: ";

	gets_s(str);

	while (_stricmp(str, "\0"))
	{
		strcpy_s(((*head)->value), str);


	}


}