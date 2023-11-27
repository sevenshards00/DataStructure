/*
* �˰��� - ��� ����(Radix Sort)
* ���ϸ�: RadixSort.c
* ���� ����: 0.1
* �ۼ���: Sevenshards
* �ۼ� ����: 2023-11-27
* ���� ���� �ۼ� ����:
* ���� ����: ������ ��� ����(LSD, Least Significant Digit) ����
* ���� ���� ����:
*/

#include <stdio.h>
#include "ListBaseQueue.h"

#define BUCKET_NUM 10

void RadixSort(int arr[], int num, int maxLen)
{
	// �Ű����� maxLen���� ���Ĵ�� �� ���� �� �������� ���� ������ ����
	Queue buckets[BUCKET_NUM];
	int bucket_idx; // ��Ŷ�� ����� �ε���
	int pos;
	int data_idx; // �����Ϳ� ����� �ε���
	int div_factor = 1; // �ڸ����� ���ϴµ� ����ϴ� ������
	int radix;

	// 10���� ��Ŷ �ʱ�ȭ
	for (bucket_idx = 0; bucket_idx < BUCKET_NUM; bucket_idx++)
		QueueInit(&buckets[bucket_idx]);

	// ���� �� �������� ���̸�ŭ �ݺ�
	for (pos = 0; pos < maxLen; pos++)
	{
		// ��Ŷ�� �����͸� �ִ� �κ�
		for (data_idx = 0; data_idx < num; data_idx++)
		{
			// N��° �ڸ��� ���� ����
			radix = (arr[data_idx] / div_factor) % 10;

			// ������ ���ڸ� �ٰŷ� ��Ŷ�� �����͸� ����
			QEnqueue(&buckets[radix], arr[data_idx]);
		}

		// ��Ŷ���� �����͸� �����ϴ� �κ�
		// ��Ŷ�� �� ��ŭ �ݺ�
		for (bucket_idx = 0, data_idx = 0; bucket_idx < BUCKET_NUM; bucket_idx++)
		{
			// ��Ŷ�� ����� ���� ������� �� ������ �ٽ� arr�� ����
			while (!QisEmpty(&buckets[bucket_idx]))
				arr[data_idx++] = QDequeue(&buckets[bucket_idx]);
		}

		// N��° �ڸ��� ���� ������ ���ؼ� �������� ����
		div_factor *= 10;
	}
}

int main()
{
	int arr[7] = { 13, 212, 14, 7141, 10987, 6, 15 };
	int i;
	int len = sizeof(arr) / sizeof(int);

	RadixSort(arr, len, 5);

	for (i = 0; i < len; i++)
		printf("%d ", arr[i]);

	printf("\n");

	return 0;
}