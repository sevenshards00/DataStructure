/*
* ���� �ڷᱸ�� - AVL Ʈ�� (���� Ž�� Ʈ�� Ȯ��)
* ���ϸ�: AVLRebalance.c
* ���� ����: 0.1
* �ۼ���: Sevenshards
* �ۼ� ����: 2023-11-29
* ���� ���� �ۼ� ����:
* ���� ����: ������ ��� ���� Ž�� Ʈ���� AVL Ʈ�� Ȯ�� ����
* ���� ���� ����: 
*/

#include <stdio.h>
#include "BinaryTree.h"

// LL ȸ��
BTreeNode* RotateLL(BTreeNode* bst)
{
	BTreeNode* pNode; // �θ�(parent) ���
	BTreeNode* cNode; // �ڽ�(chile) ���

	// pNode�� cNode�� ���� LLȸ���� ���� ��ġ�� ����Ű�� ��
	pNode = bst;
	cNode = GetLeftSubTree(pNode);

	// ���� LL ȸ���� ����Ǵ� �κ�
	ChangeLeftSubTree(pNode, GetRightSubTree(cNode));
	ChangeRightSubTree(cNode, pNode);

	// LLȸ���� ���� ����� ��Ʈ ����� �ּ� �� ��ȯ
	return cNode;
}
// RR ȸ��
BTreeNode* RotateRR(BTreeNode* bst)
{
	BTreeNode* pNode; // �θ�(parent) ���
	BTreeNode* cNode; // �ڽ�(chile) ���

	// pNode�� cNode�� ���� RRȸ���� ���� ��ġ�� ����Ű�� ��
	pNode = bst;
	cNode = GetRightSubTree(pNode);

	// ���� RR ȸ���� ����Ǵ� �κ�
	ChangeRightSubTree(pNode, GetLeftSubTree(cNode));
	ChangeLeftSubTree(cNode, pNode);

	// RRȸ���� ���� ����� ��Ʈ ����� �ּ� �� ��ȯ
	return cNode;
}

// LR ȸ�� -> 1) �κ��� RRȸ�� 2) LLȸ��
BTreeNode* RotateLR(BTreeNode* bst)
{
	BTreeNode* pNode; // �θ�(parent) ���
	BTreeNode* cNode; // �ڽ�(child) ���

	// pNode�� cNode�� ���� LRȸ���� ���� ��ġ�� ����Ű�� ��
	pNode = bst;
	cNode = GetLeftSubTree(pNode);

	// ���� LR ȸ���� ����Ǵ� �κ�
	ChangeLeftSubTree(pNode, RotateRR(cNode)); // 1) �κ��� RRȸ��
	return RotateLL(pNode); // 2) LLȸ��
}
// RL ȸ�� -> 1) �κ��� LLȸ�� 2) RRȸ��
BTreeNode* RotateRL(BTreeNode* bst)
{
	BTreeNode* pNode; // �θ�(parent) ���
	BTreeNode* cNode; // �ڽ�(child) ���

	// pNode�� cNode�� ���� LRȸ���� ���� ��ġ�� ����Ű�� ��
	pNode = bst;
	cNode = GetRightSubTree(pNode);

	// ���� LR ȸ���� ����Ǵ� �κ�
	ChangeRightSubTree(pNode, RotateLL(cNode)); // 1) �κ��� LLȸ��
	return RotateRR(pNode); // 2) RRȸ��
}

// Ʈ���� ����(height)�� ���
int GetHeight(BTreeNode* bst)
{
	int left_h; // ������ ����
	int right_h; // �������� ����

	// ����� Ż�� ����
	if (bst == NULL) // �ܸ� �����
		return 0; // 0�� ��ȯ

	// ����� ������ �̿��Ͽ� ���̸� ���
	left_h = GetHeight(GetLeftSubTree(bst));
	right_h = GetHeight(GetRightSubTree(bst));

	// ū ���� ���̸� ��ȯ
	// ������� �����̹Ƿ� ��ȯ�ϸ鼭 1�� ����
	if (left_h > right_h)
		return left_h + 1;
	else
		return right_h + 1;
}

// �� ���� Ʈ���� ������ ���̸� ���
int GetHeightDiff(BTreeNode* bst)
{
	int lsh; // left sub tree height
	int rsh; // right sub tree height

	if (bst == NULL) // Ʈ���� ��尡 ���ٸ�
		return 0; // 0�� ��ȯ

	lsh = GetHeight(GetLeftSubTree(bst));
	rsh = GetHeight(GetRightSubTree(bst));

	return lsh - rsh; // ���� �μ� ��� ��� ��ȯ

}

// Ʈ���� ������ ��� �Լ�
BTreeNode* Rebalance(BTreeNode** pRoot)
{
	int hDiff = GetHeightDiff(*pRoot); // ���� �μ� ��� ���

	// ���� �μ��� +2 �̻��̶�� LL �Ǵ� LR ����
	if (hDiff > 1) // ���� ���� Ʈ�� �������� ���̰� 2�̻� ���̰� ���ٸ�
	{
		// ���� ���� Ʈ���� ���� �μ��� Ȯ���Ѵ�
		if (GetHeightDiff(GetLeftSubTree(*pRoot)) > 0)
			*pRoot = RotateLL(*pRoot); // +1 �̻��̶�� LL ����
		else
			*pRoot = RotateLR(*pRoot); // -1 ���϶�� LR ����
	}

	// ���� �μ��� -2 ���϶�� RR �Ǵ� RL ����
	if (hDiff < -1) // ������ ���� Ʈ�� �������� ���̰� 2�̻� ���̰� ���ٸ�
	{
		// ������ ���� Ʈ���� ���� �μ��� Ȯ���Ѵ�
		if (GetHeightDiff(GetRightSubTree(*pRoot)) < 0)
			*pRoot = RotateRR(*pRoot); // -1 ���϶�� RR ����
		else
			*pRoot = RotateRL(*pRoot); // +1 �̻��̶�� RL ����
	}

	return *pRoot;
}