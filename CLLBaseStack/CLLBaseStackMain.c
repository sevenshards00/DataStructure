// 11.03 원형 리스트 기반 스택
// ListBaseStack.c

#include <stdio.h>
#include "CLinkedList.h"
#include "CLLBaseStack.h"

int main()
{
	Stack stack;
	StackInit(&stack);

	SPush(&stack, 1);
	SPush(&stack, 2);
	SPush(&stack, 3);
	SPush(&stack, 4);
	SPush(&stack, 5);

	while (!SisEmpty(&stack))
		printf("%d가 pop 되었습니다.\n", SPop(&stack));

	return 0;
}