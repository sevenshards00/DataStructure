/*
* 이것이 자료구조+알고리즘이다 - 리스트(List) - 단일 연결 리스트
* 파일명: SingleLinkedList.h
* 파일 버전: 0.5
* 작성자: Sevenshards
* 작성 일자: 2024-02-01
* 이전 버전 작성 일자: 2024-02-01
* 버전 내용: 단일 연결 리스트 다시 구현
* 이전 버전 내용: STL의 forward_list 흉내내기 (소멸자 로직 수정)
*/

#pragma once

// 앞으로 들이면 좋을 습관
// 들어가고 나가는 매개변수를 통해서 들어오고 나가는 데이터를 표시할 때는 매크로를 이용하자.
// 코드 가독성이 한결 올라간다.
#define IN
#define OUT

#include <cstdio>
#include <cstdlib>
#include <Windows.h>
#include <tchar.h>


// Node Class
template <typename T>
struct Node
{
	T m_data; // 노드의 데이터
	Node<T> *m_next; // 다음 노드를 가리키기 위한 포인터
};

// C++의 STL forward_list -> 단방향 연결 리스트
template <typename T>
class ForwardList // C++의 단일 연결 리스트 이름을 따서 ForwardList라고 하였음.
{
public:
	// 생성자(Constructor)
	ForwardList() :m_head(new Node<T>()), m_tail(new Node<T>())
	{
		m_head->m_next = m_tail;
		m_tail->m_next = nullptr;
	};
	// 소멸자(Destructor)
	~ForwardList()
	{
		// 더미 노드 기반이며, tail까지 있는 단일 연결 리스트.
		// 소멸자에서는 head부터 tail까지 모두 지워버리는 케이스
		Node<T> *curr = m_head->m_next;
		Node<T> *before = m_head;

		// 현재 가리키는 노드의 다음이 tail이 아닐 때까지 할당 해제 수행
		while (curr->m_next != nullptr)
		{
			delete before;
			before = curr;
			curr = curr->m_next;
		}
		// 위의 loop가 끝나면 curr는 tail이 된다.
		delete curr;
	}
	// head에 노드 삽입
	void push_front(IN const T &in_data)
	{
		Node<T> *newNode = new Node<T>();
		newNode->m_data = in_data;
		newNode->m_next = m_head->m_next;
		m_head->m_next = newNode;
	}

private:
	Node<T> *m_head;
	Node<T> *m_tail;
	DWORD m_nodeCnt = 0;
};