// 11.03 �迭 ��� ����
// ArrayBaseStack.c

#include <stdio.h>
#include <stdlib.h>
#include "ArrayBaseStack.h"

void StackInit(Stack* pstack) // ���� �ʱ�ȭ
{
	pstack->topIndex = -1; // �迭�̹Ƿ� ���� ����Ű�� �ε����� -1��.
}
int SisEmpty(Stack* pstack) // ������ ����ִ°� �ƴѰ� Ȯ��
{
	if (pstack->topIndex == -1) // ������ ����ִٸ�
		return TRUE;
	else
		return FALSE;
}

void SPush(Stack* pstack, Data data) // ���ÿ� �����͸� ���� (�Ϲ����� stack�� push����)
{
	pstack->topIndex += 1; // �ε����� �ϳ� ������Ű��
	pstack->stackArr[pstack->topIndex] = data; // ����(�迭)�� �����͸� ����
}


Data SPop(Stack* pstack) // ���ÿ� �ִ� �����͸� ����, ���ÿ� ���� ��ȯ (�Ϲ����� stack�� pop����)
{
	int rIdx; // ������ �ε��� ��, �� ó������ �ʱ�ȭ�� ���ߴ°�?

	if (SisEmpty(pstack)) // ���� ������ ����ִ°� �ƴѰ��� Ȯ��
	{
		printf("Stack is Empty!"); // ����ִٸ� ������ ȭ�鿡 ����ϰ�
		exit(-1); // ����, ����� exit �Լ��� stdlib.h�� �ִ�
	}

	rIdx = pstack->topIndex; // ������ �ε��� ���� ���� ������ topIndex ���� �ְ�
	pstack->topIndex -= 1; // �ε��� ���� �ϳ� ���ҽ�Ų��.

	return pstack->stackArr[rIdx]; // ���� ������ �ε����� ���� ���� ��ȯ�ϸ� ����.
}


Data SPeek(Stack* pstack) // ���ÿ� ���������� ���ִ� ���� Ȯ��, ���Ŵ� ���� ���� (�Ϲ����� stack�� peek����)
{
	// pop ����� ���� ������, ������ ������ ������ �����ʹ� ������ �ʴ� ���� ����Ʈ.
	if (SisEmpty(pstack)) // ���� ������ ����ִ°� �ƴѰ��� Ȯ��
	{
		printf("Stack is Empty!"); // ����ִٸ� ������ ȭ�鿡 ����ϰ�
		exit(-1); // ����, ����� exit �Լ��� stdlib.h�� �ִ�
	}
	return pstack->stackArr[pstack->topIndex]; // ���� topIndex�� ���� ���� ��ȯ�ϸ� ����.
}