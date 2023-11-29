/*
* ���� �ڷᱸ�� - ���� ����Ʈ ��� ���� Ʈ��
* ���ϸ�: BinaryTree.c
* ���� ����: 0.3
* �ۼ���: Sevenshards
* �ۼ� ����: 2023-11-28
* ���� ���� �ۼ� ����: 2023-11-23
* ���� ����: ����, ������ �ڽ� ��� ���� ���� �Լ� �߰� �� ����, ������ �ڽ� ��� ���� �Լ� �߰�
* ���� ���� ����: ����, ���� ��ȸ �߰� �� ��ȸ �� �� ���� ������ �� �ֵ��� �Լ� ������ ���.
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

// ����� ���� �� ���� (�޸� �Ҵ� ���� ���� ����)
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

// 11.28 �߰�
// �޸� �Ҵ� ���� ���� main�� ���� �ڽ� ��� ����
void ChangeLeftSubTree(BTreeNode* main, BTreeNode* sub) // �Ű����� sub�� ���޵� Ʈ�� �Ǵ� ��带 �Ű����� main�� ���� ����Ʈ���� ����
{
	main->left = sub;
}

// �޸� �Ҵ� ���� ���� main�� ������ �ڽ� ��带 ����
void ChangeRightSubTree(BTreeNode* main, BTreeNode* sub) // �Ű� ���� sub�� ���޵� Ʈ�� �Ǵ� ��带 �Ű����� main�� ������ ����Ʈ���� ����
{
	main->right = sub;
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

// 11.28 �߰�
// ��� ���� �κ�
// ���⼭ �ٷ� free�� �ϴ� ���� �ƴ϶�, �ش� �Լ��� ȣ���� �������� free�� ���� �Ҵ��� �޸𸮸� ����.
// �׷��� �ּҰ��� ��ȯ�ϰ� �� ��.
BTreeNode* RemoveLeftSubTree(BTreeNode* bt) // ���� �ڽ� ��带 Ʈ������ ����, ���ŵ� ����� �ּҰ� ��ȯ
{
	BTreeNode* dNode = NULL; // ������ ���, �Ϻ� �����Ϸ������� �ʱ�ȭ���� ������ ������ ���Ƿ� NULL�� �ʱ�ȭ

	if (bt != NULL) // ��� ��尡 �ִٸ� (NULL�� �ƴ϶��)
	{
		dNode = bt->left; // ���ŵ� ��带 ���� ����� ���� �ڽ� ����
		bt->left = NULL; // ���� �ڽ� ���� NULL�� �ٲپ� �ƹ��͵� ����Ű�� �ʴ´�
	}

	return dNode;
}

BTreeNode* RemoveRightSubTree(BTreeNode* bt) // ������ �ڽ� ��带 Ʈ������ ����, ���ŵ� ����� �ּҰ� ��ȯ
{
	BTreeNode* dNode = NULL; // ������ ���, �Ϻ� �����Ϸ������� �ʱ�ȭ���� ������ ������ ���Ƿ� NULL�� �ʱ�ȭ

	if (bt != NULL) // ��� ��尡 �ִٸ� (NULL�� �ƴ϶��)
	{
		dNode = bt->right; // ���ŵ� ��带 ���� ����� ���� �ڽ� ����
		bt->right = NULL; // ���� �ڽ� ���� NULL�� �ٲپ� �ƹ��͵� ����Ű�� �ʴ´�
	}

	return dNode;
}