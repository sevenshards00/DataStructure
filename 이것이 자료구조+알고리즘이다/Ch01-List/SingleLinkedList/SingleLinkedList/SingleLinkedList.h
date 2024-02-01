/*
* 이것이 자료구조+알고리즘이다 - 리스트(List) - 단일 연결 리스트
* 파일명: SingleLinkedList.h
* 파일 버전: 0.4
* 작성자: Sevenshards
* 작성 일자: 2024-02-01
* 이전 버전 작성 일자: 2024-01-31
* 버전 내용: STL의 forward_list 흉내내기 (소멸자 로직 수정)
* 이전 버전 내용: STL의 forward_list 흉내내기 (프로토타입 완성)
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
	Node<T> *begin();
	// 리스트의 끝 다음 노드 위치를 반환 (end)
	Node<T> *end();
	// 노드 삭제(pop_front) - head에서 노드 제거
	bool pop_front(T *nodeData);
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

	// 널 포인터일 때까지
	while (curr->next != nullptr)
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
inline bool ForwardList<T>::insert_after(Node<T> *curr, CONST T &newData)
{
	Node<T> *newNode = new Node<T>();
	newNode->data = newData;

	newNode->next = curr->next;
	curr->next = newNode;
	++nodeCnt;

	return true;
}

// 리스트의 처음 노드 위치를 반환 (begin)
template <typename T>
inline Node<T> *ForwardList<T>::begin()
{
	return head->next;
}

// 리스트의 끝 다음 노드 위치를 반환 (end)
template <typename T>
inline Node<T> *ForwardList<T>::end()
{
	Node<T> *curr = head->next;
	while (curr->next != tail)
		curr = curr->next;

	return curr;
}

// 노드 삭제(pop_front) - head에서 노드 제거
template <typename T>
inline bool ForwardList<T>::pop_front(T *nodeData)
{
	Node<T> *dNode = head->next;
	if (dNode == tail)
		return false;

	head->next = dNode->next;
	*nodeData = dNode->data;
	delete dNode;
	--nodeCnt;

	return true;

}
// 노드 삭제(erase_after) - 특정 위치 다음 노드 제거
template <typename T>
inline bool ForwardList<T>::erase_after(Node<T> *curr, T *nodeData)
{
	// 노드가 없거나 하나만 있을 경우에는 특정 위치 다음에 지울 것이 없으므로 삭제하지 않는다.
	if (curr->next == tail || head->next == tail)
		return false;

	Node<T> *dNode = curr->next;
	curr->next = dNode->next;
	*nodeData = dNode->data;
	delete dNode;
	--nodeCnt;

	return true;
}

// 노드 갯수(Count)
template <typename T>
inline DWORD ForwardList<T>::Count() const
{
	return nodeCnt;
}