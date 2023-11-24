/*
* 선형 자료구조 - 연결 리스트 기반 Stack
* 파일명: ListBaseStack.c
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2023-11-23
* 이전 버전 작성 일자:
* 버전 내용: 스택의 기본적인 ADT 구현
* 이전 버전 내용:
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