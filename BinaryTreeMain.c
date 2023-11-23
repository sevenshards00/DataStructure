/*
* 자료구조 - 이진트리 구현
* 작성자: Sevenshards
* 작성 일자: 2023.11.23
* 비선형 자료구조 - 연결 리스트 기반 이진 트리
* 파일명: BinaryTree.c
*/

#include <stdio.h>
#include "BinaryTree.h"

// 순회 (재귀를 이용하여 구현한다!)
// 중위 순회 1) 왼쪽 서브 트리 2) 루트 노드 3) 오른쪽 서브 트리
void InorderTraversal(BTreeNode* bt)
{
	if (bt == NULL) // 만약 공집합 노드(NULL)이라면? 재귀의 탈출 조건이 된다.
		return;

	InorderTraversal(bt->left); // 1) 왼쪽 서브 트리를 순회
	printf("%d\n", bt->data); // 2) 루트 노드를 방문
	InorderTraversal(bt->right); // 3) 오른쪽 서브 트리를 순회
}

int main()
{
	// 노드 생성
	BTreeNode* bt1 = MakeBTreeNode();
	BTreeNode* bt2 = MakeBTreeNode();
	BTreeNode* bt3 = MakeBTreeNode();
	BTreeNode* bt4 = MakeBTreeNode();

	// 노드에 데이터 저장
	SetData(bt1, 1);
	SetData(bt2, 2);
	SetData(bt3, 3);
	SetData(bt4, 4);

	MakeLeftSubTree(bt1, bt2); // bt1의 왼쪽 자식 노드로 bt2 연결
	MakeRightSubTree(bt1, bt3); // bt1의 오른쪽 자식 노드로 bt3 연결
	MakeLeftSubTree(bt2, bt4); // bt2의 왼쪽 자식 노드로 bt4 연결

	//printf("%d\n", GetData(GetLeftSubTree(bt1))); // bt1의 왼쪽 자식 노드 데이터 출력
	//printf("%d\n", GetData(GetRightSubTree(bt1))); // bt1의 오른쪽 자식 노드 데이터 출력
	//printf("%d\n", GetData(GetLeftSubTree(GetLeftSubTree(bt1)))); // bt1의 왼쪽 자식 노드의 왼쪽 자식 노드의 데이터 출력

	InorderTraversal(bt1);

	return 0;
}