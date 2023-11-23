/*
* 선형 자료구조 - 연결 리스트 기반 Stack 계산기 구현
* 파일명: InfixToPostfix.h
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2023-11-23
* 이전 버전 작성 일자:
* 버전 내용: 중위 표기법을 후위 표기법으로 바꾸는 프로그램의 구현
* 이전 버전 내용:
*/

#define _CRT_SECURE_NO_WARNINGS

#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "ListBaseStack.h"

// 연산자 우선 순위를 부여
int GetOpPrec(char op)
{
	switch (op)
	{
	// 곱셈과 나눗셈이 우선 순위가 가장 높고
	case '*':
	case '/':
		return 5;
	// 덧셈과 뺄셈이 그 다음으로 우선 순위가 높고
	case '+':
	case '-':
		return 3;
	// 여는 소괄호의 우선 순위가 가장 낮다.
	// 닫는 괄호는 연산자 우선순위를 신경쓸 필요가 없다.
	// 만나는 순간 스택에 쌓아놨던 것을 다 pop 처리하므로
	case '(':
		return 1;
	}

	return -1; // 연산자가 아닌 다른 것이 들어올 경우에는 에러 처리를 위해 -1 반환
}

// 스택에 들어가는 연산자의 우선 순위 비교
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

// 중위 -> 후위 표기법으로 변환하는 함수
void ConvToRPNExp(char exp[]) // RPN -> Reverse Polish Notation, 후위 표기법 영문
{
	Stack stack; // 연산자를 담을 스택
	int expLen = strlen(exp); // 입력받은 수식의 길이
	char* convExp = (char*)malloc((sizeof(char) * expLen) + 1); // 후위 표기식이 담길 배열 동적 할당

	int i, idx = 0; // 수식 배열에 쓰일 인덱스 i와 후위 표기식의 인덱스 idx
	char tok, popOp; // 입력받은 수식의 토큰(tok)과 스택에서 pop된 연산자를 담을 변수(popOp)

	memset(convExp, 0, (sizeof(char) * expLen + 1)); // 동적할당한 배열의 메모리 공간을 0으로 초기화
	StackInit(&stack); // stack 초기화

	// 입력 받은 수식을 토큰으로 나눠서 반복 수행
	for (i = 0; i < expLen; i++)
	{
		tok = exp[i];
		if (isdigit(tok)) // 입력된 토큰이 숫자(피연산자)라면
		{
			convExp[idx++] = tok; // 변환된 수식에 저장
		}
		else // 연산자라면 스택에 담는 과정 수행
		{
			switch (tok)
			{
			case '(': // '('일 경우 무조건 스택에 들어간다
				SPush(&stack, tok);
				break;
			case ')': // ')'일 경우, '('을 만날때까지 스택에 담겨있던 연산자를 모두 pop한다.
				while (1)
				{
					popOp = SPop(&stack);
					if (popOp == '(') // 마지막으로 pop된 연산자가 '('라면 pop을 중단
						break;
					convExp[idx++] = popOp; // 후위 표기식에 연산자를 저장
				}
				break;
			// 나머지 '+', '-', '*', '/' 에 대한 처리
			case '+':
			case '-':
			case '*':
			case '/':
				// 두 개의 조건 동시에 만족하는 상황 동안 반복문을 수행.
				// 1. 스택이 비어있지 않음
				// 2. 현재 스택의 가장 위에 있는 연산자와 현재 연산자를 비교해서 0보다 크거나 같다
				// 2의 경우, 스택에 담겨 있는 연산자의 우선순위가 같거나 더 높은 경우에 Pop을 수행한다.
				while (!SisEmpty(&stack) && WhoPrecOp(SPeek(&stack), tok) >= 0)
					convExp[idx++] = SPop(&stack);

				// 그리고 연산자를 스택에 저장
				SPush(&stack, tok);
				break;
			}	
		}
	}

	// 위의 과정이 다 끝나면 마지막으로 스택에 남은 연산자를 전부 Pop한다.
	while (!SisEmpty(&stack))
		convExp[idx++] = SPop(&stack);

	strcpy(exp, convExp); // 변환된 후위 표기식을 exp에 복사하고
	free(convExp); // 할당한 메모리를 해제한다.
}