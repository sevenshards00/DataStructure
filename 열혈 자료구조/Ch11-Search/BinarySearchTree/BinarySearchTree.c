/*
* ���� �ڷᱸ�� - ���� ����Ʈ ��� ���� Ž�� Ʈ��
* ���ϸ�: BinarySearchTree.c
* ���� ����: 0.1
* �ۼ���: Sevenshards
* �ۼ� ����: 2023-11-28
* ���� ���� �ۼ� ����:
* ���� ����: ������ ���� Ž�� Ʈ�� ����.
* ���� ���� ����:
*/
#include <stdlib.h>
#include "BinarySearchTree.h"

// ���� Ž�� Ʈ���� ���� �� �ʱ�ȭ
void BSTMakeAndInit(BTreeNode** pRoot)
{
	*pRoot = NULL;
}

// ��忡 ����� ������ ��ȯ
BSTData BSTGetNodeData(BTreeNode* bst)
{
	return bst->data;
}

// ���� Ž�� Ʈ���� ������� ������ ���� (��� ���� ����)
void BSTInsert(BTreeNode** pRoot, BSTData data)
{
	BTreeNode* pNode = NULL; // ���� ��� ������ �θ� ���
	BTreeNode* cNode = *pRoot; // ���� ���, ��Ʈ ��忡������ �����ϹǷ� ��Ʈ ����� �ּҰ����� �ʱ�ȭ
	BTreeNode* newNode = NULL; // ���� ������ ���

	// ���� ������ ���(�� �����Ͱ� ��� ���)�� �߰��� ��ġ�� ã��
	while (cNode != NULL) // ���� ��尡 NULL�� �ƴ� ������, �ٽ� ���ؼ� ���ο� ��尡 �߰��� ��ġ�� ã�� ������
	{
		if (data == GetData(cNode)) // ���� ����� �����Ͱ� �Էµ� �����Ϳ� ���ٸ�
			return; // ������(Ű)�� �ߺ��� ������� �����Ƿ� return

		// ������ �ߺ� �˻簡 ���� ��
		pNode = cNode; // ���� ��� ��ġ�� ���� ��ġ�� ����� �θ� ���� ����

		if (data < GetData(cNode)) // �߰��� �����Ͱ� ���� ����� �����ͺ��� �۴ٸ�
			cNode = GetLeftSubTree(cNode); // �������� �̵�
		else // �߰��� �����Ͱ� ���� ����� �����ͺ��� ũ�ٸ�
			cNode = GetRightSubTree(cNode); // ���������� �̵�
	}

	// ��ġ�� ã�� ��, �ش� ��ġ�� ���ο� ��� �����ϰ� �߰�
	newNode = MakeBTreeNode(); // ���ο� ��带 ����
	SetData(newNode, data); // ���ο� ��忡 ������ ����

	// ���� ������ ��ġ(cNode)�� �θ���(pNode)�� �ڽ� ���� �߰�
	if (pNode != NULL) // ���� ������ ��尡 ��Ʈ ���(��Ʈ ���� �θ� ��尡 �����Ƿ�)�� �ƴ϶��
	{
		if (data < GetData(pNode)) // �θ� ��尡 ���� �����ͺ��� ���ο� ����� �����Ͱ� �۴ٸ�
			MakeLeftSubTree(pNode, newNode); // �������� �� ��带 ����
		else // �θ� ��尡 ���� �����ͺ��� ���ο� ����� �����Ͱ� ũ�ٸ�
			MakeRightSubTree(pNode, newNode); // ���������� �� ��带 ����
	}
	else // ���� ���� �����Ǵ� ��尡 ��Ʈ �����
		*pRoot = newNode; // ���ο� ��尡 ��Ʈ ��尡 �ȴ�.
}

// ���� Ž�� Ʈ���� ������� ������ Ž��
BTreeNode* BSTSearch(BTreeNode* bst, BSTData target)
{
	BTreeNode* cNode = bst; // ���� ����Ű�� ���, Ʈ���� �ּҰ�(��Ʈ ����� �ּҰ�)���� �����Ѵ�.
	BSTData cData; // ���� ����Ű�� ����� ������ ��

	// ���� ����Ű�� ��尡 NULL�� �ƴҶ�����
	while (cNode != NULL)
	{
		cData = GetData(cNode);

		if (target == cData) // ����� ã�Ҵٸ�
			return cNode; // ���� ����Ű�� ����� �ּҰ� ��ȯ
		else if (target < cData) // ã�� ���� ���� ����� �����ͺ��� �۴ٸ�
			cNode = GetLeftSubTree(cNode); // �������� �̵�
		else // ã�� ���� ���� ����� �����ͺ��� ũ�ٸ�
			cNode = GetRightSubTree(cNode);
	}

	return NULL; // Ž�� ����� �ƿ� ���� ���, NULL�� ��ȯ
}