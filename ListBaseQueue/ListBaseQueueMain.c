// 11.05 리스트 기반 Queue 구현
// head로만 노드가 들어오는 리스트 생각, 다만 head와 tail이 존재한다 생각하자. 조회는 없다
// ListBaseQueueMain.c

#include <stdio.h>
#include "ListBaseQueue.h"

int main()
{
	Queue queue;
	QueueInit(&queue);
	int i;

	printf("Queue를 초기화하고 값을 0부터 49까지 Enqueue합니다.\n");

	for (i = 0; i < 50; i++)
	{
		QEnqueue(&queue, i);
		printf("%d를 Enqueue했습니다.\n", i);
	}

	printf("\n\n");

	printf("이제 Queue에 있는 값을 Dequeue합니다.\n");
	while (!QisEmpty(&queue))
	{
		printf("현재 Peek값: %d\n", QPeek(&queue));
		printf("%d를 dequeue 했습니다.\n", QDequeue(&queue));
	}

	printf("이제 Queue가 비었는지 확인합니다.\n");
	if (QisEmpty(&queue))
		printf("Queue가 비어있는 상황입니다.\n");
	else
		printf("Queue가 비어 있지 않습니다.\n");

	printf("이번에는 Queue에 홀수만 Enqueue합니다.\n");

	for (i = 0; i < 50; i++)
	{
		if (i % 2 != 0)
		{
			QEnqueue(&queue, i);
			printf("%d를 Enqueue했습니다.\n", i);
		}
	}

	printf("다시 Queue에 있는 값을 Dequeue합니다.\n");
	while (!QisEmpty(&queue))
	{
		printf("현재 Peek값: %d\n", QPeek(&queue));
		printf("%d를 dequeue 했습니다.\n", QDequeue(&queue));
	}

	printf("\n\n");

	printf("이제 Queue가 비었는지 확인합니다.\n");
	if (QisEmpty(&queue))
		printf("Queue가 비어있는 상황입니다.\n");
	else
		printf("Queue가 비어 있지 않습니다.\n");


	return 0;
}