// 11.02 ���� ���� ����Ʈ
// DBLinkedList.h

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "DBLinkedList.h"

int main()
{
	// ����Ʈ ���� �� �ʱ�ȭ
	List list;
	int data;
	ListInit(&list);

	// ��� 8�� ����
	LInsert(&list, 1);
	LInsert(&list, 2);
	LInsert(&list, 3);
	LInsert(&list, 4);
	LInsert(&list, 5);
	LInsert(&list, 6);
	LInsert(&list, 7);
	LInsert(&list, 8);

	// �� ù��° �����͸� �а�
	if (LFirst(&list, &data))
	{
		printf("%d ", data);

		// ������(������)���� ������ ��ȸ
		while (LNext(&list, &data))
			printf("%d ", data);

		// ����(������)���� ������ ��ȸ
		while (LPrev(&list, &data))
			printf("%d ", data);
	}
	printf("\n\n");

	// ������ ���� ����
	// �� ù��° �����͸� �а�
	if (LFirst(&list, &data))
	{
		if (data == 1 || data == 3 || data == 5 || data ==8)
			LRemove(&list);

		// ������(������)���� ������ ��ȸ
		while (LNext(&list, &data))
		{
			if (data == 1 || data == 3 || data == 5 || data == 8)
				LRemove(&list);
		}
		// ����(������)���� ������ ��ȸ
		while (LPrev(&list, &data))
		{
			if (data == 1 || data == 3 || data == 5 || data == 8)
				LRemove(&list);
		}
	}
	printf("\n\n");

	// ���� �� ���� ��� Ȯ��
	// �� ù��° �����͸� �а�
	if (LFirst(&list, &data))
	{
		printf("%d ", data);

		// ������(������)���� ������ ��ȸ
		while (LNext(&list, &data))
			printf("%d ", data);

		// ����(������)���� ������ ��ȸ
		while (LPrev(&list, &data))
			printf("%d ", data);
	}
	printf("\n\n");

	return 0;
}