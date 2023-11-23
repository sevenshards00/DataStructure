/*
* �ڷᱸ�� - ����Ʈ�� ����
* �ۼ���: Sevenshards
* �ۼ� ����: 2023.11.23
* ���� �ڷᱸ�� - ���� ����Ʈ ��� ���� Ʈ��
* ���ϸ�: BinaryTree.h
*/
// ������ ǥ���� �����ڸ�, ���� Ʈ���� ����"�� �� �ִ� ����"�� ����� �����̴�.
// ���� ���� �� ���ΰ��� ���߿� ��������.
#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

typedef int BTData; // ���� Ʈ���� ������. �ڷ����� ���ǻ� int

// ���� Ʈ���� ��� ����ü. ���� ���� ����Ʈ ����.
// �׸��� �� ��ü�� Tree��.
// ���� ���� �ڷ� ���������� ����Ʈ�� ����, ť�� ���� ���� ��� ����, ����Ʈ, ����, ť�� ���� ����ü�� �����Ͽ���.
// ������ �̰� ����Ӱ� ���ÿ� Ʈ���� �ȴ�.
typedef struct _bTreeNode
{
	BTData data;
	struct _bTreeNode* left;
	struct _bTreeNode* right;
} BTreeNode; 

// ����� ���� �� ������ ����� ��ȸ
BTreeNode* MakeBTreeNode(void); // ���� Ʈ���� ��� ����
BTData GetData(BTreeNode* bt); // ���� Ʈ�� ����� �����͸� ��ȯ
void SetData(BTreeNode* bt, BTData data); // ���� Ʈ�� ��忡 �����͸� ����

BTreeNode* GetLeftSubTree(BTreeNode* bt); // ���� ���� Ʈ���� �ּ� ��(���� ���� Ʈ���� ��Ʈ ���)�� ��ȯ
BTreeNode* GetRightSubTree(BTreeNode* bt); // ������ ���� Ʈ���� �ּ� ��(������ ���� Ʈ���� ��Ʈ ���)�� ��ȯ

// ����� ����
void MakeLeftSubTree(BTreeNode* main, BTreeNode* sub); // �Ű����� sub�� ���޵� Ʈ�� �Ǵ� ��带 �Ű����� main�� ���� ����Ʈ���� ����
void MakeRightSubTree(BTreeNode* main, BTreeNode* sub); // �Ű� ���� sub�� ���޵� Ʈ�� �Ǵ� ��带 �Ű����� main�� ������ ����Ʈ���� ����

#endif