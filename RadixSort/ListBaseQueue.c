/*
* 자료구조 - 연결 리스트 기반 큐(List Base Queue)
* 파일명: ListBaseQueue.c
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2023-11-27
* 이전 버전 작성 일자:
* 버전 내용: 간단한 연결 리스트 기반 큐 구현
* 이전 버전 내용:
*/

#include <stdio.h>
#include <stdlib.h>
#include "ListBaseQueue.h"

void QueueInit(Queue* pq) // Queue 초기화
{
	pq->front = NULL;
	pq->rear = NULL;
}

int QisEmpty(Queue* pq) // Queue가 비었는가 확인
{
	if (pq->front == NULL)
		return TRUE;
	else
		return FALSE;
}

void QEnqueue(Queue* pq, Data data) // Queue에 노드 삽입
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;

	if (QisEmpty(pq))
	{
		pq->front = newNode;
		pq->rear = newNode;
	}
	else
	{
		pq->rear->next = newNode;
		pq->rear = newNode;
	}
}

Data QDequeue(Queue* pq) // 현재 Queue에서 front를 가리키고 있는 노드 제거
{
	Node* deq_Node;
	Data deq_Data;

	if (QisEmpty(pq))
	{
		printf("Queue is Empty\n");
		exit(-1);
	}

	deq_Node = pq->front;
	deq_Data = deq_Node->data;
	pq->front = pq->front->next;

	free(deq_Node);
	return deq_Data;
}

Data QPeek(Queue* pq) // 현재 Queue에서 front를 가리키는 노드의 데이터 확인 (제거는 안함)
{
	if (QisEmpty(pq))
	{
		printf("Queue is Empty\n");
		exit(-1);
	}

	return pq->front->data;
}