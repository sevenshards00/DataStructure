/*
* �ڷᱸ�� - ����Ʈ�� ����
* �ۼ���: Sevenshards
* �ۼ� ����: 2023.11.23
* ���� �ڷᱸ�� - ���� ����Ʈ ��� ���� Ʈ��
* ���ϸ�: BinaryTree.c
*/

#include <stdio.h>
#include "BinaryTree.h"

// ��ȸ (��͸� �̿��Ͽ� �����Ѵ�!)
// ���� ��ȸ 1) ���� ���� Ʈ�� 2) ��Ʈ ��� 3) ������ ���� Ʈ��
void InorderTraversal(BTreeNode* bt)
{
	if (bt == NULL) // ���� ������ ���(NULL)�̶��? ����� Ż�� ������ �ȴ�.
		return;

	InorderTraversal(bt->left); // 1) ���� ���� Ʈ���� ��ȸ
	printf("%d\n", bt->data); // 2) ��Ʈ ��带 �湮
	InorderTraversal(bt->right); // 3) ������ ���� Ʈ���� ��ȸ
}

int main()
{
	// ��� ����
	BTreeNode* bt1 = MakeBTreeNode();
	BTreeNode* bt2 = MakeBTreeNode();
	BTreeNode* bt3 = MakeBTreeNode();
	BTreeNode* bt4 = MakeBTreeNode();

	// ��忡 ������ ����
	SetData(bt1, 1);
	SetData(bt2, 2);
	SetData(bt3, 3);
	SetData(bt4, 4);

	MakeLeftSubTree(bt1, bt2); // bt1�� ���� �ڽ� ���� bt2 ����
	MakeRightSubTree(bt1, bt3); // bt1�� ������ �ڽ� ���� bt3 ����
	MakeLeftSubTree(bt2, bt4); // bt2�� ���� �ڽ� ���� bt4 ����

	//printf("%d\n", GetData(GetLeftSubTree(bt1))); // bt1�� ���� �ڽ� ��� ������ ���
	//printf("%d\n", GetData(GetRightSubTree(bt1))); // bt1�� ������ �ڽ� ��� ������ ���
	//printf("%d\n", GetData(GetLeftSubTree(GetLeftSubTree(bt1)))); // bt1�� ���� �ڽ� ����� ���� �ڽ� ����� ������ ���

	InorderTraversal(bt1);

	return 0;
}