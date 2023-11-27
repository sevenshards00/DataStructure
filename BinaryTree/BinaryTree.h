/*
* 비선형 자료구조 - 연결 리스트 기반 이진 트리
* 파일명: BinaryTree.h
* 파일 버전: 0.2
* 작성자: Sevenshards
* 작성 일자: 2023-11-23
* 이전 버전 작성 일자: 2023-11-23
* 버전 내용: 전위, 중위 순회 추가 및 순회 시 할 일을 결정할 수 있도록 함수 포인터 사용.
* 이전 버전 내용: 중위 순회 기능까지 포함한 이진 트리 구현.
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
BTData GetData(BTreeNode* bt); // 이진 트리 노드의 데이터를 반환 (Getter)
void SetData(BTreeNode* bt, BTData data); // 이진 트리 노드에 데이터를 저장 (Setter)

BTreeNode* GetLeftSubTree(BTreeNode* bt); // 왼쪽 서브 트리의 주소 값(왼쪽 서브 트리의 루트 노드)을 반환
BTreeNode* GetRightSubTree(BTreeNode* bt); // 오른쪽 서브 트리의 주소 값(오른쪽 서브 트리의 루트 노드)을 반환

// 노드의 연결
void MakeLeftSubTree(BTreeNode* main, BTreeNode* sub); // 매개변수 sub로 전달된 트리 또는 노드를 매개변수 main의 왼쪽 서브트리로 연결
void MakeRightSubTree(BTreeNode* main, BTreeNode* sub); // 매개 변수 sub로 전달된 트리 또는 노드를 매개변수 main의 오른쪽 서브트리로 연결

// 순회 (재귀를 이용하여 구현한다!)
// 함수 포인터를 선언 -> 이 부분에 대한 설명이 좀 더 필요하다.
typedef void VisitFuncPtr(BTData data);
// typedef void (*VisitFuncPtr)(BTData data); -> 이거랑 동일하다.
// 여기에 대해서 내용을 추가 정리해두겠다.
// typedef 선언이 없었다고 치면 현재 반환형은 void에 매개변수는 BTData형의 data를 받는 함수가 되고, 함수의 이름은 VisitFuncPtr이 된다.
// 그런데 여기서 typedef 선언이 추가되면, 함수의 이름이 아니라 "함수 포인터"로 인지를 하게 된다.
// 마치 배열이 연산식에 사용되면 포인터가 되는 것처럼 decay된다는 개념과 비슷하다.
// 그렇기 때문에 VisitFuncPtr이라는 이름을 자료형처럼 쓸 수 있는 것이다.

// 중위 순회 1)왼쪽 서브 트리 -> 2)루트 노드 -> 3)오른쪽 서브 트리
void InorderTraversal(BTreeNode* bt, VisitFuncPtr action);
// 전위 순회 1)루트 노드 -> 2)왼쪽 서브 트리 -> 3)오른쪽 서브 트리
void PreorderTraversal(BTreeNode* bt, VisitFuncPtr action);
// 후위 순회 1)왼쪽 서브 트리 -> 2)오른쪽 서브트리 -> 3)루트 노드
void PostorderTraversal(BTreeNode* bt, VisitFuncPtr action);

// 트리의 모든 노드 삭제
void DeleteTree(BTreeNode* bt);

#endif