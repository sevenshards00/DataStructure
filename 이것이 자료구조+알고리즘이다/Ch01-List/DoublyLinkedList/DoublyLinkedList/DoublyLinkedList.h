/*
* 이것이 자료구조+알고리즘이다 - 리스트(List) - 이중 연결 리스트
* 파일명: DoublyLinkedList.h
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-30
* 이전 버전 작성 일자:
* 버전 내용: 이중 연결 리스트 구현
* 이전 버전 내용:
*/

#pragma once

#include <cstdio>
#include <cstdlib>
#include <Windows.h>
#include <tchar.h>

// 클래스 템플릿으로 구현
// 더미노드 기반
// Node Class
template <typename T>
struct Node
{
	T data = NULL;
	Node<T> *next = nullptr;
	Node<T> *prev = nullptr;
};

template <typename T>
class DoublyLinkedList
{
public:
	// 생성자 (List 초기화(Init)과 같음)
	DoublyLinkedList();
	// 소멸자
	~DoublyLinkedList();
	// 노드 추가 (head쪽으로)
	void AppendFront(CONST T &newData);
	// 노드 추가 (tail쪽으로)
	void AppendRear(CONST T &newData);
	// 노드 삽입 (특정 위치에 삽입)
	bool InsertNode(DWORD idx, CONST T &newData);
	// 노드 탐색 (순방향 탐색)
	bool SearchNodeForward(DWORD idx, T *nodeData);
	// 노드 탐색 (역방향 탐색)
	bool SearchNodeReverse(DWORD idx, T *nodeData);
	// 노드 삭제
	bool DestroyNode(DWORD idx, T *nodeData);
	// 노드 개수 반환
	DWORD Count() const;
private:
	Node<T> *head; // head
	Node<T> *tail; // tail
	DWORD nodeCnt = 0; // 노드 개수
};

// 생성자 (List 초기화(Init)과 같음)
template <typename T>
inline DoublyLinkedList<T>::DoublyLinkedList()
	:head(new Node<T>), tail(new Node<T>), nodeCnt(0)
{
	head->next = tail;
	tail->prev = head;
}
// 소멸자
template <typename T>
inline DoublyLinkedList<T>::~DoublyLinkedList()
{
	Node<T> *curr = head;
	while (curr == tail)
		
	

	while (curr->next == tail)
	{
		curr = curr->next;
		delete curr->prev;
	}

	delete curr;
}
// 노드 추가 (head쪽으로)
template <typename T>
inline void DoublyLinkedList<T>::AppendFront(CONST T &newData)
{
	Node<T> *newNode = new Node<T>; // 새 노드 생성
	newNode->data = newData; // 노드에 데이터를 복사
	newNode->next = head->next; // 새로운 노드의 다음 노드를 head가 가리키는 다음 노드로 변경
	head->next->prev = newNode; // head가 기존에 가리키던 다음 노드의 이전 노드를 새로운 노드로 변경
	newNode->prev = head; // 새로운 노드의 이전 노드를 head로 변경
	head->next = newNode; // 마지막으로 head의 다음 노드를 새 노드로 변경

	++nodeCnt;
}

// 노드 추가 (tail쪽으로)
template <typename T>
inline void DoublyLinkedList<T>::AppendRear(CONST T &newData)
{
	Node<T> *newNode = new Node<T>; // 새 노드 생성
	newNode->data = newData; // 노드에 데이터를 복사
	newNode->prev = tail->prev; // 새로운 노드의 이전 노드를 tail이 가리키는 이전 노드로 변경
	tail->prev->next = newNode; // tail이 기존에 가리키던 이전 노드의 다음 노드를 새로운 노드로 변경
	newNode->next = tail; // 새로운 노드의 다음 노드를 tail로 변경
	tail->prev = newNode; // 마지막으로 tail의 이전 노드를 새 노드로 변경

	++nodeCnt;
}
// 노드 삽입 (특정 위치 다음에 삽입)
template <typename T>
inline bool DoublyLinkedList<T>::InsertNode(DWORD idx, CONST T &newData)
{
	// 노드의 인덱스는 0부터 시작한다고 가정 (더미 노드 제외)
	// 삽입하고자 하는 위치가 범위를 벗어나는 경우
	if (idx >= nodeCnt || idx < 0)
		return false;

	DWORD insertIdx = 0;
	Node<T> *newNode = new Node<T>;
	newNode->data = newData;

	Node<T> *curr = head->next;
	while (insertIdx != idx)
	{
		curr = curr->next;
		++insertIdx;
	}

	newNode->next = curr->next;
	newNode->prev = curr->next->prev;
	curr->next->prev = newNode;
	curr->next = newNode;

	++nodeCnt;

	return true;
}

// 노드 탐색 (순방향 탐색)
template <typename T>
inline bool DoublyLinkedList<T>::SearchNodeForward(DWORD idx, T *nodeData)
{
	if (idx >= nodeCnt || idx < 0)
		return false;

	DWORD searchIdx = 0;
	Node<T> *curr = head->next;

	while (searchIdx != idx)
	{
		curr = curr->next;
		++searchIdx;
	}

	*nodeData = curr->data;
	return true;
}

// 노드 탐색 (역방향 탐색)
template <typename T>
inline bool DoublyLinkedList<T>::SearchNodeReverse(DWORD idx, T *nodeData)
{
	if (idx >= nodeCnt || idx < 0)
		return false;

	DWORD searchIdx = nodeCnt - 1;
	Node<T> *curr = tail->prev;

	while (searchIdx != idx)
	{
		curr = curr->prev;
		--searchIdx;
	}

	*nodeData = curr->data;
	return true;
}

// 노드 삭제
template <typename T>
inline bool DoublyLinkedList<T>::DestroyNode(DWORD idx, T *nodeData)
{
	if (idx >= nodeCnt || idx < 0 || (head->next == tail))
		return false;

	DWORD rIdx = 0;
	Node<T> *curr = head->next;

	while (rIdx != idx)
	{
		curr = curr->next;
		++rIdx;
	}

	curr->prev->next = curr->next;
	curr->next->prev = curr->prev;

	*nodeData = curr->data;
	delete curr;
	--nodeCnt;
	return true;
}

// 노드 개수 반환
template <typename T>
inline DWORD DoublyLinkedList<T>::Count() const
{
	return nodeCnt;
}