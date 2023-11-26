/*
* 알고리즘 - 버블 정렬(Bubble Sort)
* 파일명: BubbleSort.c
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2023-11-26
* 이전 버전 작성 일자:
* 버전 내용: 간단한 버블 정렬 구현
* 이전 버전 내용:
*/

#include <stdio.h>

void BubbleSort(int arr[], int n)
{
	int i, j; // 반복문에 쓰일 변수 i, j
	int temp; // 변수 swap에 사용할 임시 변수

	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < (n - i) - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				// 데이터 정렬
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