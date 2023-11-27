// 11.03 배열 기반 스택
// ArrayBaseStack.h

#ifndef __ARRAY_BASE_STACK_H__
#define __ARRAY_BASE_STACK_H__

#define TRUE 1
#define FALSE 0
#define STACK_LEN 100

typedef int Data; // 편의상 int를 Data로, 다른 데이터 타입 넣어서 메인 함수 바꿔가면서 하면 됨

typedef struct _arrayStack
{
	Data stackArr[STACK_LEN]; // 배열을 기반으로 한 스택이므로 배열 사용, 현재 기준 int형 배열
	int topIndex; // 현재 스택의 데이터가 저장된 위치를 기억하기 위해 사용하는 top 변수, 여기서는 topindex라고 하였음
} ArrayStack;

typedef ArrayStack Stack; // 편의상 ArrayStack이라고 쓰기 뭐하니 별칭으로 Stack이라고 함

void StackInit(Stack* pstack); // 스택 초기화

int SisEmpty(Stack* pstack); // 스택이 비어있는가 아닌가 확인

void SPush(Stack* pstack, Data data); // 스택에 데이터를 저장 (일반적인 stack의 push연산)

Data SPop(Stack* pstack); // 스택에 있는 데이터를 제거, 동시에 값을 반환 (일반적인 stack의 pop연산)

Data SPeek(Stack* pstack); // 스택에 마지막으로 들어가있는 값을 확인, 제거는 하지 않음 (일반적인 stack의 peek연산)

#endif