/*
* ���� �ڷᱸ�� - AVL Ʈ�� (���� Ž�� Ʈ�� Ȯ��)
* ���ϸ�: AVLTreeMain.c
* ���� ����: 0.1
* �ۼ���: Sevenshards
* �ۼ� ����: 2023-11-29
* ���� ���� �ۼ� ����:
* ���� ����: ������ ��� ���� Ž�� Ʈ���� AVL Ʈ�� Ȯ�� ����
* ���� ���� ����:
*/

#include <stdio.h>
#include "BinaryTree.h"
#include "BinarySearchTree.h"

int main()
{
	BTreeNode* avlRoot;
	BTreeNode* clNode; // ��Ʈ ����� ���� (current left) �ڽ� ���
	BTreeNode* crNode; // ��Ʈ ����� ������ (current right) �ڽ� ���

	BTreeNode* clNode2; // clNode�� ���� �ڽ� ���
	BTreeNode* crNode2; // clNode�� ������ �ڽ� ���

	BTreeNode* clNode3; // clNode2�� ���� �ڽ� ���
	BTreeNode* crNode3; // clNode2�� ������ �ڽ� ���

	BSTMakeAndInit(&avlRoot); // Ʈ�� ���� �� �ʱ�ȭ

	// ��� ����
	BSTInsert(&avlRoot, 1);
	BSTInsert(&avlRoot, 2);
	BSTInsert(&avlRoot, 3);
	BSTInsert(&avlRoot, 4);
	BSTInsert(&avlRoot, 5);
	BSTInsert(&avlRoot, 6);
	BSTInsert(&avlRoot, 7);
	BSTInsert(&avlRoot, 8);
	BSTInsert(&avlRoot, 9);

	printf("��Ʈ ���: %d\n", GetData(avlRoot));

	clNode = GetLeftSubTree(avlRoot);   //2, ��Ʈ 4�� ����
	crNode = GetRightSubTree(avlRoot);  //6, ��Ʈ 4�� ������
	printf("%d, %d \n", GetData(clNode), GetData(crNode));

	clNode2 = GetLeftSubTree(clNode);    //1, 2�� ����
	crNode2 = GetRightSubTree(clNode);   //3, 2�� ������
	printf("%d, %d \n", GetData(clNode2), GetData(crNode2));

	clNode2 = GetLeftSubTree(crNode);    //5, 3�� ����
	crNode2 = GetRightSubTree(crNode);   //8, 3�� ������
	printf("%d, %d \n", GetData(clNode2), GetData(crNode2));

	clNode3 = GetLeftSubTree(crNode2);   //7, 8�� ����
	crNode3 = GetRightSubTree(crNode2);  //9, 8�� ������
	printf("%d, %d \n", GetData(clNode3), GetData(crNode3));
	return 0;
}