/*
* ���� �ڷᱸ�� - ���� ����Ʈ ��� ���� Ʈ��
* ���ϸ�: BinaryTree.h
* ���� ����: 0.3
* �ۼ���: Sevenshards
* �ۼ� ����: 2023-11-28
* ���� ���� �ۼ� ����: 2023-11-23
* ���� ����: ����, ������ �ڽ� ��� ���� ���� �Լ� �߰� �� ����, ������ �ڽ� ��� ���� �Լ� �߰�
* ���� ���� ����: ����, ���� ��ȸ �߰� �� ��ȸ �� �� ���� ������ �� �ֵ��� �Լ� ������ ���.
*/
// ������ ǥ���� �����ڸ�, ���� Ʈ���� ����"�� �� �ִ� ����"�� ����� �����̴�.
// ���� ���� �� ���ΰ��� ���߿� ��������.
#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

typedef int BTData; // ���� Ʈ���� ������. �ڷ����� ���ǻ� int

// ���� Ʈ���� ��� ����ü. ���� ���� ����Ʈ ����.
// �׸��� �� ��ü�� Tree��.
// ���� ���� �ڷ� ���������� ����Ʈ�� ����, ť�� ���� ���� ��� ����, ����Ʈ, ����, ť�� ���� ����ü�� �����Ͽ���.
// ������ �̰� ����Ӱ� ���ÿ� Ʈ���� �ȴ�.
typedef struct _bTreeNode
{
	BTData data;
	struct _bTreeNode* left;
	struct _bTreeNode* right;
} BTreeNode;

// ����� ���� �� ������ ����� ��ȸ
BTreeNode* MakeBTreeNode(void); // ���� Ʈ���� ��� ����
BTData GetData(BTreeNode* bt); // ���� Ʈ�� ����� �����͸� ��ȯ (Getter)
void SetData(BTreeNode* bt, BTData data); // ���� Ʈ�� ��忡 �����͸� ���� (Setter)

BTreeNode* GetLeftSubTree(BTreeNode* bt); // ���� ���� Ʈ���� �ּ� ��(���� ���� Ʈ���� ��Ʈ ���)�� ��ȯ
BTreeNode* GetRightSubTree(BTreeNode* bt); // ������ ���� Ʈ���� �ּ� ��(������ ���� Ʈ���� ��Ʈ ���)�� ��ȯ


// ����� ���� �� ���� (�޸� �Ҵ� ���� ���� ����)
void MakeLeftSubTree(BTreeNode* main, BTreeNode* sub); // �Ű����� sub�� ���޵� Ʈ�� �Ǵ� ��带 �Ű����� main�� ���� ����Ʈ���� ����
void MakeRightSubTree(BTreeNode* main, BTreeNode* sub); // �Ű� ���� sub�� ���޵� Ʈ�� �Ǵ� ��带 �Ű����� main�� ������ ����Ʈ���� ����

// 11.28 �߰�
// �޸� �Ҹ��� �������� �ʰ� ����, ������ �ڽ� ��� ����
void ChangeLeftSubTree(BTreeNode* main, BTreeNode* sub); // �Ű����� sub�� ���޵� Ʈ�� �Ǵ� ��带 �Ű����� main�� ���� ����Ʈ���� ����
void ChangeRightSubTree(BTreeNode* main, BTreeNode* sub); // �Ű� ���� sub�� ���޵� Ʈ�� �Ǵ� ��带 �Ű����� main�� ������ ����Ʈ���� ����

// ��ȸ (��͸� �̿��Ͽ� �����Ѵ�!)
// �Լ� �����͸� ���� -> �� �κп� ���� ������ �� �� �ʿ��ϴ�.
typedef void VisitFuncPtr(BTData data);
// typedef void (*VisitFuncPtr)(BTData data); -> �̰Ŷ� �����ϴ�.
// ���⿡ ���ؼ� ������ �߰� �����صΰڴ�.
// typedef ������ �����ٰ� ġ�� ���� ��ȯ���� void�� �Ű������� BTData���� data�� �޴� �Լ��� �ǰ�, �Լ��� �̸��� VisitFuncPtr�� �ȴ�.
// �׷��� ���⼭ typedef ������ �߰��Ǹ�, �Լ��� �̸��� �ƴ϶� "�Լ� ������"�� ������ �ϰ� �ȴ�.
// ��ġ �迭�� ����Ŀ� ���Ǹ� �����Ͱ� �Ǵ� ��ó�� decay�ȴٴ� ����� ����ϴ�.
// �׷��� ������ VisitFuncPtr�̶�� �̸��� �ڷ���ó�� �� �� �ִ� ���̴�.

// ���� ��ȸ 1)���� ���� Ʈ�� -> 2)��Ʈ ��� -> 3)������ ���� Ʈ��
void InorderTraversal(BTreeNode* bt, VisitFuncPtr action);
// ���� ��ȸ 1)��Ʈ ��� -> 2)���� ���� Ʈ�� -> 3)������ ���� Ʈ��
void PreorderTraversal(BTreeNode* bt, VisitFuncPtr action);
// ���� ��ȸ 1)���� ���� Ʈ�� -> 2)������ ����Ʈ�� -> 3)��Ʈ ���
void PostorderTraversal(BTreeNode* bt, VisitFuncPtr action);

// Ʈ���� ��� ��� ����
void DeleteTree(BTreeNode* bt);

// 11.28 �߰�
// ��� ���� �κ�
BTreeNode* RemoveLeftSubTree(BTreeNode* bt); // ���� �ڽ� ��带 Ʈ������ ����, ���ŵ� ����� �ּҰ� ��ȯ
BTreeNode* RemoveRightSubTree(BTreeNode* bt); // ������ �ڽ� ��带 Ʈ������ ����, ���ŵ� ����� �ּҰ� ��ȯ

#endif