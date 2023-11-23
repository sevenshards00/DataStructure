/*
* 선형 자료구조 - 연결 리스트 기반 Stack 계산기 구현
* 파일명: InfixToPostfixmain.c
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2023-11-23
* 이전 버전 작성 일자:
* 버전 내용: 중위 표기법을 후위 표기법으로 바꾸는 프로그램의 구현
* 이전 버전 내용:
*/

#include <stdio.h>
#include "InfixToPostfix.h"

int main()
{
	char exp1[] = "1+2*3";
	char exp2[] = "(1+2)*3";
	char exp3[] = "((1-2)+3)*(5-2)";

	ConvToRPNExp(exp1);
	ConvToRPNExp(exp2);
	ConvToRPNExp(exp3);

	printf("%s \n", exp1);
	printf("%s \n", exp2);
	printf("%s \n", exp3);

	return 0;
}