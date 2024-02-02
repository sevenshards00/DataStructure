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

		// 현재 가리키는 노드의 다음이 nullptr이 아닐 때까지 할당 해제 수행
		// tail의 next는 nullptr
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
		++m_nodeCnt;
	}
	// tail에 노드 삽입
	void push_back(IN const T &in_data)
	{
		// curr와 before를 이용
		Node<T> *curr = m_head->m_next;
		Node<T> *before = m_head;

		// loop를 돌면서 tail 직전까지 이동한다.
		while (curr->m_next != m_tail)
		{
			before = curr;
			curr = curr->m_next;
		}
		// loop가 끝나면 curr은 tail의 직전 노드를 가리키게 된다.
		// 새 노드 생성
		Node<T> *newNode = new Node<T>();
		newNode->m_data = in_data;
		
		newNode->m_next = m_tail; // 새 노드는 tail을 가리키고
		curr->m_next = newNode; // tail의 직전 노드가 새 노드를 가리키게 한다.
		++m_nodeCnt;
	}
	// 특정 노드 다음에 노드 삽입
	bool insert_after(IN const DWORD &idx, IN const T &in_data)
	{
		// 지정한 노드 위치가 전체 인덱스를 벗어나는 경우 -> 삽입 불가
		// 예를 들어 전체 노드가 3개라면 인덱스는 0, 1, 2가 되며 3을 입력 받으면 삽입할 수 없다.
		if (idx >= m_nodeCnt)
			return false;

		// 노드의 위치는 0부터 시작한다고 가정
		DWORD loc = idx;

		Node<T> *curr = m_head->m_next;

		// loop로 현재 노드 위치까지 이동
		for (DWORD i = 0; i != loc; ++i)
			curr = curr->m_next;
		
		Node<T> *newNode = new Node<T>();
		newNode->m_next = curr->m_next;
		newNode->m_data = in_data;
		curr->m_next = newNode;
		++m_nodeCnt;
		return true;
	}
	// 특정 위치의 노드 조회
	bool search(IN const DWORD &idx, OUT T &out_data)
	{
		// 지정한 노드 위치가 전체 인덱스를 벗어나는 경우 -> 조회 불가
		// 예를 들어 전체 노드가 3개라면 인덱스는 0, 1, 2가 되며 3을 입력 받으면 조회할 수 없다.
		if (idx >= m_nodeCnt)
			return false;

		DWORD loc = idx;
		Node<T> *curr = m_head->m_next;
		// loop로 지정한 위치의 노드까지 이동
		for (DWORD i = 0; i != loc; ++i)
			curr = curr->m_next;

		out_data = curr->m_data;
		return true;
	}
	// head에서 노드 삭제
	bool pop_front(OUT T &out_data)
	{
		// head가 가리키는 다음 노드가 tail이라면 -> 리스트가 비었다는 것
		if (m_head->m_next == m_tail)
			return false;

		Node<T> *popNode = m_head->m_next; // 삭제 대상 노드는 head 다음의 노드
		out_data = popNode->m_data; // 삭제 대상 노드의 데이터
		m_head->m_next = popNode->m_next; // head가 가리키는 다음 노드를 현재 삭제할 노드가 가리키는 다음 노드로 변경

		delete popNode; // 노드를 할당 해제하고
		--m_nodeCnt; // 노드 개수 감소
		return true;
	}
	// tail에서 노드 삭제
	bool pop_back(OUT T &out_data)
	{
		// head가 가리키는 다음 노드가 tail이라면 -> 리스트가 비었다는 것
		if (m_head->m_next == m_tail)
			return false;

		// curr와 before를 이용하여 tail까지 이동
		Node<T> *curr = m_head->m_next;
		Node<T> *before = m_head;
		Node<T> *popNode;
		
		// loop를 돌면서 tail 직전까지 이동한다.
		while (curr->m_next != m_tail)
		{
			before = curr;
			curr = curr->m_next;
		}

		popNode = curr;
		out_data = popNode->m_data;
		before->m_next = m_tail;
		delete popNode;
		--m_nodeCnt;
		return true;
	}

	// 특정 인덱스의 노드 삭제
	bool remove(IN const DWORD idx, OUT T &out_data)
	{
		if (idx >= m_nodeCnt)
			return false;

		Node<T> *curr = m_head->m_next;
		Node<T> *before = m_head;
		Node<T> *popNode;

		for (DWORD i = 0; i != idx; ++i)
		{
			before = curr;
			curr = curr->m_next;
		}

		popNode = curr;
		out_data = popNode->m_data;
		before->m_next = curr->m_next;
		delete popNode;
		--m_nodeCnt;
		return true;
	}

	// 리스트의 노드 개수 반환
	DWORD count()
	{
		return m_nodeCnt;
	}
private:
	Node<T> *m_head;
	Node<T> *m_tail;
	DWORD m_nodeCnt = 0;
};