/*
* 이것이 자료구조+알고리즘이다 - 탐색(Search)
* 파일명: ITree.h
* 파일 버전: 0.13
* 작성자: Sevenshards
* 작성 일자: 2024-03-06
* 이전 버전 작성 일자: 2024-03-05
* 버전 내용: 레드 블랙 트리로 확장 (C++, Template)
* 이전 버전 내용: Transplant 함수 로직 수정 및 자잘한 부분 변경
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
	// 구조체(템플릿)명: st_RBNode
	// 용도: 레드 블랙 트리의 노드 (템플릿)
	//--------------------------------------------------------------------
	template <typename T>
	struct st_Node
	{
		st_Node<T> *m_parent;				// 부모 노드
		st_Node<T> *m_left;				// 왼쪽 자식 노드
		st_Node<T> *m_right;				// 오른쪽 자식 노드
		COLOR m_color = COLOR::BLACK;		// 노드의 색깔
		T m_key;							// 노드의 Key값
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
		virtual st_Node<T> *Search(IN const T &key) = 0;
		virtual st_Node<T> *Minimum(IN st_Node<T> *pNode) = 0;
		virtual st_Node<T> *Maximum(IN st_Node<T> *pNode) = 0;

		// 3) 순회(PreOrder, InOrder, PostOrder)
		virtual void PreOrderPrint() = 0;
		virtual void InOrderPrint() = 0;
		virtual void PostOrderPrint() = 0;

		virtual void PreOrder(IN st_Node<T> *) = 0;
		virtual void InOrder(IN st_Node<T> *) = 0;
		virtual void PostOrder(IN st_Node<T> *) = 0;

		// 4) 기타 연산
		virtual void Count() = 0;
		virtual void Draw(IN st_Node<T> *curr, IN HDC memDC, IN INT32 top, IN INT32 left, IN INT32 right) = 0;
	};
}