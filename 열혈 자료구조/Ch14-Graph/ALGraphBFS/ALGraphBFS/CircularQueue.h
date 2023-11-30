/*
* 선형 자료구조 - Queue (배열 기반, 원형 큐)
* 파일명: CircularQueue.h
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2023-11-05
* 이전 버전 작성 일자:
* 버전 내용: 배열 기반의 원형(Circular) Queue 구현
* 이전 버전 내용:
*/
#ifndef __C_QUEUE_H__
#define __C_QUEUE_H__

#define TRUE 1
#define FALSE 0

#define QUE_LEN 100 // 큐의 길이, 배열이므로 매크로로 100으로 고정
typedef int Data; // 편의상 받는 데이터는 int로 했고 Data로 지칭, 다른 데이터로 바꾼다면 여길 바꾸면 된다

typedef struct _circularqueue // 배열 기반 원형 큐의 구조체, 배열과 front, rear 셋으로 구성
{
	Data arr[QUE_LEN]; // 현재 큐를 구성할 배열
	int front; // front
	int rear; // rear

} CQueue;

typedef CQueue Queue; // 편의상 CQueue를 Queue로 별칭 붙여 사용

void QueueInit(Queue* pq); // Queue 초기화

int QisEmpty(Queue* pq); // Queue가 비었는가 확인

void QEnqueue(Queue* pq, Data data); // Queue에 데이터 삽입

Data QDequeue(Queue* pq); // Queue에 들어있는 데이터 반환 및 삭제

Data QPeek(Queue* pq); // 현재 Front가 가리키는 값 반환

#endif