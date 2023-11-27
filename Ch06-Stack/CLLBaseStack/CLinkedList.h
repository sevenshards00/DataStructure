// 11.03 원형 연결 리스트
// 더미 노드 기반으로 구현하지 않는다
// CLinkedList.h

#ifndef __C_LINKED_LIST_H__
#define __C_LINKED_LIST_H__

#define TRUE 1
#define FALSE 0

typedef int Data; // 편의상 일단 int를 LData로

// 노드 구조체 정의
typedef struct _node
{
	Data data;
	struct _node* next;
}Node;

// 리스트 구조체 정의
typedef struct _clinkedlist
{
	Node* list;
	Node* tail;
	Node* cur;
	Node* before;
	int numOfData;
} CLinkedList;

typedef CLinkedList List; // 편의상 List로

void ListInit(List* plist); // 리스트 초기화

void LInsert(List* plist, Data data); // 노드 삽입

void LInsertFront(List* plist, Data data); // head에 노드 추가

int LFirst(List* plist, Data* pdata); // 맨 처음 노드 참조

int LNext(List* plist, Data* pdata); // 맨 처음 노드 참조 이후 다음 노드 참조

Data LRemove(List* plist); // 현재 참조 중인 노드 삭제

int LCount(List* plist); // 현재 노드 전체 개수

#endif