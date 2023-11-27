/*
* ���� �ڷᱸ�� - ���� Ʈ�� (���� Ʈ���� ����)
* ���ϸ�: ExpressionTree.c
* ���� ����: 0.1
* �ۼ���: Sevenshards
* �ۼ� ����: 2023-11-24
* ���� ���� �ۼ� ����:
* ���� ����: ���� Ʈ�� ���� �� ��� ��� ���α׷� �ۼ�
* ���� ���� ����:
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h> // ���ڿ� ���� �Լ� ����� ���� ������� ����
#include <ctype.h> // isdigit() �Լ� ����� ���� ������� ����
#include "BinaryTree.h" // ���� Ʈ���� ���� Ʈ���� ����.
#include "ListBaseStack.h" // ������ �̿��Ͽ� ���� Ʈ���� �����ϹǷ� ������� ����

// ���� Ʈ�� ����
BTreeNode* MakeExpTree(char exp[])
{
	Stack stack; // Ʈ�� ������ ����� ���� ����
	BTreeNode* pnode; // Ʈ���� ���� ��� ����

	int expLen = strlen(exp); // �Է¹��� ������ ����
	int i; // �ݺ����� ���� ���� i

	StackInit(&stack); // ���� �ʱ�ȭ

	for (i = 0; i < expLen; i++) // ������ ��ū���� �������� ���� Ʈ�� ����
	{
		pnode = MakeBTreeNode(); // ���� Ʈ���� ������ ���ο� ��带 ����

		if (isdigit(exp[i])) // ���� �ǿ����ڶ��
			SetData(pnode, exp[i] - '0'); // ����� �����͸� ����, exp[i]�� �����̹Ƿ� ���� '0'���� ���� ���� �������̴�.
		else // �����ڶ��
		{
			MakeRightSubTree(pnode, SPop(&stack)); // ���ÿ��� ���� ���� ���(�Ǵ� ����Ʈ��)�� ������ �ڽ� ���� �����ϰ�
			MakeLeftSubTree(pnode, SPop(&stack)); // �� ���� ���ÿ��� ���� ���(�Ǵ� ����Ʈ��)�� ���� �ڽ� ���� �����Ѵ�.
			SetData(pnode, exp[i]); // �׸��� �����ڸ� ��忡 �����Ѵ�.
		}

		SPush(&stack, pnode); // ���� ������ ��ġ�� ���� ���ÿ� ����ִ´�.
	}

	return SPop(&stack); // ���������� ����Ʈ���� �ϼ��� �Ǹ� �ֻ�� ��Ʈ ����� �ּҰ��� ��ȯ�Ѵ�.
}

int EvaluateExpTree(BTreeNode* bt) // ���� Ʈ���� �̿��� ���
{
	int op1, op2; // �ǿ�����1, 2�� ����� ����

	if (GetLeftSubTree(bt) == NULL && GetRightSubTree(bt) == NULL) // �ܸ����, �� �ǿ����ڶ��
		return GetData(bt); // �ǿ����� ���� ��ȯ�Ѵ�

	op1 = EvaluateExpTree(GetLeftSubTree(bt)); // ���� ����Ʈ���� ���� ���� �ǿ����ڷ� �޴´� (���)
	op2 = EvaluateExpTree(GetRightSubTree(bt)); // ������ ����Ʈ���� ���� ���� �ǿ����ڷ� �޴´� (���)

	switch (GetData(bt)) // �������� ������ ���� ���
	{
	case '+':
		return op1 + op2;
	case '-':
		return op1 - op2;
	case '*':
		return op1 * op2;
	case '/':
		return op1 / op2;
	}

	return 0;
}

void ShowNodeData(int data)
{
	if (0 <= data && data <= 9)
		printf("%d ", data);
	else
		printf("%c ", data);
}

// ������ ���� Ʈ���� �°� �Ǿ��°� Ȯ���ϱ� ���� ���� ��º�
void ShowPrefixTypeExp(BTreeNode* bt) // ���� ǥ��� ��� ���
{
	PreorderTraversal(bt, ShowNodeData); // ���� ��ȸ, �׸��� ��ȸ�ϸ鼭 �ϴ� ������ ShowNodeData.
}

void ShowInfixTypeExp(BTreeNode* bt) // ���� ǥ��� ��� ���
{

	if (bt == NULL) // ���� ������ ���(NULL)�̶��? ����� Ż�� ������ �ȴ�.
		return;

	if (bt->left != NULL || bt->right != NULL) // �����ڸ� ������� �����̳� �����ʿ� �ǿ����ڰ� ���� ��, ��ȣ'('�� ���� 
		printf("(");

	// ��͸� �̿��ϴ� ���� �ٽ��̴�!
	ShowInfixTypeExp(bt->left); // 1) ù ��° �ǿ����� ���
	ShowNodeData(bt->data); // 2) ������ ���
	ShowInfixTypeExp(bt->right); // 3) �� ��° �ǿ����� ���

	if (bt->left != NULL || bt->right != NULL) // �����ڸ� ������� �����̳� �����ʿ� �ǿ����ڰ� ������ ��ȣ ')'�� �ݴ´�.
		printf(")");
}

void ShowPostfixTypeExp(BTreeNode* bt) // ���� ǥ��� ��� ���
{
	PostorderTraversal(bt, ShowNodeData); // ���� ��ȸ, �׸��� ��ȸ�ϸ鼭 �ϴ� ������ ShowNodeData.
}