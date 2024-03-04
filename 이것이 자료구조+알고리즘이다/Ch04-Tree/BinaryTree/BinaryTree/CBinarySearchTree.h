/*
* 이것이 자료구조+알고리즘이다 - 트리(Tree)
* 파일명: CBinaryTree.h
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-03-02
* 이전 버전 작성 일자:
* 버전 내용: 이진 트리 구현(C++, Template) (구현중)
* 이전 버전 내용:
*/

///////////////////////////////////////////////////////////////////////////
// 파일명: BinaryTree.h
// 파일 내용: 이진 트리 클래스 템플릿 정의
///////////////////////////////////////////////////////////////////////////

#pragma once

#define IN
#define OUT

namespace mylib_tree
{
	//--------------------------------------------------------------------
	// 클래스(템플릿)명: CBinaryTree
	// 용도: BinaryTree 클래스 템플릿
	//--------------------------------------------------------------------
	template <typename T>
	class CBinarySearchTree : public CBinaryTree<T>
	{
	public:
		// 생성자
		CBinarySearchTree();
		// 소멸자
		~CBinarySearchTree() {}
		virtual bool Insert(T key) override;
		virtual bool Delete(T key) override;
	};
}

template <typename T>
mylib_tree::CBinarySearchTree<T>::CBinarySearchTree()
	:mylib_tree::CBinaryTree<T>::m_nodeCnt(0)
{
	mylib_tree::CBinaryTree<T>::m_NIL.m_parent = &m_NIL;
	mylib_tree::CBinaryTree<T>::m_NIL.m_left = &m_NIL;
	mylib_tree::CBinaryTree<T>::m_NIL.m_right = &m_NIL;
	mylib_tree::CBinaryTree<T>::m_NIL.m_COLOR = COLOR::BLACK;
	mylib_tree::CBinaryTree<T>::m_pRoot = &m_NIL;
}

template <typename T>
bool mylib_tree::CBinarySearchTree<T>::Insert(T key)
{
	st_Node<T> newNode = new st_Node<T>;
	newNode->m_color = COLOR::BLACK;
	newNode->m_key = key;
	newNode->m_left = &m_NIL;
	newNode->m_right = &m_NIL;
	
	if (m_pRoot == &m_NIL || m_pRoot == nullptr)
	{
		m_pRoot = newNode;
		++m_nodeCnt;
		return true;
	}

	if (m_Insert(m_pRoot, newNode))
	{
		++m_nodeCnt;
		return true;
	}

	return false;
}

template <typename T>
bool mylib_tree::CBinarySearchTree<T>::Delete(T key)
{
	st_Node<T> dNode = m_Delete(m_pRoot, key);
	if (dNode != nullptr)
	{
		delete dNode;

		--m_nodeCnt;
		return true;
	}

	return false;
}