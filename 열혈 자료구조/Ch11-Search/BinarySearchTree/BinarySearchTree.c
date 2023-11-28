/*
* ���� �ڷᱸ�� - ���� ����Ʈ ��� ���� Ž�� Ʈ��
* ���ϸ�: BinarySearchTree.c
* ���� ����: 0.2
* �ۼ���: Sevenshards
* �ۼ� ����: 2023-11-28
* ���� ���� �ۼ� ����: 2023-11-28
* ���� ����: ���� ���, Ʈ�� ��ü ��ȸ �߰��� ����
* ���� ���� ����: ������ ���� Ž�� Ʈ�� ����.
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

// Ʈ������ ��带 �����ϰ� ���ŵ� ����� �ּҰ��� ��ȯ
BTreeNode* BSTRemove(BTreeNode** pRoot, BSTData target)
{
	// ���� ����� ��Ʈ ����� ��쵵 ����Ͽ� ����
	BTreeNode* pVRoot = MakeBTreeNode(); // ���� ��Ʈ ��� (Virtual Root Node)
	BTreeNode* pNode = pVRoot; // �θ� ���, �ʱ�ȭ �ϸ鼭 ������ ��Ʈ ��带 ����Ų��
	BTreeNode* cNode = *pRoot; // ���� ���, �ʱ�ȭ �ϸ鼭 ��Ʈ ��带 ����Ų��
	BTreeNode* dNode = NULL; // ������ ����� ���, �Ϻ� �����Ϸ������� �ʱ�ȭ���� ������ ������ ���Ƿ� NULL�� �ʱ�ȭ

	// ��Ʈ ��带 pVRoot�� ����Ű�� �ִ� ����� ������ �ڽ� ��尡 �ǰ� �Ѵ�.
	ChangeRightSubTree(pVRoot, *pRoot);

	// ���� ����� �� ��带 Ž��
	while (cNode != NULL && GetData(cNode) != target)
	{
		pNode = cNode; // ���� ��� ��ġ�� ���� ��ġ�� ����� �θ� ���� ����

		if (target < GetData(cNode)) // ������ �����Ͱ� ���� ����� �����ͺ��� �۴ٸ�
			cNode = GetLeftSubTree(cNode); // �������� �̵�
		else // ������ �����Ͱ� ���� ����� �����ͺ��� ũ�ٸ�
			cNode = GetRightSubTree(cNode); // ���������� �̵�
	}

	if (cNode == NULL) // ���� ����� ���ٸ�
		return NULL; // NULL�� return

	dNode = cNode; // ���� ����� dNode�� ����Ű�� ��

	// 1�� ���̽�: ���� ����� �ܸ� �����
	if (GetLeftSubTree(dNode) == NULL && GetRightSubTree(dNode) == NULL) // ���ʿ� �ڽ� ��尡 �� �� �����Ƿ�
	{
		if (GetLeftSubTree(pNode) == dNode) // ���� ������ ����� �θ� ����� ���� �����
			RemoveLeftSubTree(pNode); // �θ� ����� ���� ��带 ����
		else // ������ �����
			RemoveRightSubTree(pNode); // �θ� ����� ������ ��带 ����
	}

	// 2�� ���̽�: ���� ����� �ڽ� ��带 �ϳ� ���� ���
	else if (GetLeftSubTree(dNode) == NULL || GetRightSubTree(dNode) == NULL) // ������ ����� ���� �Ǵ� �����ʿ� �ڽ� ��尡 �ִٸ�
	{
		BTreeNode* dcNode; // ���� ����� �ڽ�(child) ��带 ����Ű�� ���� ����� BTreeNode* ����

		if (GetLeftSubTree(dNode) != NULL) // ������ ����� ���ʿ� �ڽ� ��尡 �ִٸ�
			dcNode = GetLeftSubTree(dNode); // dcNode�� ������ ����� ���� �ڽ��� ����Ű�� �Ѵ�.
		else // ������ ����� �����ʿ� �ڽ� ��尡 �ִٸ�
			dcNode = GetRightSubTree(dNode); //dcNode�� ������ ����� ������ �ڽ��� ����Ű�� �Ѵ�.

		if (GetLeftSubTree(pNode) == dNode) // ���� ������ ����� �θ� ����� ���� �����
			ChangeLeftSubTree(pNode, dcNode); // �θ� ����� ������ ������ ����� �ڽ� ���� �ٲ۴�.
		else // ������ �����
			ChangeRightSubTree(pNode, dcNode); // �θ� ����� �������� ������ ����� �ڽ� ���� �ٲ۴�.
	}

	// 3�� ���̽�: ���� ����� ���� �� �ڽ� ��带 ���� ���
	// �� ��쿡�� ������ ����� ������ ���� Ʈ������ ���� ���� ���� ���ϴ� ��带 ã�´�.
	// �׸��� ���� ���� ���� ���ϴ� ��带 ������ ��带 ��ü�Ѵ�.
	else
	{
		BTreeNode* mNode = GetRightSubTree(dNode); // ��ü�� ��带 ����Ų��. ������ ����Ʈ������ ���� ���� ���� ã�ƾ� �ϴ� ������ �ڽ� ��� ������ �ʱ�ȭ
		BTreeNode* mpNode = dNode; // ��ü�� ����� �θ� ���. ������ ��带 ����Ű�� ������ �ʱ�ȭ
		int delData; // ������ ����� �����͸� �ޱ� ���� ����

		// ���� ��带 ��ü�� ��带 ã�´�.
		while (GetLeftSubTree(mNode) != NULL) // ���� ���� ���� ã�� ���̹Ƿ� ��� ���� ����Ʈ���� ã���� ��. NULL�� ������ �� �̻� ���� ��.
		{
			mpNode = mNode; // ��ü�� ����� �θ� ��� ����
			mNode = GetLeftSubTree(mNode); // ��ü�� ��带 ã�� ���� ���� �ڽ� ���� ����
		}

		// ��ü�� ��带 ã�� ��
		// ��ü ��忡 ����� ���� ������ ��忡 ����
		delData = GetData(dNode); // ������ ��忡 �ִ� ���� �޴´�.
		SetData(dNode, GetData(mNode)); // ������ ��忡 �ִ� ���� ��ü�� ����� ������ ����

		// ��ü ����� �θ� ���� �ڽ� ��带 �����Ѵ�.
		if (GetLeftSubTree(mpNode) == mNode) // ��ü�� ����� �θ� ����� ���� �ڽ� ��尡 ��ü�� �����
			ChangeLeftSubTree(mpNode, GetRightSubTree(mNode)); // ���� �ڽ� ���� ����
		else // ��ü�� ����� �θ� ����� ������ �ڽ� ��尡 ��ü�� �����
			ChangeRightSubTree(mpNode, GetRightSubTree(mNode)); // ������ �ڽ� ���� ����

		dNode = mNode; // ������ ��带 ��ü�� ���� ����
		SetData(dNode, delData); // ������ ��尡 ������ �ִ� �����͸� �ٽ� �Է�
	}

	// ������ ��尡 ��Ʈ ����� ��쿡 ���� �߰� ó��
	if (GetRightSubTree(pVRoot) != *pRoot) // ���� ��Ʈ ����� ������ �ڽ� ��尡 ��Ʈ��尡 �ƴ϶��
		*pRoot = GetRightSubTree(pVRoot); // ��Ʈ ��尡 �ٲ� ���̹Ƿ� ���� ��Ʈ ����� ������ �ڽ��� ��Ʈ���� ����

	free(pVRoot); // ���� ��Ʈ ����� �Ҹ�
	return dNode; // ���� ����� �ּҰ� ��ȯ
}

// int�� �������� ����� ���� �Լ�
void ShowIntData(int data)
{
	printf("%d ", data);
}

// ���� Ž�� Ʈ���� ����� ��� ����� ������ ���
void BSTShowAll(BTreeNode* bst)
{
	InorderTraversal(bst, ShowIntData);
}