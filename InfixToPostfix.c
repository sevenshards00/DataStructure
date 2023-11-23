/*
* ���� �ڷᱸ�� - ���� ����Ʈ ��� Stack ���� ����
* ���ϸ�: InfixToPostfix.h
* ���� ����: 0.1
* �ۼ���: Sevenshards
* �ۼ� ����: 2023-11-23
* ���� ���� �ۼ� ����:
* ���� ����: ���� ǥ����� ���� ǥ������� �ٲٴ� ���α׷��� ����
* ���� ���� ����:
*/

#define _CRT_SECURE_NO_WARNINGS

#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "ListBaseStack.h"

// ������ �켱 ������ �ο�
int GetOpPrec(char op)
{
	switch (op)
	{
	// ������ �������� �켱 ������ ���� ����
	case '*':
	case '/':
		return 5;
	// ������ ������ �� �������� �켱 ������ ����
	case '+':
	case '-':
		return 3;
	// ���� �Ұ�ȣ�� �켱 ������ ���� ����.
	// �ݴ� ��ȣ�� ������ �켱������ �Ű澵 �ʿ䰡 ����.
	// ������ ���� ���ÿ� �׾Ƴ��� ���� �� pop ó���ϹǷ�
	case '(':
		return 1;
	}

	return -1; // �����ڰ� �ƴ� �ٸ� ���� ���� ��쿡�� ���� ó���� ���� -1 ��ȯ
}

// ���ÿ� ���� �������� �켱 ���� ��
int WhoPrecOp(char op1, char op2)
{
	int op1Prec = GetOpPrec(op1);
	int op2Prec = GetOpPrec(op2);

	if (op1Prec > op2Prec)
		return 1;
	else if (op1Prec < op2Prec)
		return -1;
	else
		return 0;
}

// ���� -> ���� ǥ������� ��ȯ�ϴ� �Լ�
void ConvToRPNExp(char exp[]) // RPN -> Reverse Polish Notation, ���� ǥ��� ����
{
	Stack stack; // �����ڸ� ���� ����
	int expLen = strlen(exp); // �Է¹��� ������ ����
	char* convExp = (char*)malloc((sizeof(char) * expLen) + 1); // ���� ǥ����� ��� �迭 ���� �Ҵ�

	int i, idx = 0; // ���� �迭�� ���� �ε��� i�� ���� ǥ����� �ε��� idx
	char tok, popOp; // �Է¹��� ������ ��ū(tok)�� ���ÿ��� pop�� �����ڸ� ���� ����(popOp)

	memset(convExp, 0, (sizeof(char) * expLen + 1)); // �����Ҵ��� �迭�� �޸� ������ 0���� �ʱ�ȭ
	StackInit(&stack); // stack �ʱ�ȭ

	// �Է� ���� ������ ��ū���� ������ �ݺ� ����
	for (i = 0; i < expLen; i++)
	{
		tok = exp[i];
		if (isdigit(tok)) // �Էµ� ��ū�� ����(�ǿ�����)���
		{
			convExp[idx++] = tok; // ��ȯ�� ���Ŀ� ����
		}
		else // �����ڶ�� ���ÿ� ��� ���� ����
		{
			switch (tok)
			{
			case '(': // '('�� ��� ������ ���ÿ� ����
				SPush(&stack, tok);
				break;
			case ')': // ')'�� ���, '('�� ���������� ���ÿ� ����ִ� �����ڸ� ��� pop�Ѵ�.
				while (1)
				{
					popOp = SPop(&stack);
					if (popOp == '(') // ���������� pop�� �����ڰ� '('��� pop�� �ߴ�
						break;
					convExp[idx++] = popOp; // ���� ǥ��Ŀ� �����ڸ� ����
				}
				break;
			// ������ '+', '-', '*', '/' �� ���� ó��
			case '+':
			case '-':
			case '*':
			case '/':
				// �� ���� ���� ���ÿ� �����ϴ� ��Ȳ ���� �ݺ����� ����.
				// 1. ������ ������� ����
				// 2. ���� ������ ���� ���� �ִ� �����ڿ� ���� �����ڸ� ���ؼ� 0���� ũ�ų� ����
				// 2�� ���, ���ÿ� ��� �ִ� �������� �켱������ ���ų� �� ���� ��쿡 Pop�� �����Ѵ�.
				while (!SisEmpty(&stack) && WhoPrecOp(SPeek(&stack), tok) >= 0)
					convExp[idx++] = SPop(&stack);

				// �׸��� �����ڸ� ���ÿ� ����
				SPush(&stack, tok);
				break;
			}	
		}
	}

	// ���� ������ �� ������ ���������� ���ÿ� ���� �����ڸ� ���� Pop�Ѵ�.
	while (!SisEmpty(&stack))
		convExp[idx++] = SPop(&stack);

	strcpy(exp, convExp); // ��ȯ�� ���� ǥ����� exp�� �����ϰ�
	free(convExp); // �Ҵ��� �޸𸮸� �����Ѵ�.
}