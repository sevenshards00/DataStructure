/*
* 선형 자료구조 - 연결 리스트 기반 Stack 계산기 v0.2
* 파일명: ListBaseStack.h
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2023-11-23
* 이전 버전 작성 일자: 
* 버전 내용: 중위 표기법을 후위 표기법으로 바꾸는 프로그램의 구현
* 이전 버전 내용: 
*/

#ifndef __LIST_BASE_STACK_H__
#define __LIST_BASE_STACK_H__

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

void StackInit(Stack* pstack);

int SisEmpty(Stack* pstack);

void SPush(Stack* pstack, Data data);

Data SPop(Stack* pstack);

Data SPeek(Stack* pstack);

#endif