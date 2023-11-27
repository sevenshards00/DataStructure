// 11.02 원형 링크드 리스트
// CLinkedListMain.c
//
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "CLinkedList.h"

int main()
{
	// 리스트 생성 및 초기화
	List list;
	int data, i, nodeNum;
	ListInit(&list);

	// 리스트에 데이터 저장
	// tail쪽으로 삽입
	LInsert(&list, 3);
	LInsert(&list, 4);
	LInsert(&list, 5);
	// head쪽으로 삽입
	LInsertFront(&list, 2);
	LInsertFront(&list, 1);

	// 데이터 3회 연속 출력
	if (LFirst(&list, &data))
	{
		printf("%d ", data);

		for (i = 0; i < (LCount(&list)) * 3 - 1; i++)
		{
			if (LNext(&list, &data))
				printf("%d ", data);
		}
	}
	printf("%\n\n");

	// 2의 배수만 찾아서 삭제
	nodeNum = LCount(&list);

	// 노드가 하나도 없는게 아니라면
	if (nodeNum != 0)
	{
		LFirst(&list, &data);
		if (data % 2 == 0)
			LRemove(&list);

		for (i = 0; i < nodeNum - 1; i++)
		{
			LNext(&list, &data);
			if (data % 2 == 0)
				LRemove(&list);
		}
	}

	// 마지막으로 전체 데이터 출력
	if (LFirst(&list, &data))
	{
		printf("%d ", data);

		for (i = 0; i < (LCount(&list)) - 1; i++)
		{
			if (LNext(&list, &data))
				printf("%d ", data);
		}
	}
	printf("%\n\n");

	return 0;
}