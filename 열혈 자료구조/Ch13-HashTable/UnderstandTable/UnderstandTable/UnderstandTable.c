/*
* 자료구조 - 해시 테이블 (테이블 + 해시)
* 파일명: UnderstandTable.c
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2023-11-29
* 이전 버전 작성 일자:
* 버전 내용: 테이블 자료구조에 대한 이해를 위한 코드
* 이전 버전 내용:
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

typedef struct _empInfo
{
	int empNum; // 사원 번호
	int age; // 나이
} EmpInfo;

int main()
{
	EmpInfo empInfoArr[100];
	EmpInfo ei;
	int eNum;

	// 데이터 저장
	printf("사번과 나이 입력: ");
	scanf("%d %d", &(ei.empNum), &(ei.age));
	empInfoArr[ei.empNum] = ei;

	// 데이터 조회
	printf("확인할 사원의 사번 입력: ");
	scanf("%d", &eNum);

	ei = empInfoArr[eNum];
	printf("사번: %d, 나이: %d\n", ei.empNum, ei.age);
	return 0;
}