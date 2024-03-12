/*
* 이것이 자료구조+알고리즘이다 - 정렬(Sorting)
* 파일명: BubbleSort.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-03-12
* 이전 버전 작성 일자:
* 버전 내용: 간단한 버블 정렬 구현
* 이전 버전 내용:
*/

#include <iostream>
using std::cout;

constexpr int arr_len = 10;

void BubbleSort(int arr[], int len)
{
	int temp;
	for (int i = 0; i != len - 1; ++i)
	{
		for (int j = 0; j != len - i - 1; ++j)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

int main()
{
	int arr[arr_len] = {8, 7, 5, 4, 3, 9, 0, 1, 6, 2};
	BubbleSort(arr, arr_len);
	for (int i = 0; i != arr_len; ++i)
		cout << arr[i] << ' ';
	cout << '\n';
}