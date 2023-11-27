/*
* ���� �ڷᱸ�� - ���� ����Ʈ ��� Stack ���� v0.3
* ���ϸ�: ListBaseStack.h
* ���� ����: 0.1
* �ۼ���: Sevenshards
* �ۼ� ����: 2023-11-23
* ���� ���� �ۼ� ����:
* ���� ����: ���� ǥ����� ���� ǥ������� �ٲٴ� ���α׷��� ����
* ���� ���� ����:
*/

#include <stdio.h>
#include <stdlib.h>
#include "ListBaseStack.h"

void StackInit(Stack* pstack)
{
	pstack->head = NULL;
}

int SisEmpty(Stack* pstack)
{
	if (pstack->head == NULL)
		return TRUE;
	else
		return FALSE;
}

void SPush(Stack* pstack, Data data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;

	newNode->next = pstack->head;
	pstack->head = newNode;
}

Data SPop(Stack* pstack)
{
	Node* pNode;
	Data pData;

	if (SisEmpty(pstack))
	{
		printf("Stack is Empty\n");
		exit(-1);
	}

	pNode = pstack->head;
	pData = pNode->data;

	pstack->head = pstack->head->next;

	free(pNode);
	return pData;
}

Data SPeek(Stack* pstack)
{
	if (SisEmpty(pstack))
	{
		printf("Stack is Empty\n");
		exit(-1);
	}

	return pstack->head->data;
}