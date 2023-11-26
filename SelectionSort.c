/*
* 알고리즘 - 선택 정렬(Selection Sort)
* 파일명: SelectionSort.c
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2023-11-26
* 이전 버전 작성 일자:
* 버전 내용: 간단한 선택 정렬 구현
* 이전 버전 내용:
*/

#include <stdio.h>

void SelectionSort(int arr[], int n)
{
	int i, j;
	int maxIdx;
	int temp;

	for (i = 0; i < n - 1; i++)
	{
		maxIdx = i;
		for (j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[maxIdx])
				maxIdx = j;
		}

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