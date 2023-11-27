/*
* ���� �ڷᱸ�� - ���� ����Ʈ ��� Stack ���� v0.3
* ���ϸ�: PostCaculator.h
* ���� ����: 0.1
* �ۼ���: Sevenshards
* �ۼ� ����: 2023-11-23
* ���� ���� �ۼ� ����:
* ���� ����: ���� ǥ����� ����ϴ� ���α׷��� ����
* ���� ���� ����:
*/

#include <string.h>
#include <ctype.h>
#include "ListBaseStack.h"

// ���� ǥ����� ������ ����� ����� ��ȯ�ϴ� �Լ�
int EvalRPNEXP(char exp[])
{
	Stack stack; // ���������� ��꿡���� ������ ���.
	int expLen = strlen(exp); // �Է¹��� ���� ǥ����� ����
	int i; // �ݺ����� ���� ����
	char tok, op1, op2; // �Է¹��� ���� ǥ����� ��ū(tok)�� �ǿ����� ������ ��� ���� op1, op2

	StackInit(&stack); // ������ �ʱ�ȭ

	for (i = 0; i < expLen; i++)
	{
		tok = exp[i]; // �Է¹��� ����ǥ����� ��ū���� �ϳ��ϳ� �޴´�.

		if (isdigit(tok)) // �ǿ�����(����)���
		{
			SPush(&stack, tok - '0'); // �Է¹��� ���ڸ� ���ڷ� �ٲٱ� ���� ����'0'���� ��(���� �������� ���ϱ� ����)�� ���ؼ� stack�� ����.
		}
		else // �����ڶ��
		{
			op2 = SPop(&stack); // �� ��° �ǿ����ڸ� ���ÿ��� ������
			op1 = SPop(&stack); // ù ��° �ǿ����ڸ� ���ÿ��� ������

			// �������� ������ ���� �� �����ڿ� ���� ���갪�� ����ϰ� �ٽ� ���ÿ� �ִ´�
			switch (tok)
			{
			case '+':
				SPush(&stack, op1 + op2);
				break;
			case '-':
				SPush(&stack, op1 - op2);
				break;
			case '*':
				SPush(&stack, op1 * op2);
				break;
			case '/':
				SPush(&stack, op1 / op2);
				break;
			}
		}
	}

	return SPop(&stack); // ���������� ���� ��(���� ��)�� return�Ѵ�.

}
