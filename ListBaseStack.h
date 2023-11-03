// 11.03 리스트 기반 스택
// ListBaseStack.h

#ifndef __LIST_STACK_H__
#define __LIST_STACK_H__

#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct _node
{
	Data data;
	struct _node* next;
} Node;

typedef struct _liststack
{
	Node* head;
} ListStack;

typedef ListStack Stack;

void StackInit(Stack* pstack); // 스택 초기화

int SisEmpty(Stack* pstack); // 스택 비었는가 (isEmpty)

void SPush(Stack* pstack, Data data); // push

Data SPop(Stack* pstack); // pop

Data SPeek(Stack* pstack); // peek

#endif
