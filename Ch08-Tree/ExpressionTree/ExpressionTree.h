/*
* 비선형 자료구조 - 수식 트리 (이진 트리의 응용)
* 파일명: ExpressionTree.h
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2023-11-24
* 이전 버전 작성 일자:
* 버전 내용: 수식 트리 구현 및 계산 결과 프로그램 작성
* 이전 버전 내용:
*/

#ifndef __EXPRESSION_TREE_H__
#define __EXPRESSION_TREE_H__

#include "BinaryTree.h" // 수식 트리도 이진 트리의 일종.

BTreeNode* MakeExpTree(char exp[]); // 수식 트리 구성
int EvaluateExpTree(BTreeNode* bt); // 수식 트리를 이용한 계산

// 생성한 수식 트리가 맞게 되었는가 확인하기 위해 만든 출력부
void ShowPrefixTypeExp(BTreeNode* bt); // 전위 표기법 기반 출력
void ShowInfixTypeExp(BTreeNode* bt); // 중위 표기법 기반 출력
void ShowPostfixTypeExp(BTreeNode* bt); // 후위 표기법 기반 출력

#endif