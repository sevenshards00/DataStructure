/*
* �˰��� - �� ����(Heap Sort)
* ���ϸ�: HeapSort.c
* ���� ����: 0.1
* �ۼ���: Sevenshards
* �ۼ� ����: 2023-11-26
* ���� ���� �ۼ� ����:
* ���� ����: ������ �� ���� ����
* ���� ���� ����:
*/

#include <stdio.h>
#include "Heap.h"

// ù ��° ������ �켱 ������ ũ�ٸ�, 0���� ū ���� ��ȯ (��������)
// �� ��° ������ �켱 ������ ũ�ٸ�, 0���� ���� ���� ��ȯ (��������)
// ù ��° ���ڿ� �� ��° ������ �켱 ������ ���ٸ� 0�� ��ȯ
int PriComp(int n1, int n2)
{
	return n2 - n1; // ��������
	//return n1 - n2; // ��������
}

void HeapSort(int arr[], int n, PriorityComp pc)
{
	Heap heap;
	int i;

	// �� �ʱ�ȭ - �� ����ü�� �������� �켱������ �Ǻ��� �Լ��� ���ڷ� ����
	HeapInit(&heap, pc);

	// ���� ����� ������ ���� ����
	for (i = 0; i < n; i++)
		HInsert(&heap, arr[i]);

	// ���� �� ���� �ٽ� ������ ����
	for (i = 0; i < n; i++)
		arr[i] = HDelete(&heap);
}

int main()
{
	int arr[4] = { 3, 4, 2, 1 };
	int i;

	HeapSort(arr, sizeof(arr) / sizeof(int), PriComp);

	for (i = 0; i < 4; i++)
		printf("%d ", arr[i]);

	printf("\n");
	
	return 0;
}