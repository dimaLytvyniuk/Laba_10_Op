#include "stdafx.h"
#include "resultive.h"
#include<iomanip>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <conio.h>

using namespace std;

FILE *f;



void CraeteFile()
{
	char str[100];
	fopen_s(&f,"main.txt", "wt");

	printf_s("Input data to file\n\n");
	gets_s(str);

	while (_stricmp(str, "\0"))
	{
		fputs(str, f);
		fputc('\n', f);
		gets_s(str);
	}

	fclose(f);
}

void PrintFile()
{
	system("cls");

	char str[100];

	printf("Text in file\n\n");

	fopen_s(&f, "main.txt", "rt");

	while (!feof(f))
	{
		str[0]=0;
		fgets(str, 100, f);
		printf("%s",str);
		
	}

	fclose(f);
}

bool Proverka()
{
	char str[100];
	TStack* tail = NULL;
	bool res = true;
	int count = 0;
	fopen_s(&f, "main.txt", "rt");

	while (!feof(f))
	{
		count = 0;
		str[0] = 0;
		fgets(str, 100, f);

		for (int i = 0;i < strlen(str);i++)
		{
			if ((str[i] == '{') || (str[i] == '(') || (str[i] == '['))
			{
				AddToStack(&tail, str[i]);
				count++;
			}
			else
			{  
				if ((str[i] == ')') || (str[i] == '}') || (str[i] == ']'))
				{
					if (((str[i] == '}') && (PeekStack(tail) == '{')) || ((str[i] == ')') && (PeekStack(tail) == '(')) || ((str[i] == ']') && (PeekStack(tail) == '[')))
					{
						PopStack(&tail);
						count--;
					}
					else
					{
						res = false;
						return res;
					}
				}
			}
		}

		if (count != 0)
			return false;
	}

	fclose(f);
	return res;
}

void CreateResult()
{
	char str[100],
		prom[100];
	TStack* tail = NULL;
	bool fl = Proverka();

	fopen_s(&f, "main.txt", "rt");


	prom[0] = 0;

	if (fl)
	{
		printf("\n\nText in brackets: \n\n");

		while (!feof(f))
		{
			str[0] = 0;
			fgets(str, 100, f);

			for (int i = 0;i < strlen(str);i++)
			{
				if ((str[i] == '{') || (str[i] == '(') || (str[i] == '['))
				{

					i += AnalizStrok(str, i, prom);
					prom[0] = 0;
				}
			}
		}
	}
	else
	{
		printf("\n\nProblem with count of brackets");
	}

	fclose(f);
	_getch();

}

int AnalizStrok(char input[100], int pos,char out[100])
{
	char ch = input[pos],
		prom[100];
	int count = 0;

	prom[0] = 0;

	TQueue* head = NULL,
		*tailQueue = NULL;

	AddQueue(&head, &tailQueue, ch);

	for (int i = pos+1;i < strlen(input);i++)
	{
		
		if ((input[i] == '{') || (input[i] == '(') || (input[i] == '['))
		{
			i=AnalizStrok(input, i, prom);

			for (int j = 0;j < strlen(prom);j++)
				AddQueue(&head, &tailQueue, prom[j]);

			prom[0] = 0;
		}
		else
		{
			if ((input[i] == '}') || (input[i] == ')') || (input[i] == ']'))
			{
				AddQueue(&head, &tailQueue, input[i]);
				count = i;
				break;
			}
			else
			{
				AddQueue(&head, &tailQueue, input[i]);
			}
		}
	}

	while (head)
	{
		int strl = strlen(out);
		out[strl]= PopQueue(&head, &tailQueue);
		out[strl+1] = 0;
	}

	printf("%s\n", out);
	return count;
}