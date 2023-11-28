/*
* ���� �ڷᱸ�� - ���� ����Ʈ ��� ���� Ž�� Ʈ��
* ���ϸ�: BinarySearchTreeMain.h
* ���� ����: 0.1
* �ۼ���: Sevenshards
* �ۼ� ����: 2023-11-28
* ���� ���� �ۼ� ����:
* ���� ����: ������ ���� Ž�� Ʈ�� ����.
* ���� ���� ����:
*/

#include <stdio.h>
#include "BinarySearchTree.h"

int main()
{
	BTreeNode* bstRoot;
	BTreeNode* sNode; // search node

	BSTMakeAndInit(&bstRoot);

	BSTInsert(&bstRoot, 9);
	BSTInsert(&bstRoot, 1);
	BSTInsert(&bstRoot, 6);
	BSTInsert(&bstRoot, 2);
	BSTInsert(&bstRoot, 8);
	BSTInsert(&bstRoot, 3);
	BSTInsert(&bstRoot, 5);
	BSTInsert(&bstRoot, 1);

	sNode = BSTSearch(bstRoot, 1);
	if (sNode == NULL) // ã�� ���� ���
		printf("Search failed\n");
	else // ã���� ��
		printf("Search success. Key value: %d\n", BSTGetNodeData(sNode));

	sNode = BSTSearch(bstRoot, 4);
	if (sNode == NULL) // ã�� ���� ���
		printf("Search failed\n");
	else // ã���� ��
		printf("Search success. Key value: %d\n", BSTGetNodeData(sNode));

	sNode = BSTSearch(bstRoot, 6);
	if (sNode == NULL) // ã�� ���� ���
		printf("Search failed\n");
	else // ã���� ��
		printf("Search success. Key value: %d\n", BSTGetNodeData(sNode));

	sNode = BSTSearch(bstRoot, 7);
	if (sNode == NULL) // ã�� ���� ���
		printf("Search failed\n");
	else // ã���� ��
		printf("Search success. Key value: %d\n", BSTGetNodeData(sNode));

	return 0;
}