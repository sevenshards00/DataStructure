/*
* ���� �ڷᱸ�� - ��(Heap) ����� �켱���� ť(Priority Queue)
* ���ϸ�: PriorityQueue.c
* ���� ����: 0.1
* �ۼ���: Sevenshards
* �ۼ� ����: 2023-11-24
* ���� ���� �ۼ� ����:
* ���� ����: ���� ������� �� �켱���� ť ����
* ���� ���� ����:
*/
#include "PriorityQueue.h"
#include "Heap.h"

typedef Heap PQueue; // Heap�� PQueue��� ��Ī �ο�
typedef HData PQData; // HData�� PQData��� ��Ī �ο�

// �켱 ���� ť �ʱ�ȭ
void PQueueInit(PQueue* ppq, PriorityComp pc)
{
	HeapInit(ppq, pc);
}

// �켱 ���� ť�� ������� Ȯ��
int PQisEmpty(PQueue* ppq)
{
	return HisEmpty(ppq);
}

// Enqueue ����
void PEnqueue(PQueue* ppq, PQData data)
{
	HInsert(ppq, data);
}

// Dequeue ����
PQData PDequeue(PQueue* ppq)
{
	return HDelete(ppq);
}