/*
* 자료구조 - 해시 테이블 (테이블 + 해시)
* 파일명: Table.c
* 파일 버전: 0.2
* 작성자: Sevenshards
* 작성 일자: 2023-11-29
* 이전 버전 작성 일자: 2023-11-29
* 버전 내용: 해시 충돌 문제 해결을 위한 체이닝 기법 구현
* 이전 버전 내용: 간단한 해시 테이블 구현
*/

#include <stdio.h>
#include <stdlib.h>
#include "Table.h"
#include "SingleLinkedList.h"

// 초기화
void TBLInit(Table* pt, HashFunc* pf)
{
	int i;

	// 모든 슬롯 초기화
	for (i = 0; i < MAX_TBL; i++)
		ListInit(&(pt->tbl[i]));

	// 해시 함수 등록
	pt->hf = pf;
}

// 키와 값을 저장
void TBLInsert(Table* pt, Key k, Value v)
{
	int hv = pt->hf(k); // 해시 함수를 통해 생성된 해시 값
	Slot newSlot = { k, v };

	if (TBLSearch(pt, k) != NULL) // 키가 중복된다면
	{
		printf("키 중복\n");
		return;
	}
	else
		LInsert(&(pt->tbl[hv]), newSlot);
}

// 키를 근거로 테이블에서 데이터 삭제
Value TBLDelete(Table* pt, Key k)
{
	int hv = pt->hf(k); // 해시 함수를 통해 생성된 해시 값
	Slot cSlot;

	if (LFirst(&(pt->tbl[hv]), &cSlot)) // 연결 리스트의 맨 첫번째 노드 조회
	{
		if (cSlot.key == k) // 키와 같다면
		{
			LRemove(&(pt->tbl[hv])); // 노드 삭제
			return cSlot.val;
		}
		else // 아니라면
		{
			while (LNext(&(pt->tbl[hv]), &cSlot)) // 첫 번째 이후 노드를 조회
			{
				if (cSlot.key == k) // 키와 같다면
				{
					LRemove(&(pt->tbl[hv])); // 노드 삭제
					return cSlot.val;
				}
			}
		}
	}

	return NULL; // 삭제를 못했다면 NULL 반환
}
// 키를 근거로 테이블에서 데이터 조회
Value TBLSearch(Table* pt, Key k)
{
	int hv = pt->hf(k); // 해시 함수를 통해 생성된 해시 값
	Slot cSlot;

	if (LFirst(&(pt->tbl[hv]), &cSlot)) // 연결 리스트의 맨 첫번째 노드 조회
	{
		if (cSlot.key == k) // 키와 같다면
			return cSlot.val;
		else // 아니라면
		{
			while (LNext(&(pt->tbl[hv]), &cSlot)) // 첫 번째 이후 노드를 조회
			{
				if (cSlot.key == k) // 키와 같다면
					return cSlot.val;
			}
		}
	}

	return NULL; // 못찾았다면 NULL 반환
}