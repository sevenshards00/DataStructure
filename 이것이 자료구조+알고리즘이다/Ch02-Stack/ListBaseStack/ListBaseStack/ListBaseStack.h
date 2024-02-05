/*
* 이것이 자료구조+알고리즘이다 - 스택(Stack)
* 파일명: ListBaseStack.h
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-02-05
* 이전 버전 작성 일자:
* 버전 내용: 연결 리스트 기반 스택 구현(C++, Template)
* 이전 버전 내용:
*/

#pragma once

#define IN
#define OUT

#include <iostream>
#include <Windows.h>
#include <tchar.h>

template <typename T>
struct Node
{
	T m_data;
	Node<T> *m_next = nullptr;
};

template <typename T>
class Stack
{
public:
	// 생성자
	Stack() :m_top(new Node<T>()) {};
	// 소멸자
	~Stack()
	{
		Node<T> *curr = m_top->m_next;
		while (curr->m_next != nullptr)
		{
			delete m_top;
			m_top = curr;
			curr = curr->m_next;
		}
		delete curr;
	}
	// isEmpty
	bool isEmpty()
	{
		if (m_top->m_next == nullptr)
			return true;
		else
			return false;
	}
	
	// push
	bool push(IN const T &data)
	{
		Node<T> *newNode = new(std::nothrow) Node<T>();
		if (newNode == nullptr)
			exit(-1);

		newNode->m_data = data;
		newNode->m_next = m_top->m_next;
		m_top->m_next = newNode;

		return true;
	}
	// pop
	bool pop(OUT T &data)
	{
		if (isEmpty())
			return false;
		
		Node<T> *popNode = m_top->m_next;
		data = popNode->m_data;

		m_top->m_next = popNode->m_next;
		delete popNode;

		return true;
	}
	// peek
	bool peek(OUT T &data)
	{
		if (isEmpty())
			return false;

		data = m_top->m_next->m_data;
		return true;
	}
private:
	Node<T> *m_top;
};