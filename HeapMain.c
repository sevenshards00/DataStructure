/*
* 비선형 자료구조 - 배열 기반의 힙(Heap)
* 파일명: HeapMain.c
* 파일 버전: 0.2
* 작성자: Sevenshards
* 작성 일자: 2023-11-24
* 이전 버전 작성 일자: 2023-11-24
* 버전 내용: 우선 순위 판단 기준을 힙에 설정할 수 있도록 함수 포인터로 변경
* 이전 버전 내용: 간단한 힙의 구현
*/
#include <stdio.h>
#include "Heap.h"

int DataPriorityComp(char ch1, char ch2)
{
	return ch2 - ch1;
}

int main()
{
	Heap heap;
	HeapInit(&heap, DataPriorityComp); // 힙 초기화

	HInsert(&heap, 'A'); // 문자 'A'를 힙에 가장 높은 우선 순위로 저장
	HInsert(&heap, 'B'); // 문자 'B'를 힙에 두 번째 우선 순위로 저장
	HInsert(&heap, 'C'); // 문자 'C'를 힙에 가장 낮은 우선 순위로 저장
	printf("%c \n", HDelete(&heap)); // Heap에서 삭제되는 문자 확인

	// 2회차 저장
	HInsert(&heap, 'A'); // 문자 'A'를 힙에 가장 높은 우선 순위로 저장
	HInsert(&heap, 'B'); // 문자 'B'를 힙에 두 번째 우선 순위로 저장
	HInsert(&heap, 'C'); // 문자 'C'를 힙에 가장 낮은 우선 순위로 저장
	printf("%c \n", HDelete(&heap)); // Heap에서 삭제되는 문자 확인

	while (!HisEmpty(&heap))
		printf("%c \n", HDelete(&heap)); // Heap에서 삭제되는 문자 확인

	return 0;
}