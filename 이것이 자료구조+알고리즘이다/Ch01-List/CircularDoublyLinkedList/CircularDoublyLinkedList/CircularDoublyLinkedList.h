/*
* 이것이 자료구조+알고리즘이다 - 리스트(List) - 환형 이중 연결 리스트
* 파일명: CircularDoublyLinkedList.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-02-01
* 이전 버전 작성 일자: 2024-01-31
* 버전 내용: 환형 이중 연결 리스트 구현(C++, Template)
* 이전 버전 내용:
*/

#pragma once

#define IN
#define OUT

#include <Windows.h>
#include <tchar.h>

template <typename T>
struct Node
{
	T m_data;
	Node<T> *m_next = nullptr;
	Node<T> *m_prev = nullptr;
};

template <typename T>
class List
{
public:
	// 생성자, 더미 노드 안씀
	List() : m_head(nullptr), m_tail(nullptr), m_nodeCnt(0) {}
	// 소멸자
	~List()
	{
		Node<T> *curr = m_head;
		while (curr->m_next != m_tail)
		{
			delete curr->m_prev;
			curr = curr->m_next;
		}

		delete curr;
	}
	// 삽입
	// head쪽으로 노드 삽입
	void push_front(IN const T &in_data)
	{
		Node<T> *newNode = new Node<T>();
		newNode->m_data = in_data;

		if (m_head == nullptr && m_tail == nullptr)
		{
			m_head = newNode;
			m_tail = newNode;
		}

		newNode->m_next = m_head;
		newNode->m_prev = m_tail;
		m_tail->m_next = newNode;
		m_head->m_prev = newNode;
		m_head = newNode;
		++m_nodeCnt;
	}
	// tail쪽으로 노드 삽입
	void push_back(IN const T &in_data)
	{
		Node<T> *newNode = new Node<T>();
		newNode->m_data = in_data;

		if (m_head == nullptr && m_tail == nullptr)
		{
			m_head = newNode;
			m_tail = newNode;
		}

		newNode->m_next = m_head;
		newNode->m_prev = m_tail;
		m_tail->m_next = newNode;
		m_head->m_prev = newNode;
		m_tail = newNode;
		++m_nodeCnt;

	}
	// 특정 위치 다음에 삽입
	// 인덱스는 0부터 시작한다 가정
	bool insert(IN const INT &idx, IN const T &in_data)
	{
		if (idx >= m_nodeCnt)
			return false;

		// 맨 처음 인덱스에 삽입할 경우 -> head에 삽입하는 것과 동일
		if (idx == 0)
		{
			push_front(in_data);
			return true;
		}
		
		// 맨 마지막 인덱스에 삽입할 경우 -> tail에 삽입하는 것과 동일
		if (idx == (m_nodeCnt - 1))
		{
			push_back(in_data);
			return true;
		}

		Node<T> *newNode = new Node<T>();
		newNode->m_data = in_data;

		Node<T> *curr = m_head;

		for (int i = 0; i != idx; ++i)
			curr = curr->m_next;

		newNode->m_next = curr->m_next;
		newNode->m_prev = curr->m_next->m_prev;
		curr->m_next->m_prev = newNode;
		curr->m_next = newNode;

		++m_nodeCnt;

		return true;
	}

	// 조회
	// 정방향 조회
	// head부터 0으로 시작
	bool getNodeForward(IN const INT &idx, OUT T &out_data)
	{
		if (idx >= m_nodeCnt)
			return false;

		Node<T> *curr = m_head;

		for (int i = 0; i != idx; ++i)
			curr = curr->m_next;

		out_data = curr->m_data;

		return true;
	}

	// 역방향 조회
	// tail부터 0으로 시작
	bool getNodeReverse(IN const INT &idx, OUT T &out_data)
	{
		if (idx >= m_nodeCnt)
			return false;

		Node<T> *curr = m_tail;

		for (int i = 0; i != idx; ++i)
			curr = curr->m_prev;

		out_data = curr->m_data;

		return true;
	}

	// 삭제
	// head쪽의 노드 삭제
	bool pop_front(OUT T &out_data)
	{
		Node<T> *popNode = m_head;

		// 리스트가 비어있는 경우
		if (m_head == nullptr && m_tail == nullptr)
			return false;
		// 마지막으로 남은 노드일 경우
		if (m_head == m_tail)
		{
			out_data = popNode->m_data;
			delete popNode;
			m_head = nullptr;
			m_tail = nullptr;
			--m_nodeCnt;

			return true;
		}

		m_head = m_head->m_next;
		m_head->m_prev = m_tail;
		m_tail->m_next = m_head;
		out_data = popNode->m_data;
		delete popNode;
		--m_nodeCnt;

		return true;

	}
	// tail쪽의 노드 삭제
	bool pop_back(OUT T &out_data)
	{
		Node<T> *popNode = m_tail;

		// 리스트가 비어있는 경우
		if (m_head == nullptr && m_tail == nullptr)
			return false;

		// 마지막으로 남은 노드일 경우
		if (m_head == m_tail)
		{
			out_data = popNode->m_data;
			delete popNode;
			m_head = nullptr;
			m_tail = nullptr;
			--m_nodeCnt;

			return true;
		}

		m_tail = m_tail->m_prev;
		m_head->m_prev = m_tail;
		m_tail->m_next = m_head;
		out_data = popNode->m_data;
		delete popNode;
		--m_nodeCnt;
		
	}
	// 특정 위치의 노드 삭제
	bool erase(IN const INT &idx, OUT T &out_data)
	{
		if (idx >= m_nodeCnt)
			return false;

		// 맨 처음 인덱스에 삽입할 경우 -> head에 삽입하는 것과 동일
		if (idx == 0)
		{
			pop_front(out_data);
			return true;
		}

		// 맨 마지막 인덱스에 삽입할 경우 -> tail에 삽입하는 것과 동일
		if (idx == (m_nodeCnt - 1))
		{
			pop_back(out_data);
			return true;
		}

		Node<T> *popNode = m_head;

		for (int i = 0; i != idx; ++i)
			popNode = popNode->m_next;

		out_data = popNode->m_data;
		popNode->m_prev->m_next = popNode->m_next;
		popNode->m_next->m_prev = popNode->m_prev;
		delete popNode;
		--m_nodeCnt;
	}

	// 노드 개수 반환
	DWORD count() const
	{
		return m_nodeCnt;
	}

private:
	Node<T> *m_head;
	Node<T> *m_tail;
	DWORD m_nodeCnt;
};