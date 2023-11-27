// 11.05 배열 기반 원형 Queue 구현
// 배열 기반이므로 원형 Queue로 구현함, 배열을 꽉 채우지 않는다는 것이 포인트
// CircularQueue.c
#include <stdio.h>
#include <stdlib.h>
#include "CircularQueue.h"

void QueueInit(Queue* pq) // Queue 초기화
{
	pq->front = 0; // front는 0을 가리키고
	pq->rear = 0; // rear도 0을 가리킨다
}
int QisEmpty(Queue* pq) // Queue가 비었는가 확인
{
	if (pq->front == pq->rear) // front와 rear가 똑같다면
		return TRUE; // 비어있으므로 TRUE 반환
	else
		return FALSE; // 비어있지 않다면 FALSE 반환
}

// 배열 기반 원형 큐에서만 쓰이는 함수
// 배열 내에서 front와 rear가 계속 돌아야하므로 사용한다.
int NextPosIdx(int pos)
{
	// 실제 배열 인덱스의 끝은 QUE_LEN-1
	// 그리고 현재 인덱스가 끝을 가리킨다면
	// 다시 0부터 돌려보내기 위함
	//
	if (pos == QUE_LEN - 1) // 현재 인덱스가 끝을 가리킨다면
		return 0; // 0으로 돌려보낸다
	else // 그게 아니라면
		return pos + 1; // 다음 인덱스를 가리키게 한다
}
void QEnqueue(Queue* pq, Data data) // Queue에 데이터 삽입
{
	if (NextPosIdx(pq->rear) == pq->front) // rear의 다음이 front라면? Queue가 꽉 찼다는 것
	{
		printf("Queue Fulled\n");
		exit(-1); // 더 이상 채울 수 없으므로 종료
	}
	//그게 아니라면

	pq->rear = NextPosIdx(pq->rear); // rear를 한 칸 앞으로 이동하고
	pq->arr[pq->rear] = data; // 데이터를 넣는다.
}
Data QDequeue(Queue* pq) // Queue에 들어있는 데이터 반환 및 삭제
{
	if (QisEmpty(pq)) // Queue가 비었다면
	{
		printf("Queue is Empty\n");
		exit(-1); // 수행 못하므로 종료
	}
	// 그게 아니라면
	pq->front = NextPosIdx(pq->front); // front를 다음 인덱스로 바꾸고
	return pq->arr[pq->front]; // 현재 front가 가리키는 인덱스의 값을 반환
}

Data QPeek(Queue* pq) // 현재 Front가 가리키는 값 반환
{
	if (QisEmpty(pq)) // Queue가 비었다면
	{
		printf("Queue is Empty\n");
		exit(-1); // 수행 못하므로 종료
	}
	// 그게 아니라면
	
	return pq->arr[NextPosIdx(pq->front)]; // 현재 front가 가리키는 인덱스의 값을 반환
}