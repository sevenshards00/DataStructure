/*
* ���� �ڷᱸ�� - ��(Heap) ����� �켱���� ť(Priority Queue)
* ���ϸ�: PriorityQueue.h
* ���� ����: 0.1
* �ۼ���: Sevenshards
* �ۼ� ����: 2023-11-24
* ���� ���� �ۼ� ����: 
* ���� ����: ���� ������� �� �켱���� ť ����
* ���� ���� ����:
*/

#ifndef __PRIORITY_QUEUE_H__
#define __PRIORITY_QUEUE_H__

#include "Heap.h"

typedef Heap PQueue; // Heap�� PQueue��� ��Ī �ο�
typedef HData PQData; // HData�� PQData��� ��Ī �ο�

// �켱 ���� ť �ʱ�ȭ
void PQueueInit(PQueue* ppq, PriorityComp pc);

// �켱 ���� ť�� ������� Ȯ��
int PQisEmpty(PQueue* ppq);

// Enqueue ����
void PEnqueue(PQueue* ppq, PQData data);

// Dequeue ����
PQData PDequeue(PQueue* ppq);

#endif