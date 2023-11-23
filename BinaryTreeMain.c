/*
* 비선형 자료구조 - 연결 리스트 기반 이진 트리
* 파일명: BinaryTreeMain.c
* 파일 버전: 0.2
* 작성자: Sevenshards
* 작성 일자: 2023-11-23
* 이전 버전 작성 일자: 2023-11-23
* 버전 내용: 전위, 중위 순회 추가 및 순회 시 할 일을 결정할 수 있도록 함수 포인터 사용.
* 이전 버전 내용: 중위 순회 기능까지 포함한 이진 트리 구현.
*/

#include <stdio.h>
#include "BinaryTree.h"

void ShowIntData(int data);

int main()
{
	// 노드 생성
	BTreeNode* bt1 = MakeBTreeNode();
	BTreeNode* bt2 = MakeBTreeNode();
	BTreeNode* bt3 = MakeBTreeNode();
	BTreeNode* bt4 = MakeBTreeNode();
	BTreeNode* bt5 = MakeBTreeNode();
	BTreeNode* bt6 = MakeBTreeNode();

	// 노드에 데이터 저장
	SetData(bt1, 1);
	SetData(bt2, 2);
	SetData(bt3, 3);
	SetData(bt4, 4);
	SetData(bt5, 5);
	SetData(bt6, 6);

	MakeLeftSubTree(bt1, bt2); // bt1의 왼쪽 자식 노드로 bt2 연결
	MakeRightSubTree(bt1, bt3); // bt1의 오른쪽 자식 노드로 bt3 연결
	MakeLeftSubTree(bt2, bt4); // bt2의 왼쪽 자식 노드로 bt4 연결
	MakeRightSubTree(bt2, bt5); // bt2의 오른쪽 자식 노드로 bt5 연결
	MakeRightSubTree(bt3, bt6); // bt3의 오른쪽 자식 노드로 bt6 연결

	PreorderTraversal(bt1, ShowIntData);
	printf("\n");
	InorderTraversal(bt1, ShowIntData);
	printf("\n");
	PostorderTraversal(bt1, ShowIntData);
	printf("\n");

	DeleteTree(bt1);

	return 0;
}

void ShowIntData(int data)
{
	printf("%d ", data);
}