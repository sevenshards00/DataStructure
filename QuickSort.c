/*
* �˰��� - �� ����(Quick Sort)
* ���ϸ�: QuickSort.c
* ���� ����: 0.1
* �ۼ���: Sevenshards
* �ۼ� ����: 2023-11-26
* ���� ���� �ۼ� ����:
* ���� ����: ������ �� ���� ����
* ���� ���� ����:
*/

#include <stdio.h>

// ������ �̵�(��ȯ)�� ���
void Swap(int arr[], int idx1, int idx2)
{
	int temp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = temp;
}

int MedianOfThree(int arr[], int left, int right)
{
	int samples[3] = { left, (left + right) / 2, right };

	if (arr[samples[0]] > arr[samples[1]])
		Swap(samples, 0, 1);

	if (arr[samples[1]] > arr[samples[2]])
		Swap(samples, 1, 2);

	if (arr[samples[0]] > arr[samples[1]])
		Swap(samples, 0, 1);

	return samples[1];
}

// �� ������ ������ �����ϴ� Partition �Լ�
int Partition(int arr[], int left, int right)
{
	int pivot_idx = MedianOfThree(arr, left, right);
	int pivot = arr[pivot_idx]; // �ǹ� ���� ��ġ�� ���� ��������
	int low = left + 1; // �ǹ��� ������ ���� ���� ���� �ε���
	int high = right; // �ǹ��� ������ ���� �����ʰ��� �ε���

	Swap(arr, left, pivot_idx);

	printf("pivot: %d\n", pivot);

	while (low <= high) // low�� high�� ���� �������� ���� ������ �ݺ� ����
	{
		// �ǹ����� ū ���� ã�� ����
		while (pivot >= arr[low] && low <= right)
			low++; // low�� ���������� �̵�

		// �ǹ����� ���� ���� ã�� ����
		while (pivot <= arr[high] && high >= (left + 1))
			high--; // high�� �������� �̵�

		// low�� high�� �������� �ʾҴٸ� Swap ����
		if (low <= high)
			Swap(arr, low, high);
	}

	Swap(arr, left, high); // �ǹ��� high�� ����Ű�� ����� ��ȯ
	return high; // �Ű��� �ǹ��� ��ġ ���� ��ȯ
}

void QuickSort(int arr[], int left, int right)
{
	if (left < right)
	{
		int pivot = Partition(arr, left, right); // �ѷ� ������
		QuickSort(arr, left, pivot - 1); // ���� ���� ����
		QuickSort(arr, pivot + 1, right); // ������ ���� ����
	}
}

int main()
{
	//int arr[7] = {3, 2, 4, 1, 7, 6, 5};
	//int arr[3] = { 3, 3, 3 };
	int arr[15] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

	int len = sizeof(arr) / sizeof(int);
	int i;

	QuickSort(arr, 0, len - 1);

	for (i = 0; i < len; i++)
		printf("%d ", arr[i]);

	printf("\n");
	return 0;
}