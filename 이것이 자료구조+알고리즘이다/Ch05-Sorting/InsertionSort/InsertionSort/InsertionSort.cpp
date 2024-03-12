/*
* 이것이 자료구조+알고리즘이다 - 정렬(Sorting)
* 파일명: InsertionSort.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-03-12
* 이전 버전 작성 일자:
* 버전 내용: 간단한 삽입 정렬 구현
* 이전 버전 내용:
*/

#include <iostream>
using std::cout;

constexpr int arr_len = 10;

void InsertionSort(int arr[], int len)
{
	int temp;

	for (int i = 1; i != len; ++i)
	{
		temp = arr[i];
		int j = i - 1;

		while (j != -1 && arr[j] > temp)
		{
			arr[j + 1] = arr[j];
			--j;
		}
		arr[j + 1] = temp;
	}
}

int main()
{
	int arr[arr_len] = { 8, 7, 5, 4, 3, 9, 0, 1, 6, 2 };
	InsertionSort(arr, arr_len);
	for (int i = 0; i != arr_len; ++i)
		cout << arr[i] << ' ';
	cout << '\n';

	return 0;
}