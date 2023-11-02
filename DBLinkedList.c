// 11.02 이중 연결 리스트
// DBLinkedList.c
#include <stdlib.h>
#include "DBLinkedList.h"

void ListInit(List* plist) // 리스트 초기화
{
	plist->head = NULL;
	plist->numOfData = 0;
}

void LInsert(List* plist, LData data) // 노드 삽입
{
	// 새로운 노드 생성 및 데이터 입력
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	// 새로운 노드의 다음을 head가 가리키는 곳으로 가리켜라
	// 이게 두 가지 케이스를 나눠서 보아야 한다.
	// 만약 초기화된 직후 아무것도 없는 상태에서 최초로 생성되는 노드라면? NULL 값이 들어간다
	// 하지만 그게 아니라면? 현재 head가 가리키는 노드를 가리키게 된다.
	// 따라서 새로운 노드의 next에는 head가 가리키는 노드를 가리킬 수 있게 된다.
	//
	newNode->next = plist->head; 
	// 그래서 이 부분에서 조건식으로 물어본다.
	// 만약 초기화 직후의 상황이 아니라면?
	// head의 prev가 새로운 노드를 가리키도록 한다
	//
	if (plist->head != NULL)
		plist->head->prev = newNode;

	// 여기도 위에서처럼 두 가지 케이스로 나눠서 보아야 한다.
	// 위의 조건식을 성립하지 않고 넘어왔다면?
	// 초기화된 직후라는 말이 되고 새로 생성된 노드의 prev에는 NULL이 들어가고, head는 새 노드를 가리킨다
	// 그런데 위의 조건식을 성립하고 넘어왔다라고 하면? head가 가리키고 있던 노드의 prev를 통해 새 노드와 연결된다.
	// 그리고 새 노드의 prev에는 NULL값을 주고, head는 새로운 노드를 가리키게 된다.
	//
	newNode->prev = NULL;
	plist->head = newNode;

	(plist->numOfData)++;
}

int LFirst(List* plist, LData* pdata) // 리스트의 맨 처음 노드 참조
{
	if (plist->head == NULL) // 만약 리스트가 비었다면?
		return FALSE; // 데이터 조회 불가

	plist->cur = plist->head; // cur가 첫 번째 노드를 가리키도록 함
	*pdata = plist->cur->data; // 첫 번째 노드의 데이터를 참조

	return TRUE; // 데이터 조회 성공
}

int LNext(List* plist, LData* pdata) // 리스트의 맨 처음 노드 참조 이후 참조
{
	if (plist->cur->next == NULL) // 뒤에 읽을 노드가 없다면?
		return FALSE; // 데이터 조회 실패
	
	plist->cur = plist->cur->next; // cur를 오른쪽로 이동
	*pdata = plist->cur->data; // 현재 위치의 노드 데이터를 참조

	return TRUE;
}

int LPrev(List* plist, LData* pdata) // 이전 노드 참조
{
	if (plist->cur->prev == NULL) // 앞에 읽을 노드가 없다면?
		return FALSE; // 데이터 조회 실패

	plist->cur = plist->cur->prev; // cur를 왼쪽으로 이동
	*pdata = plist->cur->data; // 현재 위치의 데이터를 참조

	return TRUE;
}

LData LRemove(List* plist) // 노드 삭제, 이건 일단 챕터 끝나고 따로 생각해보기로
{
	Node* rNode = plist->cur;
	LData rData = plist->cur->data;

	// 맨 첫 번째 노드를 지운다고 하면
	if (plist->cur == plist->head)
	{
		plist->cur = plist->cur->next;
		plist->head = plist->cur;
		plist->cur->prev = NULL;
	}
	else if (plist->cur->next == NULL)
	{
		plist->cur = plist->cur->prev;
		plist->cur->next = NULL;
	}
	else
	{
		plist->cur->prev->next = plist->cur->next;
		plist->cur->next->prev = plist->cur->prev;
		plist->cur = plist->cur->prev;
	}

	free(rNode);
	(plist->numOfData)--;
	return rData;
}

int LCount(List* plist) // 현재 리스트에 있는 노드의 수 반환
{
	return plist->numOfData;
}