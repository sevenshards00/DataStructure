/*
* ���� �ڷᱸ�� - ���� ����Ʈ ��� Stack
* ���ϸ�: ListBaseStack.h
* ���� ����: 0.11
* �ۼ���: Sevenshards
* �ۼ� ����: 2023-11-24
* ���� ���� �ۼ� ����: 2023-11-23
* ���� ����: ���� Ʈ�� ������ �°� typedef�� ���������� ����
* ���� ���� ����: ������ �⺻���� ADT ����
*/

#include "BinaryTree.h"

#ifndef __LIST_BASE_STACK_H__
#define __LIST_BASE_STACK_H__

#define TRUE 1
#define FALSE 0

typedef BTreeNode* Data; // ���ÿ� ���� ������ ������ ����� �ּҰ��� ��ƾ� ��

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

void StackInit(Stack* pstack);

int SisEmpty(Stack* pstack);

void SPush(Stack* pstack, Data data);

Data SPop(Stack* pstack);

Data SPeek(Stack* pstack);

#endif