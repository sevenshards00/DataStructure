/*
* �˰��� - ���� ����(Merge Sort)
* ���ϸ�: MergeSort.c
* ���� ����: 0.1
* �ۼ���: Sevenshards
* �ۼ� ����: 2023-11-26
* ���� ���� �ۼ� ����:
* ���� ����: ������ ���� ���� ����
* ���� ���� ����:
*/

#include <stdio.h>
#include <stdlib.h>

// ���� ����
void MergeTwoArea(int arr[], int left, int mid, int right)
{
	int front_Idx = left; // ù ��° �ε���(���� ����)
	int rear_Idx = mid + 1; // mid(�߰�)�� �ٷ� ���� -> �������� �� ù ��° �ε���
	int i;

	int* sortArr = (int*)malloc(sizeof(int) * (right + 1)); // ������ �����͸� ���� �迭 ���� �Ҵ�
	int sort_Idx = left; // ���� �Ҵ翡 ���� ù �ε���

	// ù ��° �ε����� mid�� �������ų� (���ʿ� ���� �迭�� ������ ���� ���)
	// �������� �ε����� right�� �������ų� (�����ʿ� ���� �迭�� ������ ���� ���)
	while (front_Idx <= mid && rear_Idx <= right)
	{
		if (arr[front_Idx] <= arr[rear_Idx]) // �������� ���� �¿쿡 ���� ���� ���� ��
			sortArr[sort_Idx] = arr[front_Idx++];
		else
			sortArr[sort_Idx] = arr[rear_Idx++];

		sort_Idx++;
	}

	// ���� �� ������ ������
	if (front_Idx > mid)
	{
		for (i = rear_Idx; i <= right; i++, sort_Idx++) // ������ �κ��� ä��
			sortArr[sort_Idx] = arr[i];
	}
	else
	{
		for (i = front_Idx; i <= mid; i++, sort_Idx++) // ���� �κ��� ä��
			sortArr[sort_Idx] = arr[i];
	}

	for (i = left; i <= right; i++)
		arr[i] = sortArr[i]; // ���� �迭�� ���ĵ� ���� ����

	free(sortArr); // �Ҵ� ����
}

void MergeSort(int arr[], int left, int right)
{
	int mid;

	if (left < right)
	{
		// �߰� ������ ���
		mid = (left + right) / 2;

		// �ѷ� ������ ���� (���)
		MergeSort(arr, left, mid);
		MergeSort(arr, mid + 1, right);
		
		// ������ �� �迭�� ����
		MergeTwoArea(arr, left, mid, right);
	}

	
}

int main()
{
	int arr[7] = { 3, 2, 4, 1, 7, 6, 5 };
	int i;

	// �迭�� ��ü ������ ����
	MergeSort(arr, 0, (sizeof(arr) / sizeof(int)) - 1);


	for (i = 0; i < 7; i++)
		printf("%d ", arr[i]);

	printf("\n");
	return 0;
}