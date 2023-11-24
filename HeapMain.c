/*
* ���� �ڷᱸ�� - �迭 ����� ��(Heap)
* ���ϸ�: HeapMain.c
* ���� ����: 0.2
* �ۼ���: Sevenshards
* �ۼ� ����: 2023-11-24
* ���� ���� �ۼ� ����: 2023-11-24
* ���� ����: �켱 ���� �Ǵ� ������ ���� ������ �� �ֵ��� �Լ� �����ͷ� ����
* ���� ���� ����: ������ ���� ����
*/
#include <stdio.h>
#include "Heap.h"

int DataPriorityComp(char ch1, char ch2)
{
	return ch2 - ch1;
}

int main()
{
	Heap heap;
	HeapInit(&heap, DataPriorityComp); // �� �ʱ�ȭ

	HInsert(&heap, 'A'); // ���� 'A'�� ���� ���� ���� �켱 ������ ����
	HInsert(&heap, 'B'); // ���� 'B'�� ���� �� ��° �켱 ������ ����
	HInsert(&heap, 'C'); // ���� 'C'�� ���� ���� ���� �켱 ������ ����
	printf("%c \n", HDelete(&heap)); // Heap���� �����Ǵ� ���� Ȯ��

	// 2ȸ�� ����
	HInsert(&heap, 'A'); // ���� 'A'�� ���� ���� ���� �켱 ������ ����
	HInsert(&heap, 'B'); // ���� 'B'�� ���� �� ��° �켱 ������ ����
	HInsert(&heap, 'C'); // ���� 'C'�� ���� ���� ���� �켱 ������ ����
	printf("%c \n", HDelete(&heap)); // Heap���� �����Ǵ� ���� Ȯ��

	while (!HisEmpty(&heap))
		printf("%c \n", HDelete(&heap)); // Heap���� �����Ǵ� ���� Ȯ��

	return 0;
}