// 11.05 ����Ʈ ��� ť
// �߸� �����ߴ�. �����ʹ� tail������ ���;� �Ѵ�.
// �̴�� �����ѰŸ� stack�� �ٸ� ���� ��������. �ٸ� head�� tail�� �����Ѵ� ��������. ��ȸ�� ����
// ListBaseQueue.c
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
		/*
		* �߸� ������ �ڵ�. �̴�� �����ϸ� ��������, ť�� �ƴϴ�.
		* head������ ���ͼ� head�ʿ��� �����Ͱ� ������ ���������� �����̴�. ť�� �ƴϴ�.
		* ���� tail�ʺ��� ���δ�.
		newNode->next = pq->front;
		pq->front = newNode;
		*/
		pq->rear->next = newNode;
		pq->rear = newNode;
	}
}
Data QDequeue(Queue* pq) // ���� Queue���� front�� ����Ű�� �ִ� ��� ����
{
	if (QisEmpty(pq))
	{
		printf("Queue is Empty\n");
		exit(-1);
	}
	
	Node* rNode = pq->front;
	Data rData = rNode->data;
	
	// ���� ���� �ʿ䰡 ��������.
	// ������ ��带 ���� ���鶧 next�� NULL�� �ش�
	// �׸��� ���������� ���� ����϶� ����鼭 pq->front�� pq->front->next�� ����Ű�� �ᱹ NULL�� ����Ű�� �ȴ�
	// �׸��� rear ���� �� ����Ű���� �𸣰� ������
	// �ᱹ front���� �������� ������ �Ǳ� ������ ��� ��������.
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
Data QPeek(Queue* pq) // ���� Queue���� front�� ����Ű�� ����� ������ Ȯ�� (���Ŵ� ����)
{
	if (QisEmpty(pq))
	{
		printf("Queue is Empty\n");
		exit(-1);
	}

	return pq->front->data;
}