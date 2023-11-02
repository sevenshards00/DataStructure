// 11.02 이중 연결 리스트
// DBLinkedList.h

#ifndef __DB_LINKED_LIST_H__
#define __DB_LINKED_LIST_H__

#define TRUE 1
#define FALSE 0

typedef int LData;

// 이중 연결 리스트의 노드 구조체
typedef struct _node
{
	LData data; // 데이터
	struct _node* next; // 다음 노드 위치
	struct _node* prev; // 이전 노드 위치
} Node;

typedef struct _dblinkedlist
{
	Node* head; // 헤드, 맨 처음 노드를 가리킴
	Node* cur; // 현재 참조 중인 위치
	int numOfData; // 리스트에 들어있는 노드 개수
} DBLinkedList;

typedef DBLinkedList List; // 편의상 List로 별칭 붙이기 위해 typedef

void ListInit(List* plist); // 리스트 초기화

void LInsert(List* plist, LData data); // 노드 삽입

int LFirst(List* plist, LData* pdata); // 리스트의 맨 처음 노드 참조

int LNext(List* plist, LData* pdata); // 리스트의 맨 처음 노드 참조 이후 참조

int LPrev(List* plist, LData* pdata); // 이전 노드 참조

LData LRemove(List* plist); // 노드 삭제, 이건 일단 챕터 끝나고 따로 생각해보기로

int LCount(List* plist); // 현재 리스트에 있는 노드의 수 반환

#endif