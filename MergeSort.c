/*
* 알고리즘 - 병합 정렬(Merge Sort)
* 파일명: MergeSort.c
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2023-11-26
* 이전 버전 작성 일자:
* 버전 내용: 간단한 병합 정렬 구현
* 이전 버전 내용:
*/

#include <stdio.h>
#include <stdlib.h>

// 병합 과정
void MergeTwoArea(int arr[], int left, int mid, int right)
{
	int front_Idx = left; // 첫 번째 인덱스(가장 왼쪽)
	int rear_Idx = mid + 1; // mid(중간)의 바로 다음 -> 오른쪽의 맨 첫 번째 인덱스
	int i;

	int* sortArr = (int*)malloc(sizeof(int) * (right + 1)); // 정렬한 데이터를 담을 배열 동적 할당
	int sort_Idx = left; // 동적 할당에 쓰일 첫 인덱스

	// 첫 번째 인덱스가 mid와 같아지거나 (왼쪽에 나눈 배열의 끝까지 가는 경우)
	// 오른쪽의 인덱스가 right와 같아지거나 (오른쪽에 나눈 배열의 끝까지 가는 경우)
	while (front_Idx <= mid && rear_Idx <= right)
	{
		if (arr[front_Idx] <= arr[rear_Idx]) // 합쳐지기 전에 좌우에 나뉜 값에 대한 비교
			sortArr[sort_Idx] = arr[front_Idx++];
		else
			sortArr[sort_Idx] = arr[rear_Idx++];

		sort_Idx++;
	}

	// 병합 후 정렬이 끝나면
	if (front_Idx > mid)
	{
		for (i = rear_Idx; i <= right; i++, sort_Idx++) // 오른쪽 부분을 채움
			sortArr[sort_Idx] = arr[i];
	}
	else
	{
		for (i = front_Idx; i <= mid; i++, sort_Idx++) // 왼쪽 부분을 채움
			sortArr[sort_Idx] = arr[i];
	}

	for (i = left; i <= right; i++)
		arr[i] = sortArr[i]; // 원래 배열에 정렬된 값을 대입

	free(sortArr); // 할당 해제
}

void MergeSort(int arr[], int left, int right)
{
	int mid;

	if (left < right)
	{
		// 중간 지점을 계산
		mid = (left + right) / 2;

		// 둘로 나눠서 정렬 (재귀)
		MergeSort(arr, left, mid);
		MergeSort(arr, mid + 1, right);
		
		// 정렬이 된 배열을 병합
		MergeTwoArea(arr, left, mid, right);
	}

	
}

int main()
{
	int arr[7] = { 3, 2, 4, 1, 7, 6, 5 };
	int i;

	// 배열의 전체 영역을 정렬
	MergeSort(arr, 0, (sizeof(arr) / sizeof(int)) - 1);


	for (i = 0; i < 7; i++)
		printf("%d ", arr[i]);

	printf("\n");
	return 0;
}