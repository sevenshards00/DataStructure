// 11.02 더미 노드 기반 더블 링크드 리스트
// DDBLinkedList.c

#ifndef __DDB_LINKED_LIST_H__
#define __DDB_LINKED_LIST_H__

#define TRUE 1
#define FALSE 0

typedef int LData;

typedef struct _node
{
	LData data;
	struct _node* next;
	struct _node* prev;
} Node;

typedef struct _ddblist
{
	Node* head;
	Node* tail;
	Node* cur;
	int numOfData;
} DDBList;

typedef DDBList List;

#include <stdlib.h>
#include "DDBLinkedList.h"

// 리스트 초기화에 사용
void ListInit(List* plist)
{
	// head와 tail에 더미 노드 메모리 할당
	plist->head = (Node*)malloc(sizeof(Node));
	plist->tail = (Node*)malloc(sizeof(Node));

	// head의 prev는 NULL, next는 tail을 가리키게
	plist->head->prev = NULL;
	plist->head->next = plist->tail;
	// tail의 next는 NULL, prev는 head를 가리키게
	plist->tail->prev = plist->head;
	plist->tail->next = NULL;
	
	// 현재 데이터의 갯수는 0으로 설정
	plist->numOfData = 0;

}
// 노드 삽입
void LInsert(List* plist, LData data)
{	
	Node* newNode = (Node*)malloc(sizeof(Node)); // 새로운 노드 생성
	newNode->data = data; // 매개 변수로 받은 값 노드의 data에 대입
	
	newNode->prev = plist->tail->prev; // 1) tail이 가리키던 이전 노드를 새로운 노드의 prev 값으로 넣어주고
	plist->tail->prev->next = newNode; // 2) tail이 이전에 가리키고 있던 다음 주소값에 새로운 노드를 가리키게 한다

	newNode->next = plist->tail; // 3) 새로운 노드의 next가 tail을 가리키게 한다.
	plist->tail->prev = newNode; // 4) 마지막으로 tail의 prev를 새로운 노드를 가리키게 한다

	(plist->numOfData)++; // 노드 갯수 증가

}
// 맨 처음 노드 참조
int LFirst(List* plist, LData* pdata)
{
	if (plist->head == plist->tail) // head와 tail이 가리키는게 같다면
		return FALSE; // 노드가 없는 것이므로 FALSE 반환
	
	plist->cur = plist->head->next; // 현재 위치 cur를 head의 다음에 두고 (초기화)
	*pdata = plist->cur->data; // 데이터를 참조하여 가져온다

	return TRUE; // 데이터 반환 성공
}
// 맨 처음 이후 노드 참조
int LNext(List* plist, LData* pdata)
{
	if (plist->cur->next == plist->tail) // cur의 다음이 tail을 가리킨다면
		return FALSE; // 더 이상 참조할 노드가 없는 것이므로 FALSE 반환

	plist->cur = plist->cur->next; // 현재 위치 cur를 다음에 두고
	*pdata = plist->cur->data; // 데이터를 참조하여 가져온다

	return TRUE; // 데이터 반환 성공
}
// 맨 처음 이후 현재 참조한 노드를 기준으로 앞의 노드 참조
int LPrev(List* plist, LData* pdata)
{
	if (plist->cur->prev == plist->head) // cur의 이전 노드가 head를 가리킨다면
		return FALSE; // 더 이상 참조할 노드가 없는 것이므로 FALSE 반환

	plist->cur = plist->cur->prev; // 현재 위치 cur를 이전에 두고
	*pdata = plist->cur->data; // 데이터를 참조하여 가져온다

	return TRUE; // 데이터 반환 성공
}
// 노드 삭제
// 전제 조건은 연속 호출은 절대 안된다는 점
// LFirst나 LNext 이후에 호출이 되어야 한다
LData LRemove(List* plist)
{
	Node* rNode = plist->cur; // 현재 삭제할 노드 위치
	LData rData = plist->cur->data; // 삭제할 노드가 가지고 있는 데이터

	plist->cur->prev->next = plist->cur->next; // 현재 가리키고 있는 이전 노드가 가리키는 다음 노드를 현재 노드가 가리키는 다음 노드로
	plist->cur->next->prev = plist->cur->prev; // 현재 가리키고 있는 다음 노드가 가리키는 이전 노드를 현재 노드가 가리키는 이전 노드로

	plist->cur = plist->cur->prev; // 현재 위치를 하나 앞으로

	(plist->numOfData)--; // 노드 개수 감소

	free(rNode); // 할당된 노드 메모리 해제
	
	return rData; // 노드의 데이터 반환
}
// 현재 리스트에 있는 노드의 수
int LCount(List* plist)
{
	return plist->numOfData;
}

#endif