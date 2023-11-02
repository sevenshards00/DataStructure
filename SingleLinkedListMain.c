// 11.02 SingleLinkedList 복기 2회차
// SingleLinkedListMain.c
//
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "SingleLinkedList.h"

int main()
{
	// 리스트 선언 및 초기화
	List list;
	int data;
	ListInit(&list);

	// 데이터 5개 입력
	LInsert(&list, 11);
	LInsert(&list, 22);
	LInsert(&list, 33);
	LInsert(&list, 44);
	LInsert(&list, 55);

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