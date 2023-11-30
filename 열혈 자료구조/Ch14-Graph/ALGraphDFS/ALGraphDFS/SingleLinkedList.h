#pragma once
/*
* 선형 자료구조 - 단일 연결 리스트 (더미 노드 기반)
* 파일명: SingleLinkedList.h
* 파일 버전: 0.3
* 작성자: Sevenshards
* 작성 일자: 2023-11-30
* 이전 버전 작성 일자: 2023-11-29
* 버전 내용: 정렬 기준 삽입 추가
* 이전 버전 내용: 해시 충돌 문제 해결을 위한 체이닝 기법 구현
*/
#ifndef __SINGLE_LINKED_LIST_H__
#define __SINGLE_LINKED_LIST_H__

#define TRUE 1 // 참일 경우 1
#define FALSE 0 // 거짓일 경우 0

typedef int LData; // 어떤 데이터를 쓸지 모르니 일단은 LData로 매크로 지정, 편의상 int
typedef int CompareFunc(LData d1, LData d2);

typedef struct _node
{
	LData data; // 노드에 담길 데이터
	struct _node* next; // 다음 노드를 가리키기 위한 포인터
} Node;

typedef struct _linkedlist
{
	Node* head; // head를 가리키는 포인터
	Node* cur; // 현재 참조하는 위치를 가리키는 포인터
	Node* before; // 현재보다 하나 앞의 위치를 가리키는 포인터
	int numOfData; // 현재 저장된 데이터 수를 확인하기 위해 사용
	CompareFunc* comp; // 정렬 기준 함수를 가리키기 위한 함수 포인터
} LinkedList;

typedef LinkedList List;

void ListInit(List* plist); // 리스트의 초기화에 사용

void FInsert(List* plist, LData data); // 정렬 기준 없이 리스트의 노드를 생성할 때 사용

void SInsert(List* plist, LData data); // 정렬 기준에 맞춰서 리스트의 노드를 생성할 때 사용

void LInsert(List* plist, LData data); // 리스트의 노드를 새로 생성할 때 사용

int LFirst(List* plist, LData* pdata); // 리스트의 맨 첫번째 데이터를 참조할 때 사용

int LNext(List* plist, LData* pdata); // LFirst 이후의 데이터를 참조할 때 사용

LData LRemove(List* plist); // LFirst, LNext가 참조한 데이터를 삭제하고 메모리 해제에 사용, 연속 호출 불가

int LCount(List* plist); // 현재 리스트에 저장된 노드 수 확인

void SetSortRule(List* plist, CompareFunc pcomp); // 리스트에 정렬 기준 함수를 등록

#endif