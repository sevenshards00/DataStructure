/*
* 자료구조 - 해시 테이블 (테이블 + 해시)
* 파일명: Slot.h
* 파일 버전: 0.2
* 작성자: Sevenshards
* 작성 일자: 2023-11-29
* 이전 버전 작성 일자: 2023-11-29
* 버전 내용: 해시 충돌 문제 해결을 위한 체이닝 기법 구현
* 이전 버전 내용: 간단한 해시 테이블 구현
*/

#ifndef __SLOT_H__
#define __SLOT_H__

#include "Person.h"

typedef int Key; // 주민등록번호의 데이터형이 int, 그리고 int형을 Key로
typedef Person* Value; // Person형 구조체 포인터 변수를 Value로


// 테이블 각각의 공간(Slot)
typedef struct _slot
{
	Key key; // Key
	Value val; // Value
} Slot;
#endif