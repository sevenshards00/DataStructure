/*
* 자료구조 - 해시 테이블 (테이블 + 해시)
* 파일명: SimpleHashMain.c
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2023-11-29
* 이전 버전 작성 일자:
* 버전 내용: 간단한 해시 테이블 구현
* 이전 버전 내용:
*/

#include <stdio.h>
#include <stdlib.h>
#include "Person.h"
#include "Table.h"

// 사용자 정의 해시 함수
int MyHashFunc(int k)
{
	return k % 100;
}

int main()
{
	Table myTbl;
	Person* np;
	Person* sp;
	Person* rp;

	TBLInit(&myTbl, MyHashFunc);

	// 데이터 입력
	np = MakePersonData(20120003, "Lee", "Seoul");
	TBLInsert(&myTbl, GetSSN(np), np);

	np = MakePersonData(20130012, "Kim", "Jeju");
	TBLInsert(&myTbl, GetSSN(np), np);

	np = MakePersonData(20170049, "Han", "Kangwon");
	TBLInsert(&myTbl, GetSSN(np), np);

	// 데이터 조회
	sp = TBLSearch(&myTbl, 20120003);
	if (sp != NULL) // NULL이 아니라면 -> 제대로 조회가 되었다면
		ShowPersonInfo(sp); // 정보 출력
	sp = TBLSearch(&myTbl, 20130012);
	if (sp != NULL) // NULL이 아니라면 -> 제대로 조회가 되었다면
		ShowPersonInfo(sp); // 정보 출력
	sp = TBLSearch(&myTbl, 20170049);
	if (sp != NULL) // NULL이 아니라면 -> 제대로 조회가 되었다면
		ShowPersonInfo(sp); // 정보 출력

	// 데이터 삭제
	rp = TBLDelete(&myTbl, 20120003);
	if (rp != NULL) // NULL이 아니라면 -> 반환이 되었다면
		free(rp); // 메모리 할당 해제
	rp = TBLDelete(&myTbl, 20130012);
	if (rp != NULL) // NULL이 아니라면 -> 반환이 되었다면
		free(rp); // 메모리 할당 해제
	rp = TBLDelete(&myTbl, 20170049);
	if (rp != NULL) // NULL이 아니라면 -> 반환이 되었다면
		free(rp); // 메모리 할당 해제
	return 0;
}