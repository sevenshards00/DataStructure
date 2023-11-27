/*
* �˰��� - ���� ����(Bubble Sort)
* ���ϸ�: BubbleSort.c
* ���� ����: 0.1
* �ۼ���: Sevenshards
* �ۼ� ����: 2023-11-26
* ���� ���� �ۼ� ����:
* ���� ����: ������ ���� ���� ����
* ���� ���� ����:
*/

#include <stdio.h>

void BubbleSort(int arr[], int n)
{
	int i, j; // �ݺ����� ���� ���� i, j
	int temp; // ���� swap�� ����� �ӽ� ����

	for (i = 0; i < n - 1; i++) // �����Ͱ� n����� n-1��ŭ�� �ݺ��� �����Ͽ� ���� ����
	{
		for (j = 0; j < (n - i) - 1; j++) // ��ȯ�� �̷����� �κ�. ���ĵǾ� ���鼭 ���� �ε����� ���� �پ�Ƿ� ���ǽ��� j<(n-i)-1
		{
			if (arr[j] > arr[j + 1])
			{
				// ������ ����
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

int main()
{
	int arr[4] = { 3, 2, 1, 4 };
	int i;

	BubbleSort(arr, sizeof(arr) / sizeof(int));

	for (i = 0; i < 4; i++)
		printf("%d ", arr[i]);

	printf("\n");
	
	return 0;
}