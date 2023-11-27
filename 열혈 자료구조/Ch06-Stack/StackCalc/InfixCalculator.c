/*
* 선형 자료구조 - 연결 리스트 기반 Stack 계산기 v0.3
* 파일명: InfixCalculator.c
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2023-11-23
* 이전 버전 작성 일자:
* 버전 내용: 중위 표기법 수식 -> 후위 표기법 수식 변환 -> 후위 표기법 수식 계산 -> 계산 결과 프로그램 통합
* 이전 버전 내용:
*/

#define _CRT_SECURE_NO_WARNINGS

#include <string.h>
#include <stdlib.h>
#include "InfixToPostfix.h" // 후위 표기식 변환에 사용
#include "PostCalculator.h" // 후위 표기식 계산에 사용
#include "InfixCalculator.h"

// 중위 표기법 수식 -> 후위 표기법 수식 변환 -> 후위 표기법 수식 계산 -> 계산 결과 반환
// 이 모든걸 하나에 담는 함수
int EvalInfixExp(char exp[])
{
	int len = strlen(exp); // 입력 받은 수식의 길이
	int ret; // 계산 결과를 받을 변수
	char* expcpy = (char*)malloc((sizeof(char) * len) + 1); // 입력 받은 수식을 복사하기 위한 배열 동적할당
	strcpy(expcpy, exp);

	ConvToRPNExp(expcpy); // 후위 표기식으로 변환
	ret = EvalRPNEXP(expcpy); // 변환된 후위 표기식을 계산하여 계산 결과를 저장

	free(expcpy); // 동적 할당 했던 메모리를 해제하고
	return ret; // 결과를 반환
}
