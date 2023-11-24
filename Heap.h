/*
* 비선형 자료구조 - 배열 기반의 힙(Heap)
* 파일명: Heap.h
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2023-11-24
* 이전 버전 작성 일자:
* 버전 내용: 간단한 힙의 구현
* 이전 버전 내용:
*/

#ifndef __HEAP_H__
#define __HEAP_H__

#define TRUE 1
#define FALSE 0

#define HEAP_LEN 100

typedef char HData; // 힙에 저장될 데이터를 HData라고 별칭
typedef int Priority; // 힙에서 사용될 우선 순위

// 힙에서 사용될 구성 요소(Element) 구조체 정의
typedef struct _heapelement
{
	Priority pr;
	HData data;
} HeapElem;

// 힙 구조체 정의
typedef struct _heap
{
	int numOfData; // 힙의 데이터 갯수
	HeapElem heapArr[HEAP_LEN];
} Heap;

void HeapInit(Heap* ph); // 힙의 초기화
int HisEmpty(Heap* ph); // 힙이 비었는지 확인

void HInsert(Heap* ph, HData data, Priority pr); // 힙에 데이터 삽입
HData HDelete(Heap* ph); // 힙에 데이터 삭제

#endif