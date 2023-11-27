/*
* �ڷᱸ�� - ���� ����Ʈ ��� ť(List Base Queue)
* ���ϸ�: ListBaseQueue.c
* ���� ����: 0.1
* �ۼ���: Sevenshards
* �ۼ� ����: 2023-11-27
* ���� ���� �ۼ� ����:
* ���� ����: ������ ���� ����Ʈ ��� ť ����
* ���� ���� ����:
*/

#include <stdio.h>
#include <stdlib.h>
#include "ListBaseQueue.h"

void QueueInit(Queue* pq) // Queue �ʱ�ȭ
{
	pq->front = NULL;
	pq->rear = NULL;
}

int QisEmpty(Queue* pq) // Queue�� ����°� Ȯ��
{
	if (pq->front == NULL)
		return TRUE;
	else
		return FALSE;
}

void QEnqueue(Queue* pq, Data data) // Queue�� ��� ����
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

Data QDequeue(Queue* pq) // ���� Queue���� front�� ����Ű�� �ִ� ��� ����
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

Data QPeek(Queue* pq) // ���� Queue���� front�� ����Ű�� ����� ������ Ȯ�� (���Ŵ� ����)
{
	if (QisEmpty(pq))
	{
		printf("Queue is Empty\n");
		exit(-1);
	}

	return pq->front->data;
}