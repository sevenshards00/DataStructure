/*
* 선형 자료구조 - 단일 연결 리스트 (더미 노드 기반)
* 파일명: SingleLinkedListMain.c
* 파일 버전: 0.3
* 작성자: Sevenshards
* 작성 일자: 2023-11-30
* 이전 버전 작성 일자: 2023-11-29
* 버전 내용: 정렬 기준 삽입 추가
* 이전 버전 내용: 해시 충돌 문제 해결을 위한 체이닝 기법 구현
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "SingleLinkedList.h"

// 우선순위 비교를 위한 함수 정의
int WhoIsPrecede(int d1, int d2)
{
	// 오름차순 기준
	if (d1 < d2)
		return 0; // d1이 정렬 순서상 앞선다
	else
		return 1; // d2가 정렬 순서상 앞서거나 같다
}

int main()
{
	// 리스트 선언 및 초기화
	List list;
	int data;
	ListInit(&list);

	SetSortRule(&list, WhoIsPrecede); // 정렬의 기준 등록

	// 데이터 5개 입력
	LInsert(&list, 11);
	LInsert(&list, 11);
	LInsert(&list, 22);
	LInsert(&list, 22);
	LInsert(&list, 33);

	// 저장된 데이터 개수 출력 및 전체 데이터 출력
	printf("Stored Data Count: %d\n", LCount(&list));

	if (LFirst(&list, &data))
		printf("%d ", data);
	while (LNext(&list, &data))
		printf("%d ", data);

	printf("\n\n");

	// 숫자 22만 찾아서 삭제
	if (LFirst(&list, &data))
	{
		if (data == 22)
			LRemove(&list);

		while (LNext(&list, &data))
		{
			if (data == 22)
				LRemove(&list);
		}
	}

	// 삭제 후 남은 데이터 수 조회 및 전체 데이터 출력
	printf("Stored Data Count: %d\n", LCount(&list));

	if (LFirst(&list, &data))
		printf("%d ", data);
	while (LNext(&list, &data))
		printf("%d ", data);

	printf("\n\n");
	return 0;
}