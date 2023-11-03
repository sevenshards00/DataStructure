// 11.03 ���� ����Ʈ ��� ����
// CLLBaseStack.c

#include <stdio.h>
#include <stdlib.h>
#include "CLLBaseStack.h"
#include "CLinkedList.h"

void StackInit(Stack* pstack) // ���� �ʱ�ȭ
{
	pstack->plist = (List*)malloc(sizeof(List));
	ListInit(pstack->plist);
}

int SisEmpty(Stack* pstack) // ���� ����°� (isEmpty)
{
	if (LCount(pstack->plist) == 0) // head�� NULL�̸� ������ ����ٴ� ���̰�
		return TRUE; // TRUE�� ��ȯ
	else // ������� �ʴٸ�
		return FALSE; // FALSE�� ��ȯ
}

void SPush(Stack* pstack, Data data) // push
{
	LInsertFront(pstack->plist, data);
}

Data SPop(Stack* pstack) // pop
{
	Data rData; // ���� ��尡 ������ �ִ� ������
	LFirst(pstack->plist, &rData);
	LRemove(pstack->plist);
	return rData; // ���� ����� ������ ��ȯ
}

Data SPeek(Stack* pstack) // peek
{
	Data pData;
	LFirst(pstack->plist, &pData);
	return pData;
}