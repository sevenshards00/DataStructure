/*
* 이것이 자료구조+알고리즘이다 - 큐(Queue)
* 파일명: CircularQueue.h
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-02-29
* 이전 버전 작성 일자:
* 버전 내용: 배열 기반 환형 큐 구현(C++, Template)
* 이전 버전 내용:
*/

///////////////////////////////////////////////////////////////////////////
// 파일명: CircularQueue.h
// 파일 내용: 환형 큐에서 사용할 변수 및 클래스 정의
///////////////////////////////////////////////////////////////////////////

#pragma once

// 편의상 추가한 부분
// 인자로 들어올 데이터와 나갈 데이터 구분
#define IN
#define OUT

//--------------------------------------------------------------------
// 클래스(템플릿)명: CQueue
// 용도: 환형 Queue 객체
//--------------------------------------------------------------------

template <typename T>
class CQueue
{
public:
	// 컴파일러에 의해 생성되는 기본 생성자는 삭제 처리
	CQueue() = delete;
	
	// 생성자
	explicit CQueue(IN DWORD cap);
	// 소멸자
	~CQueue();
	// 삽입(rear에 삽입)
	bool push(IN CONST T &data);
	// 삭제(front에서 제거)
	bool pop(OUT T &data);
	// front 값 조회
	bool front(OUT T &data);
	// rear 값 조회
	bool back(OUT T &data);
	// Queue의 크기 반환
	DWORD size() const;
	// Queue가 비었는지 확인
	bool empty() const;
	// 환형 큐 Index를 돌리기 위한 Helper Function
	DWORD NextPosIdx(DWORD idx);
private:
	T *m_arrQueue;		// 배열 형태의 Queue
	DWORD m_capacity;	// 큐의 용량
	DWORD m_front;		// Queue의 맨 앞
	DWORD m_rear;		// Queue의 맨 뒤
	DWORD m_cnt;		// Queue의 요소 갯수
};

//--------------------------------------------------------------------
// 함수명: NextPosIdx
// 용도: 환형 큐 Index를 돌리기 위한 Helper Function
//--------------------------------------------------------------------
template <typename T>
DWORD CQueue<T>::NextPosIdx(DWORD idx)
{
	if (idx >= m_capacity)
		return 0;
	else
		return idx + 1;
}

// 생성자
template <typename T>
CQueue<T>::CQueue(IN DWORD cap)
	: m_capacity(cap), m_front(0), m_rear(0)
{
	m_arrQueue = new T[cap];
}

// 소멸자
template <typename T>
CQueue<T>::~CQueue()
{
	delete[] m_arrQueue;
}

//--------------------------------------------------------------------
// 함수명: push
// 용도: Queue의 Enqueue 연산
//--------------------------------------------------------------------
template <typename T>
bool CQueue<T>::push(IN CONST T &data)
{
	if (m_front == (NextPosIdx(m_rear)))
		return false;

	m_rear = NextPosIdx(m_rear);
	m_arrQueue[m_rear] = data;
	++m_cnt;

	return true;
}

//--------------------------------------------------------------------
// 함수명: pop
// 용도: Queue의 Dequeue 연산
//--------------------------------------------------------------------
template <typename T>
bool CQueue<T>::pop(OUT T &data)
{
	if (empty())
		return false;

	m_front = NextPosIdx(m_front);
	data = m_arrQueue[m_front];
	--m_cnt;

	return true;
}

//--------------------------------------------------------------------
// 함수명: front
// 용도: Queue의 front 값을 조회
//--------------------------------------------------------------------
template <typename T>
bool CQueue<T>::front(OUT T &data)
{
	if (empty())
		return false;

	data = m_arrQueue[NextPosIdx(m_front)];

	return true;
}

//--------------------------------------------------------------------
// 함수명: back
// 용도: Queue의 rear 값을 조회
//--------------------------------------------------------------------
template <typename T>
bool CQueue<T>::back(OUT T &data)
{
	if (empty())
		return false;

	data = m_arrQueue[m_rear];

	return true;
}

//--------------------------------------------------------------------
// 함수명: size
// 용도: 현재 Queue의 요소 갯수 반환 
//--------------------------------------------------------------------
template <typename T>
DWORD CQueue<T>::size() const
{
	return m_cnt;
}

//--------------------------------------------------------------------
// 함수명: empty
// 용도: Queue가 비었는지 확인
//--------------------------------------------------------------------
template <typename T>
bool CQueue<T>::empty() const
{
	if (m_front == m_rear)
		return true;
	else
		return false;
}