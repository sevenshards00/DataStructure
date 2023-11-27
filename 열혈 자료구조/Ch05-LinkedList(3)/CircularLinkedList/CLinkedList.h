// 11.02 원형 링크드 리스트
// CLinkedList.h
//

#ifndef __C_LINKED_LIST_H__
#define __C_LINKED_LIST_H__

#define TRUE 1
#define FALSE 0

typedef int LData;

typedef struct _node
{
	LData data;
	struct _node* next;
} Node;

typedef struct _clinkedlist
{
	Node* tail; // tail이 가리키는 위치
	Node* cur; // 현재 참조를 위해 가리키는 노드 위치
	Node* before; // 현재 참조를 위해 가리키는 노드보다 하나 앞의 위치
	int numOfData; // 리스트에 저장된 노드 갯수
} CLinkedList;

typedef CLinkedList List; // 편의상 List라고 쓰기 위해 typedef 지정

void ListInit(List* plist); // 리스트 초기화

// 이전 링크드 리스트와 바뀐 부분
void LInsert(List* plist, LData data); // tail에 노드 추가
void LInsertFront(List* plist, LData data); // head에 노드 추가

int LFirst(List* plist, LData* data); // 맨 처음 노드부터 참조
int LNext(List* plist, LData* data); // 맨 처음 노드 이후 참조

LData LRemove(List* plist); // 현재 참조 중인 노드 삭제

int LCount(List* plist); // 리스트의 노드 갯수 반환

#endif