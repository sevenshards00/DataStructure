// 11.03 원형 리스트 기반 스택
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

void StackInit(Stack* pstack); // 스택 초기화

int SisEmpty(Stack* pstack); // 스택 비었는가 (isEmpty)

void SPush(Stack* pstack, Data data); // push

Data SPop(Stack* pstack); // pop

Data SPeek(Stack* pstack); // peek

#endif