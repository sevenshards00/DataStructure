/*
* 선형 자료구조 - 연결 리스트 기반 Stack 계산기 v0.2
* 파일명: PostCalculatorMain.c
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2023-11-23
* 이전 버전 작성 일자:
* 버전 내용: 후위 표기식을 계산하는 프로그램의 구현
* 이전 버전 내용:
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