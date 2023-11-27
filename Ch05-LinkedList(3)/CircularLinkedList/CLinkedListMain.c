// 11.02 ���� ��ũ�� ����Ʈ
// CLinkedListMain.c
//
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "CLinkedList.h"

int main()
{
	// ����Ʈ ���� �� �ʱ�ȭ
	List list;
	int data, i, nodeNum;
	ListInit(&list);

	// ����Ʈ�� ������ ����
	// tail������ ����
	LInsert(&list, 3);
	LInsert(&list, 4);
	LInsert(&list, 5);
	// head������ ����
	LInsertFront(&list, 2);
	LInsertFront(&list, 1);

	// ������ 3ȸ ���� ���
	if (LFirst(&list, &data))
	{
		printf("%d ", data);

		for (i = 0; i < (LCount(&list)) * 3 - 1; i++)
		{
			if (LNext(&list, &data))
				printf("%d ", data);
		}
	}
	printf("%\n\n");

	// 2�� ����� ã�Ƽ� ����
	nodeNum = LCount(&list);

	// ��尡 �ϳ��� ���°� �ƴ϶��
	if (nodeNum != 0)
	{
		LFirst(&list, &data);
		if (data % 2 == 0)
			LRemove(&list);

		for (i = 0; i < nodeNum - 1; i++)
		{
			LNext(&list, &data);
			if (data % 2 == 0)
				LRemove(&list);
		}
	}

	// ���������� ��ü ������ ���
	if (LFirst(&list, &data))
	{
		printf("%d ", data);

		for (i = 0; i < (LCount(&list)) - 1; i++)
		{
			if (LNext(&list, &data))
				printf("%d ", data);
		}
	}
	printf("%\n\n");

	return 0;
}