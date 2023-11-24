/*
* ���� �ڷᱸ�� - ���� Ʈ�� (���� Ʈ���� ����)
* ���ϸ�: ExpressionTree.h
* ���� ����: 0.1
* �ۼ���: Sevenshards
* �ۼ� ����: 2023-11-24
* ���� ���� �ۼ� ����:
* ���� ����: ���� Ʈ�� ���� �� ��� ��� ���α׷� �ۼ�
* ���� ���� ����:
*/

#ifndef __EXPRESSION_TREE_H__
#define __EXPRESSION_TREE_H__

#include "BinaryTree.h" // ���� Ʈ���� ���� Ʈ���� ����.

BTreeNode* MakeExpTree(char exp[]); // ���� Ʈ�� ����
int EvaluateExpTree(BTreeNode* bt); // ���� Ʈ���� �̿��� ���

// ������ ���� Ʈ���� �°� �Ǿ��°� Ȯ���ϱ� ���� ���� ��º�
void ShowPrefixTypeExp(BTreeNode* bt); // ���� ǥ��� ��� ���
void ShowInfixTypeExp(BTreeNode* bt); // ���� ǥ��� ��� ���
void ShowPostfixTypeExp(BTreeNode* bt); // ���� ǥ��� ��� ���

#endif