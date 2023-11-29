/*
* 자료구조 - 해시 테이블 (테이블 + 해시)
* 파일명: Person.c
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2023-11-29
* 이전 버전 작성 일자:
* 버전 내용: 간단한 해시 테이블 구현
* 이전 버전 내용:
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Person.h"

int GetSSN(Person* p) // 객체 지향 관점 -> 엑세스 함수 (Getter)
{
	return p->ssn;
}
void ShowPersonInfo(Person* p) // 객체 지향 관점 -> const 함수
{
	printf("주민등록번호: %d\n", p->ssn);
	printf("이름: %s\n", p->name);
	printf("주소: %s\n", p->addr);
}
Person* MakePersonData(int ssn, char* name, char* addr) // 객체 지향 관점 -> 생성자
{
	Person* newP = (Person*)malloc(sizeof(Person));
	newP->ssn = ssn;
	strcpy(newP->name, name);
	strcpy(newP->addr, addr);
	return newP;
}