/*
* 비선형 자료구조 - 배열 기반의 힙(Heap)
* 파일명: Heap.h
* 파일 버전: 0.2
* 작성자: Sevenshards
* 작성 일자: 2023-11-24
* 이전 버전 작성 일자: 2023-11-24
* 버전 내용: 우선 순위 판단 기준을 힙에 설정할 수 있도록 함수 포인터로 변경
* 이전 버전 내용: 간단한 힙의 구현
*/

#ifndef __HEAP_H__
#define __HEAP_H__

#define TRUE 1
#define FALSE 0

#define HEAP_LEN 100

#include "ALEdge.h"

typedef Edge HData; // 힙에 저장될 데이터를 HData라고 별칭
typedef int PriorityComp(HData d1, HData d2); // 힙에서 사용될 우선 순위

// 힙 구조체 정의
typedef struct _heap
{
	PriorityComp* comp; // 우선 순위 기준을 판단할 함수 포인터 변수 선언
	int numOfData; // 힙의 데이터 갯수
	HData heapArr[HEAP_LEN]; // 배열 기반의 힙
} Heap;

void HeapInit(Heap* ph, PriorityComp pc); // 힙의 초기화
int HisEmpty(Heap* ph); // 힙이 비었는지 확인

void HInsert(Heap* ph, HData data); // 힙에 데이터 삽입
HData HDelete(Heap* ph); // 힙에 데이터 삭제

#endif