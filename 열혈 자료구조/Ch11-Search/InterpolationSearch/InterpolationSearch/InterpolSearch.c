/*
* 알고리즘 - 보간 탐색(Interpolation Search)
* 파일명: InterpolSearch.c
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2023-11-27
* 이전 버전 작성 일자:
* 버전 내용: 기존에 구현한 이진 탐색 알고리즘을 기반으로 보간 탐색 구현
* 이전 버전 내용:
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int InterpolationSearch(int arr[], int first, int last, int target)
{
	int pos; // 보간 탐색에서는 중앙값이 아닌 비례식에서 유도된 식을 기반으로 탐색 위치를 정한다.

	// 찾고자 하는 값이 배열의 첫 번째 값보다 작거나 마지막 값보다 큰 경우 - 보간 탐색에서의 재귀 탈출 조건 첫 번째.
	if (target < arr[first] || target > arr[last])
		return -1;

	// 비례식에 의해 유도된 식을 기반으로 한 탐색 위치를 설정한다.
	pos = ((double)(target - arr[first]) / (arr[last] - arr[first]) * (last - first)) + first;

	// 탐색 시작
	// 찾은 경우 인덱스 값을 반환 - 재귀의 탈출 조건 두 번째.
	if (target == arr[pos])
		return pos;

	// 값을 찾지 못한 경우
	else if (target > arr[pos]) // 목표로 한 값이 탐색 시작 위치의 값보다 크다면
		return InterpolationSearch(arr, pos + 1, last, target); // pos 까지는 비교했으므로 pos의 다음 인덱스부터 last까지 다시 탐색
	else // 목표로 한 값이 탐색 시작 위치의 값보다 작다면
		return InterpolationSearch(arr, first, pos - 1, target); // pos까지는 비교했으므로 first부터 pos의 바로 이전 인덱스까지 다시 탐색 
}


int main()
{
	int arr[] = { 1,3,5,7,9 };
	int result;

	// 배열 내에 없는 2를 찾기 위해 호출 -> 문제가 생긴다
	result = InterpolationSearch(arr, 0, sizeof(arr) / sizeof(int) - 1, 2);

	if (result == -1)
		printf("찾지 못함\n");
	else
		printf("%d 번째 인덱스에 있음\n", result);

	return 0;
}