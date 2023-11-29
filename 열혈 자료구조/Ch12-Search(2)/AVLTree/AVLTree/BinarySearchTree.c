/*
* 비선형 자료구조 - 연결 리스트 기반 이진 탐색 트리
* 파일명: BinarySearchTree.c
* 파일 버전: 0.3
* 작성자: Sevenshards
* 작성 일자: 2023-11-29
* 이전 버전 작성 일자: 2023-11-28
* 버전 내용: AVL 트리 확장에 따른 삽입, 삭제 부분 수정
* 이전 버전 내용: 삭제 기능, 트리 전체 조회 추가로 구현
*/
#include <stdlib.h>
#include "BinarySearchTree.h"
#include "AVLRebalance.h"

// 이진 탐색 트리의 생성 및 초기화
void BSTMakeAndInit(BTreeNode** pRoot)
{
	*pRoot = NULL;
}

// 노드에 저장된 데이터 반환
BSTData BSTGetNodeData(BTreeNode* bst)
{
	return bst->data;
}

// 이진 탐색 트리를 대상으로 데이터 저장 (노드 생성 포함)
// 재귀 형태로 변경하여 구현
// 반환형으로 BTreeNode*를 반환. -> 자기 참조 가능.
// 이 부분은 객체 지향 공부하면서 다시 보면 좋을듯 하여 void로 놓지 않았음
BTreeNode* BSTInsert(BTreeNode** pRoot, BSTData data)
{
	if (*pRoot == NULL) // 노드가 추가될 위치를 찾은 상황 (재귀의 탈출 조건)
	{
		*pRoot = MakeBTreeNode(); // 새로운 노드를 생성하고
		SetData(*pRoot, data); // 새로운 노드에 데이터를 저장
	}
	else if (data < GetData(*pRoot)) // 새로 저장될 데이터가 현재 가리키는 노드보다 작다면
	{
		BSTInsert(&((*pRoot)->left), data); // 왼쪽에 추가하기 위한 BSTInsert 호출 (재귀)
		*pRoot = Rebalance(pRoot); // 노드 추가가 끝난 이후 Rebalance 호출을 통한 리밸런싱
	}
	else if (data > GetData(*pRoot)) // 새로 저장될 데이터가 현재 가리키는 노드보다 크다면
	{
		BSTInsert(&((*pRoot)->right), data); // 오른쪽에 추가하기 위한 BSTInsert 다시 호출 (재귀)
		*pRoot = Rebalance(pRoot); // 노드 추가가 끝난 이후 Rebalance 호출을 통한 리밸런싱
	}
	else // 그 이외의 경우는 Key의 값이 같은 경우 하나.
	{
		return NULL; // 이진 탐색 트리에서 Key는 중복을 허용하지 않으므로 NULL 반환
	}

	return *pRoot;
}

// 이진 탐색 트리를 대상으로 데이터 탐색
BTreeNode* BSTSearch(BTreeNode* bst, BSTData target)
{
	BTreeNode* cNode = bst; // 현재(current) 가리키는 노드, 트리의 주소값(루트 노드의 주소값)부터 시작한다.
	BSTData cData; // 현재 가리키는 노드의 데이터 값

	// 현재 가리키는 노드가 NULL이 아닐때까지
	while (cNode != NULL)
	{
		cData = GetData(cNode);

		if (target == cData) // 대상을 찾았다면
			return cNode; // 현재 가리키는 노드의 주소값 반환
		else if (target < cData) // 찾는 값이 현재 노드의 데이터보다 작다면
			cNode = GetLeftSubTree(cNode); // 왼쪽으로 이동
		else // 찾는 값이 현재 노드의 데이터보다 크다면
			cNode = GetRightSubTree(cNode);
	}

	return NULL; // 탐색 대상이 아예 없는 경우, NULL을 반환
}

// 트리에서 노드를 제거하고 제거된 노드의 주소값을 반환
BTreeNode* BSTRemove(BTreeNode** pRoot, BSTData target)
{
	// 삭제 대상이 루트 노드일 경우도 고려하여 진행
	BTreeNode* pVRoot = MakeBTreeNode(); // 가상 루트 노드 (Virtual Root Node) - 저자가 쓴 꼼수(?)
	BTreeNode* pNode = pVRoot; // 현재 가리키는 노드의 부모 노드, 초기화 하면서 가상의 루트 노드를 가리킨다
	BTreeNode* cNode = *pRoot; // 현재(current) 가리키는 노드, 초기화 하면서 루트 노드를 가리킨다
	BTreeNode* dNode = NULL; // 지워질 대상의 노드, 일부 컴파일러에서는 초기화하지 않으면 에러를 띄우므로 NULL로 초기화

	// 루트 노드를 pVRoot가 가리키고 있는 노드의 오른쪽 자식 노드가 되게 한다.
	ChangeRightSubTree(pVRoot, *pRoot);

	// 삭제 대상이 될 노드를 탐색
	while (cNode != NULL && GetData(cNode) != target)
	{
		pNode = cNode; // 현재 노드 위치를 현재 위치한 노드의 부모 노드로 갱신

		if (target < GetData(cNode)) // 삭제할 데이터가 현재 노드의 데이터보다 작다면
			cNode = GetLeftSubTree(cNode); // 왼쪽으로 이동
		else // 삭제할 데이터가 현재 노드의 데이터보다 크다면
			cNode = GetRightSubTree(cNode); // 오른쪽으로 이동
	}

	if (cNode == NULL) // 삭제 대상이 없다면
		return NULL; // NULL을 return

	dNode = cNode; // 삭제 대상을 dNode가 가리키게 함

	// 1번 케이스: 삭제 대상이 단말 노드라면
	if (GetLeftSubTree(dNode) == NULL && GetRightSubTree(dNode) == NULL) // 양쪽에 자식 노드가 둘 다 없으므로
	{
		if (GetLeftSubTree(pNode) == dNode) // 만약 삭제할 노드의 부모 노드의 왼쪽 노드라면
			RemoveLeftSubTree(pNode); // 부모 노드의 왼쪽 노드를 삭제
		else // 오른쪽 노드라면
			RemoveRightSubTree(pNode); // 부모 노드의 오른쪽 노드를 삭제
	}

	// 2번 케이스: 삭제 대상이 자식 노드를 하나 갖는 경우
	else if (GetLeftSubTree(dNode) == NULL || GetRightSubTree(dNode) == NULL) // 삭제할 노드의 왼쪽 또는 오른쪽에 자식 노드가 있다면
	{
		BTreeNode* dcNode; // 삭제 대상 노드의 자식(child) 노드를 가리키기 위해 사용할 BTreeNode* 변수

		if (GetLeftSubTree(dNode) != NULL) // 삭제할 노드의 왼쪽에 자식 노드가 있다면
			dcNode = GetLeftSubTree(dNode); // dcNode가 삭제할 노드의 왼쪽 자식을 가리키게 한다.
		else // 삭제할 노드의 오른쪽에 자식 노드가 있다면
			dcNode = GetRightSubTree(dNode); //dcNode가 삭제할 노드의 오른쪽 자식을 가리키게 한다.

		if (GetLeftSubTree(pNode) == dNode) // 만약 삭제할 노드의 부모 노드의 왼쪽 노드라면
			ChangeLeftSubTree(pNode, dcNode); // 부모 노드의 왼쪽을 삭제할 노드의 자식 노드로 바꾼다.
		else // 오른쪽 노드라면
			ChangeRightSubTree(pNode, dcNode); // 부모 노드의 오른쪽을 삭제할 노드의 자식 노드로 바꾼다.
	}

	// 3번 케이스: 삭제 대상이 양쪽 다 자식 노드를 갖는 경우
	// 이 경우에는 삭제할 노드의 오른쪽 서브 트리에서 가장 작은 값을 지니는 노드를 찾는다.
	// 그리고 가장 작은 값을 지니는 노드를 삭제할 노드를 대체한다.
	else
	{
		BTreeNode* mNode = GetRightSubTree(dNode); // 대체할 노드를 가리킨다. 오른쪽 서브트리에서 가장 작은 값을 찾아야 하니 오른쪽 자식 노드 값으로 초기화
		BTreeNode* mpNode = dNode; // 대체할 노드의 부모 노드. 삭제할 노드를 가리키는 것으로 초기화
		int delData; // 삭제할 노드의 데이터를 받기 위한 변수

		// 삭제 노드를 대체할 노드를 찾는다.
		while (GetLeftSubTree(mNode) != NULL) // 가장 작은 값을 찾는 것이므로 계속 왼쪽 서브트리만 찾으면 됨. NULL을 만나면 더 이상 없는 것.
		{
			mpNode = mNode; // 대체할 노드의 부모 노드 갱신
			mNode = GetLeftSubTree(mNode); // 대체할 노드를 찾기 위해 왼쪽 자식 노드로 갱신
		}

		// 대체할 노드를 찾은 후
		// 대체 노드에 저장된 값을 삭제할 노드에 대입
		delData = GetData(dNode); // 삭제할 노드에 있는 값을 받는다. (백업)
		SetData(dNode, GetData(mNode)); // 삭제할 노드에 있는 값을 대체할 노드의 값으로 변경

		// 대체할 노드의 부모 노드와 대체 노드의 자식 노드를 연결한다.
		if (GetLeftSubTree(mpNode) == mNode) // 대체할 노드의 부모 노드의 왼쪽 자식 노드가 대체할 노드라면
			ChangeLeftSubTree(mpNode, GetRightSubTree(mNode)); // 대체할 노드의 자식 노드를 왼쪽 자식 노드로 연결
		else // 대체할 노드의 부모 노드의 오른쪽 자식 노드가 대체할 노드라면
			ChangeRightSubTree(mpNode, GetRightSubTree(mNode)); // 대체할 노드의 자식 노드를 오른쪽 자식 노드로 연결

		dNode = mNode; // 삭제할 노드를 대체할 노드로 변경
		SetData(dNode, delData); // 삭제할 노드가 가지고 있던 데이터를 다시 입력
	}

	// 삭제된 노드가 루트 노드일 경우에 대한 추가 처리
	if (GetRightSubTree(pVRoot) != *pRoot) // 가상 루트 노드의 오른쪽 자식 노드가 루트노드가 아니라면
		*pRoot = GetRightSubTree(pVRoot); // 루트 노드가 바뀐 것이므로 가상 루트 노드의 오른쪽 자식을 루트노드로 변경

	free(pVRoot); // 가상 루트 노드의 소멸
	*pRoot = Rebalance(pRoot); 	// 노드 제거 후 리밸런싱
	return dNode; // 삭제 노드의 주소값 반환
}

// int형 데이터의 출력을 위한 함수
void ShowIntData(int data)
{
	printf("%d ", data);
}

// 이진 탐색 트리에 저장된 모든 노드의 데이터 출력
void BSTShowAll(BTreeNode* bst)
{
	InorderTraversal(bst, ShowIntData);
}