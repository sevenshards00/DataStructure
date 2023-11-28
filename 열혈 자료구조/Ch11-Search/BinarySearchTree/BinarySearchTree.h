/*
* ���� �ڷᱸ�� - ���� ����Ʈ ��� ���� Ž�� Ʈ��
* ���ϸ�: BinarySearchTree.h
* ���� ����: 0.1
* �ۼ���: Sevenshards
* �ۼ� ����: 2023-11-28
* ���� ���� �ۼ� ����:
* ���� ����: ������ ���� Ž�� Ʈ�� ����.
* ���� ���� ����:
*/

#ifndef __BINARY_SEARCH_TREE_H__
#define __BINARY_SEARCH_TREE_H__

#include "BinaryTree.h"

typedef BTData BSTData; // ���� Ʈ������ ����ϴ� �������� BTData�� BSTData�� ��Ī �ο�

// ���� Ž�� Ʈ���� ���� �� �ʱ�ȭ
void BSTMakeAndInit(BTreeNode** pRoot);

// ��忡 ����� ������ ��ȯ
BSTData BSTGetNodeData(BTreeNode* bst); 

// ���� Ž�� Ʈ���� ������� ������ ���� (��� ���� ����)
void BSTInsert(BTreeNode** pRoot, BSTData data);

// ���� Ž�� Ʈ���� ������� ������ Ž��
BTreeNode* BSTSearch(BTreeNode* bst, BSTData target);

#endif