/*
* 비선형 자료구조 - 연결 리스트 기반 이진 탐색 트리
* 파일명: BinarySearchTree.h
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2023-11-28
* 이전 버전 작성 일자:
* 버전 내용: 간단한 이진 탐색 트리 구현.
* 이전 버전 내용:
*/

#ifndef __BINARY_SEARCH_TREE_H__
#define __BINARY_SEARCH_TREE_H__

#include "BinaryTree.h"

typedef BTData BSTData; // 이진 트리에서 사용하는 데이터형 BTData를 BSTData로 별칭 부여

// 이진 탐색 트리의 생성 및 초기화
void BSTMakeAndInit(BTreeNode** pRoot);

// 노드에 저장된 데이터 반환
BSTData BSTGetNodeData(BTreeNode* bst); 

// 이진 탐색 트리를 대상으로 데이터 저장 (노드 생성 포함)
void BSTInsert(BTreeNode** pRoot, BSTData data);

// 이진 탐색 트리를 대상으로 데이터 탐색
BTreeNode* BSTSearch(BTreeNode* bst, BSTData target);

#endif