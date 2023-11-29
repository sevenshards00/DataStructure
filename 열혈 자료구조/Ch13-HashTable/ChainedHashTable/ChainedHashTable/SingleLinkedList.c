/*
* 선형 자료구조 - 단일 연결 리스트 (더미 노드 기반)
* 파일명: SingleLinkedList.c
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2023-11-02
* 이전 버전 작성 일자:
* 버전 내용: 더미 노드 기반 단일 연결 리스트 구현
* 이전 버전 내용:
*/

#include <stdlib.h>
#include "SingleLinkedList.h"

// 리스트의 초기화에 사용
void ListInit(List* plist)
{
	plist->head = (Node*)malloc(sizeof(Node)); // 더미 노드를 바로 가리키게 한다.
	plist->head->next = NULL; // 더미 노드가 가리키는 다음을 NULL로
	plist->numOfData = 0; // 그리고 더미노드를 제외하고 실제 데이터 수를 기록해야하므로 0이다. -1이 아니다.
}

// 리스트의 노드를 새로 생성할 때 사용
void LInsert(List* plist, LData data)
{
	Node* newNode = malloc(sizeof(Node)); // 새로운 노드 메모리 할당
	newNode->data = data; // 노드에 데이터 입력

	// 잘못 쓴 부분. 여기를 잘못 써서 다 꼬였다.
	// newNode->next = NULL; // 새로운 노드가 가리키는 다음 노드는 없으므로 NULL
	newNode->next = plist->head->next; // head부터 데이터가 들어가기 때문에, 항상 더미노드 다음을 가리키고 있는 것을 새로운 노드가 가리키게 해야함
	plist->head->next = newNode; // head에서부터 들어가므로 더미노드 다음을 새로운 노드를 가리키게 함
	(plist->numOfData)++; // 데이터 수 증가
}

// 리스트의 맨 첫번째 데이터를 참조할 때 사용
int LFirst(List* plist, LData* pdata)
{
	// 쓸 필요 없었음. 매개변수 있으므로 그거 쓰면 됨
	// LData nData; // 노드의 데이터를 받기 위한 변수
	if (plist->head->next == NULL) // 만약 더미노드 이후에 가리키는 노드가 없다면
		return FALSE; // 데이터가 없다

	plist->cur = plist->head->next; // 현재 위치를 다음 노드를 가리키게 한다
	plist->before = plist->head; // 그리고 before는 현재 위치 앞인 더미노드를 가리킨다

	*pdata = plist->cur->data; // 현재 위치의 데이터를 참조

	return TRUE; // 데이터 참조에 성공했다

}

// LFirst 이후의 데이터를 참조할 때 사용
int LNext(List* plist, LData* pdata)
{
	// 마찬가지로 쓸 필요 없었음. 매개변수 있으므로 그거 쓰면 됨
	// LData nData; // 노드의 데이터를 받기 위한 변수
	if (plist->cur->next == NULL) // 현재 위치 다음이 가리키는 노드가 없다면
		return FALSE; // 데이터가 없다

	*pdata = plist->cur->data; // 현재 가리키는 위치의 데이터 참조
	plist->before = plist->cur; // before에 현재 가리키는 노드 위치를 저장
	plist->cur = plist->cur->next; // 현재 가리키는 위치를 하나 앞으로 이동

	return TRUE; // 데이터 참조 성공
}

// LFirst, LNext가 참조한 데이터를 삭제하고 메모리 해제에 사용, 연속 호출 불가
LData LRemove(List* plist)
{
	LData rdata; // 지워질 노드의 데이터
	Node* rNode; // 현재 참조 중인, 지워질 노드를 담기 위한 노드 포인터

	rdata = plist->cur->data; // 현재 지워질 데이터를 담고
	rNode = plist->cur; // 지워질 노드는 현재 참조중인 노드를 가리킨다

	plist->before->next = plist->cur->next; // 그리고 이전 노드와 현재 가리키는 노드의 뒤를 연결
	plist->cur = plist->before; // 그리고 현재 참조중인 위치를 하나 앞으로 옮긴다

	free(rNode); // 여기서 메모리를 해제해주고
	(plist->numOfData)--; // 데이터 수 감소
	return rdata; // 데이터를 반환한다.
}

// 현재 리스트에 저장된 노드 수 확인
int LCount(List* plist)
{
	return plist->numOfData;
}