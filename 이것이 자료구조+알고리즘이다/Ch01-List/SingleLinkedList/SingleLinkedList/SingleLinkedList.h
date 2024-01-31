/*
* 이것이 자료구조+알고리즘이다 - 리스트(List) - 단일 연결 리스트
* 파일명: SingleLinkedList.h
* 파일 버전: 0.2
* 작성자: Sevenshards
* 작성 일자: 2024-01-31
* 이전 버전 작성 일자: 2024-01-29
* 버전 내용: STL의 forward_list 흉내내기 - 클래스명 변경 및 내부 구현 변경 (미완)
* 이전 버전 내용: 단일 연결 리스트 구현
*/

#pragma once

#include <cstdio>
#include <cstdlib>
#include <Windows.h>
#include <tchar.h>


// Node Class
template <typename T>
struct Node
{
	T data = NULL;
	Node<T> *next = nullptr;
};

// C++의 STL forward_list -> 단방향 연결 리스트
template <typename T>
class ForwardList
{
public:
	// 생성자 (List 생성)
	ForwardList();
	// 소멸자
	~ForwardList();
	// forward_list ADT	
	// 노드 추가(push_front) - head로 들어가는 경우
	void push_front(CONST T &newData);
	// 노드 삽입(insert_after) - 특정 위치 다음에 삽입하는 경우
	bool insert_after(Node<T>* curr, CONST T &newData);
	// 리스트의 처음 노드 위치를 반환 (begin)
	Node *begin();
	// 리스트의 끝 다음 노드 위치를 반환 (end)
	Node *end();
	// 노드 삭제(pop_front) - head에서 노드 제거
	bool pop_front();
	// 노드 삭제(erase_after) - 특정 위치 다음 노드 제거
	bool erase_after(Node<T> *curr, T* nodeData);
	// 노드 갯수(Count)
	DWORD Count() const;
private:
	Node<T> *head; // head
	Node<T> *tail; // tail
	DWORD nodeCnt = 0;
};

// 생성자 (List 생성) - 더미 노드 기반
template <typename T>
inline ForwardList<T>::ForwardList()
	:head(new Node<T>()), tail(new Node<T>())
{
	head->next = tail;
}
// 소멸자
template <typename T>
inline ForwardList<T>::~ForwardList()
{
	Node<T> *curr = head->next;
	Node<T> *before = head;

	while (curr->next == tail)
	{
		delete before;
		before = curr;
		curr = curr->next;
	}

	delete curr;

}
// forward_list ADT	
// 노드 추가(push_front) - head로 들어가는 경우
template <typename T>
inline void ForwardList<T>::push_front(CONST T &newData)
{
	Node<T> *newNode = new Node<T>();
	newNode->data = newData;
	newNode->next = head->next;
	head->next = newNode;
	nodeCnt++;
}
// // 노드 삽입(insert_after) - 특정 위치 다음에 삽입하는 경우
template <typename T>
inline bool ForwardList<T>::insert_after(Node *curr, CONST T &newData)
{
	Node<T> *newNode = new Node<T>();
	newNode->data = newData;

	DWORD insertIdx = 0;
	Node<T> *curr = head->next;
	Node<T> *before = head;
	

	if (idx >= nodeCnt)
		return false;

	while (idx != insertIdx)
	{
		before = curr;
		curr = curr->next;
		insertIdx++;
	}

	newNode->next = curr->next;
	curr->next = newNode;
	nodeCnt++;

	return true;
}

template <typename T>
inline Node *ForwardList<T>::begin()
{

}

template <typename T>
inline Node *ForwardList<T>::end()
{

}

// 노드 삭제(Destroy) - 대상 노드 제거
template <typename T>
inline bool ForwardList<T>::DestroyNode(DWORD idx, T *nodeData)
{
	DWORD removeIdx = 0;
	Node<T> *curr = head->next;
	Node<T> *before = head;
	
	if (idx >= nodeCnt)
		return false;

	while (removeIdx != idx)
	{
		before = curr;
		curr = curr->next;
		removeIdx++;
	}

	*nodeData = curr->data;
	before->next = curr->next;
	nodeCnt--;
	delete curr;
}
// 노드 갯수(Count)
template <typename T>
inline DWORD ForwardList<T>::Count() const
{
	return nodeCnt;
}