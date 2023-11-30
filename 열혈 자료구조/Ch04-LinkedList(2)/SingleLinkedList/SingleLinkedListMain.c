/*
* ���� �ڷᱸ�� - ���� ���� ����Ʈ (���� ��� ���)
* ���ϸ�: SingleLinkedListMain.c
* ���� ����: 0.3
* �ۼ���: Sevenshards
* �ۼ� ����: 2023-11-30
* ���� ���� �ۼ� ����: 2023-11-29
* ���� ����: ���� ���� ���� �߰�
* ���� ���� ����: �ؽ� �浹 ���� �ذ��� ���� ü�̴� ��� ����
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "SingleLinkedList.h"

// �켱���� �񱳸� ���� �Լ� ����
int WhoIsPrecede(int d1, int d2)
{
	// �������� ����
	if (d1 < d2)
		return 0; // d1�� ���� ������ �ռ���
	else
		return 1; // d2�� ���� ������ �ռ��ų� ����
}

int main()
{
	// ����Ʈ ���� �� �ʱ�ȭ
	List list;
	int data;
	ListInit(&list);

	SetSortRule(&list, WhoIsPrecede); // ������ ���� ���

	// ������ 5�� �Է�
	LInsert(&list, 11);
	LInsert(&list, 11);
	LInsert(&list, 22);
	LInsert(&list, 22);
	LInsert(&list, 33);

	// ����� ������ ���� ��� �� ��ü ������ ���
	printf("Stored Data Count: %d\n", LCount(&list));

	if (LFirst(&list, &data))
		printf("%d ", data);
	while (LNext(&list, &data))
		printf("%d ", data);

	printf("\n\n");

	// ���� 22�� ã�Ƽ� ����
	if (LFirst(&list, &data))
	{
		if (data == 22)
			LRemove(&list);

		while (LNext(&list, &data))
		{
			if (data == 22)
				LRemove(&list);
		}
	}

	// ���� �� ���� ������ �� ��ȸ �� ��ü ������ ���
	printf("Stored Data Count: %d\n", LCount(&list));

	if (LFirst(&list, &data))
		printf("%d ", data);
	while (LNext(&list, &data))
		printf("%d ", data);

	printf("\n\n");
	return 0;
}