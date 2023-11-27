// 11.05 리스트 기반 큐
// head로만 노드가 들어오는 리스트 생각, 다만 head와 tail이 존재한다 생각하자. 조회는 없다
// ListBaseQueue.h

#ifndef __LIST_BASE_QUEUE_H__
#define __LIST_BASE_QUEUE_H__

#define TRUE 1
#define FALSE 0

// 편의상 int를 Data라고 지칭. 다른 데이터 타입을 쓰고 싶다면 여길 바꾸면 된다.
typedef int Data;

// 노드 구조체 정의
typedef struct _node
{
	Data data;
	struct _node* next;
} Node;

// 큐 구조체 정의, front와 rear를 사용
typedef struct _listqueue {
	Node* front;
	Node* rear;
} ListQueue;

// ListQueue라고 다 쓰기 불편하니 Queue라고 별칭 부여
typedef ListQueue Queue;

void QueueInit(Queue* pq); // Queue 초기화

int QisEmpty(Queue* pq); // Queue가 비었는가 확인

void QEnqueue(Queue* pq, Data data); // Queue에 노드 삽입

Data QDequeue(Queue* pq); // 현재 Queue에서 front를 가리키고 있는 노드 제거

Data QPeek(Queue* pq); // 현재 Queue에서 front를 가리키는 노드의 데이터 확인 (제거는 안함)
#endif