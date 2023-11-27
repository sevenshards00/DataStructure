// 11.03 배열 기반 스택
// ArrayBaseStackMain.c

#include <stdio.h>
#include "ArrayBaseStack.h"

int main()
{
	// 스택 선언 및 초기화
	Stack stack;
	StackInit(&stack);

	// 데이터 삽입
	SPush(&stack, 1);
	SPush(&stack, 2);
	SPush(&stack, 3);
	SPush(&stack, 4);
	SPush(&stack, 5);

	while (!SisEmpty(&stack))
		printf("%d가 pop 되었습니다.\n", SPop(&stack));

	return 0;
}