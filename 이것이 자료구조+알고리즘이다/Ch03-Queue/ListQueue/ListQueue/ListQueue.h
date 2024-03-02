/*
* 이것이 자료구조+알고리즘이다 - 큐(Queue)
* 파일명: ListQueue.h
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-03-02
* 이전 버전 작성 일자: 
* 버전 내용: 단일 연결 리스트 기반 큐 구현(C++, Template)
* 이전 버전 내용: 
*/

///////////////////////////////////////////////////////////////////////////
// 파일명: ListQueue.h
// 파일 내용: 리스트 기반 큐에서 사용할 변수 및 클래스 정의
///////////////////////////////////////////////////////////////////////////

#pragma once

// 편의상 추가한 부분
// 인자로 들어올 데이터와 나갈 데이터 구분
#define IN
#define OUT

//--------------------------------------------------------------------
// 구조체(템플릿)명: st_Node
// 용도: Queue의 노드 템플릿
//--------------------------------------------------------------------
template <typename T>
struct st_Node
{
	T m_data;
	st_Node<T> *m_next;
	st_Node<T> *m_prev;
};

//--------------------------------------------------------------------
// 클래스(템플릿)명: CListQueue
// 용도: 리스트 기반 Queue 클래스 템플릿
//--------------------------------------------------------------------

template <typename T>
class CListQueue
{
public:
	// 생성자
	CListQueue();
	// 소멸자
	~CListQueue();
	// 삽입
	void push(IN CONST T &ref);
	// 삭제
	void pop();
	// front 값 조회
	void front(OUT T &ref);
	// rear 값 조회
	void back(OUT T &ref);
	// Queue의 요소 갯수
	DWORD size() const;
	// Queue가 비었는지 확인
	bool empty() const;
private:
	st_Node<T> *m_front;	// Queue의 front
	st_Node<T> *m_rear;		// Queue의 rear
	DWORD m_cnt;			// Queue의 요소 갯수
};

//--------------------------------------------------------------------
// 함수명: CListQueue
// 용도: 생성자
//--------------------------------------------------------------------
template <typename T>
CListQueue<T>::CListQueue() : m_cnt(0)
{
	// 더미 노드 기반의 Queue
	// front와 rear에 더미 노드 생성
	m_front = new st_Node<T>;
	m_rear = new st_Node<T>;
	m_front->m_next = m_rear;
	m_front->m_prev = nullptr;
	m_rear->m_next = nullptr;
	m_rear->m_prev = m_front;
}

//--------------------------------------------------------------------
// 함수명: ~CListQueue
// 용도: 소멸자
//--------------------------------------------------------------------
template <typename T>
CListQueue<T>::~CListQueue()
{

}

//--------------------------------------------------------------------
// 함수명: push
// 용도: Queue의 Enqueue 연산
//--------------------------------------------------------------------
template<typename T>
void CListQueue<T>::push(IN CONST T &ref)
{
	st_Node<T> *newNode = new st_Node<T>;
	newNode->m_data = ref;
	newNode->m_next = m_rear;
	newNode->m_prev = m_rear->m_prev;
	m_rear->m_prev->m_next = newNode;
	m_rear->m_prev = newNode;
	++m_cnt;
}
//--------------------------------------------------------------------
// 함수명: pop
// 용도: Queue의 Dequeue 연산
//--------------------------------------------------------------------
template<typename T>
void CListQueue<T>::pop()
{
	if (empty())
		return;

	st_Node<T> *dNode = m_front->m_next;
	dNode->m_next->m_prev = m_front;
	m_front->m_next = dNode->m_next;

	delete dNode;
	--m_cnt;
}

//--------------------------------------------------------------------
// 함수명: front
// 용도: Queue의 front값 조회
//--------------------------------------------------------------------

template<typename T>
void CListQueue<T>::front(OUT T &ref)
{
	if (empty())
		return;

	ref = m_front->m_next->m_data;
}

//--------------------------------------------------------------------
// 함수명: back
// 용도: Queue의 rear 값 조회
//--------------------------------------------------------------------
template<typename T>
void CListQueue<T>::back(OUT T &ref)
{
	if (empty())
		return;

	ref = m_rear->m_prev->m_data;
}

//--------------------------------------------------------------------
// 함수명: size
// 용도: Queue의 요소 갯수 반환
//--------------------------------------------------------------------
template<typename T>
DWORD CListQueue<T>::size() const
{
	return m_cnt;
}

//--------------------------------------------------------------------
// 함수명: empty
// 용도: Queue가 비었는지 확인
//--------------------------------------------------------------------
template<typename T>
bool CListQueue<T>::empty() const
{
	if (m_front->m_next == m_rear)
		return true;
	else
		return false;
}