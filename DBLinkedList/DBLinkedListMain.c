// 11.02 이중 연결 리스트
// DBLinkedList.h

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "DBLinkedList.h"

int main()
{
	// 리스트 선언 및 초기화
	List list;
	int data;
	ListInit(&list);

	// 노드 8개 생성
	LInsert(&list, 1);
	LInsert(&list, 2);
	LInsert(&list, 3);
	LInsert(&list, 4);
	LInsert(&list, 5);
	LInsert(&list, 6);
	LInsert(&list, 7);
	LInsert(&list, 8);

	// 맨 첫번째 데이터를 읽고
	if (LFirst(&list, &data))
	{
		printf("%d ", data);

		// 오른쪽(순방향)으로 데이터 조회
		while (LNext(&list, &data))
			printf("%d ", data);

		// 왼쪽(역방향)으로 데이터 조회
		while (LPrev(&list, &data))
			printf("%d ", data);
	}
	printf("\n\n");

	// 데이터 삭제 실험
	// 맨 첫번째 데이터를 읽고
	if (LFirst(&list, &data))
	{
		if (data == 1 || data == 3 || data == 5 || data ==8)
			LRemove(&list);

		// 오른쪽(순방향)으로 데이터 조회
		while (LNext(&list, &data))
		{
			if (data == 1 || data == 3 || data == 5 || data == 8)
				LRemove(&list);
		}
		// 왼쪽(역방향)으로 데이터 조회
		while (LPrev(&list, &data))
		{
			if (data == 1 || data == 3 || data == 5 || data == 8)
				LRemove(&list);
		}
	}
	printf("\n\n");

	// 삭제 후 최종 출력 확인
	// 맨 첫번째 데이터를 읽고
	if (LFirst(&list, &data))
	{
		printf("%d ", data);

		// 오른쪽(순방향)으로 데이터 조회
		while (LNext(&list, &data))
			printf("%d ", data);

		// 왼쪽(역방향)으로 데이터 조회
		while (LPrev(&list, &data))
			printf("%d ", data);
	}
	printf("\n\n");

	return 0;
}