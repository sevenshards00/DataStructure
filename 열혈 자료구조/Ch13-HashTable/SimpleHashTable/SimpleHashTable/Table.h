/*
* 자료구조 - 해시 테이블 (테이블 + 해시)
* 파일명: Table.h
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2023-11-29
* 이전 버전 작성 일자:
* 버전 내용: 간단한 해시 테이블 구현
* 이전 버전 내용:
*/

#ifndef __TABLE_H__
#define __TABLE_H__

#include "Slot.h"

#define MAX_TBL 100

typedef int HashFunc(Key k); // 함수 포인터로 쓰기 위해(HashFunc) typedef 선언

// 테이블 구조체
typedef struct _table
{
	Slot tbl[MAX_TBL];
	HashFunc* hf;
} Table;

// 초기화
void TableInit(Table* pt, HashFunc* pf);

// 키와 값을 저장
void TBLInsert(Table* pt, Key k, Value v);

// 키를 근거로 테이블에서 데이터 삭제
Value TBLDelete(Table* pt, Key k);
// 키를 근거로 테이블에서 데이터 조회
Value TBLSearch(Table* pt, Key k);

#endif