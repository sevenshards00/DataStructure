/*
* �˰��� - ���� ����(Selection Sort)
* ���ϸ�: SelectionSort.c
* ���� ����: 0.1
* �ۼ���: Sevenshards
* �ۼ� ����: 2023-11-26
* ���� ���� �ۼ� ����:
* ���� ����: ������ ���� ���� ����
* ���� ���� ����:
*/

#include <stdio.h>

void SelectionSort(int arr[], int n)
{
	int i, j;
	int maxIdx; // �켱 ������ ���� ���� �ε��� ��
	int temp;

	for (i = 0; i < n - 1; i++)
	{
		maxIdx = i; // �ε��� ���� i��. �� ó���̶�� 0����
		for (j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[maxIdx]) // �������� ���� ����
				maxIdx = j; // ���� ���ϴ� ���� �� �۴ٸ� �ش� �ε����� �ٲ۴�.
		}

		// ������ ��ȯ
		temp = arr[i];
		arr[i] = arr[maxIdx];
		arr[maxIdx] = temp;
	}
}

int main()
{
	int arr[4] = { 3, 4, 2, 1 };
	int i;

	SelectionSort(arr, sizeof(arr)/sizeof(int));

	for (i = 0; i < 4; i++)
		printf("%d ", arr[i]);

	printf("\n");

	return 0;
}