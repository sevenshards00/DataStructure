// 11.05 리스트 기반 큐
// 잘못 생각했다. 데이터는 tail쪽으로 들어와야 한다.
// 이대로 구현한거면 stack과 다를 것이 없어진다. 다만 head와 tail이 존재한다 생각하자. 조회는 없다
// ListBaseQueue.c
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
		/*
		* 잘못 구현한 코드. 이대로 구현하면 스택이지, 큐가 아니다.
		* head쪽으로 들어와서 head쪽에서 데이터가 나가게 만들어놨으니 스택이다. 큐가 아니다.
		* 노드는 tail쪽부터 쌓인다.
		newNode->next = pq->front;
		pq->front = newNode;
		*/
		pq->rear->next = newNode;
		pq->rear = newNode;
	}
}
Data QDequeue(Queue* pq) // 현재 Queue에서 front를 가리키고 있는 노드 제거
{
	if (QisEmpty(pq))
	{
		printf("Queue is Empty\n");
		exit(-1);
	}
	
	Node* rNode = pq->front;
	Data rData = rNode->data;
	
	// 굳이 따질 필요가 없어진다.
	// 어차피 노드를 새로 만들때 next에 NULL을 준다
	// 그리고 마지막으로 남은 노드일때 지우면서 pq->front에 pq->front->next를 가리키면 결국 NULL을 가리키게 된다
	// 그리고 rear 값은 뭘 가리키는지 모르게 되지만
	// 결국 front값만 기준으로 따지면 되기 때문에 상관 없어진다.
	//
	/*
	if (pq->front == pq->rear)
	{
		pq->front = NULL;
		free(rNode);
		return rData;
	}
	*/

	pq->front = pq->front->next;
	free(rNode);
	return rData;
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