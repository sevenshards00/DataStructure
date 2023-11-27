// 11.02 SingleLinkedList ���� 2ȸ��
// SingleLinkedListMain.c
//
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "SingleLinkedList.h"

int main()
{
	// ����Ʈ ���� �� �ʱ�ȭ
	List list;
	int data;
	ListInit(&list);

	// ������ 5�� �Է�
	LInsert(&list, 11);
	LInsert(&list, 22);
	LInsert(&list, 33);
	LInsert(&list, 44);
	LInsert(&list, 55);

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