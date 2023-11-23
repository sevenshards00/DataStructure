/*
* �ڷᱸ�� - ����Ʈ�� ����
* �ۼ���: Sevenshards
* �ۼ� ����: 2023.11.23
* ���� �ڷᱸ�� - ���� ����Ʈ ��� ���� Ʈ��
* ���ϸ�: BinaryTree.c
*/
// ������ ǥ���� �����ڸ�, ���� Ʈ���� ����"�� �� �ִ� ����"�� ����� �����̴�.
// ���� ���� �� ���ΰ��� ���߿� ��������.
#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"

// ����� ���� �� ������ ����� ��ȸ
BTreeNode* MakeBTreeNode(void) // ���� Ʈ���� ��� ����
{
	BTreeNode* node = (BTreeNode*)malloc(sizeof(BTreeNode));
	node->left = NULL;
	node->right = NULL;
	return node;
}

BTData GetData(BTreeNode* bt) // ���� Ʈ�� ����� �����͸� ��ȯ
{
	return bt->data;
}

void SetData(BTreeNode* bt, BTData data) // ���� Ʈ�� ��忡 �����͸� ����
{
	bt->data = data;
}

BTreeNode* GetLeftSubTree(BTreeNode* bt) // ���� ���� Ʈ���� �ּ� ��(���� ���� Ʈ���� ��Ʈ ���)�� ��ȯ
{
	return bt->left;
}
BTreeNode* GetRightSubTree(BTreeNode* bt) // ������ ���� Ʈ���� �ּ� ��(������ ���� Ʈ���� ��Ʈ ���)�� ��ȯ
{
	return bt->right;
}

// ����� ����
void MakeLeftSubTree(BTreeNode* main, BTreeNode* sub) // �Ű����� sub�� ���޵� Ʈ�� �Ǵ� ��带 �Ű����� main�� ���� ����Ʈ���� ����
{
	if (main->left != NULL) // �̹� ���ʿ� ����� Ʈ���� ��尡 �ִٸ�
		free(main->left); // �Ҵ�� �޸𸮸� �����Ѵ�.
	
	main->left = sub; // �׸��� ���� ���ʿ� �����Ѵ�.
}

void MakeRightSubTree(BTreeNode* main, BTreeNode* sub) // �Ű� ���� sub�� ���޵� Ʈ�� �Ǵ� ��带 �Ű����� main�� ������ ����Ʈ���� ����
{
	if (main->right != NULL) // �̹� �����ʿ� ����� Ʈ���� ��尡 �ִٸ�
		free(main->right); // �Ҵ�� �޸𸮸� �����Ѵ�.

	main->right = sub; // �׸��� ���� �����ʿ� �����Ѵ�.
}