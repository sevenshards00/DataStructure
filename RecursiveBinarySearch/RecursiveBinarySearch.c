/*
* 알고리즘 - 이진 탐색(Binary Search)
* 파일명: RecursiveBinarySearch.c
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2023-11-27
* 이전 버전 작성 일자:
* 버전 내용: 재귀적으로 구성한 이진 탐색 알고리즘 구현
* 이전 버전 내용:
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int RecursiveBinarySearch(int arr[], int first, int last, int target)
{
	int mid;
	// first보다 last가 커지는 경우 = 값을 찾지 못한 경우 - 재귀의 탈출 조건 첫 번째.
	if (first > last)
		return -1;

	// 이후 첫번째 인덱스와 마지막 인덱스의 절반인 중앙값을 설정한다.
	mid = (first + last) / 2;

	// 탐색 시작
	// 찾은 경우 인덱스 값을 반환 - 재귀의 탈출 조건 두 번째.
	if (target == arr[mid])
		return mid;

	// 값을 찾지 못한 경우
	else if (target > arr[mid]) // 목표로 한 값이 중앙값보다 크다면
		return RecursiveBinarySearch(arr, mid + 1, last, target); // mid 까지는 비교했으므로 mid의 다음 인덱스부터 last까지 다시 탐색
	else // 목표로 한 값이 중앙값보다 작다면
		return RecursiveBinarySearch(arr, first, mid - 1, target); // mid까지는 비교했으므로 first부터 mid의 바로 이전 인덱스까지 다시 탐색 
}


int main()
{
	int arr[] = { 1,3,5,7,9 };
	int input, result;
	printf("찾을 수 : ");
	scanf("%d", &input);
	result = RecursiveBinarySearch(arr, 0, (sizeof(arr) / sizeof(int)) - 1, input);

	if (result == -1)
		printf("찾지 못함\n");
	else
		printf("%d 번째 인덱스에 있음\n", result);


	return 0;
}