#pragma once



struct TREE//��������� ������
{
	int value;//������� ����
	int level=0;//����� � �����
	int positionX = 0;//������� �� ����������
	int positionY = 0;//������� �� ��������
	TREE* left;//�������� �� ��� ��������
	TREE* right;//�������� �� ����� ��������
};

bool AddToTree(TREE** head, int value);//��������� �� ������
void PrintTree(TREE* head);//���� ������
void PaintTree(TREE* head);//���������� ������
int SearchRozr(int value);//����� ���������� �����
int SearchMax(TREE* head);//����� ������������� �������� � �����
