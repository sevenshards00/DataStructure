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
#include "ExpressionTree.h"

int main()
{
	char exp[] = "12+7*"; // ���� ǥ����� ����
	BTreeNode* eTree = MakeExpTree(exp); // ���� Ʈ�� ����

	printf("���� ǥ����� ����: ");
	ShowPrefixTypeExp(eTree); // ���� Ʈ���� �Է¹޾� ���� ǥ��� �������� ���
	printf("\n");

	printf("���� ǥ����� ����: ");
	ShowInfixTypeExp(eTree); // ���� Ʈ���� �Է¹޾� ���� ǥ������� ���
	printf("\n");

	printf("���� ǥ����� ����: ");
	ShowPostfixTypeExp(eTree); // ����
	printf("\n");

	printf("������ ���: %d\n", EvaluateExpTree(eTree));

	return 0;
}