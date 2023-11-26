/*
* 알고리즘 - 삽입 정렬(Insertion Sort)
* 파일명: InsertionSort.c
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2023-11-26
* 이전 버전 작성 일자:
* 버전 내용: 간단한 삽입 정렬 구현
* 이전 버전 내용:
*/

#include <stdio.h>

void InsertionSort(int arr[], int n)
{
	int i, j;
	int insertData;

	for (i = 1; i < n; i++) // 첫 번째가 아닌 두 번째 요소부터 마지막 요소까지
	{
		insertData = arr[i]; // 정렬 대상을 별도로 저장

		for (j = i - 1; j >= 0; j--) // i-1 번째 요소부터 첫 번째 요소까지 역순으로
		{
			if (arr[j] > insertData)
				arr[j + 1] = arr[j]; // 비교 대상을 한 칸 앞으로 이동
			else
				break; // 삽입 위치를 찾았으므로 반복문 탈출
		}

		arr[j + 1] = insertData; // 찾은 위치에 정렬 대상 삽입
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