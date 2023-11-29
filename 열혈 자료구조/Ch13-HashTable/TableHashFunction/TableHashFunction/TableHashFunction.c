/*
* 자료구조 - 해시 테이블 (테이블 + 해시)
* 파일명: TableHashFunction.c
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2023-11-29
* 이전 버전 작성 일자:
* 버전 내용: 해시 함수에 대한 이해를 위한 코드
* 이전 버전 내용:
*/

#include <stdio.h>

typedef struct _empinfo
{
	int empNum; // 직원의 고유 번호(Key)
	int age; // 직원의 나이(Value)
} EmpInfo;

// Hash 함수
int GetHashValue(int empNum)
{
	return empNum % 100;
}

int main()
{
	EmpInfo empInfoArr[100];

	EmpInfo emp1 = { 20120003, 42 };
	EmpInfo emp2 = { 20130012, 33 };
	EmpInfo emp3 = { 20170049, 27 };

	EmpInfo r1, r2, r3;

	// 키를 해시한 값을 인덱스 값으로 이용하여 저장
	empInfoArr[GetHashValue(emp1.empNum)] = emp1;
	empInfoArr[GetHashValue(emp2.empNum)] = emp2;
	empInfoArr[GetHashValue(emp3.empNum)] = emp3;
	
	// 키를 해시한 값을 인덱스 값으로 이용하여 탐색
	r1 = empInfoArr[GetHashValue(20120003)];
	r2 = empInfoArr[GetHashValue(20130012)];
	r3 = empInfoArr[GetHashValue(20170049)];

	// 탐색한 결과 확인
	printf("사번: %d 나이: %d\n", r1.empNum, r1.age);
	printf("사번: %d 나이: %d\n", r2.empNum, r2.age);
	printf("사번: %d 나이: %d\n", r3.empNum, r3.age);
	return 0;
}