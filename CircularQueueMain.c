// 11.05 배열 기반 원형 Queue 구현
// 배열 기반이므로 원형 Queue로 구현함, 배열을 꽉 채우지 않는다는 것이 포인트
// CircularQueueMain.c

#include <stdio.h>
#include "CircularQueue.h"

int main()
{
	Queue queue;
	QueueInit(&queue);
	int i;

	printf("Queue를 초기화하고 값을 0부터 98까지 Enqueue합니다.\n");

	for (i = 0; i < QUE_LEN-1; i++)
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
	if(QisEmpty(&queue))
		printf("Queue가 비어있는 상황입니다.\n");
	else
		printf("Queue가 비어 있지 않습니다.\n");
		
	printf("이번에는 Queue에 홀수만 Enqueue합니다.\n");

	for (i = 0; i < QUE_LEN - 1; i++)
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