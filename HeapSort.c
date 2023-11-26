/*
* 알고리즘 - 힙 정렬(Heap Sort)
* 파일명: HeapSort.c
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2023-11-26
* 이전 버전 작성 일자:
* 버전 내용: 간단한 힙 정렬 구현
* 이전 버전 내용:
*/

#include <stdio.h>
#include "Heap.h"

// 첫 번째 인자의 우선 순위가 크다면, 0보다 큰 값을 반환 (오름차순)
// 두 번째 인자의 우선 순위가 크다면, 0보다 작은 값을 반환 (내림차순)
// 첫 번째 인자와 두 번째 인자의 우선 순위가 같다면 0을 반환
int PriComp(int n1, int n2)
{
	return n2 - n1; // 오름차순
	//return n1 - n2; // 내림차순
}

void HeapSort(int arr[], int n, PriorityComp pc)
{
	Heap heap;
	int i;

	// 힙 초기화 - 힙 구조체와 데이터의 우선순위를 판별할 함수를 인자로 전달
	HeapInit(&heap, pc);

	// 정렬 대상을 가지고 힙을 구성
	for (i = 0; i < n; i++)
		HInsert(&heap, arr[i]);

	// 힙에 들어간 값을 다시 꺼내서 정렬
	for (i = 0; i < n; i++)
		arr[i] = HDelete(&heap);
}

int main()
{
	int arr[4] = { 3, 4, 2, 1 };
	int i;

	HeapSort(arr, sizeof(arr) / sizeof(int), PriComp);

	for (i = 0; i < 4; i++)
		printf("%d ", arr[i]);

	printf("\n");
	
	return 0;
}