/*
* 비선형 자료구조 - AVL 트리 (이진 탐색 트리 확장)
* 파일명: AVLTreeMain.c
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2023-11-29
* 이전 버전 작성 일자:
* 버전 내용: 균형을 잡는 이진 탐색 트리인 AVL 트리 확장 구현
* 이전 버전 내용:
*/

#include <stdio.h>
#include "BinaryTree.h"
#include "BinarySearchTree.h"

int main()
{
	BTreeNode* avlRoot;
	BTreeNode* clNode; // 루트 노드의 왼쪽 (current left) 자식 노드
	BTreeNode* crNode; // 루트 노드의 오른쪽 (current right) 자식 노드

	BTreeNode* clNode2; // clNode의 왼쪽 자식 노드
	BTreeNode* crNode2; // clNode의 오른쪽 자식 노드

	BTreeNode* clNode3; // clNode2의 왼쪽 자식 노드
	BTreeNode* crNode3; // clNode2의 오른쪽 자식 노드

	BSTMakeAndInit(&avlRoot); // 트리 생성 및 초기화

	// 노드 삽입
	BSTInsert(&avlRoot, 1);
	BSTInsert(&avlRoot, 2);
	BSTInsert(&avlRoot, 3);
	BSTInsert(&avlRoot, 4);
	BSTInsert(&avlRoot, 5);
	BSTInsert(&avlRoot, 6);
	BSTInsert(&avlRoot, 7);
	BSTInsert(&avlRoot, 8);
	BSTInsert(&avlRoot, 9);

	printf("루트 노드: %d\n", GetData(avlRoot));

	clNode = GetLeftSubTree(avlRoot);   //2, 루트 4의 왼편
	crNode = GetRightSubTree(avlRoot);  //6, 루트 4의 오른편
	printf("%d, %d \n", GetData(clNode), GetData(crNode));

	clNode2 = GetLeftSubTree(clNode);    //1, 2의 왼편
	crNode2 = GetRightSubTree(clNode);   //3, 2의 오른편
	printf("%d, %d \n", GetData(clNode2), GetData(crNode2));

	clNode2 = GetLeftSubTree(crNode);    //5, 3의 왼편
	crNode2 = GetRightSubTree(crNode);   //8, 3의 오른편
	printf("%d, %d \n", GetData(clNode2), GetData(crNode2));

	clNode3 = GetLeftSubTree(crNode2);   //7, 8의 왼편
	crNode3 = GetRightSubTree(crNode2);  //9, 8의 오른편
	printf("%d, %d \n", GetData(clNode3), GetData(crNode3));
	return 0;
}