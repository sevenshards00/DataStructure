/*
* 비선형 자료구조 - 연결 리스트 기반 이진 탐색 트리
* 파일명: BinarySearchTreeMain.h
* 파일 버전: 0.2
* 작성자: Sevenshards
* 작성 일자: 2023-11-28
* 이전 버전 작성 일자: 2023-11-28
* 버전 내용: 삭제 기능, 트리 전체 조회 추가로 구현
* 이전 버전 내용: 간단한 이진 탐색 트리 구현.
*/

#include <stdio.h>
#include <stdlib.h>
#include "BinarySearchTree.h"

int main()
{
	BTreeNode* bstRoot;
	BTreeNode* sNode; // search node

	BSTMakeAndInit(&bstRoot);

	BSTInsert(&bstRoot, 5);
	BSTInsert(&bstRoot, 8);
	BSTInsert(&bstRoot, 1);
	BSTInsert(&bstRoot, 6);
	BSTInsert(&bstRoot, 4);
	BSTInsert(&bstRoot, 9);
	BSTInsert(&bstRoot, 3);
	BSTInsert(&bstRoot, 2);
	BSTInsert(&bstRoot, 7);

	BSTShowAll(bstRoot);
	printf("\n");
	sNode = BSTRemove(&bstRoot, 3);
	free(sNode);

	BSTShowAll(bstRoot);
	printf("\n");
	sNode = BSTRemove(&bstRoot, 8);
	free(sNode);

	BSTShowAll(bstRoot);
	printf("\n");
	sNode = BSTRemove(&bstRoot, 1);
	free(sNode);

	BSTShowAll(bstRoot);
	printf("\n");
	sNode = BSTRemove(&bstRoot, 6);
	free(sNode);

	BSTShowAll(bstRoot);
	printf("\n");
	return 0;
}