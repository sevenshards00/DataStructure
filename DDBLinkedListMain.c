// 11.02 ���� ���� ����Ʈ
// DBLinkedList.h

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "DDBLinkedList.h"

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
		printf("������(head to tail)\n");
		printf("%d ", data);

		// ������(������)���� ������ ��ȸ
		while (LNext(&list, &data))
			printf("%d ", data);

		printf("\n");
		printf("������(tail to head)\n");
		// ����(������)���� ������ ��ȸ
		while (LPrev(&list, &data))
			printf("%d ", data);
	}
	printf("\n\n");

	// ������ ���� ����
	// �� ù��° �����͸� �а�
	if (LFirst(&list, &data))
	{
		printf("1,3,5,8�� ���� ��带 ���� �� �ٽ� �����͸� ��ȸ�մϴ�.\n");
		printf("������(head to tail)���� ��ȸ�ϸ� ��� ���Ÿ� �����մϴ�.\n");
		if (data == 1 || data == 3 || data == 5 || data == 8)
			printf("%d �����͸� ���� ��带 �����߽��ϴ�.\n", LRemove(&list));
			

		// ������(������)���� ������ ��ȸ
		while (LNext(&list, &data))
		{
			if (data == 1 || data == 3 || data == 5 || data == 8)
				printf("%d �����͸� ���� ��带 �����߽��ϴ�.\n", LRemove(&list));
		}

		printf("������ ������(tail to head)���� ��ȸ�ϸ� ��� ���Ÿ� �����մϴ�.\n");
		printf("�տ��� ��� ���Ÿ� ���������Ƿ� ��� ������ ���õ� �޽����� ������ �ȵ˴ϴ�.\n");
		// ����(������)���� ������ ��ȸ
		while (LPrev(&list, &data))
		{
			if (data == 1 || data == 3 || data == 5 || data == 8)
				printf("%d �����͸� ���� ��带 �����߽��ϴ�.\n", LRemove(&list));
		}
	}
	printf("\n\n");

	// ���� �� ���� ��� Ȯ��
	// �� ù��° �����͸� �а�
	if (LFirst(&list, &data))
	{
		printf("������(head to tail)\n");
		printf("%d ", data);

		// ������(������)���� ������ ��ȸ
		while (LNext(&list, &data))
			printf("%d ", data);

		printf("\n");
		printf("������(tail to head)\n");
		// ����(������)���� ������ ��ȸ
		while (LPrev(&list, &data))
			printf("%d ", data);
	}
	printf("\n\n");

	return 0;
}