/*
* 비선형 자료구조 - 연결 리스트 기반 이진 탐색 트리
* 파일명: BinarySearchTreeMain.h
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2023-11-28
* 이전 버전 작성 일자:
* 버전 내용: 간단한 이진 탐색 트리 구현.
* 이전 버전 내용:
*/

#include <stdio.h>
#include "BinarySearchTree.h"

int main()
{
	BTreeNode* bstRoot;
	BTreeNode* sNode; // search node

	BSTMakeAndInit(&bstRoot);

	BSTInsert(&bstRoot, 9);
	BSTInsert(&bstRoot, 1);
	BSTInsert(&bstRoot, 6);
	BSTInsert(&bstRoot, 2);
	BSTInsert(&bstRoot, 8);
	BSTInsert(&bstRoot, 3);
	BSTInsert(&bstRoot, 5);
	BSTInsert(&bstRoot, 1);

	sNode = BSTSearch(bstRoot, 1);
	if (sNode == NULL) // 찾지 못한 경우
		printf("Search failed\n");
	else // 찾았을 때
		printf("Search success. Key value: %d\n", BSTGetNodeData(sNode));

	sNode = BSTSearch(bstRoot, 4);
	if (sNode == NULL) // 찾지 못한 경우
		printf("Search failed\n");
	else // 찾았을 때
		printf("Search success. Key value: %d\n", BSTGetNodeData(sNode));

	sNode = BSTSearch(bstRoot, 6);
	if (sNode == NULL) // 찾지 못한 경우
		printf("Search failed\n");
	else // 찾았을 때
		printf("Search success. Key value: %d\n", BSTGetNodeData(sNode));

	sNode = BSTSearch(bstRoot, 7);
	if (sNode == NULL) // 찾지 못한 경우
		printf("Search failed\n");
	else // 찾았을 때
		printf("Search success. Key value: %d\n", BSTGetNodeData(sNode));

	return 0;
}