/*
* 비선형 자료구조 - 힙(Heap) 기반의 우선순위 큐(Priority Queue)
* 파일명: PriorityQueue.c
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2023-11-24
* 이전 버전 작성 일자:
* 버전 내용: 힙을 기반으로 한 우선순위 큐 구현
* 이전 버전 내용:
*/
#include "PriorityQueue.h"
#include "Heap.h"

typedef Heap PQueue; // Heap을 PQueue라고 별칭 부여
typedef HData PQData; // HData를 PQData라고 별칭 부여

// 우선 순위 큐 초기화
void PQueueInit(PQueue* ppq, PriorityComp pc)
{
	HeapInit(ppq, pc);
}

// 우선 순위 큐가 비었는지 확인
int PQisEmpty(PQueue* ppq)
{
	return HisEmpty(ppq);
}

// Enqueue 연산
void PEnqueue(PQueue* ppq, PQData data)
{
	HInsert(ppq, data);
}

// Dequeue 연산
PQData PDequeue(PQueue* ppq)
{
	return HDelete(ppq);
}