// 11.03 배열 기반 스택
// ArrayBaseStack.c

#include <stdio.h>
#include <stdlib.h>
#include "ArrayBaseStack.h"

void StackInit(Stack* pstack) // 스택 초기화
{
	pstack->topIndex = -1; // 배열이므로 현재 가리키는 인덱스는 -1로.
}
int SisEmpty(Stack* pstack) // 스택이 비어있는가 아닌가 확인
{
	if (pstack->topIndex == -1) // 스택이 비어있다면
		return TRUE;
	else
		return FALSE;
}

void SPush(Stack* pstack, Data data) // 스택에 데이터를 저장 (일반적인 stack의 push연산)
{
	pstack->topIndex += 1; // 인덱스를 하나 증가시키고
	pstack->stackArr[pstack->topIndex] = data; // 스택(배열)에 데이터를 저장
}


Data SPop(Stack* pstack) // 스택에 있는 데이터를 제거, 동시에 값을 반환 (일반적인 stack의 pop연산)
{
	int rIdx; // 지워질 인덱스 값, 왜 처음부터 초기화를 안했는가?

	if (SisEmpty(pstack)) // 먼저 스택이 비어있는가 아닌가를 확인
	{
		printf("Stack is Empty!"); // 비어있다면 다음을 화면에 출력하고
		exit(-1); // 종료, 참고로 exit 함수는 stdlib.h에 있다
	}

	rIdx = pstack->topIndex; // 지워질 인덱스 값을 현재 스택의 topIndex 값을 주고
	pstack->topIndex -= 1; // 인덱스 값을 하나 감소시킨다.

	return pstack->stackArr[rIdx]; // 현재 지워질 인덱스가 가진 값을 반환하며 종료.
}


Data SPeek(Stack* pstack) // 스택에 마지막으로 들어가있는 값을 확인, 제거는 하지 않음 (일반적인 stack의 peek연산)
{
	// pop 연산과 거의 동일함, 하지만 스택의 마지막 데이터는 지우지 않는 것이 포인트.
	if (SisEmpty(pstack)) // 먼저 스택이 비어있는가 아닌가를 확인
	{
		printf("Stack is Empty!"); // 비어있다면 다음을 화면에 출력하고
		exit(-1); // 종료, 참고로 exit 함수는 stdlib.h에 있다
	}
	return pstack->stackArr[pstack->topIndex]; // 현재 topIndex가 가진 값을 반환하며 종료.
}