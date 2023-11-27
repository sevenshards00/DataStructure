// 11.03 �迭 ��� ����
// ArrayBaseStack.h

#ifndef __ARRAY_BASE_STACK_H__
#define __ARRAY_BASE_STACK_H__

#define TRUE 1
#define FALSE 0
#define STACK_LEN 100

typedef int Data; // ���ǻ� int�� Data��, �ٸ� ������ Ÿ�� �־ ���� �Լ� �ٲ㰡�鼭 �ϸ� ��

typedef struct _arrayStack
{
	Data stackArr[STACK_LEN]; // �迭�� ������� �� �����̹Ƿ� �迭 ���, ���� ���� int�� �迭
	int topIndex; // ���� ������ �����Ͱ� ����� ��ġ�� ����ϱ� ���� ����ϴ� top ����, ���⼭�� topindex��� �Ͽ���
} ArrayStack;

typedef ArrayStack Stack; // ���ǻ� ArrayStack�̶�� ���� ���ϴ� ��Ī���� Stack�̶�� ��

void StackInit(Stack* pstack); // ���� �ʱ�ȭ

int SisEmpty(Stack* pstack); // ������ ����ִ°� �ƴѰ� Ȯ��

void SPush(Stack* pstack, Data data); // ���ÿ� �����͸� ���� (�Ϲ����� stack�� push����)

Data SPop(Stack* pstack); // ���ÿ� �ִ� �����͸� ����, ���ÿ� ���� ��ȯ (�Ϲ����� stack�� pop����)

Data SPeek(Stack* pstack); // ���ÿ� ���������� ���ִ� ���� Ȯ��, ���Ŵ� ���� ���� (�Ϲ����� stack�� peek����)

#endif