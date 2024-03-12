/*
* 이것이 자료구조+알고리즘이다 - 정렬(Sorting)
* 파일명: SelectionSort.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-03-12
* 이전 버전 작성 일자:
* 버전 내용: 간단한 선택 정렬 구현
* 이전 버전 내용:
*/

#include <iostream>
using std::cout;

constexpr int arr_len = 10;

void SelectionSort(int arr[], int len)
{
	int min_idx;
	int temp;

	for (int i = 0; i != len - 1; ++i)
	{
		min_idx = i;

		for (int j = i + 1; j != len; ++j)
		{
			if (arr[min_idx] > arr[j])
			{
				temp = arr[j];
				arr[j] = arr[min_idx];
				arr[min_idx] = temp;
			}
		}
	}

}

int main()
{
	int arr[arr_len] = { 8, 7, 5, 4, 3, 9, 0, 1, 6, 2 };
	SelectionSort(arr, arr_len);
	for (int i = 0; i != arr_len; ++i)
		cout << arr[i] << ' ';
	cout << '\n';

	return 0;
}