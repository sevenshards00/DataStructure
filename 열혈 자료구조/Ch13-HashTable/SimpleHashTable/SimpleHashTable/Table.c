/*
* 자료구조 - 해시 테이블 (테이블 + 해시)
* 파일명: Table.c
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2023-11-29
* 이전 버전 작성 일자:
* 버전 내용: 간단한 해시 테이블 구현
* 이전 버전 내용:
*/

#include <stdio.h>
#include <stdlib.h>
#include "Table.h"

// 초기화
void TBLInit(Table* pt, HashFunc* pf)
{
	int i;

	// 모든 슬롯 초기화
	for (i = 0; i < MAX_TBL; i++)
		(pt->tbl[i]).status = EMPTY;

	// 해시 함수 등록
	pt->hf = pf;
}

// 키와 값을 저장
void TBLInsert(Table* pt, Key k, Value v)
{
	int hv = pt->hf(k); // 해시 함수를 통해 생성된 해시 값
	pt->tbl[hv].val = v;
	pt->tbl[hv].key = k;
	pt->tbl[hv].status = INUSE;
}

// 키를 근거로 테이블에서 데이터 삭제
Value TBLDelete(Table* pt, Key k)
{
	int hv = pt->hf(k); // 해시 함수를 통해 생성된 해시 값

	if ((pt->tbl[hv]).status != INUSE) // 슬롯이 INUSE가 아니라면
		return NULL; // 찾지 못함
	else
	{
		(pt->tbl[hv]).status = DELETED; // DELETED로 변경
		return (pt->tbl[hv]).val; // 삭제 대상 값 반환
	}
}
// 키를 근거로 테이블에서 데이터 조회
Value TBLSearch(Table* pt, Key k)
{
	int hv = pt->hf(k); // 해시 함수를 통해 생성된 해시 값

	if ((pt->tbl[hv]).status != INUSE) // 슬롯이 INUSE가 아니라면
		return NULL; // 찾지 못함
	else
		return (pt->tbl[hv]).val; // 조회 대상 값 반환
}