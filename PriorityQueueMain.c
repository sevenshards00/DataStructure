/*
* 비선형 자료구조 - 힙(Heap) 기반의 우선순위 큐(Priority Queue)
* 파일명: PriorityQueueMain.c
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2023-11-24
* 이전 버전 작성 일자:
* 버전 내용: 힙을 기반으로 한 우선순위 큐 구현
* 이전 버전 내용:
*/

int DataPriorityComp(char ch1, char ch2)
{
	return ch2 - ch1; // 아스키코드 오름차순
	//return ch1 - ch2 // 아스키코드 내림차순
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