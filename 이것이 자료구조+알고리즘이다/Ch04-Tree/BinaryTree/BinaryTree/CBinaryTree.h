/*
* 이것이 자료구조+알고리즘이다 - 트리(Tree)
* 파일명: CTree.h
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-03-04
* 이전 버전 작성 일자:
* 버전 내용: 이진 트리 구현(C++, Template) (구현중)
* 이전 버전 내용:
*/

#pragma once

///////////////////////////////////////////////////////////////////////////
// 파일명: CTree.h
// 파일 내용: 기본적인 트리 클래스 템플릿 정의
///////////////////////////////////////////////////////////////////////////

#define IN
#define OUT

//--------------------------------------------------------------------
// 네임스페이스 : mylib_tree
// 용도: 트리 라이브러리 구분을 위한 네임스페이스 선언
//--------------------------------------------------------------------

namespace mylib_tree
{
	
	// Red-Black Tree에서 쓰일 열거형 변수.
	// 
	enum class COLOR
	{
		BLACK = 0,
		RED
	};

	//--------------------------------------------------------------------
	// 구조체(템플릿)명: st_Node
	// 용도: 트리의 노드 (템플릿)
	//--------------------------------------------------------------------
	template <typename T>
	struct st_Node
	{
		st_Node<T> *m_parent;			// Tree의 Node의 부모 노드
		st_Node<T> *m_left;				// Tree의 Node의 왼쪽 자식 노드
		st_Node<T> *m_right;			// Tree의 Node의 오른쪽 자식 노드
		COLOR m_color;					// Tree의 Node의 색깔
		T m_key;						// Tree의 Node가 가지는 Key(현재 기준으로는 STL의 set과 동일, Value가 추가되면 map)
	};

	//--------------------------------------------------------------------
	// 클래스(템플릿)명: CTree
	// 용도: Tree 클래스 템플릿
	//--------------------------------------------------------------------
	template <typename T>
	class CBinaryTree
	{
	public:
		CBinaryTree() {}					// 생성자
		virtual ~CBinaryTree() { }			// 소멸자
		
		// Interface
		// Tree에서의 기본 연산
		// 1) 변경(Insert, Delete)
		// 2) 질의(Search, Minimum, Maximum, Predecessor, Successor)
		// 3) 순회(PreOrder, InOrder, PostOrder)
		
		// 변경 연산 - 순수 가상 함수
		// Tree에서의 노드 삽입과 제거 연산은 별도로 구현되어야 함 -> Tree마다 삽입, 삭제 연산이 다르기 때문
		// 노드 삽입
		virtual bool Insert(T key) = 0;
		// 노드 제거
		virtual bool Delete(T key) = 0;

		// 질의(Query) 연산
		// 특정 노드 탐색 (Search)
		bool Search(T key);
		// 최소값을 가진 노드 탐색 (Minimum)
		T Minimum();
		// 최대값을 가진 노드 탐색 (Maximum)
		T Maximum();
		// 직전 노드 (Predecessor)
		T Predecessor(T key);
		// 직후 노드 (Successor)
		T Successor(T key);

		// 노드 순회
		// 전위 순회
		void PreOrder();
		// 중위 순회
		void InOrder();
		// 후위 순회
		void PostOrder();

		// 실제 연산 구현부
	protected:
		// 변경 연산
		// 노드 삽입
		bool m_Insert(IN st_Node<T> *pTree, IN st_Node<T> *pInsert);
		// 노드 제거
		st_Node<T> m_Delete(IN st_Node<T> *pNode, IN T key);

		// 질의(Query) 연산
		// 특정 노드 탐색 (m_Search)
		st_Node<T> *m_Search(IN st_Node<T> *pNode, IN T key);
		// 최소값을 가진 노드 탐색 (m_Minimum)
		st_Node<T> *m_Minimum(IN st_Node<T> *pNode);
		// 최대값을 가진 노드 탐색 (m_Maximum)
		st_Node<T> *m_Maximum(IN st_Node<T> *pNode);
		// 직전 노드 (m_Predecessor)
		st_Node<T> *m_Predecessor(IN st_Node<T> *pNode);
		// 직후 노드 (m_Successor)
		st_Node<T> *m_Successor(IN st_Node<T> *pNode);

		// 노드 순회
		// 전위 순회
		void m_PreOrder(IN const st_Node<T> &pTree);
		// 중위 순회
		void m_InOrder(IN const st_Node<T> &pTree);
		// 후위 순회
		void m_PostOrder(IN const st_Node<T> &pTree);
	protected:
		st_Node<T> *m_pRoot;	// Tree의 root노드
		st_Node<T> m_NIL;		// NIL 노드
		DWORD m_nodeCnt;		// Tree의 노드 개수
	};
}

//--------------------------------------------------------------------
// 클래스 멤버 함수 정의 부분
//--------------------------------------------------------------------

//--------------------------------------------------------------------
// 인터페이스 (Interface)
//--------------------------------------------------------------------

//--------------------------------------------------------------------
// 함수명: Search(T Key)
// 용도: 특정 노드 탐색 (Search)
//--------------------------------------------------------------------
template <typename T>
bool mylib_tree::CBinaryTree<T>::Search(T key)
{
	if (m_pRoot == &m_NIL)
		return false;

	if (m_Search(m_pRoot, key) != nullptr)
		return true;
	else
		return false;

}

//--------------------------------------------------------------------
// 함수명: Minimum()
// 용도: 최소값을 가진 노드 탐색
//--------------------------------------------------------------------
template <typename T>
T mylib_tree::CBinaryTree<T>::Minimum()
{
	st_Node<T> target = m_Minimum(m_pRoot);
	return target->m_key;
}

//--------------------------------------------------------------------
// 함수명: Maximum()
// 용도: 최대값을 가진 노드 탐색
//--------------------------------------------------------------------
template <typename T>
T mylib_tree::CBinaryTree<T>::Maximum()
{
	st_Node<T> target = m_Maximum(m_pRoot);
	return target->m_key;
}

//--------------------------------------------------------------------
// 함수명: Predecessor(T key)
// 용도: 직전 노드 요소 탐색
//--------------------------------------------------------------------
template <typename T>
T mylib_tree::CBinaryTree<T>::Predecessor(T key)
{
	st_Node<T> curr = m_Search(m_pRoot, key);
	st_Node<T> target = m_Predecessor(curr);
	return target->m_key;
}

//--------------------------------------------------------------------
// 함수명: Successor(T key)
// 용도: 직후 노드 요소 탐색
//--------------------------------------------------------------------
template <typename T>
T mylib_tree::CBinaryTree<T>::Successor(T key)
{
	st_Node<T> curr = m_Search(m_pRoot, key);
	st_Node<T> target = m_Successor(curr);
	return target->m_key;
}

//--------------------------------------------------------------------
// 함수명: PreOrder()
// 용도: 전위 순회 결과 출력
//--------------------------------------------------------------------
template <typename T>
void mylib_tree::CBinaryTree<T>::PreOrder()
{
	wprintf(L"PreOrder:\t");
	m_PreOrder(m_pRoot);
	wprintf(L"\n");
}

//--------------------------------------------------------------------
// 함수명: InOrder()
// 용도: 중위 순회 결과 출력
//--------------------------------------------------------------------
template <typename T>
void mylib_tree::CBinaryTree<T>::InOrder()
{
	wprintf(L"InOrder:\t");
	m_InOrder(m_pRoot);
	wprintf(L"\n");
}

//--------------------------------------------------------------------
// 함수명: PostOrder()
// 용도: 후위 순회 결과 출력
//--------------------------------------------------------------------
template <typename T>
void mylib_tree::CBinaryTree<T>::PostOrder()
{
	wprintf(L"PostOrder:\t");
	m_PostOrder(m_pRoot);
	wprintf(L"\n");
}


//--------------------------------------------------------------------
// 구현 (Implementaion)
//--------------------------------------------------------------------

// 변경 연산
// 
//--------------------------------------------------------------------
// 함수명: m_Insert
// 용도: 노드 삽입
//--------------------------------------------------------------------
template <typename T>
bool mylib_tree::CBinaryTree<T>::m_Insert(IN st_Node<T> *pCurr, IN st_Node<T> *pInsert)
{
	st_Node<T> *curr_pos = pCurr;
	st_Node<T> *curr_parent = pCurr->m_parent;

	while (curr_pos != &m_NIL)
	{
		curr_parent = curr_pos;
		if (pInsert->m_key < curr_pos->m_key)
			curr_pos = curr_pos->m_left;
		else
			curr_pos = curr_pos->m_right;
	}

	pInsert->m_parent = curr_parent;
}
// 노드 제거
template <typename T>
mylib_tree::st_Node<T> mylib_tree::CBinaryTree<T>::m_Delete(IN st_Node<T> *pNode, IN T key)
{
	st_Node<T> *dNode;
	if (pNode == &m_NIL)
		return nullptr;

	if (pNode->m_key == key)
	{
		if (pNode->m_left == &m_NIL && pNode->m_right == &m_NIL)
		{
			if (pNode->m_parent == &m_NIL)
				m_pRoot = &m_NIL;
			else if (pNode->m_parent->m_left == pNode)
				pNode->m_parent->m_left = &m_NIL;
			else if (pNode->m_parent->m_righy == pNode)
				pNode->m_parent->m_right = &m_NIL;

			return pNode;
		}
		else if (pNode->m_left == &m_NIL || pNode->m_right == &m_NIL)
		{
			if (pNode->m_left != &m_NIL)
				dNode = pNode->m_left;
			else
				dNode = pNode->m_right;

			pNode->m_key = dNode->m_key;
			pNode->m_left = dNode->m_left;
			pNode->m_right = dNode->m_right;

			if (dNode->m_left != &m_NIL)
				dNode->m_left->m_parent = pNode;

			if (dNode->m_right != &m_NIL)
				dNode->m_right->m_parent = pNode;

			return dNode;
		}

		else
		{
			dNode = pNode->m_right;

			while (dNode->m_left != &m_NIL)
				dNode = dNode->m_left;

			pNode->m_key = dNode->m_key;
			dNode->m_right->m_parent = dNode->m_parent;

			if (dNode->m_parent->m_left == dNode)
				dNode->m_parent->m_left = dNode->m_right;
			else
				dNode->m_parent->m_right = dNode->m_right;

			return dNode;
		}

		if (pNode->m_key > key)
		{
			if (pNode->m_left == nullptr)
				return nullptr;
			else
				return m_Delete(pNode->m_left, key);
		}

		if (pNode->m_key < key)
		{
			if (pNode->m_right == nullptr)
				return nullptr;
			else
				return m_Delete(pNode->m_right, key);
		}

		return nullptr;
	}
}

// 질의(Query) 연산
//--------------------------------------------------------------------
// 함수명: m_Search
// 용도: 특정 키 값을 가진 노드 탐색
//--------------------------------------------------------------------
template <typename T>
mylib_tree::st_Node<T> *mylib_tree::CBinaryTree<T>::m_Search(IN st_Node<T> *pNode, IN T key)
{
	while (pNode != &m_NIL && pNode->m_key != key)
	{
		if (key < pNode->m_key)
			pNode = pNode->m_left;
		else
			pNode = pNode->m_right;
	}
	return pNode;
}

//--------------------------------------------------------------------
// 함수명: m_Minimum
// 용도: 최소값 노드 탐색
//--------------------------------------------------------------------
template <typename T>
mylib_tree::st_Node<T> *mylib_tree::CBinaryTree<T>::m_Minimum(IN st_Node<T> *pNode)
{
	while (pNode->m_left != &m_NIL)
		pNode = pNode->m_left;

	return pNode;
}

//--------------------------------------------------------------------
// 함수명: m_Maximum
// 용도: 최대값 노드 탐색
//--------------------------------------------------------------------
template <typename T>
mylib_tree::st_Node<T> *mylib_tree::CBinaryTree<T>::m_Maximum(IN st_Node<T> *pNode)
{
	while (pNode->m_right != &m_NIL)
		pNode = pNode->m_right;

	return pNode;
}

//--------------------------------------------------------------------
// 함수명: m_Predecessor
// 용도: 직전 노드 탐색
//--------------------------------------------------------------------
template <typename T>
mylib_tree::st_Node<T> *mylib_tree::CBinaryTree<T>::m_Predecessor(IN st_Node<T> *pNode)
{
	if (pNode.m_left != &m_NIL)
		return m_Minimum(pNode);

	st_Node<T> *target = pNode->m_parent;
	while (target != &m_NIL && pNode == target->m_left)
	{
		pNode = target;
		target = target.m_parent;
	}

	return target;
}

//--------------------------------------------------------------------
// 함수명: m_Successor
// 용도: 직후 노드 탐색
//--------------------------------------------------------------------
template <typename T>
mylib_tree::st_Node<T> *mylib_tree::CBinaryTree<T>::m_Successor(IN st_Node<T> *pNode)
{
	if (pNode.m_right != &m_NIL)
		return m_Maximum(pNode);

	st_Node<T> *target = pNode->m_parent;
	while (target != &m_NIL && pNode == target->m_right)
	{
		pNode = target;
		target = target->m_parent;
	}

	return target;
}

//--------------------------------------------------------------------
// 함수명: m_PreOrder()
// 용도: 전위 순회
//--------------------------------------------------------------------
template <typename T>
void mylib_tree::CBinaryTree<T>::m_PreOrder(IN const st_Node<T> &pTree)
{
	if (pTree == &m_NIL || pTree == nullptr)
		return;
	wprintf(L"%d", pTree->m_key);
	m_PreOrder(pTree->m_left);
	m_PreOrder(pTree->m_right);
}

//--------------------------------------------------------------------
// 함수명: m_InOrder()
// 용도: 중위 순회
//--------------------------------------------------------------------
template <typename T>
void mylib_tree::CBinaryTree<T>::m_InOrder(IN const st_Node<T> &pTree)
{
	if (pTree == &m_NIL || pTree == nullptr)
		return;

	m_InOrder(pTree->m_left);
	wprintf(L"%d", pTree->m_key);
	m_InOrder(pTree->m_right);
}

//--------------------------------------------------------------------
// 함수명: m_PostOrder()
// 용도: 후위 순회
//--------------------------------------------------------------------
template <typename T>
void mylib_tree::CBinaryTree<T>::m_PostOrder(IN const st_Node<T> &pTree)
{
	if (pTree == &m_NIL || pTree == nullptr)
		return;

	m_PostOrder(pTree->m_left);
	m_PostOrder(pTree->m_right);
	wprintf(L"%d", pTree->m_key);
}