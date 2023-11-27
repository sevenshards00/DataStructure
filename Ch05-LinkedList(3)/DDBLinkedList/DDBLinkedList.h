// 11.02 더미 노드 기반 더블 링크드 리스트
// DDBLinkedList.h

#ifndef __DDB_LINKED_LIST_H__
#define __DDB_LINKED_LIST_H__

#define TRUE 1 // 진짜 C는 Bool 타입을 지원하지 않으므로 이걸 TRUE로 대체
#define FALSE 0 // 마찬가지 이유로 이걸 FALSE 값으로 대체

typedef int LData; // 편의상 int를 LData로 변형. 어떤 데이터를 넣던 이 부분만 바꿔주면 됨

// Node 구조체 정의
typedef struct _node
{
	LData data;
	struct _node* next;
	struct _node* prev;
} Node;

// 리스트 구조체 정의
typedef struct _ddblist
{
	Node* head;
	Node* tail;
	Node* cur;
	int numOfData;
} DDBList;

typedef DDBList List; // 편의상 List라고 쓰려고 typedef 선언

void ListInit(List* plist); // 리스트 초기화에 사용

void LInsert(List* plist, LData data); // 노드 삽입

int LFirst(List* plist, LData* pdata); // 맨 처음 노드 참조

int LNext(List* plist, LData* pdata); // 맨 처음 이후 노드 참조

int LPrev(List* plist, LData* pdata); // 맨 처음 이후 현재 참조한 노드를 기준으로 앞의 노드 참조

LData LRemove(List* plist); // 노드 삭제

int LCount(List* plist); // 현재 리스트에 있는 노드의 수

#endif