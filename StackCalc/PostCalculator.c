/*
* 선형 자료구조 - 연결 리스트 기반 Stack 계산기 v0.3
* 파일명: PostCaculator.h
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2023-11-23
* 이전 버전 작성 일자:
* 버전 내용: 후위 표기식을 계산하는 프로그램의 구현
* 이전 버전 내용:
*/

#include <string.h>
#include <ctype.h>
#include "ListBaseStack.h"

// 후위 표기법의 수식을 계산한 결과를 반환하는 함수
int EvalRPNEXP(char exp[])
{
	Stack stack; // 마찬가지로 계산에서도 스택을 사용.
	int expLen = strlen(exp); // 입력받은 후위 표기식의 길이
	int i; // 반복문에 사용될 인자
	char tok, op1, op2; // 입력받은 후위 표기식의 토큰(tok)과 피연산자 변수를 담기 위한 op1, op2

	StackInit(&stack); // 스택의 초기화

	for (i = 0; i < expLen; i++)
	{
		tok = exp[i]; // 입력받은 후위표기식을 토큰으로 하나하나 받는다.

		if (isdigit(tok)) // 피연산자(숫자)라면
		{
			SPush(&stack, tok - '0'); // 입력받은 문자를 숫자로 바꾸기 위해 문자'0'과의 차(실제 정수값을 구하기 위해)를 구해서 stack에 저장.
		}
		else // 연산자라면
		{
			op2 = SPop(&stack); // 두 번째 피연산자를 스택에서 꺼내고
			op1 = SPop(&stack); // 첫 번째 피연산자를 스택에서 꺼낸다

			// 연산자의 종류에 따라 두 연산자에 대한 연산값을 계산하고 다시 스택에 넣는다
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

	return SPop(&stack); // 마지막으로 계산된 값(최종 값)을 return한다.

}
