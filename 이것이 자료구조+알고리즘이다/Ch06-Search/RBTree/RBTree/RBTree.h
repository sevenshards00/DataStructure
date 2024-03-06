/*
* 이것이 자료구조+알고리즘이다 - 탐색(Search)
* 파일명: RBTree.h
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-03-06
* 이전 버전 작성 일자:
* 버전 내용: 레드 블랙 트리 (C++, Template)
* 이전 버전 내용:
*/

///////////////////////////////////////////////////////////////////////////
// 파일명: RBTree.h
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
	class RBTree : public ITree<T>
	{
	public:
		// 생성자
		RBTree();
		// 소멸자
		~RBTree();

		//--------------------------------------------------------------------
		// 인터페이스 (Interface)
		//--------------------------------------------------------------------

		// 1) 변경(Insert, Delete)
		virtual void Insert(IN const T &key) override;
		virtual void Delete(IN const T &key) override;

		// 2) 질의(Search, Minimum, Maximum, Predecessor, Successor)
		virtual st_Node<T> *Search(IN const T &key) override;
		virtual st_Node<T> *Minimum(IN st_Node<T> *pNode) override;
		virtual st_Node<T> *Maximum(IN st_Node<T> *pNode) override;

		// 3) 순회(PreOrder, InOrder, PostOrder)
		virtual void PreOrderPrint() override;
		virtual void InOrderPrint() override;
		virtual void PostOrderPrint() override;

		// 3) 순회(PreOrder, InOrder, PostOrder)
		virtual void PreOrder(IN st_Node<T> *pNode) override;
		virtual void InOrder(IN st_Node<T> *pNode) override;
		virtual void PostOrder(IN st_Node<T> *pNode) override;

		// 4) 기타 연산
		virtual void Count() override;

	private:
		// 1) 변경(Insert, Delete)
		void RBTransplant(IN st_Node<T> *dPos, IN st_Node<T> *pNode);
		void LeftRotate(IN st_Node<T> *target);
		void RightRotate(IN st_Node<T> *target);
		void InsertFixUp(IN st_Node<T> *newNode);

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
void mylib_tree::RBTree<T>::Insert(IN const T &key)
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
	newNode->m_color = COLOR::RED;

	if (parent == &m_NIL)
		m_pRoot = newNode;
	else if (newNode->m_key < parent->m_key)
		parent->m_left = newNode;
	else
		parent->m_right = newNode;
	InsertFixUp(newNode);
	++m_nodeCnt;
}

//--------------------------------------------------------------------
// 함수명: Delete
// 용도: 노드 삭제
//--------------------------------------------------------------------
template <typename T>
void mylib_tree::RBTree<T>::Delete(IN const T &key)
{
	st_Node<T> *dNode = Search(key);
	st_Node<T> *pred = nullptr;

	if (dNode == nullptr)
		return;

	if (dNode->m_left == &m_NIL)
		RBTransplant(dNode, dNode->m_left);
	else if (dNode->m_right == &m_NIL)
		RBTransplant(dNode, dNode->m_right);
	else
	{
		pred = Minimum(dNode->m_right);

		if (pred != dNode->m_right)
		{
			RBTransplant(pred, pred->m_right);
			pred->m_right = dNode->m_right;
			pred->m_right->m_parent = pred;
		}

		RBTransplant(dNode, pred);
		pred->m_left = dNode->m_left;
		pred->m_left->m_parent = pred;
	}

	--m_nodeCnt;
}

// 2) 질의(Search, Minimum, Maximum, Predecessor, Successor)
//--------------------------------------------------------------------
// 함수명: Search
// 용도: 해당 Key값을 가지고 있는 노드의 값 출력 (현재 기준으로는 Key를 출력)
//--------------------------------------------------------------------
template <typename T>
mylib_tree::st_Node<T> *mylib_tree::RBTree<T>::Search(IN const T &key)
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
mylib_tree::st_Node<T> *mylib_tree::RBTree<T>::Minimum(IN st_Node<T> *pNode)
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
mylib_tree::st_Node<T> *mylib_tree::RBTree<T>::Maximum(IN st_Node<T> *pNode)
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
void mylib_tree::RBTree<T>::PreOrderPrint()
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
void mylib_tree::RBTree<T>::InOrderPrint()
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
void mylib_tree::RBTree<T>::PostOrderPrint()
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
void mylib_tree::RBTree<T>::PreOrder(IN st_Node<T> *pNode)
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
void mylib_tree::RBTree<T>::InOrder(IN st_Node<T> *pNode)
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
void mylib_tree::RBTree<T>::PostOrder(IN st_Node<T> *pNode)
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
void mylib_tree::RBTree<T>::Count()
{
	std::wcout << L"Node Count: " << m_nodeCnt << L'\n';
}

//--------------------------------------------------------------------
// 클래스 멤버 함수 정의 부분
//--------------------------------------------------------------------

//--------------------------------------------------------------------
// 함수명: RBTree
// 용도: 생성자
//--------------------------------------------------------------------
template <typename T>
mylib_tree::RBTree<T>::RBTree()
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
mylib_tree::RBTree<T>::~RBTree()
{
}

// 1) 변경(Insert, Delete)
//--------------------------------------------------------------------
// 함수명: m_RBTransplant
// 용도: 노드 삭제 보조 연산
//--------------------------------------------------------------------
template <typename T>
void mylib_tree::RBTree<T>::RBTransplant(IN st_Node<T> *dPos, IN st_Node<T> *pNode)
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

//--------------------------------------------------------------------
// 함수명: m_LeftRoate
// 용도: 회전 연산
//--------------------------------------------------------------------
template <typename T>
void mylib_tree::RBTree<T>::LeftRotate(IN st_Node<T> *target)
{
	st_Node<T> *rightChild = target->m_right;
	target->m_right = rightChild->m_left;
	rightChild->m_parent = target->m_parent;

	// 오른쪽 자식 노드의 왼쪽에 서브트리가 있는지 확인
	if (rightChild->m_left != &m_NIL)
		rightChild->m_left->m_parent = target;

	// 대상 노드의 부모가 NIL 노드라면 -> root 노드
	if (target->m_parent == &m_NIL)
		m_pRoot = rightChild;
	// 그게 아닐 경우 처리
	else if (target == target->m_parent->m_left)
		target->m_parent->m_left = rightChild;
	else
		target->m_parent->m_right = rightChild;

	rightChild->m_left = target;
	target->m_parent = rightChild;
}

//--------------------------------------------------------------------
// 함수명: m_RightRotate
// 용도: 회전 연산
//--------------------------------------------------------------------
template <typename T>
void mylib_tree::RBTree<T>::RightRotate(IN st_Node<T> *target)
{
	st_Node<T> *leftChild = target->m_left;
	target->m_left = leftChild->m_right;
	leftChild->m_parent = target->m_parent;

	// 왼쪽 자식 노드의 오른쪽에 서브트리가 있는지 확인
	if (leftChild->m_right != &m_NIL)
		leftChild->m_right->m_parent = target;

	// 대상 노드의 부모가 NIL 노드라면 -> root 노드
	if (target->m_parent == &m_NIL)
		m_pRoot = leftChild;
	// 그게 아닐 경우 처리
	else if (target == target->m_parent->m_left)
		target->m_parent->m_left = leftChild;
	else
		target->m_parent->m_right = leftChild;

	leftChild->m_right = target;
	target->m_parent = leftChild;
}


template <typename T>
void mylib_tree::RBTree<T>::InsertFixUp(IN st_Node<T> *newNode)
{
	st_Node<T> *uncleNode = nullptr;
	while (newNode->m_parent->m_color == COLOR::RED)
	{
		// 부모 노드가 조부모 노드의 왼쪽 자식일 경우
		if (newNode->m_parent == newNode->m_parent->m_parent->m_left)
		{
			// 삼촌 노드는 조부모 노드의 오른쪽 자식
			uncleNode = newNode->m_parent->m_parent->m_right;

			// 1번 케이스: 삼촌 노드가 빨간색이라면
			if (uncleNode->m_color == COLOR::RED)
			{
				// 부모와 삼촌 노드를 검은색으로 변경
				newNode->m_parent->m_color = COLOR::BLACK;
				uncleNode->m_color = COLOR::BLACK;
				// 조부모 노드의 색을 빨간색으로 변경
				newNode->m_parent->m_parent->m_color = COLOR::RED;
				// 새로 삽입한 노드를 조부모 노드로 변경하고 다시 loop
				newNode = newNode->m_parent->m_parent;
			}
			
			else
			{
				// 2번 케이스: 삼촌 노드가 검은색이며 삽입된 노드가 부모의 오른쪽 자식일 경우
				// 사실상 3번 케이스로 바꿔버려서 해결
				if (newNode == newNode->m_parent->m_right)
				{
					newNode = newNode->m_parent;
					LeftRotate(newNode);
				}

				// 3번 케이스: 삼촌 노드가 검은색이며 삽입된 노드가 부모의 왼쪽 자식일 경우
				newNode->m_parent->m_color = COLOR::BLACK;
				newNode->m_parent->m_parent->m_color = COLOR::RED;
				RightRotate(newNode->m_parent->m_parent);
			}			
			
			
		}
		// 부모 노드가 조부모 노드의 오른쪽 자식일 경우
		// 위와 대칭 구조
		else
		{
			uncleNode = newNode->m_parent->m_parent->m_left;
			// 1번 케이스: 삼촌 노드가 빨간색이라면
			if (uncleNode->m_color == COLOR::RED)
			{
				newNode->m_parent->m_color = COLOR::BLACK;
				uncleNode->m_color = COLOR::BLACK;
				newNode->m_parent->m_parent->m_color = COLOR::RED;
				newNode = newNode->m_parent->m_parent;
			}
			else
			{
				// 2번 케이스: 삼촌 노드가 검은색이며 삽입된 노드가 부모의 왼쪽 자식일 경우
				if (newNode == newNode->m_parent->m_left)
				{
					newNode = newNode->m_parent;
					RightRotate(newNode);
				}

				// 3번 케이스: 삼촌 노드가 검은색이며 삽입된 노드가 부모의 오른쪽 자식일 경우
				newNode->m_parent->m_color = COLOR::BLACK;
				newNode->m_parent->m_parent->m_color = COLOR::RED;
				LeftRotate(newNode->m_parent->m_parent);
			}
		}
	}
	// loop 종료 후에는 루트 노드를 검은색으로 바꿔서 레드블랙 트리의 특성을 유지.
	m_pRoot->m_color = COLOR::BLACK;
}