/*
* 비선형 자료구조 - 수식 트리 (이진 트리의 응용)
* 파일명: ExpressionTree.c
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2023-11-24
* 이전 버전 작성 일자:
* 버전 내용: 수식 트리 구현 및 계산 결과 프로그램 작성
* 이전 버전 내용:
*/

#include <stdio.h>
#include "ExpressionTree.h"

int main()
{
	char exp[] = "12+7*"; // 후위 표기법의 수식
	BTreeNode* eTree = MakeExpTree(exp); // 수식 트리 생성

	printf("전위 표기법의 수식: ");
	ShowPrefixTypeExp(eTree); // 수식 트리를 입력받아 전위 표기법 수식으로 출력
	printf("\n");

	printf("중위 표기법의 수식: ");
	ShowInfixTypeExp(eTree); // 수식 트리를 입력받아 중위 표기법으로 출력
	printf("\n");

	printf("후위 표기법의 수식: ");
	ShowPostfixTypeExp(eTree); // 수식
	printf("\n");

	printf("연산의 결과: %d\n", EvaluateExpTree(eTree));

	return 0;
}