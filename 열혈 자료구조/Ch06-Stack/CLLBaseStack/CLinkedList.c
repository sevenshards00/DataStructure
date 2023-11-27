// 11.03 원형 연결 리스트
// 더미 노드 기반으로 구현하지 않는다
// CLinkedList.c

#include <stdlib.h>
#include "CLinkedList.h"

void ListInit(List* plist) // 리스트 초기화
{
	plist->tail = NULL;
	plist->numOfData = 0;
}

// 잘못 짰다.
// head쪽으로만 데이터가 들어간다고 가정하고 이딴 코드를 썼다.
// 이건 tail쪽으로 들어가는 노드 삽입의 경우다
//
void LInsert(List* plist, Data data) // 노드 삽입
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	if (plist->tail == NULL) // 만약 리스트가 비어있다면
	{
		plist->tail = newNode; // 새로운 노드를 tail이 가리키게 한다
		newNode->next = plist->tail; // 그리고 새로운 노드를 tail을 가리키게 하여 자신을 가리키게 한다
	}
	else
	{
		newNode->next = plist->tail->next; // 새로운 노드의 다음이 맨 첫번째 노드를 가리키도록 tail->next 값을 주고
		plist->tail->next = newNode; // 그리고 현재 tail이 가리키고 있는(새로운 노드보다 하나 앞의 노드) 노드의 next를 새로운 노드를 가리키게 한다.
		plist->tail = newNode; // 마지막으로, tail이 새로운 노드를 가리켜서 가장 오른쪽의 노드를 가리키게 한다.

	}
	// tail쪽으로 들어온 새로운 노드는 가장 오른쪽이다.
	// 가장 오른쪽에 들어왔기 때문에 새로운 노드는 맨 첫번째, 가장 오른쪽의 노드를 가리켜야 한다.
	newNode->next = plist->tail->next; // 그래서 첫 번째로는 새로운 노드의 next를 tail->next, 가장 왼쪽 노드를 가리키게 한다.

	(plist->numOfData)++;
}

// 원형 링크드 리스트를 하면서 이걸 미처 생각하지 않고 있었다.
// 내가 구현한 것도 사실은 엉망인 코드였다.
// 원래 구현한게 Front 내용이었고, 위에 있는 것도 완벽하지 않다.
//
void LInsertFront(List* plist, Data data) // head에 노드 추가
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
int LFirst(List* plist, Data* pdata) // 맨 처음 노드 참조
{
	if (plist->tail == NULL) // 리스트가 비어있다면
		return FALSE; // 노드 참조 실패
	// 그게 아니라면

	plist->cur = plist->tail->next; // 맨 첫번째(가장 왼쪽) 노드를 가리키게 하고
	plist->before = plist->tail; // 하나 앞의 노드(tail)를 가리키게 한다

	*pdata = plist->cur->data; // 현재 가리키는 요소의 값을 가져온다.

	return TRUE; // 데이터 참조 성공.

}

int LNext(List* plist, Data* pdata) // 맨 처음 노드 참조 이후 다음 노드 참조
{
	// 원형 링크드 리스트이므로 굳이 NULL인지 따질 필요는 없다. 연속 호출이 가능하므로
	// 그래도 혹시 모르니 조건식을 달아둔다면
	if (plist->tail == NULL) // 리스트가 비어있다면
		return FALSE; // 노드 참조 실패

	// 또 순서 문제
	// 아까랑 똑같은 이치다.
	// C는 순차적으로 진행하는데, 이걸 못하면 도대체 뭘 어쩌자는거냐
	// 이전에 현재 위치를 넣고, 그리고 난 다음에 한 칸 옮기고 그리고 데이터를 읽어라
	// 안그러면 안읽히고, 이상한 데이터가 나온다
	// 제발 좀
	//
	plist->before = plist->cur; // 현재의 위치를 이전 위치로 바꾼다
	plist->cur = plist->cur->next; // 현재 위치보다 하나 앞의 노드를 가리키게 하고
	*pdata = plist->cur->data; // 현재 가리키는 요소의 값을 가져온다.

	return TRUE;
}

Data LRemove(List* plist) // 현재 참조 중인 노드 삭제
{
	// 여기가 중요한 포인트
	// 1) tail을 지우는 경우
	// 만약 data가 남아있는데, tail을 지우는 경우라면 tail을 하나 앞으로 옮겨줘야 한다.
	// 2) 데이터가 마지막으로 딱 하나 남았을 때 지우는 경우
	// 이때는 마지막으로 남은 노드도 tail인 경우다. 리스트가 비워지는 경우이므로 tail이 NULL을 가리키도록 한다
	// 3) 그것도 아니라면 그냥 이전 단일 연결 리스트처럼 연결을 바꿔주면 된다.
	//

	Node* rNode = plist->cur; // 지울 노드를 현재 가리키는 노드로
	Data rData = plist->cur->data; // 그리고 현재 지울 노드가 가지고 있는 데이터

	if (plist->cur == plist->tail) // 일단 현재 가리키는 위치가 tail이라면
	{
		if (plist->tail == plist->tail->next) // tail과 tail->next가 같다면? 마지막으로 딱 하나 남은 노드가 된다
		{
			plist->tail = NULL;; // 더 이상 가리키는 것이 없게 하고
		}
		plist->tail = plist->before; // 현재 가리키는 노드의 하나 앞으로 옮긴다
	}

	plist->before->next = plist->cur->next;
	plist->cur = plist->before;

	free(rNode);
	(plist->numOfData)--; // 전체 노드 수 감소
	return rData;
}

int LCount(List* plist) // 현재 노드 전체 개수
{
	return plist->numOfData;
}