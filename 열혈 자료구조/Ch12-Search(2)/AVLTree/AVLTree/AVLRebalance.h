/*
* 비선형 자료구조 - AVL 트리 (이진 탐색 트리 확장)
* 파일명: AVLRebalance.h
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2023-11-29
* 이전 버전 작성 일자:
* 버전 내용: 균형을 잡는 이진 탐색 트리인 AVL 트리 확장 구현
* 이전 버전 내용:
*/

#ifndef __AVL_REBALANCE_H__
#define __AVL_REBALANCE_H__

#include "BinaryTree.h"

// 트리의 균형을 잡는 함수
BTreeNode* Rebalance(BTreeNode** pRoot);

#endif