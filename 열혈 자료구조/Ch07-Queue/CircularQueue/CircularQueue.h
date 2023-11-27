// 11.05 �迭 ��� ���� Queue ����
// �迭 ����̹Ƿ� ���� Queue�� ������, �迭�� �� ä���� �ʴ´ٴ� ���� ����Ʈ
// CircularQueue.h
#ifndef __C_QUEUE_H__
#define __C_QUEUE_H__

#define TRUE 1
#define FALSE 0

#define QUE_LEN 100 // ť�� ����, �迭�̹Ƿ� ��ũ�η� 100���� ����
typedef int Data; // ���ǻ� �޴� �����ʹ� int�� �߰� Data�� ��Ī, �ٸ� �����ͷ� �ٲ۴ٸ� ���� �ٲٸ� �ȴ�

typedef struct _circularqueue // �迭 ��� ���� ť�� ����ü, �迭�� front, rear ������ ����
{
	Data arr[QUE_LEN]; // ���� ť�� ������ �迭
	int front; // front
	int rear; // rear

} CQueue;

typedef CQueue Queue; // ���ǻ� CQueue�� Queue�� ��Ī �ٿ� ���

void QueueInit(Queue* pq); // Queue �ʱ�ȭ

int QisEmpty(Queue* pq); // Queue�� ����°� Ȯ��

void QEnqueue(Queue* pq, Data data); // Queue�� ������ ����

Data QDequeue(Queue* pq); // Queue�� ����ִ� ������ ��ȯ �� ����

Data QPeek(Queue* pq); // ���� Front�� ����Ű�� �� ��ȯ

#endif