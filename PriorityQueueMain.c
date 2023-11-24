/*
* ���� �ڷᱸ�� - ��(Heap) ����� �켱���� ť(Priority Queue)
* ���ϸ�: PriorityQueueMain.c
* ���� ����: 0.1
* �ۼ���: Sevenshards
* �ۼ� ����: 2023-11-24
* ���� ���� �ۼ� ����:
* ���� ����: ���� ������� �� �켱���� ť ����
* ���� ���� ����:
*/

int DataPriorityComp(char ch1, char ch2)
{
	return ch2 - ch1; // �ƽ�Ű�ڵ� ��������
	//return ch1 - ch2 // �ƽ�Ű�ڵ� ��������
}

#include <stdio.h>
#include "PriorityQueue.h"

int main()
{
	PQueue pq;
	PQueueInit(&pq, DataPriorityComp);

	PEnqueue(&pq, 'A');
	PEnqueue(&pq, 'B');
	PEnqueue(&pq, 'C');
	printf("%c \n", PDequeue(&pq));

	PEnqueue(&pq, 'A');
	PEnqueue(&pq, 'B');
	PEnqueue(&pq, 'C');
	printf("%c \n", PDequeue(&pq));

	while(!PQisEmpty(&pq))
		printf("%c \n", PDequeue(&pq));

	return 0;
}