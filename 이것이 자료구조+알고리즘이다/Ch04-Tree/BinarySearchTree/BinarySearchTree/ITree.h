/*
* 이것이 자료구조+알고리즘이다 - 트리(Tree)
* 파일명: ITree.h
* 파일 버전: 0.12
* 작성자: Sevenshards
* 작성 일자: 2024-03-05
* 이전 버전 작성 일자: 2024-03-05
* 버전 내용: Transplant 함수 로직 수정 및 자잘한 부분 변경
* 이전 버전 내용: 주석 및 노드 갯수 반환하는 함수 추가
*/

///////////////////////////////////////////////////////////////////////////
// 파일명: ITree.h
// 파일 내용: 트리의 인터페이스 및 사용할 구조체와 변수 선언
///////////////////////////////////////////////////////////////////////////

#pragma once

#define IN
#define OUT

//--------------------------------------------------------------------
// 네임스페이스 : mylib_tree
// 용도: 이진 탐색 트리 라이브러리 구분을 위한 네임스페이스 선언
//--------------------------------------------------------------------

namespace mylib_tree
{
	//--------------------------------------------------------------------
	// 열거형: COLOR
	// 용도: 레드 블랙 트리의 노드에서 사용할 열거형 변수
	//--------------------------------------------------------------------
	enum class COLOR
	{
		BLACK = 0,
		RED
	};
	//--------------------------------------------------------------------
	// 구조체(템플릿)명: st_Node
	// 용도: 이진 탐색 트리, AVL 트리의 노드 (템플릿)
	//--------------------------------------------------------------------
	template <typename T>
	struct st_Node
	{
		st_Node<T> *m_parent;		// 부모 노드
		st_Node<T> *m_left;			// 왼쪽 자식 노드
		st_Node<T> *m_right;		// 오른쪽 자식 노드
		T m_key;					// 노드의 Key값
	};

	//--------------------------------------------------------------------
	// 구조체(템플릿)명: st_RBNode
	// 용도: 레드 블랙 트리의 노드 (템플릿)
	//--------------------------------------------------------------------
	template <typename T>
	struct st_RBNode
	{
		st_RBNode<T> *m_parent;		// 부모 노드
		st_RBNode<T> *m_left;		// 왼쪽 자식 노드
		st_RBNode<T> *m_right;		// 오른쪽 자식 노드
		COLOR m_color;				// 노드의 색깔
		T m_key;					// 노드의 Key값
	};

	//--------------------------------------------------------------------
	// 클래스(템플릿)명: ITree
	// 용도: Tree의 추상 클래스 템플릿
	//--------------------------------------------------------------------
	template <typename T>
	class ITree
	{
		// Tree에서의 기본 연산
		// 1) 변경(Insert, Delete)
		// 2) 질의(Search, Minimum, Maximum, Predecessor, Successor)
		// 3) 순회(PreOrder, InOrder, PostOrder)
	public:
		// 가상 소멸자
		virtual ~ITree() { };
		
		// 1) 변경(Insert, Delete)
		virtual void Insert(IN const T &key) = 0;
		virtual void Delete(IN const T &key) = 0;

		// 2) 질의(Search, Minimum, Maximum, Predecessor, Successor)
		virtual bool Search(IN const T &key, OUT T *value) = 0;
		virtual void Minimum() = 0;
		virtual void Maximum() = 0;
		virtual void Predecessor() = 0;
		virtual void Successor() = 0;

		// 3) 순회(PreOrder, InOrder, PostOrder)
		virtual void PreOrder() = 0;
		virtual void InOrder() = 0;
		virtual void PostOrder() = 0;

		// 4) 기타 연산
		virtual void Count() = 0;
	};
}