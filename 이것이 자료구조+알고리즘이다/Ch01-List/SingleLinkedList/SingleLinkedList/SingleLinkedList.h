/*
* 이것이 자료구조+알고리즘이다 - 리스트(List) - 단일 연결 리스트
* 파일명: SingleLinkedList.h
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-29
* 이전 버전 작성 일자: 
* 버전 내용: 단일 연결 리스트 구현
* 이전 버전 내용:
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

// List
template <typename T>
class SingleLinkedList
{
public:
	// 생성자 (List 생성)
	SingleLinkedList();
	// 소멸자
	~SingleLinkedList();
	// List ADT
	// 노드 추가(Append) - head로 들어가는 경우
	void AppendFront(CONST T &newData);
	// 노드 추가(Append) - tail로 들어가는 경우
	void AppendBack(CONST T &newData);
	// 노드 삽입(Insert) - 중간에 삽입하는 경우
	bool InsertNode(DWORD idx, CONST T &newData);
	// 노드 탐색(Search)
	bool SearchNode(DWORD idx, T* nodeData);
	// 노드 삭제(Destroy) - 대상 노드 제거
	bool DestroyNode(DWORD idx, T* nodeData);
	// 노드 갯수(Count)
	DWORD Count() const;
private:
	Node<T> *head;
	Node<T> *tail;
	DWORD nodeCnt = 0;
};

// 생성자 (List 생성) - 더미 노드 기반
template <typename T>
inline SingleLinkedList<T>::SingleLinkedList()
	:head(new Node<T>()), tail(new Node<T>())
{
	head->next = tail;
}
// 소멸자
template <typename T>
inline SingleLinkedList<T>::~SingleLinkedList()
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
// List ADT
// 노드 추가(Append) - head로 들어가는 경우
template <typename T>
inline void SingleLinkedList<T>::AppendFront(CONST T &newData)
{
	Node<T> *newNode = new Node<T>();
	newNode->data = newData;
	newNode->next = head->next;
	head->next = newNode;
	nodeCnt++;
}
// 노드 추가(Append) - tail로 들어가는 경우
template <typename T>
inline void SingleLinkedList<T>::AppendBack(CONST T &newData)
{
	Node<T> *newNode = new Node<T>();
	newNode->data = newData;
	newNode->next = tail;
	Node<T> *curr = head->next;
	Node<T> *before = head;

	while (curr->next != tail)
	{
		before = curr;
		curr = curr->next;
	}

	curr->next = newNode;
	nodeCnt++;
}
// 노드 삽입(Insert) - 중간에 삽입하는 경우
template <typename T>
inline bool SingleLinkedList<T>::InsertNode(DWORD idx, CONST T &newData)
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
// 노드 탐색(Search)
template <typename T>
inline bool SingleLinkedList<T>::SearchNode(DWORD idx, T *nodeData)
{
	DWORD searchIdx = 0;
	Node<T> *curr = head->next;
	Node<T> *before = head;
	

	if (idx >= nodeCnt)
		return false;

	while (searchIdx != idx)
	{
		before = curr;
		curr = curr->next;
		searchIdx++;
	}

	*nodeData = curr->data;
	return true;
}
// 노드 삭제(Destroy) - 대상 노드 제거
template <typename T>
inline bool SingleLinkedList<T>::DestroyNode(DWORD idx, T *nodeData)
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
inline DWORD SingleLinkedList<T>::Count() const
{
	return nodeCnt;
}