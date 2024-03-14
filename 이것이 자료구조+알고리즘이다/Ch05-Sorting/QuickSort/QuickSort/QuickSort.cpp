/*
* 이것이 자료구조+알고리즘이다 - 정렬(Sorting)
* 파일명: QuickSort.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-03-14
* 이전 버전 작성 일자:
* 버전 내용: 퀵 정렬 구현
* 이전 버전 내용:
*/

#include <Windows.h>
#include <iostream>
using std::cout;

void Swap(int parr[], int idx1, int idx2)
{
	int temp = parr[idx1];
	parr[idx1] = parr[idx2];
	parr[idx2] = temp;
}

int Partition(int parr[], int left, int right)
{
	// 맨 우측값을 피벗으로 지정
	// 이 부분은 개선할 수 있음
	// 가장 간단한 방법은 임의의 세 원소를 정해서 그중에서 중앙값을 구한 인덱스를 피벗으로 사용하는 것.
	int pivot = parr[right];
	int low = left - 1;

	for (int high = left; high != right; ++high)
	{
		if (parr[high] <= pivot)
		{
			++low;
			Swap(parr, low, high);
		}
	}

	Swap(parr, low + 1, right);

	return low + 1;
}

void QuickSort(int parr[], int left, int right)
{
	if (left < right)
	{
		int pivot_idx = Partition(parr, left, right);
		QuickSort(parr, left, pivot_idx - 1);
		QuickSort(parr, pivot_idx + 1, right);
	}
}

int wmain()
{
	int arr1[] = { 2, 8, 7, 1, 3, 5, 6, 4 };
	QuickSort(arr1, 0, sizeof(arr1) / sizeof(int) - 1);
	for (int i = 0; i != _countof(arr1); ++i)
		cout << arr1[i] << ' ';
	cout << '\n';

	return 0;
}