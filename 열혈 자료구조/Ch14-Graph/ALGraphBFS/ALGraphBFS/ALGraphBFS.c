/*
* 비선형 자료구조 - 인접 리스트(Adjacent List) 기반 무방향 그래프
* 파일명: ALGraphBFS.c
* 파일 버전: 0.3
* 작성자: Sevenshards
* 작성 일자: 2023-11-30
* 이전 버전 작성 일자: 2023-11-30
* 버전 내용: 너비 우선 탐색(Breadth First Search) 추가 구현
* 이전 버전 내용: 깊이 우선 탐색(Depth First Search) 추가 구현 (이전 파일명: ALGraphDFS.c)
*/

#include <stdio.h>
#include <stdlib.h>
#include "ALGraphBFS.h"
// 인접 리스트 기반으로 구현을 하므로 단일 연결 리스트를 사용
#include "SingleLinkedList.h"
// DFS 구현에 스택을 사용
#include "ArrayBaseStack.h"
// BFS 구현에 큐를 사용
#include "CircularQueue.h"

// 저자는 출력의 형태를 좋게 하기 위해서 정렬 기준(우선순위 판별)을 넣었다.
// 사실 넣어도 그만이고 안넣어도 그만인 부분이다.
// 혹시라도 이 미흡한 코드를 보고 따라한다면 이 함수는 빼도 된다.
int WhoisPrecede(int d1, int d2)
{
	// 오름차순 정렬
	if (d1 < d2)
		return 0; // d1의 우선 순위가 앞선다면 0을
	else
		return 1; // d2의 우선 순위가 앞서거나 같다면 1을
}

// 그래프 자료구조의 ADT
// 초기화
void GraphInit(ALGraph* pg, int nv)
{
	pg->numVertex = nv; // 입력받은 nv는 정점의 수
	pg->numEdge = 0; // 초기화시 간선의 수는 0
	pg->adjList = (List*)malloc(sizeof(List) * pg->numVertex); // 정점의 수만큼 메모리 할당
	pg->visitInfo = (int*)malloc(sizeof(int) * pg->numVertex); // 정점의 수만큼 메모리 할당
	memset(pg->visitInfo, 0, sizeof(int) * pg->numVertex); // 배열의 모든 요소를 0으로 초기화
	int i; // 반복문에서 사용할 변수 i

	for (i = 0; i < nv; i++)
	{
		ListInit(&(pg->adjList[i])); // 정점의 수만큼 List 초기화
		SetSortRule(&(pg->adjList[i]), WhoisPrecede); // 각 List에 정렬 기준 함수 등록 -> 정렬 기준을 안쓴다면 빼도 됨
	}
}

// 그래프의 리소스 해제 (삭제)
void GraphDestroy(ALGraph* pg)
{
	if (pg->adjList != NULL) // NULL이 아니라면 할당이 된 상황
		free(pg->adjList); // 할당 해제
	if (pg->visitInfo != NULL) // NULL이 아니라면 할당이 된 상황
		free(pg->visitInfo); // 할당 해제
}

// 간선 추가(연결)
void AddEdge(ALGraph* pg, int fromV, int toV)
{
	LInsert(&(pg->adjList[fromV]), toV); // from->to
	LInsert(&(pg->adjList[toV]), fromV); // to->from
	pg->numEdge += 1; // 간선 갯수 추가
}
// 간선 정보 출력
void ShowGraphEdgeInfo(ALGraph* pg)
{
	int i; // 반복문에 사용할 변수 i
	int vertex; // 정점

	for (i = 0; i < pg->numVertex; i++)
	{
		printf("%c와 연결된 정점: ", i + 65); // 아스키 코드 65가 'A'

		if (LFirst(&(pg->adjList[i]), &vertex))
		{
			printf("%c ", vertex += 65);

			while (LNext(&(pg->adjList[i]), &vertex))
				printf("%c ", vertex += 65);
		}

		printf("\n");
	}
}

// 정점의 방문을 진행하는 함수
// 두 번째 인자로 전달된 이름의 정점에 방문을 진행
int VisitVertex(ALGraph* pg, int visitV)
{
	if (pg->visitInfo[visitV] == 0) // 아직 방문하지 않았다면
	{
		pg->visitInfo[visitV] = 1; // 방문한 것으로 바꾼다. 0이면 아직 안들른 것, 1이면 들른것. flag 개념
		printf("%c ", visitV + 65); // 방문한 정점의 이름을 출력
		return TRUE; // 방문을 했으므로 TRUE 반환
	}

	return FALSE; // 방문을 못했으므로 FALSE 반환
}

// 깊이 우선 탐색(DFS) 기반 그래프의 정점 정보 출력
void DFSShowGraphVertex(ALGraph* pg, int startV)
{
	Stack stack; // 경로 정보의 추적에 사용할 스택
	int visitV = startV; // 시작 정점으로 방문한 정점을 초기화
	int nextV; // 다음에 방문할 정점

	StackInit(&stack); // 스택의 초기화
	VisitVertex(pg, visitV); // 시작 정점을 방문
	// 여기서 스택에 넣는 부분은 사실 필요가 없다.
	// 카페에서 저자의 답변을 확인해본 결과는 다음과 같았다.
	// VisitVertex와 SPush는 쌍을 이루는 것이 좋고, 가독성 차원에서 놔둔 것이라고.
	// 실제로 디버깅을 하면 스택에는 시작 정점이 두 번 들어가는 것이 확인된다.
	// 결론은 주석 처리해도 문제가 되지 않는다.
	// SPush(&stack, visitV); // 시작 정점의 정보를 스택에 넣는다.

	// visitV에 담긴 정점과 연결된 정점의 방문을 시도하기 위한 반복문
	// 가독성 차원에서 '== TRUE' 삽입, 어차피 반환 결과가 TRUE, FALSE이긴 하지만 코드 읽기 편하려면 넣는게 좋다
	while (LFirst(&(pg->adjList[visitV]), &nextV) == TRUE) // 현재 정점과 연결된 간선이 있다면
	{
		// 현재 visitV와 연결된 정점의 정보는 nextV에 담긴 상태
		int visitFlag = FALSE; // 방문 flag를 FALSE로 한다.

		if (VisitVertex(pg, nextV) == TRUE) // 다음 정점 방문에 성공했다면
		{
			SPush(&stack, visitV); // visitV에 담긴 정점의 정보를 스택에 넣는다.
			visitV = nextV; // 그리고 다음에 방문할 정점의 정보로 변경
			visitFlag = TRUE; // 방문에 성공했으므로 TRUE로 변경
		}
		else // 방문에 성공하지 못했다면
		{
			// 가독성 차원에서 '== TRUE' 삽입, 어차피 반환 결과가 TRUE, FALSE이긴 하지만 코드 읽기 편하려면 넣는게 좋다
			while (LNext(&(pg->adjList[visitV]), &nextV) == TRUE) // 다른 방문할 정점을 찾는다.
			{
				if (VisitVertex(pg, nextV) == TRUE) // 정점 방문에 성공했다면
				{
					SPush(&stack, visitV); // visitV에 담긴 정점의 정보를 스택에 넣는다.
					visitV = nextV; // 그리고 다음에 방문할 정점의 정보로 변경
					visitFlag = TRUE; // 방문에 성공했으므로 TRUE로 변경
					break; // 방문에 성공했으므로 반복 중단
				}
			}
		}

		if (visitFlag == FALSE) // 추가로 방문한 정점이 하나도 없다면
		{
			if (SisEmpty(&stack)) // 스택이 비었다면 탐색이 종료된 것
				break;
			else // 스택이 비어있는 상태가 아니라면
				visitV = SPop(&stack); // 이전의 경로로 돌아가기 위해 스택에서 꺼낸다.

		}
	}

	// 이후 탐색을 다시 수행할 수 있으므로 배열의 정보를 초기화
	memset(pg->visitInfo, 0, sizeof(int) * pg->numVertex); // 배열의 모든 요소를 0으로 초기화
}

// 너비 우선 탐색(BFS) 기반 그래프의 정점 정보 출력
void BFSShowGraphVertex(ALGraph* pg, int startV)
{
	Queue queue; // 방문할 차례(순서)의 기록을 목적으로 큐 생성
	int visitV = startV; // 시작 정점으로 방문할 정점을 초기화
	int nextV; // 다음에 방문할 정점

	QueueInit(&queue); // 큐 초기화
	VisitVertex(pg, visitV); // 시작 정점 방문

	// visitV에 담긴 정점과 연결된 정점의 모든 정점에 방문하기 위한 반복문
	// 가독성 차원에서 '== TRUE' 삽입, 어차피 반환 결과가 TRUE, FALSE이긴 하지만 코드 읽기 편하려면 넣는게 좋다
	while (LFirst(&(pg->adjList[visitV]), &nextV) == TRUE) // 현재 정점과 연결된 간선이 있다면
	{
		// 현재 visitV와 연결된 정점의 정보는 nextV에 담긴 상태
		if (VisitVertex(pg, nextV) == TRUE) // 다음 정점 방문에 성공했다면
			QEnqueue(&queue, nextV); // nextV에 방문했으므로 큐에 저장
		
		// 가독성 차원에서 '== TRUE' 삽입, 어차피 반환 결과가 TRUE, FALSE이긴 하지만 코드 읽기 편하려면 넣는게 좋다
		while (LNext(&(pg->adjList[visitV]), &nextV) == TRUE) // 이어서 방문할 정점을 찾는다.
		{
			if (VisitVertex(pg, nextV) == TRUE) // 정점 방문에 성공했다면
				QEnqueue(&queue, nextV); // nextV에 방문했으므로 큐에 저장
		}

		if (QisEmpty(&queue)) // 큐가 비었다면 탐색이 종료된 것
			break;
		else // 큐가 비어있는 상태가 아니라면
			visitV = QDequeue(&queue); // 큐에서 하나 정점을 하나 꺼내어 다시 반복문 수행.
	}

	// 이후 탐색을 다시 수행할 수 있으므로 배열의 정보를 초기화
	memset(pg->visitInfo, 0, sizeof(int) * pg->numVertex); // 배열의 모든 요소를 0으로 초기화
}