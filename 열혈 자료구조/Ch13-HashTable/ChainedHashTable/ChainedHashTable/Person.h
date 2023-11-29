/*
* 자료구조 - 해시 테이블 (테이블 + 해시)
* 파일명: Person.h
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2023-11-29
* 이전 버전 작성 일자:
* 버전 내용: 간단한 해시 테이블 구현
* 이전 버전 내용:
*/

#ifndef __PERSON_H__
#define __PERSON_H__

#define STR_LEN 50

typedef struct _person
{
	int ssn; // 주민등록번호 (Key)
	char name[STR_LEN]; // 이름 (Value)
	char addr[STR_LEN]; // 주소 (Value)
} Person;

int GetSSN(Person* p); // 객체 지향 관점 -> 엑세스 함수 (Getter)
void ShowPersonInfo(Person* p); // 객체 지향 관점 -> const 함수
Person* MakePersonData(int ssn, char* name, char* addr); // 객체 지향 관점 -> 생성자

#endif