// 11.03 ����Ʈ ��� ����
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

void StackInit(Stack* pstack); // ���� �ʱ�ȭ

int SisEmpty(Stack* pstack); // ���� ����°� (isEmpty)

void SPush(Stack* pstack, Data data); // push

Data SPop(Stack* pstack); // pop

Data SPeek(Stack* pstack); // peek

#endif
