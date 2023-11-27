// 11.05 �迭 ��� ���� Queue ����
// �迭 ����̹Ƿ� ���� Queue�� ������, �迭�� �� ä���� �ʴ´ٴ� ���� ����Ʈ
// CircularQueue.c
#include <stdio.h>
#include <stdlib.h>
#include "CircularQueue.h"

void QueueInit(Queue* pq) // Queue �ʱ�ȭ
{
	pq->front = 0; // front�� 0�� ����Ű��
	pq->rear = 0; // rear�� 0�� ����Ų��
}
int QisEmpty(Queue* pq) // Queue�� ����°� Ȯ��
{
	if (pq->front == pq->rear) // front�� rear�� �Ȱ��ٸ�
		return TRUE; // ��������Ƿ� TRUE ��ȯ
	else
		return FALSE; // ������� �ʴٸ� FALSE ��ȯ
}

// �迭 ��� ���� ť������ ���̴� �Լ�
// �迭 ������ front�� rear�� ��� ���ƾ��ϹǷ� ����Ѵ�.
int NextPosIdx(int pos)
{
	// ���� �迭 �ε����� ���� QUE_LEN-1
	// �׸��� ���� �ε����� ���� ����Ų�ٸ�
	// �ٽ� 0���� ���������� ����
	//
	if (pos == QUE_LEN - 1) // ���� �ε����� ���� ����Ų�ٸ�
		return 0; // 0���� ����������
	else // �װ� �ƴ϶��
		return pos + 1; // ���� �ε����� ����Ű�� �Ѵ�
}
void QEnqueue(Queue* pq, Data data) // Queue�� ������ ����
{
	if (NextPosIdx(pq->rear) == pq->front) // rear�� ������ front���? Queue�� �� á�ٴ� ��
	{
		printf("Queue Fulled\n");
		exit(-1); // �� �̻� ä�� �� �����Ƿ� ����
	}
	//�װ� �ƴ϶��

	pq->rear = NextPosIdx(pq->rear); // rear�� �� ĭ ������ �̵��ϰ�
	pq->arr[pq->rear] = data; // �����͸� �ִ´�.
}
Data QDequeue(Queue* pq) // Queue�� ����ִ� ������ ��ȯ �� ����
{
	if (QisEmpty(pq)) // Queue�� ����ٸ�
	{
		printf("Queue is Empty\n");
		exit(-1); // ���� ���ϹǷ� ����
	}
	// �װ� �ƴ϶��
	pq->front = NextPosIdx(pq->front); // front�� ���� �ε����� �ٲٰ�
	return pq->arr[pq->front]; // ���� front�� ����Ű�� �ε����� ���� ��ȯ
}

Data QPeek(Queue* pq) // ���� Front�� ����Ű�� �� ��ȯ
{
	if (QisEmpty(pq)) // Queue�� ����ٸ�
	{
		printf("Queue is Empty\n");
		exit(-1); // ���� ���ϹǷ� ����
	}
	// �װ� �ƴ϶��
	
	return pq->arr[NextPosIdx(pq->front)]; // ���� front�� ����Ű�� �ε����� ���� ��ȯ
}