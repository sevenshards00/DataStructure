// 11.03 �迭 ��� ����
// ArrayBaseStackMain.c

#include <stdio.h>
#include "ArrayBaseStack.h"

int main()
{
	// ���� ���� �� �ʱ�ȭ
	Stack stack;
	StackInit(&stack);

	// ������ ����
	SPush(&stack, 1);
	SPush(&stack, 2);
	SPush(&stack, 3);
	SPush(&stack, 4);
	SPush(&stack, 5);

	while (!SisEmpty(&stack))
		printf("%d�� pop �Ǿ����ϴ�.\n", SPop(&stack));

	return 0;
}