/*
* 비선형 자료구조 - 연결 리스트 기반 이진 탐색 트리
* 파일명: BinarySearchTree.c
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2023-11-28
* 이전 버전 작성 일자:
* 버전 내용: 간단한 이진 탐색 트리 구현.
* 이전 버전 내용:
*/
#include <stdlib.h>
#include "BinarySearchTree.h"

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
void BSTInsert(BTreeNode** pRoot, BSTData data)
{
	BTreeNode* pNode = NULL; // 현재 노드 기준의 부모 노드
	BTreeNode* cNode = *pRoot; // 현재 노드, 루트 노드에서부터 시작하므로 루트 노드의 주소값으로 초기화
	BTreeNode* newNode = NULL; // 새로 생성될 노드

	// 새로 생성될 노드(새 데이터가 담길 노드)가 추가될 위치를 찾기
	while (cNode != NULL) // 현재 노드가 NULL이 아닐 때까지, 다시 말해서 새로운 노드가 추가될 위치를 찾을 때까지
	{
		if (data == GetData(cNode)) // 현재 노드의 데이터가 입력된 데이터와 같다면
			return; // 데이터(키)의 중복을 허용하지 않으므로 return

		// 데이터 중복 검사가 끝난 후
		pNode = cNode; // 현재 노드 위치를 현재 위치한 노드의 부모 노드로 갱신

		if (data < GetData(cNode)) // 추가할 데이터가 현재 노드의 데이터보다 작다면
			cNode = GetLeftSubTree(cNode); // 왼쪽으로 이동
		else // 추가할 데이터가 현재 노드의 데이터보다 크다면
			cNode = GetRightSubTree(cNode); // 오른쪽으로 이동
	}

	// 위치를 찾은 후, 해당 위치에 새로운 노드 생성하고 추가
	newNode = MakeBTreeNode(); // 새로운 노드를 생성
	SetData(newNode, data); // 새로운 노드에 데이터 저장

	// 새로 생성될 위치(cNode)의 부모노드(pNode)의 자식 노드로 추가
	if (pNode != NULL) // 새로 생성될 노드가 루트 노드(루트 노드는 부모 노드가 없으므로)가 아니라면
	{
		if (data < GetData(pNode)) // 부모 노드가 가진 데이터보다 새로운 노드의 데이터가 작다면
			MakeLeftSubTree(pNode, newNode); // 왼쪽으로 새 노드를 연결
		else // 부모 노드가 가진 데이터보다 새로운 노드의 데이터가 크다면
			MakeRightSubTree(pNode, newNode); // 오른쪽으로 새 노드를 연결
	}
	else // 만약 새로 생성되는 노드가 루트 노드라면
		*pRoot = newNode; // 새로운 노드가 루트 노드가 된다.
}

// 이진 탐색 트리를 대상으로 데이터 탐색
BTreeNode* BSTSearch(BTreeNode* bst, BSTData target)
{
	BTreeNode* cNode = bst; // 현재 가리키는 노드, 트리의 주소값(루트 노드의 주소값)부터 시작한다.
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