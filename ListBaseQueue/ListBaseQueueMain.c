// 11.05 ����Ʈ ��� Queue ����
// head�θ� ��尡 ������ ����Ʈ ����, �ٸ� head�� tail�� �����Ѵ� ��������. ��ȸ�� ����
// ListBaseQueueMain.c

#include <stdio.h>
#include "ListBaseQueue.h"

int main()
{
	Queue queue;
	QueueInit(&queue);
	int i;

	printf("Queue�� �ʱ�ȭ�ϰ� ���� 0���� 49���� Enqueue�մϴ�.\n");

	for (i = 0; i < 50; i++)
	{
		QEnqueue(&queue, i);
		printf("%d�� Enqueue�߽��ϴ�.\n", i);
	}

	printf("\n\n");

	printf("���� Queue�� �ִ� ���� Dequeue�մϴ�.\n");
	while (!QisEmpty(&queue))
	{
		printf("���� Peek��: %d\n", QPeek(&queue));
		printf("%d�� dequeue �߽��ϴ�.\n", QDequeue(&queue));
	}

	printf("���� Queue�� ������� Ȯ���մϴ�.\n");
	if (QisEmpty(&queue))
		printf("Queue�� ����ִ� ��Ȳ�Դϴ�.\n");
	else
		printf("Queue�� ��� ���� �ʽ��ϴ�.\n");

	printf("�̹����� Queue�� Ȧ���� Enqueue�մϴ�.\n");

	for (i = 0; i < 50; i++)
	{
		if (i % 2 != 0)
		{
			QEnqueue(&queue, i);
			printf("%d�� Enqueue�߽��ϴ�.\n", i);
		}
	}

	printf("�ٽ� Queue�� �ִ� ���� Dequeue�մϴ�.\n");
	while (!QisEmpty(&queue))
	{
		printf("���� Peek��: %d\n", QPeek(&queue));
		printf("%d�� dequeue �߽��ϴ�.\n", QDequeue(&queue));
	}

	printf("\n\n");

	printf("���� Queue�� ������� Ȯ���մϴ�.\n");
	if (QisEmpty(&queue))
		printf("Queue�� ����ִ� ��Ȳ�Դϴ�.\n");
	else
		printf("Queue�� ��� ���� �ʽ��ϴ�.\n");


	return 0;
}