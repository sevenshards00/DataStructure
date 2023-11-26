/*
* �˰��� - ���� ����(Insertion Sort)
* ���ϸ�: InsertionSort.c
* ���� ����: 0.1
* �ۼ���: Sevenshards
* �ۼ� ����: 2023-11-26
* ���� ���� �ۼ� ����:
* ���� ����: ������ ���� ���� ����
* ���� ���� ����:
*/

#include <stdio.h>

void InsertionSort(int arr[], int n)
{
	int i, j;
	int insertData;

	for (i = 1; i < n; i++) // ù ��°�� �ƴ� �� ��° ��Һ��� ������ ��ұ���
	{
		insertData = arr[i]; // ���� ����� ������ ����

		for (j = i - 1; j >= 0; j--) // i-1 ��° ��Һ��� ù ��° ��ұ��� ��������
		{
			if (arr[j] > insertData)
				arr[j + 1] = arr[j]; // �� ����� �� ĭ ������ �̵�
			else
				break; // ���� ��ġ�� ã�����Ƿ� �ݺ��� Ż��
		}

		arr[j + 1] = insertData; // ã�� ��ġ�� ���� ��� ����
	}
}

int main()
{
	int arr[5] = { 5, 3, 2, 4, 1 };
	int i;

	InsertionSort(arr, sizeof(arr) / sizeof(int));

	for (i = 0; i < 5; i++)
		printf("%d ", arr[i]);
	printf("\n");
	return 0;
}