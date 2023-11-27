/*
* ���� �ڷᱸ�� - ���� ����Ʈ ��� ���� Ʈ��
* ���ϸ�: BinaryTreeMain.c
* ���� ����: 0.2
* �ۼ���: Sevenshards
* �ۼ� ����: 2023-11-23
* ���� ���� �ۼ� ����: 2023-11-23
* ���� ����: ����, ���� ��ȸ �߰� �� ��ȸ �� �� ���� ������ �� �ֵ��� �Լ� ������ ���.
* ���� ���� ����: ���� ��ȸ ��ɱ��� ������ ���� Ʈ�� ����.
*/

#include <stdio.h>
#include "BinaryTree.h"

void ShowIntData(int data);

int main()
{
	// ��� ����
	BTreeNode* bt1 = MakeBTreeNode();
	BTreeNode* bt2 = MakeBTreeNode();
	BTreeNode* bt3 = MakeBTreeNode();
	BTreeNode* bt4 = MakeBTreeNode();
	BTreeNode* bt5 = MakeBTreeNode();
	BTreeNode* bt6 = MakeBTreeNode();

	// ��忡 ������ ����
	SetData(bt1, 1);
	SetData(bt2, 2);
	SetData(bt3, 3);
	SetData(bt4, 4);
	SetData(bt5, 5);
	SetData(bt6, 6);

	MakeLeftSubTree(bt1, bt2); // bt1�� ���� �ڽ� ���� bt2 ����
	MakeRightSubTree(bt1, bt3); // bt1�� ������ �ڽ� ���� bt3 ����
	MakeLeftSubTree(bt2, bt4); // bt2�� ���� �ڽ� ���� bt4 ����
	MakeRightSubTree(bt2, bt5); // bt2�� ������ �ڽ� ���� bt5 ����
	MakeRightSubTree(bt3, bt6); // bt3�� ������ �ڽ� ���� bt6 ����

	PreorderTraversal(bt1, ShowIntData);
	printf("\n");
	InorderTraversal(bt1, ShowIntData);
	printf("\n");
	PostorderTraversal(bt1, ShowIntData);
	printf("\n");

	DeleteTree(bt1);

	return 0;
}

void ShowIntData(int data)
{
	printf("%d ", data);
}