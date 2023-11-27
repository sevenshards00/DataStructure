// 11.02 이중 연결 리스트
// DBLinkedList.h

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "DDBLinkedList.h"

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
		printf("순방향(head to tail)\n");
		printf("%d ", data);

		// 오른쪽(순방향)으로 데이터 조회
		while (LNext(&list, &data))
			printf("%d ", data);

		printf("\n");
		printf("역방향(tail to head)\n");
		// 왼쪽(역방향)으로 데이터 조회
		while (LPrev(&list, &data))
			printf("%d ", data);
	}
	printf("\n\n");

	// 데이터 삭제 실험
	// 맨 첫번째 데이터를 읽고
	if (LFirst(&list, &data))
	{
		printf("1,3,5,8를 가진 노드를 삭제 후 다시 데이터를 조회합니다.\n");
		printf("순방향(head to tail)으로 조회하며 노드 제거를 수행합니다.\n");
		if (data == 1 || data == 3 || data == 5 || data == 8)
			printf("%d 데이터를 가진 노드를 삭제했습니다.\n", LRemove(&list));
			

		// 오른쪽(순방향)으로 데이터 조회
		while (LNext(&list, &data))
		{
			if (data == 1 || data == 3 || data == 5 || data == 8)
				printf("%d 데이터를 가진 노드를 삭제했습니다.\n", LRemove(&list));
		}

		printf("이제는 역방향(tail to head)으로 조회하며 노드 제거를 수행합니다.\n");
		printf("앞에서 노드 제거를 진행했으므로 노드 삭제와 관련된 메시지가 나오면 안됩니다.\n");
		// 왼쪽(역방향)으로 데이터 조회
		while (LPrev(&list, &data))
		{
			if (data == 1 || data == 3 || data == 5 || data == 8)
				printf("%d 데이터를 가진 노드를 삭제했습니다.\n", LRemove(&list));
		}
	}
	printf("\n\n");

	// 삭제 후 최종 출력 확인
	// 맨 첫번째 데이터를 읽고
	if (LFirst(&list, &data))
	{
		printf("순방향(head to tail)\n");
		printf("%d ", data);

		// 오른쪽(순방향)으로 데이터 조회
		while (LNext(&list, &data))
			printf("%d ", data);

		printf("\n");
		printf("역방향(tail to head)\n");
		// 왼쪽(역방향)으로 데이터 조회
		while (LPrev(&list, &data))
			printf("%d ", data);
	}
	printf("\n\n");

	return 0;
}