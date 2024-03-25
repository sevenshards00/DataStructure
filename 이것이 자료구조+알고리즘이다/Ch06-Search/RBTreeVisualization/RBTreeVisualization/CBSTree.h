/*
* 이것이 자료구조+알고리즘이다 - 탐색(Search)
* 파일명: CBSTree.h
* 파일 버전: 0.13
* 작성자: Sevenshards
* 작성 일자: 2024-03-06
* 이전 버전 작성 일자: 2024-03-05
* 버전 내용: 레드 블랙 트리로 확장 (C++, Template)
* 이전 버전 내용: Transplant 함수 로직 수정 및 자잘한 부분 변경
*/

///////////////////////////////////////////////////////////////////////////
// 파일명: CBSTree.h
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

		// 2) 질의(Search, Minimum, Maximum)
		virtual st_Node<T> *Search(IN const T &key) override;
		virtual st_Node<T> *Minimum(IN st_Node<T> *pNode) override;
		virtual st_Node<T> *Maximum(IN st_Node<T> *pNode) override;

		// 3) 순회(PreOrder, InOrder, PostOrder)
		virtual void PreOrder(IN st_Node<T> *pNode) override;
		virtual void InOrder(IN st_Node<T> *pNode) override;
		virtual void PostOrder(IN st_Node<T> *pNode) override;

		// 4) 기타 연산
		// 트리의 노드 갯수 반환
		virtual void Count() override;

		// 순회 결과 출력
		virtual void PreOrderPrint() override;
		virtual void InOrderPrint() override;
		virtual void PostOrderPrint() override;

	private:
		// 추가 보조 연산
		void Transplant(IN st_Node<T> *dPos, IN st_Node<T> *pNode);

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
	st_Node<T> *parent = &m_NIL;
	st_Node<T> *currNode = m_pRoot;
	while (currNode != &m_NIL)
	{
		parent = currNode;
		if (key < currNode->m_key)
			currNode = currNode->m_left;
		else
			currNode = currNode->m_right;
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
// 함수명: Delete
// 용도: 노드 삭제
//--------------------------------------------------------------------
template <typename T>
void mylib_tree::CBSTree<T>::Delete(IN const T &key)
{
	st_Node<T> *dNode = Search(key);
	st_Node<T> *succ = nullptr;

	if (dNode == nullptr)
		return;

	if (dNode->m_left == &m_NIL)
		Transplant(dNode, dNode->m_right);
	else if (dNode->m_right == &m_NIL)
		Transplant(dNode, dNode->m_left);
	else
	{
		succ = Minimum(dNode->m_right);

		if (succ != dNode->m_right)
		{
			Transplant(succ, succ->m_right);
			succ->m_right = dNode->m_right;
			succ->m_right->m_parent = succ;
		}

		Transplant(dNode, succ);
		succ->m_left = dNode->m_left;
		succ->m_left->m_parent = succ;
	}

	delete dNode;
	--m_nodeCnt;
}

// 2) 질의(Search, Minimum, Maximum)
//--------------------------------------------------------------------
// 함수명: Search
// 용도: 해당 Key값을 가지고 있는 노드의 값 출력 (현재 기준으로는 Key를 출력)
//--------------------------------------------------------------------
template <typename T>
mylib_tree::st_Node<T> *mylib_tree::CBSTree<T>::Search(IN const T &key)
{
	st_Node<T> *targetNode = m_pRoot;
	while (targetNode != &m_NIL && key != targetNode->m_key)
	{
		if (key < targetNode->m_key)
			targetNode = targetNode->m_left;
		else
			targetNode = targetNode->m_right;
	}

	if (targetNode == &m_NIL || targetNode == nullptr)

		return nullptr;

	return targetNode;
}

//--------------------------------------------------------------------
// 함수명: Minimum
// 용도: 최소 Key값을 가지고 있는 노드의 Key값 출력
//--------------------------------------------------------------------
template <typename T>
mylib_tree::st_Node<T> *mylib_tree::CBSTree<T>::Minimum(IN st_Node<T> *pNode)
{
	if (pNode == &m_NIL)
		return &m_NIL;

	st_Node<T> *minNode = pNode;
	while (minNode->m_left != &m_NIL)
		minNode = minNode->m_left;

	return minNode;
}

//--------------------------------------------------------------------
// 함수명: Maximum
// 용도: 최대 Key값을 가지고 있는 노드의 Key값 출력
//--------------------------------------------------------------------
template <typename T>
mylib_tree::st_Node<T> *mylib_tree::CBSTree<T>::Maximum(IN st_Node<T> *pNode)
{
	if (pNode == &m_NIL)
		return &m_NIL;

	st_Node<T> *maxNode = pNode;
	while (maxNode->m_right != &m_NIL)
		maxNode = maxNode->m_right;

	return maxNode;
}

// 3) 순회(PreOrder, InOrder, PostOrder)
//--------------------------------------------------------------------
// 함수명: PreOrderPrint
// 용도: 전위 순회 결과 출력
//--------------------------------------------------------------------
template <typename T>
void mylib_tree::CBSTree<T>::PreOrderPrint()
{
	std::wcout << L"PreOrder:\t";
	PreOrder(m_pRoot);
	std::wcout << L'\n';
}

//--------------------------------------------------------------------
// 함수명: InOrderPrint
// 용도: 중위 순회 결과 출력
//--------------------------------------------------------------------
template <typename T>
void mylib_tree::CBSTree<T>::InOrderPrint()
{
	std::wcout << L"InOrder:\t";
	InOrder(m_pRoot);
	std::wcout << L'\n';
}

//--------------------------------------------------------------------
// 함수명: PostOrderPrint
// 용도: 후위 순회 결과 출력
//--------------------------------------------------------------------
template <typename T>
void mylib_tree::CBSTree<T>::PostOrderPrint()
{
	std::wcout << L"PostOrder:\t";
	PostOrder(m_pRoot);
	std::wcout << L'\n';
}

//--------------------------------------------------------------------
// 함수명: PreOrder
// 용도: 전위 순회
//--------------------------------------------------------------------
template <typename T>
void mylib_tree::CBSTree<T>::PreOrder(IN st_Node<T> *pNode)
{
	if (pNode == &m_NIL || pNode == nullptr)
		return;

	std::wcout << pNode->m_key << L' ';
	PreOrder(pNode->m_left);
	PreOrder(pNode->m_right);
}

//--------------------------------------------------------------------
// 함수명: InOrder
// 용도: 중위 순회
//--------------------------------------------------------------------

template <typename T>
void mylib_tree::CBSTree<T>::InOrder(IN st_Node<T> *pNode)
{
	if (pNode == &m_NIL || pNode == nullptr)
		return;

	InOrder(pNode->m_left);
	std::wcout << pNode->m_key << L' ';
	InOrder(pNode->m_right);
}

//--------------------------------------------------------------------
// 함수명: PostOrder
// 용도: 후위 순회
//--------------------------------------------------------------------
template <typename T>
void mylib_tree::CBSTree<T>::PostOrder(IN st_Node<T> *pNode)
{
	if (pNode == &m_NIL || pNode == nullptr)
		return;

	PostOrder(pNode->m_left);
	PostOrder(pNode->m_right);
	std::wcout << pNode->m_key << L' ';
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
// 함수명: m_Transplant
// 용도: 노드 삭제 보조 연산
//--------------------------------------------------------------------
template <typename T>
void mylib_tree::CBSTree<T>::Transplant(IN st_Node<T> *dPos, IN st_Node<T> *pNode)
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