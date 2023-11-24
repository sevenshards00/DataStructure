/*
* ���� �ڷᱸ�� - �迭 ����� ��(Heap)
* ���ϸ�: HeapMain.c
* ���� ����: 0.1
* �ۼ���: Sevenshards
* �ۼ� ����: 2023-11-24
* ���� ���� �ۼ� ����:
* ���� ����: ������ ���� ����
* ���� ���� ����:
*/
#include <stdio.h>
#include "Heap.h"

int main()
{
	Heap heap;
	HeapInit(&heap); // �� �ʱ�ȭ

	HInsert(&heap, 'A', 1); // ���� 'A'�� ���� ���� ���� �켱 ������ ����
	HInsert(&heap, 'B', 2); // ���� 'B'�� ���� �� ��° �켱 ������ ����
	HInsert(&heap, 'C', 3); // ���� 'C'�� ���� ���� ���� �켱 ������ ����
	printf("%c \n", HDelete(&heap)); // Heap���� �����Ǵ� ���� Ȯ��

	// 2ȸ�� ����
	HInsert(&heap, 'A', 1); // ���� 'A'�� ���� ���� ���� �켱 ������ ����
	HInsert(&heap, 'B', 2); // ���� 'B'�� ���� �� ��° �켱 ������ ����
	HInsert(&heap, 'C', 3); // ���� 'C'�� ���� ���� ���� �켱 ������ ����
	printf("%c \n", HDelete(&heap)); // Heap���� �����Ǵ� ���� Ȯ��

	while (!HisEmpty(&heap))
		printf("%c \n", HDelete(&heap)); // Heap���� �����Ǵ� ���� Ȯ��

	return 0;
}