// 11.03 ���� ����Ʈ ��� ����
// CLLBaseStack.h

#ifndef __LIST_STACK_H__
#define __LIST_STACK_H__

#define TRUE 1
#define FALSE 0

#include "CLinkedList.h"

typedef struct _liststack
{
	List* plist;
} ListStack;

typedef ListStack Stack;

void StackInit(Stack* pstack); // ���� �ʱ�ȭ

int SisEmpty(Stack* pstack); // ���� ����°� (isEmpty)

void SPush(Stack* pstack, Data data); // push

Data SPop(Stack* pstack); // pop

Data SPeek(Stack* pstack); // peek

#endif