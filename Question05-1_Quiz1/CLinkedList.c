// 11.02 원형 링크드 리스트
// CLinkedList.c
//

#include <stdlib.h>
#include "CLinkedList.h"

void ListInit(List* plist) // 리스트 초기화
{
	plist->tail = NULL;
	plist->cur = NULL;
	plist->before = NULL;
	plist->numOfData = 0;
}
// 이전 링크드 리스트와 바뀐 부분
// 삽입 부분을 통해서 알게된 것은 tail 포인터를 하나만 쓰면 생각보다 간편해진다
// 원형이라고는 하지만, 결국 tail은 마지막 요소를 가리키고있고, tail->next는 맨 첫번째 요소를 가리킨다.
//
void LInsert(List* plist, LData data) // tail에 노드 추가
{
	Node* newNode = (Node*)malloc(sizeof(Node)); // 새로운 노드 메모리 할당
	newNode->data = data; // 데이터 입력

	// 최초의 노드 생성에 대해서는 동일
	if (plist->tail == NULL) // 만약 첫 번째 노드라면
	{
		plist->tail = newNode; // tail이 첫 번째 노드를 가리키게 하고
		newNode->next = newNode; // 새로운 노드 또한 자신을 가리키게 한다
	}
	else
	{
		newNode->next = plist->tail->next; // 새로운 노드(tail쪽, 가장 오른쪽)의 다음을 tail이 가리키는 다음 주소(맨 첫번째 노드)를 넣고
		plist->tail->next = newNode; // tail이 가리키는 다음 주소는 tail쪽에 들어온 새로운 노드를 가리키게 해라
		plist->tail = newNode; // 마지막으로 tail쪽으로 새로 들어왔으므로 tail은 새로 들어온 노드를 가리켜라
	}

	(plist->numOfData)++;
}
void LInsertFront(List* plist, LData data) // head에 노드 추가
{
	Node* newNode = (Node*)malloc(sizeof(Node)); // 새로운 노드 메모리 할당
	newNode->data = data; // 데이터 입력

	// 최초의 노드 생성에 대해서는 동일
	if (plist->tail == NULL) // 만약 첫 번째 노드라면
	{
		plist->tail = newNode; // tail이 첫 번째 노드를 가리키게 하고
		newNode->next = newNode; // 새로운 노드 또한 자신을 가리키게 한다
	}
	else
	{
		newNode->next = plist->tail->next; // 새로운 노드(head쪽, 가장 왼쪽)의 다음을 tail이 가리키는 다음 주소(맨 첫번째 노드)를 넣고
		plist->tail->next = newNode; // tail이 가리키는 다음 주소는 head쪽에 들어온 새로운 노드 (맨 첫번째 노드)를 가리키게 해라
	}

	(plist->numOfData)++;
}
int LFirst(List* plist, LData* pdata) // 맨 처음 노드부터 참조
{
	if (plist->tail == NULL) // 데이터가 없다면
		return FALSE; // 반환할 데이터가 없음
	// 항상 대원칙을 하나 가지고 가자
	// 그냥 리스트때도 그렇고, 여기서도 그렇듯이 before, cur 순서로
	// 원형 리스트의 경우에는 tail이 제일 끝, tail->next가 제일 첫 번째 노드를 가리킨다
	//
	plist->before = plist->tail; // before는 현재 위치보다 하나 앞이며, First이므로 tail을 가리킨다.
	plist->cur = plist->tail->next; // cur는 현재 위치를 가리키고, 맨 첫번째 요소부터 접근하므로 tail보다 하나 앞의 위치를 가리킨다.

	*pdata = plist->cur->data;

	return TRUE;

}
int LNext(List* plist, LData* pdata) // 맨 처음 노드 이후 참조
{
	// 기존 리스트에서는 plist->cur->next == NULL 이라는 조건식이 있었다.
	// 이는 리스트의 끝을 확인하기 위함이었고, 끝이면 더 이상 읽을 필요가 없다.
	// 하지만 여기서는 tail이 NULL인지만 확인하는데 원형 리스트이므로 계속 읽을 수가 있다.
	// 그래서 조건식이 없고 무한으로 호출이 가능해진다.
	//
	if (plist->tail == NULL) // 데이터가 없다면
		return FALSE; // 반환할 데이터가 없음
	// 항상 대원칙을 하나 가지고 가자
	// 그냥 리스트때도 그렇고, 여기서도 그렇듯이 before, cur 순서로
	// 원형 리스트의 경우에는 tail이 제일 끝, tail->next가 제일 첫 번째 노드를 가리킨다
	//
	plist->before = plist->cur; // 가리키고 있던 위치를 before에 넣고
	plist->cur = plist->cur->next; // 가리키던 위치의 다음 순번을 현재 위치로 지정

	*pdata = plist->cur->data;

	return TRUE;
}
LData LRemove(List* plist) // 현재 참조 중인 노드 삭제
{
	Node* rNode = plist->cur;
	LData rData = plist->cur->data;

	if (rNode == plist->tail)
	{
		if (plist->tail == plist->tail->next)
			plist->tail = NULL;
		else
			plist->tail = plist->before;
	}

	plist->before->next = plist->cur->next;
	plist->cur = plist->before;

	free(rNode);
	(plist->numOfData)--;
	return rData;
}

int LCount(List* plist) // 리스트의 노드 갯수 반환
{
	return plist->numOfData;
}