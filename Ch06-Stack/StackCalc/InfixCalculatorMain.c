/*
* 선형 자료구조 - 연결 리스트 기반 Stack 계산기 v0.3
* 파일명: InfixCaculatorMain.c
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2023-11-23
* 이전 버전 작성 일자:
* 버전 내용: 중위 표기법 수식 -> 후위 표기법 수식 변환 -> 후위 표기법 수식 계산 -> 계산 결과 프로그램 통합
* 이전 버전 내용:
*/

#include <stdio.h>
#include "InfixCalculator.h"

int main()
{
	char exp1[] = "1+2*3";
	char exp2[] = "(1+2)*3";
	char exp3[] = "((1-2)+3)*(5-2)";

	printf("%s = %d\n", exp1, EvalInfixExp(exp1));
	printf("%s = %d\n", exp2, EvalInfixExp(exp2));
	printf("%s = %d\n", exp3, EvalInfixExp(exp3));

	return 0;
}