/*
* ���� �ڷᱸ�� - ���� ����Ʈ ��� Stack ���� v0.2
* ���ϸ�: PostCalculatorMain.c
* ���� ����: 0.1
* �ۼ���: Sevenshards
* �ۼ� ����: 2023-11-23
* ���� ���� �ۼ� ����:
* ���� ����: ���� ǥ����� ����ϴ� ���α׷��� ����
* ���� ���� ����:
*/

#include <stdio.h>
#include "InfixToPostfix.h"
#include "PostCalculator.h"

int main()
{
	char exp1[] = "42*8+";
	char exp2[] = "123+*4/";

	printf("%s = %d\n", exp1, EvalRPNEXP(exp1));
	printf("%s = %d\n", exp2, EvalRPNEXP(exp2));

	return 0;
}