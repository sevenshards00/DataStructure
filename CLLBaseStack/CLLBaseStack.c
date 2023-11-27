// 11.03 원형 리스트 기반 스택
// CLLBaseStack.c

#include <stdio.h>
#include <stdlib.h>
#include "CLLBaseStack.h"
#include "CLinkedList.h"

void StackInit(Stack* pstack) // 스택 초기화
{
	pstack->plist = (List*)malloc(sizeof(List));
	ListInit(pstack->plist);
}

int SisEmpty(Stack* pstack) // 스택 비었는가 (isEmpty)
{
	if (LCount(pstack->plist) == 0) // head가 NULL이면 스택이 비었다는 말이고
		return TRUE; // TRUE를 반환
	else // 비어있지 않다면
		return FALSE; // FALSE를 반환
}

void SPush(Stack* pstack, Data data) // push
{
	LInsertFront(pstack->plist, data);
}

Data SPop(Stack* pstack) // pop
{
	Data rData; // 지울 노드가 가지고 있는 데이터
	LFirst(pstack->plist, &rData);
	LRemove(pstack->plist);
	return rData; // 지울 노드의 데이터 반환
}

Data SPeek(Stack* pstack) // peek
{
	Data pData;
	LFirst(pstack->plist, &pData);
	return pData;
}