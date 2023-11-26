/*
* 알고리즘 - 퀵 정렬(Quick Sort)
* 파일명: QuickSort.c
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2023-11-26
* 이전 버전 작성 일자:
* 버전 내용: 간단한 퀵 정렬 구현
* 이전 버전 내용:
*/

#include <stdio.h>

// 데이터 이동(교환)에 사용
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

// 퀵 정렬을 실제로 수행하는 Partition 함수
int Partition(int arr[], int left, int right)
{
	int pivot_idx = MedianOfThree(arr, left, right);
	int pivot = arr[pivot_idx]; // 피벗 값의 위치는 가장 왼쪽으로
	int low = left + 1; // 피벗을 제외한 가장 왼쪽 값의 인덱스
	int high = right; // 피벗을 제외한 가장 오른쪽값의 인덱스

	Swap(arr, left, pivot_idx);

	printf("pivot: %d\n", pivot);

	while (low <= high) // low와 high의 값이 교차되지 않을 때까지 반복 수행
	{
		// 피벗보다 큰 값을 찾는 과정
		while (pivot >= arr[low] && low <= right)
			low++; // low를 오른쪽으로 이동

		// 피벗보다 작은 값을 찾는 과정
		while (pivot <= arr[high] && high >= (left + 1))
			high--; // high를 왼쪽으로 이동

		// low와 high가 교차되지 않았다면 Swap 수행
		if (low <= high)
			Swap(arr, low, high);
	}

	Swap(arr, left, high); // 피벗과 high가 가리키는 대상을 교환
	return high; // 옮겨진 피벗의 위치 정보 반환
}

void QuickSort(int arr[], int left, int right)
{
	if (left < right)
	{
		int pivot = Partition(arr, left, right); // 둘로 나눠서
		QuickSort(arr, left, pivot - 1); // 왼쪽 영역 실행
		QuickSort(arr, pivot + 1, right); // 오른쪽 영역 실행
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