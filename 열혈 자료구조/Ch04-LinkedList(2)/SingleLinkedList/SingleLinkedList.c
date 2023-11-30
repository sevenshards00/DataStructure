/*
* 선형 자료구조 - 단일 연결 리스트 (더미 노드 기반)
* 파일명: SingleLinkedList.c
* 파일 버전: 0.3
* 작성자: Sevenshards
* 작성 일자: 2023-11-30
* 이전 버전 작성 일자: 2023-11-29
* 버전 내용: 정렬 기준 삽입 추가 및 로직 수정
* 이전 버전 내용: 해시 충돌 문제 해결을 위한 체이닝 기법 구현
*/

#include <stdlib.h>
#include "SingleLinkedList.h"

// 리스트의 초기화에 사용
void ListInit(List* plist)
{
	plist->head = (Node*)malloc(sizeof(Node)); // 더미 노드를 바로 가리키게 한다.
	plist->head->next = NULL; // 더미 노드가 가리키는 다음을 NULL로
	plist->numOfData = 0; // 그리고 더미노드를 제외하고 실제 데이터 수를 기록해야하므로 0이다. -1이 아니다.
	plist->comp = NULL; // 초기화시 우선순위 판별을 위한 함수는 미지정된 상태이므로 NULL
}

void FInsert(List* plist, LData data) // 정렬 기준 없이 리스트의 노드를 생성할 때 사용
{
	Node* newNode = (Node*)malloc(sizeof(Node)); // 새로운 노드 메모리 할당
	newNode->data = data; // 노드에 데이터 입력
	newNode->next = plist->head->next; // head부터 데이터가 들어가기 때문에, 더미노드 다음을 가리키고 있는 것을 새로운 노드가 가리키게 해야함
	plist->head->next = newNode; // head에서부터 들어가므로 더미노드 다음을 새로운 노드를 가리키게 함
	(plist->numOfData)++; // 데이터 수 증가
}

// 정렬 기준에 맞춰서 리스트의 노드를 생성할 때 사용 (Sort Insert)
void SInsert(List* plist, LData data)
{
	Node* newNode = (Node*)malloc(sizeof(Node)); // 새로운 노드 메모리 할당
	newNode->data = data; // 노드에 데이터 입력
	Node* cur = plist->head; // 삽입을 위해 사용하는 현재 위치(current), 시작 위치는 더미노드
	
	// 새 노드가 들어갈 위치를 찾기 위한 반복문 수행
	// 더 이상 읽을 노드가 없을 때까지, 그리고 새 노드에 들어갈 데이터와 기존 노드의 데이터를 비교하여 기준에 맞을 때까지 반복
	while (cur->next != NULL && plist->comp(data, cur->next->data) != 0)
	{
		cur = cur->next; // 정렬 기준에 맞는 위치까지 다음 노드로 이동
	}

	// 반복문이 끝났다면 노드를 삽입할 위치(cursor)를 찾은 것
	newNode->next = cur->next; // cur의 다음 위치에 새로운 노드가 들어가기 때문에, cur의 다음을 새로운 노드가 가리키도록 해야함
	cur->next = newNode; // 그리고 cur의 next를 새로운 노드를 가리키게 함
	(plist->numOfData)++; // 데이터 수 증가
}

// 리스트의 노드를 새로 생성할 때 사용
void LInsert(List* plist, LData data)
{
	if (plist->comp == NULL) // 정렬 기준이 없다면
		FInsert(plist, data); // FInsert 호출
	else // 정렬 기준이 있다면
		SInsert(plist, data); // SInsert 호출
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

	
	plist->before = plist->cur; // before에 현재 가리키는 노드 위치를 저장
	plist->cur = plist->cur->next; // 현재 가리키는 위치를 하나 앞으로 이동
	*pdata = plist->cur->data; // 현재 가리키는 위치의 데이터 참조 -> 데이터 참조 위치를 잘못 지정하였음

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
// 리스트에 정렬 기준 함수를 등록
void SetSortRule(List* plist, CompareFunc pcomp)
{
	plist->comp = pcomp;
}