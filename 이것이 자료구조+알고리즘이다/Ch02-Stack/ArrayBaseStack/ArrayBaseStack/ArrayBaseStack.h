/*
* 이것이 자료구조+알고리즘이다 - 리스트(List) - 환형 이중 연결 리스트
* 파일명: ArrayBaseStack.h
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-02-02
* 이전 버전 작성 일자:
* 버전 내용: 배열 기반 스택 구현(C++, Template)
* 이전 버전 내용:
*/

#pragma once

#define IN
#define OUT

#include <Windows.h>
#include <tchar.h>

template <typename T>
class Stack
{
public:
	// 기본 생성자 사용하지 않음
	Stack() = delete;
	// 명시적으로 생성하도록 explicit 추가
	explicit Stack(IN DWORD cap) :m_capacity(cap), m_topIdx(-1), m_arrStack(new T [cap]) {}
	// 소멸자
	~Stack() { delete[] m_arrStack; }
	
	bool isEmpty()
	{
		if (m_topIdx < 0)
			return true;
		else
			return false;
	}

	void push(IN const T &data)
	{
		if (m_topIdx >= m_capacity)
			return;
		
		++m_topIdx;
		m_arrStack[m_topIdx] = data;
	}

	bool pop(OUT T &data)
	{
		if (isEmpty())
			return false;

		data = m_arrStack[m_topIdx--];
		return true;

	}

	bool peek(OUT T &data)
	{
		if (isEmpty())
			return false;

		data = m_arrStack[m_topIdx];
		return true;
	}
private:
	INT m_capacity;
	INT m_topIdx;
	T *m_arrStack;
};