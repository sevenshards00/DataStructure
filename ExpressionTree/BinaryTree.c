/*
* ���� �ڷᱸ�� - ���� ����Ʈ ��� ���� Ʈ��
* ���ϸ�: BinaryTree.c
* ���� ����: 0.2
* �ۼ���: Sevenshards
* �ۼ� ����: 2023-11-23
* ���� ���� �ۼ� ����: 2023-11-23
* ���� ����: ����, ���� ��ȸ �߰� �� ��ȸ �� �� ���� ������ �� �ֵ��� �Լ� ������ ���.
* ���� ���� ����: ���� ��ȸ ��ɱ��� ������ ���� Ʈ�� ����.
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

BTData GetData(BTreeNode* bt) // ���� Ʈ�� ����� �����͸� ��ȯ (Getter)
{
	return bt->data;
}

void SetData(BTreeNode* bt, BTData data) // ���� Ʈ�� ��忡 �����͸� ���� (Setter)
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

// ��ȸ (��͸� �̿��Ͽ� �����Ѵ�!)
// ���� ��ȸ 1)���� ���� Ʈ�� -> 2)��Ʈ ��� -> 3)������ ���� Ʈ��
void InorderTraversal(BTreeNode* bt, VisitFuncPtr action)
{
	if (bt == NULL) // ���� ������ ���(NULL)�̶��? ����� Ż�� ������ �ȴ�.
		return;

	InorderTraversal(bt->left, action); // 1) ���� ���� Ʈ���� ��ȸ
	action(bt->data); // 2) ��Ʈ ��带 �湮
	InorderTraversal(bt->right, action); // 3) ������ ���� Ʈ���� ��ȸ
}
// ���� ��ȸ 1)��Ʈ ��� -> 2)���� ���� Ʈ�� -> 3)������ ���� Ʈ��
void PreorderTraversal(BTreeNode* bt, VisitFuncPtr action)
{
	if (bt == NULL) // ���� ������ ���(NULL)�̶��? ����� Ż�� ������ �ȴ�.
		return;

	action(bt->data); // 1) ��Ʈ ��带 �湮
	PreorderTraversal(bt->left, action); // 2) ���� ���� Ʈ���� ��ȸ
	PreorderTraversal(bt->right, action); // 3) ������ ���� Ʈ���� ��ȸ
}
// ���� ��ȸ 1)���� ���� Ʈ�� -> 2)������ ����Ʈ�� -> 3)��Ʈ ���
void PostorderTraversal(BTreeNode* bt, VisitFuncPtr action)
{
	if (bt == NULL) // ���� ������ ���(NULL)�̶��? ����� Ż�� ������ �ȴ�.
		return;

	PostorderTraversal(bt->left, action); // 1) ���� ���� Ʈ���� ��ȸ
	PostorderTraversal(bt->right, action); // 2) ������ ���� Ʈ���� ��ȸ
	action(bt->data); // 3) ��Ʈ ��带 �湮
}

// Ʈ���� ��� ��� ����
void DeleteTree(BTreeNode* bt)
{
	if (bt == NULL) // ������ ���(NULL)�̶�� ��� Ż��.
		return;

	// ���� ��ȸ�� ���� ����, �׸��� ������, ���������� ��Ʈ ��带 ���� ���·� ����.
	DeleteTree(bt->left);
	DeleteTree(bt->right);

	printf("delete tree node data: %d\n", bt->data);
	free(bt);
}