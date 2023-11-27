/*
* 선형 자료구조 - 연결 리스트 기반 Stack 계산기 v0.3
* 파일명: InfixCaculator.h
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2023-11-23
* 이전 버전 작성 일자:
* 버전 내용: 중위 표기법 수식 -> 후위 표기법 수식 변환 -> 후위 표기법 수식 계산 -> 계산 결과 프로그램 통합
* 이전 버전 내용:
*/

#ifndef __INFIX_CALCULATOR_H__
#define __INFIX_CALCULATOR_H__

// 중위 표기법 수식 -> 후위 표기법 수식 변환 -> 후위 표기법 수식 계산 -> 계산 결과 반환
// 이 모든걸 하나에 담는 함수
int EvalInfixExp(char exp[]);

#endif