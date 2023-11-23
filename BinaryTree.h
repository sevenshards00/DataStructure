/*
* 자료구조 - 이진트리 구현
* 작성자: Sevenshards
* 작성 일자: 2023.11.23
* 비선형 자료구조 - 연결 리스트 기반 이진 트리
* 파일명: BinaryTree.h
*/
// 저자의 표현을 빌리자면, 이진 트리를 구현"할 수 있는 도구"를 만드는 과정이다.
// 어디다 갖다 쓸 것인가는 나중에 생각하자.
#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

typedef int BTData; // 이진 트리의 데이터. 자료형은 편의상 int

// 이진 트리의 노드 구조체. 이중 연결 리스트 구조.
// 그리고 이 자체가 Tree다.
// 이전 선형 자료 구조에서는 리스트나 스택, 큐와 같은 경우는 노드 따로, 리스트, 스택, 큐를 따로 구조체를 정의하였다.
// 하지만 이건 노드임과 동시에 트리가 된다.
typedef struct _bTreeNode
{
	BTData data;
	struct _bTreeNode* left;
	struct _bTreeNode* right;
} BTreeNode; 

// 노드의 생성 및 데이터 저장과 조회
BTreeNode* MakeBTreeNode(void); // 이진 트리의 노드 생성
BTData GetData(BTreeNode* bt); // 이진 트리 노드의 데이터를 반환
void SetData(BTreeNode* bt, BTData data); // 이진 트리 노드에 데이터를 저장

BTreeNode* GetLeftSubTree(BTreeNode* bt); // 왼쪽 서브 트리의 주소 값(왼쪽 서브 트리의 루트 노드)을 반환
BTreeNode* GetRightSubTree(BTreeNode* bt); // 오른쪽 서브 트리의 주소 값(오른쪽 서브 트리의 루트 노드)을 반환

// 노드의 연결
void MakeLeftSubTree(BTreeNode* main, BTreeNode* sub); // 매개변수 sub로 전달된 트리 또는 노드를 매개변수 main의 왼쪽 서브트리로 연결
void MakeRightSubTree(BTreeNode* main, BTreeNode* sub); // 매개 변수 sub로 전달된 트리 또는 노드를 매개변수 main의 오른쪽 서브트리로 연결

#endif