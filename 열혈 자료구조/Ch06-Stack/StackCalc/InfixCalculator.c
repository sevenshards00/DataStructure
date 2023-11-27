/*
* ���� �ڷᱸ�� - ���� ����Ʈ ��� Stack ���� v0.3
* ���ϸ�: InfixCalculator.c
* ���� ����: 0.1
* �ۼ���: Sevenshards
* �ۼ� ����: 2023-11-23
* ���� ���� �ۼ� ����:
* ���� ����: ���� ǥ��� ���� -> ���� ǥ��� ���� ��ȯ -> ���� ǥ��� ���� ��� -> ��� ��� ���α׷� ����
* ���� ���� ����:
*/

#define _CRT_SECURE_NO_WARNINGS

#include <string.h>
#include <stdlib.h>
#include "InfixToPostfix.h" // ���� ǥ��� ��ȯ�� ���
#include "PostCalculator.h" // ���� ǥ��� ��꿡 ���
#include "InfixCalculator.h"

// ���� ǥ��� ���� -> ���� ǥ��� ���� ��ȯ -> ���� ǥ��� ���� ��� -> ��� ��� ��ȯ
// �� ���� �ϳ��� ��� �Լ�
int EvalInfixExp(char exp[])
{
	int len = strlen(exp); // �Է� ���� ������ ����
	int ret; // ��� ����� ���� ����
	char* expcpy = (char*)malloc((sizeof(char) * len) + 1); // �Է� ���� ������ �����ϱ� ���� �迭 �����Ҵ�
	strcpy(expcpy, exp);

	ConvToRPNExp(expcpy); // ���� ǥ������� ��ȯ
	ret = EvalRPNEXP(expcpy); // ��ȯ�� ���� ǥ����� ����Ͽ� ��� ����� ����

	free(expcpy); // ���� �Ҵ� �ߴ� �޸𸮸� �����ϰ�
	return ret; // ����� ��ȯ
}
