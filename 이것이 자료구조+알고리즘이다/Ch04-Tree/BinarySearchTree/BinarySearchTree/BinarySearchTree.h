/*
* 이것이 자료구조+알고리즘이다 - 트리(Tree)
* 파일명: BinarySearchTree.h
* 파일 버전: 0.12
* 작성자: Sevenshards
* 작성 일자: 2024-03-05
* 이전 버전 작성 일자: 2024-03-05
* 버전 내용: Transplant 함수 로직 수정 및 자잘한 부분 변경
* 이전 버전 내용: 주석 및 노드 갯수 반환하는 함수 추가
*/

///////////////////////////////////////////////////////////////////////////
// 파일명: BinarySearchTree.h
// 파일 내용: 이진 탐색 트리 클래스 템플릿 정의
///////////////////////////////////////////////////////////////////////////

#pragma once

#define IN
#define OUT

//--------------------------------------------------------------------
// 네임스페이스 : mylib_tree
// 용도: 트리 라이브러리 구분을 위한 네임스페이스 선언
//--------------------------------------------------------------------
namespace mylib_tree
{
	//--------------------------------------------------------------------
	// 클래스(템플릿)명: CBSTree
	// 용도: 이진 탐색 트리의 클래스 템플릿
	//--------------------------------------------------------------------
	template <typename T>
	class CBSTree : public ITree<T>
	{
	public:
		// 생성자
		CBSTree();
		// 소멸자
		~CBSTree();
		
		//--------------------------------------------------------------------
		// 인터페이스 (Interface)
		//--------------------------------------------------------------------
		
		// 1) 변경(Insert, Delete)
		virtual void Insert(IN const T &key) override;
		virtual void Delete(IN const T &key) override;

		// 2) 질의(Search, Minimum, Maximum, Predecessor, Successor)
		virtual bool Search(IN const T &key, OUT T *value) override;
		virtual void Minimum() override;
		virtual void Maximum() override;
		virtual void Predecessor() override;
		virtual void Successor() override;

		// 3) 순회(PreOrder, InOrder, PostOrder)
		virtual void PreOrder() override;
		virtual void InOrder() override;
		virtual void PostOrder() override;

		// 4) 기타 연산
		virtual void Count() override;
		
	private:
		// 1) 변경(Insert, Delete)
		void m_Insert(IN st_Node<T> *pNode, IN T key);
		void m_Delete(IN st_Node<T> *pNode, IN T key);
		void m_Transplant(IN st_Node<T> *dPos, IN st_Node<T> *pNode);
		
		// 2) 질의(Search, Minimum, Maximum, Predecessor, Successor)
		st_Node<T> *m_Search(IN st_Node<T> *pNode, IN const T &target);
		st_Node<T> *m_Minimum(IN st_Node<T> *pNode);
		st_Node<T> *m_Maximum(IN st_Node<T> *pNode);
		st_Node<T> *m_Pred(IN st_Node<T> *pNode);
		st_Node<T> *m_Succ(IN st_Node<T> *pNode);

		// 3) 순회(PreOrder, InOrder, PostOrder)
		void m_PreOrder(IN st_Node<T> *pNode);
		void m_InOrder(IN st_Node<T> *pNode);
		void m_PostOrder(IN st_Node<T> *pNode);

		st_Node<T> *m_pRoot;
		st_Node<T> m_NIL;
		DWORD m_nodeCnt;
	};
}

//--------------------------------------------------------------------
// 인터페이스 (Interface) 구현부
//--------------------------------------------------------------------

// 1) 변경(Insert, Delete)
//--------------------------------------------------------------------
// 함수명: Insert
// 용도: 노드 삽입
//--------------------------------------------------------------------
template <typename T>
void mylib_tree::CBSTree<T>::Insert(IN const T &key)
{
	m_Insert(m_pRoot, key);
}

//--------------------------------------------------------------------
// 함수명: Delete
// 용도: 노드 삭제
//--------------------------------------------------------------------
template <typename T>
void mylib_tree::CBSTree<T>::Delete(IN const T &key)
{
	m_Delete(m_pRoot, key);
}

// 2) 질의(Search, Minimum, Maximum, Predecessor, Successor)
//--------------------------------------------------------------------
// 함수명: Search
// 용도: 해당 Key값을 가지고 있는 노드의 값 출력 (현재 기준으로는 Key를 출력)
//--------------------------------------------------------------------
template <typename T>
bool mylib_tree::CBSTree<T>::Search(IN const T &key, OUT T *value)
{
	st_Node<T> *result = m_Search(m_pRoot, key);
	
	if (result == &m_NIL)
		return false;

	*value = result->m_key;
	return true;
}

//--------------------------------------------------------------------
// 함수명: Minimum
// 용도: 최소 Key값을 가지고 있는 노드의 Key값 출력
//--------------------------------------------------------------------
template <typename T>
void mylib_tree::CBSTree<T>::Minimum()
{
	if(m_pRoot == &m_NIL)
		std::wcout << L"Tree is Empty\n";
	
	st_Node<T> *result = m_Minimum(m_pRoot);
	std::wcout << L"Minimum Key is " << result->m_key << L'\n';
}

//--------------------------------------------------------------------
// 함수명: Maximum
// 용도: 최대 Key값을 가지고 있는 노드의 Key값 출력
//--------------------------------------------------------------------
template <typename T>
void mylib_tree::CBSTree<T>::Maximum()
{
	if (m_pRoot == &m_NIL)
		std::wcout << L"Tree is Empty\n";

	st_Node<T> *result = m_Maximum(m_pRoot);
	std::wcout << L"Maximum Key is " << result->m_key << L'\n';
}

template <typename T>
void mylib_tree::CBSTree<T>::Predecessor()
{

}

template <typename T>
void mylib_tree::CBSTree<T>::Successor()
{

}

// 3) 순회(PreOrder, InOrder, PostOrder)
//--------------------------------------------------------------------
// 함수명: PreOrder
// 용도: 전위 순회 결과 출력
//--------------------------------------------------------------------
template <typename T>
void mylib_tree::CBSTree<T>::PreOrder()
{
	std::wcout << L"PreOrder:\t";
	m_PreOrder(m_pRoot);
	std::wcout << L'\n';
}

//--------------------------------------------------------------------
// 함수명: InOrder
// 용도: 중위 순회 결과 출력
//--------------------------------------------------------------------
template <typename T>
void mylib_tree::CBSTree<T>::InOrder()
{
	std::wcout << L"InOrder:\t";
	m_InOrder(m_pRoot);
	std::wcout << L'\n';
}

//--------------------------------------------------------------------
// 함수명: PostOrder
// 용도: 후위 순회 결과 출력
//--------------------------------------------------------------------
template <typename T>
void mylib_tree::CBSTree<T>::PostOrder()
{
	std::wcout << L"PostOrder:\t";
	m_PostOrder(m_pRoot);
	std::wcout << L'\n';
}

// 4) 기타 연산
//--------------------------------------------------------------------
// 함수명: Count
// 용도: 트리의 노드 갯수 출력
//--------------------------------------------------------------------
template <typename T>
void mylib_tree::CBSTree<T>::Count()
{
	std::wcout << L"Node Count: " << m_nodeCnt << L'\n';
}

//--------------------------------------------------------------------
// 클래스 멤버 함수 정의 부분
//--------------------------------------------------------------------

//--------------------------------------------------------------------
// 함수명: CBSTree
// 용도: 생성자
//--------------------------------------------------------------------
template <typename T>
mylib_tree::CBSTree<T>::CBSTree()
	:m_nodeCnt(0)
{
	m_NIL.m_parent = &m_NIL;
	m_NIL.m_left = &m_NIL;
	m_NIL.m_right = &m_NIL;

	m_pRoot = &m_NIL;
}

//--------------------------------------------------------------------
// 함수명: ~CBSTree
// 용도: 소멸자
//--------------------------------------------------------------------
template <typename T>
mylib_tree::CBSTree<T>::~CBSTree()
{
}

// 1) 변경(Insert, Delete)
//--------------------------------------------------------------------
// 함수명: m_Insert
// 용도: 노드 추가 연산
//--------------------------------------------------------------------
template <typename T>
void mylib_tree::CBSTree<T>::m_Insert(IN st_Node<T> *pNode, IN T key)
{
	st_Node<T> *parent = &m_NIL;
	while (pNode != &m_NIL)
	{
		parent = pNode;
		if (key < pNode->m_key)
			pNode = pNode->m_left;
		else
			pNode = pNode->m_right;
	}

	st_Node<T> *newNode = new st_Node<T>;
	newNode->m_key = key;
	newNode->m_parent = parent;
	newNode->m_left = &m_NIL;
	newNode->m_right = &m_NIL;
	
	if (parent == &m_NIL)
		m_pRoot = newNode;
	else if (newNode->m_key < parent->m_key)
		parent->m_left = newNode;
	else
		parent->m_right = newNode;
	++m_nodeCnt;
}

//--------------------------------------------------------------------
// 함수명: m_Delete
// 용도: 노드 삭제 연산
//--------------------------------------------------------------------
template <typename T>
void mylib_tree::CBSTree<T>::m_Delete(IN st_Node<T> *pNode, IN T key)
{
	st_Node<T> *dNode = m_Search(m_pRoot, key);
	st_Node<T> *pred = nullptr;
	if (dNode == &m_NIL)
		return;

	if (dNode->m_left == &m_NIL)
		m_Transplant(dNode, dNode->m_left);
	else if (dNode->m_right == &m_NIL)
		m_Transplant(dNode, dNode->m_right);
	else
	{
		pred = m_Minimum(dNode->m_right);

		if (pred->m_parent != dNode)
		{
			m_Transplant(pred, pred->m_right);
			pred->m_right = dNode->m_right;
			pred->m_right->m_parent = pred;
		}

		m_Transplant(dNode, pred);
		pred->m_left = dNode->m_left;
		pred->m_left->m_parent = pred;
	}

	--m_nodeCnt;
}

//--------------------------------------------------------------------
// 함수명: m_Transplant
// 용도: 노드 삭제 보조 연산
//--------------------------------------------------------------------
template <typename T>
void mylib_tree::CBSTree<T>::m_Transplant(IN st_Node<T> *dPos, IN st_Node<T> *pNode)
{
	if (dPos->m_parent == &m_NIL)
		m_pRoot = pNode;
	else if (dPos == dPos->m_parent->m_left)
		dPos->m_parent->m_left = pNode;
	else
		dPos->m_parent->m_right = pNode;

	if (pNode != &m_NIL)
		pNode->m_parent = dPos->m_parent;
}


// 2) 질의(Search, Minimum, Maximum, Predecessor, Successor)
//--------------------------------------------------------------------
// 함수명: m_Search
// 용도: 해당 Key값을 가지고 있는 노드 반환
//--------------------------------------------------------------------
template <typename T>
mylib_tree::st_Node<T> *mylib_tree::CBSTree<T>::m_Search(IN st_Node<T> *pNode, IN const T &target)
{
	st_Node<T> *targetNode = pNode;
	while (targetNode != &m_NIL && target != targetNode->m_key)
	{
		if (target < targetNode->m_key)
			targetNode = targetNode->m_left;
		else
			targetNode = targetNode->m_right;
	}

	return targetNode;
}

//--------------------------------------------------------------------
// 함수명: m_Minimum
// 용도: 최소 Key값을 가지고 있는 노드의 Key값 반환
//--------------------------------------------------------------------
template <typename T>
mylib_tree::st_Node<T> *mylib_tree::CBSTree<T>::m_Minimum(IN st_Node<T> *pNode)
{
	st_Node<T> *minNode = pNode;
	while (minNode->m_left != &m_NIL)
		minNode = minNode->m_left;

	return minNode;
}

//--------------------------------------------------------------------
// 함수명: m_Maximum
// 용도: 최대 Key값을 가지고 있는 노드의 Key값 반환
//--------------------------------------------------------------------
template <typename T>
mylib_tree::st_Node<T> *mylib_tree::CBSTree<T>::m_Maximum(IN st_Node<T> *pNode)
{
	st_Node<T> *maxNode = pNode;
	while (maxNode->m_right != &m_NIL)
		maxNode = maxNode->m_right;

	return maxNode;
}

template <typename T>
mylib_tree::st_Node<T> *mylib_tree::CBSTree<T>::m_Pred(IN st_Node<T> *pNode)
{

}

template <typename T>
mylib_tree::st_Node<T> *mylib_tree::CBSTree<T>::m_Succ(IN st_Node<T> *pNode)
{

}

// 3) 순회(PreOrder, InOrder, PostOrder)
//--------------------------------------------------------------------
// 함수명: m_PreOrder
// 용도: 전위 순회
//--------------------------------------------------------------------
template <typename T>
void mylib_tree::CBSTree<T>::m_PreOrder(IN st_Node<T> *pNode)
{
	if (pNode == &m_NIL || pNode == nullptr)
		return;

	std::wcout << pNode->m_key << L' ';
	m_PreOrder(pNode->m_left);
	m_PreOrder(pNode->m_right);
}

//--------------------------------------------------------------------
// 함수명: m_InOrder
// 용도: 중위 순회
//--------------------------------------------------------------------

template <typename T>
void mylib_tree::CBSTree<T>::m_InOrder(IN st_Node<T> *pNode)
{
	if (pNode == &m_NIL || pNode == nullptr)
		return;

	m_InOrder(pNode->m_left);
	std::wcout << pNode->m_key << L' ';
	m_InOrder(pNode->m_right);
}

//--------------------------------------------------------------------
// 함수명: m_PostOrder
// 용도: 후위 순회
//--------------------------------------------------------------------
template <typename T>
void mylib_tree::CBSTree<T>::m_PostOrder(IN st_Node<T> *pNode)
{
	if (pNode == &m_NIL || pNode == nullptr)
		return;

	m_PostOrder(pNode->m_left);
	m_PostOrder(pNode->m_right);
	std::wcout << pNode->m_key << L' ';
}