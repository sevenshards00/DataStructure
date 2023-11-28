/*
* ���� �ڷᱸ�� - ���� ����Ʈ ��� ���� Ž�� Ʈ��
* ���ϸ�: BinarySearchTreeMain.h
* ���� ����: 0.2
* �ۼ���: Sevenshards
* �ۼ� ����: 2023-11-28
* ���� ���� �ۼ� ����: 2023-11-28
* ���� ����: ���� ���, Ʈ�� ��ü ��ȸ �߰��� ����
* ���� ���� ����: ������ ���� Ž�� Ʈ�� ����.
*/

#include <stdio.h>
#include <stdlib.h>
#include "BinarySearchTree.h"

int main()
{
	BTreeNode* bstRoot;
	BTreeNode* sNode; // search node

	BSTMakeAndInit(&bstRoot);

	BSTInsert(&bstRoot, 5);
	BSTInsert(&bstRoot, 8);
	BSTInsert(&bstRoot, 1);
	BSTInsert(&bstRoot, 6);
	BSTInsert(&bstRoot, 4);
	BSTInsert(&bstRoot, 9);
	BSTInsert(&bstRoot, 3);
	BSTInsert(&bstRoot, 2);
	BSTInsert(&bstRoot, 7);

	BSTShowAll(bstRoot);
	printf("\n");
	sNode = BSTRemove(&bstRoot, 3);
	free(sNode);

	BSTShowAll(bstRoot);
	printf("\n");
	sNode = BSTRemove(&bstRoot, 8);
	free(sNode);

	BSTShowAll(bstRoot);
	printf("\n");
	sNode = BSTRemove(&bstRoot, 1);
	free(sNode);

	BSTShowAll(bstRoot);
	printf("\n");
	sNode = BSTRemove(&bstRoot, 6);
	free(sNode);

	BSTShowAll(bstRoot);
	printf("\n");
	return 0;
}