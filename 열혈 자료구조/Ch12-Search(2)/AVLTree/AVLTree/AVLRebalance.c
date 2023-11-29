/*
* 비선형 자료구조 - AVL 트리 (이진 탐색 트리 확장)
* 파일명: AVLRebalance.c
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2023-11-29
* 이전 버전 작성 일자:
* 버전 내용: 균형을 잡는 이진 탐색 트리인 AVL 트리 확장 구현
* 이전 버전 내용: 
*/

#include <stdio.h>
#include "BinaryTree.h"

// LL 회전
BTreeNode* RotateLL(BTreeNode* bst)
{
	BTreeNode* pNode; // 부모(parent) 노드
	BTreeNode* cNode; // 자식(chile) 노드

	// pNode와 cNode를 각각 LL회전을 위한 위치를 가리키게 함
	pNode = bst;
	cNode = GetLeftSubTree(pNode);

	// 실제 LL 회전이 수행되는 부분
	ChangeLeftSubTree(pNode, GetRightSubTree(cNode));
	ChangeRightSubTree(cNode, pNode);

	// LL회전에 의해 변경된 루트 노드의 주소 값 반환
	return cNode;
}
// RR 회전
BTreeNode* RotateRR(BTreeNode* bst)
{
	BTreeNode* pNode; // 부모(parent) 노드
	BTreeNode* cNode; // 자식(chile) 노드

	// pNode와 cNode를 각각 RR회전을 위한 위치를 가리키게 함
	pNode = bst;
	cNode = GetRightSubTree(pNode);

	// 실제 RR 회전이 수행되는 부분
	ChangeRightSubTree(pNode, GetLeftSubTree(cNode));
	ChangeLeftSubTree(cNode, pNode);

	// RR회전에 의해 변경된 루트 노드의 주소 값 반환
	return cNode;
}

// LR 회전 -> 1) 부분적 RR회전 2) LL회전
BTreeNode* RotateLR(BTreeNode* bst)
{
	BTreeNode* pNode; // 부모(parent) 노드
	BTreeNode* cNode; // 자식(child) 노드

	// pNode와 cNode를 각각 LR회전을 위한 위치를 가리키게 함
	pNode = bst;
	cNode = GetLeftSubTree(pNode);

	// 실제 LR 회전이 수행되는 부분
	ChangeLeftSubTree(pNode, RotateRR(cNode)); // 1) 부분적 RR회전
	return RotateLL(pNode); // 2) LL회전
}
// RL 회전 -> 1) 부분적 LL회전 2) RR회전
BTreeNode* RotateRL(BTreeNode* bst)
{
	BTreeNode* pNode; // 부모(parent) 노드
	BTreeNode* cNode; // 자식(child) 노드

	// pNode와 cNode를 각각 LR회전을 위한 위치를 가리키게 함
	pNode = bst;
	cNode = GetRightSubTree(pNode);

	// 실제 LR 회전이 수행되는 부분
	ChangeRightSubTree(pNode, RotateLL(cNode)); // 1) 부분적 LL회전
	return RotateRR(pNode); // 2) RR회전
}

// 트리의 높이(height)를 계산
int GetHeight(BTreeNode* bst)
{
	int left_h; // 왼쪽의 높이
	int right_h; // 오른쪽의 높이

	// 재귀의 탈출 조건
	if (bst == NULL) // 단말 노드라면
		return 0; // 0을 반환

	// 재귀적 구조를 이용하여 높이를 계산
	left_h = GetHeight(GetLeftSubTree(bst));
	right_h = GetHeight(GetRightSubTree(bst));

	// 큰 값의 높이를 반환
	// 재귀적인 구조이므로 반환하면서 1씩 증가
	if (left_h > right_h)
		return left_h + 1;
	else
		return right_h + 1;
}

// 두 서브 트리의 높이의 차이를 계산
int GetHeightDiff(BTreeNode* bst)
{
	int lsh; // left sub tree height
	int rsh; // right sub tree height

	if (bst == NULL) // 트리에 노드가 없다면
		return 0; // 0을 반환

	lsh = GetHeight(GetLeftSubTree(bst));
	rsh = GetHeight(GetRightSubTree(bst));

	return lsh - rsh; // 균형 인수 계산 결과 반환

}

// 트리의 균형을 잡는 함수
BTreeNode* Rebalance(BTreeNode** pRoot)
{
	int hDiff = GetHeightDiff(*pRoot); // 균형 인수 계산 결과

	// 균형 인수가 +2 이상이라면 LL 또는 LR 상태
	if (hDiff > 1) // 왼쪽 서브 트리 방향으로 높이가 2이상 차이가 난다면
	{
		// 왼쪽 서브 트리의 균형 인수를 확인한다
		if (GetHeightDiff(GetLeftSubTree(*pRoot)) > 0)
			*pRoot = RotateLL(*pRoot); // +1 이상이라면 LL 상태
		else
			*pRoot = RotateLR(*pRoot); // -1 이하라면 LR 상태
	}

	// 균형 인수가 -2 이하라면 RR 또는 RL 상태
	if (hDiff < -1) // 오른쪽 서브 트리 방향으로 높이가 2이상 차이가 난다면
	{
		// 오른쪽 서브 트리의 균형 인수를 확인한다
		if (GetHeightDiff(GetRightSubTree(*pRoot)) < 0)
			*pRoot = RotateRR(*pRoot); // -1 이하라면 RR 상태
		else
			*pRoot = RotateRL(*pRoot); // +1 이상이라면 RL 상태
	}

	return *pRoot;
}