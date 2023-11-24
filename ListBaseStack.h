/*
* 선형 자료구조 - 연결 리스트 기반 Stack
* 파일명: ListBaseStack.h
* 파일 버전: 0.11
* 작성자: Sevenshards
* 작성 일자: 2023-11-24
* 이전 버전 작성 일자: 2023-11-23
* 버전 내용: 수식 트리 구현에 맞게 typedef한 데이터형을 변경
* 이전 버전 내용: 스택의 기본적인 ADT 구현
*/

#include "BinaryTree.h"

#ifndef __LIST_BASE_STACK_H__
#define __LIST_BASE_STACK_H__

#define TRUE 1
#define FALSE 0

typedef BTreeNode* Data; // 스택에 담기는 데이터 유형이 노드의 주소값을 담아야 함

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