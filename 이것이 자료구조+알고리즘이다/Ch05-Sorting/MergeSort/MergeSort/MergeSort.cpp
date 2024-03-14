/*
* 이것이 자료구조+알고리즘이다 - 정렬(Sorting)
* 파일명: MergeSort.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-03-14
* 이전 버전 작성 일자:
* 버전 내용: 병합 정렬 (Top-down, Bottom-up) 구현
* 이전 버전 내용:
*/


/*
* TO-DO List:
* 1) 동적할당 하는 과정 최소화
* 2) 일정 단위가 되었을 때에는 삽입 정렬을 이용하여 정렬하기 추가로 구현
*/
#include <iostream>

//#define CLRS3
#define CLRS4

void Merge(int parr[], int left, int mid, int right)
{
	// CLRS 3판 슈도코드 기반
#ifdef CLRS3
	int l_len = mid - left + 1;
	int r_len = right - mid;
	int *l_arr = (int *)malloc(sizeof(int) * (l_len + 1));
	int *r_arr = (int *)malloc(sizeof(int) * (r_len + 1));

	if (l_arr == nullptr && r_arr == nullptr)
		return;

	for (int i = 0; i != l_len; ++i)
		l_arr[i] = parr[left + i];
	for (int i = 0; i != r_len; ++i)
		r_arr[i] = parr[mid + i + 1];

	l_arr[l_len] = INT_MAX;
	r_arr[r_len] = INT_MAX;

	int i = 0;
	int j = 0;

	for (int k = left; k <= right; ++k)
	{
		if (l_arr[i] <= r_arr[j])
		{
			parr[k] = l_arr[i];
			++i;
		}
		else
		{
			parr[k] = r_arr[j];
			++j;
		}
	}

#endif

	// CLRS 4판 슈도코드 기반
#ifdef CLRS4
	int l_len = mid - left + 1;
	int r_len = right - mid;

	int *l_arr = (int *)malloc(sizeof(int) * l_len);
	int *r_arr = (int *)malloc(sizeof(int) * r_len);

	if (l_arr == nullptr && r_arr == nullptr)
		return;

	for (int i = 0; i != l_len; ++i)
		l_arr[i] = parr[left + i];
	for (int i = 0; i != r_len; ++i)
		r_arr[i] = parr[mid + i + 1];

	int i = 0;
	int j = 0;
	int k = left;

	while (i != l_len && j != r_len)
	{
		if (l_arr[i] <= r_arr[j])
		{
			parr[k] = l_arr[i];
			++i;
		}
		else
		{
			parr[k] = r_arr[j];
			++j;
		}
		++k;
	}

	while (i != l_len)
	{
		parr[k] = l_arr[i];
		++i;
		++k;
	}

	while (j != r_len)
	{
		parr[k] = r_arr[j];
		++j;
		++k;
	}
#endif
	
	free(l_arr);
	free(r_arr);
}

void TopDownMergeSort(int parr[], int left, int right)
{
	if (left < right)
	{
		int mid = (left + right) / 2;
		TopDownMergeSort(parr, left, mid);
		TopDownMergeSort(parr, mid + 1, right);
		Merge(parr, left, mid, right);
	}
}

void BottomUpMergeSort(int parr[], int left, int right)
{
	// Bottom-Up 방식은 정렬되지 않은 배열을 분할하지 않음 -> 이미 분할이 된 상태로 가정하고 시작
	// 1, 2, 4, 8 ... -> 2의 거듭제곱 꼴로 반복
	for (int sort_sz = 1; sort_sz <= right - left; sort_sz *= 2)
	{
		for (int i = left; i < right; i += sort_sz * 2)
		{
			int begin = i;
			int mid = i + sort_sz - 1;
			int end;

			if (i + (sort_sz * 2) - 1 < right)
				end = i + (sort_sz * 2) - 1;
			else
				end = right;

			Merge(parr, begin, mid, end);
		}
	}
}

int main()
{
	int arr1[] = { 8, 1, 7, 2, 6, 3, 4, 5 };
	int arr2[] = { 8, 1, 7, 2, 6, 3, 4, 5 };
	TopDownMergeSort(arr1, 0, (sizeof(arr1) / sizeof(int)) - 1);
	for (int i = 0; i != sizeof(arr1) / sizeof(int); ++i)
		std::cout << arr1[i] << " ";

	std::cout << '\n';

	BottomUpMergeSort(arr2, 0, sizeof(arr2) / sizeof(int) - 1);
	for (int i = 0; i != sizeof(arr1) / sizeof(int); ++i)
		std::cout << arr2[i] << " ";
	std::cout << '\n';

	return 0;
}