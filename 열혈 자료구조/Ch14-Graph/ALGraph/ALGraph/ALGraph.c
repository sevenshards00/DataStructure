/*
* 비선형 자료구조 - 인접 리스트(Adjacent List) 기반 무방향 그래프
* 파일명: ALGraph.h
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2023-11-30
* 이전 버전 작성 일자:
* 버전 내용: 간단한 인접 리스트 기반 무방향 그래프 구현
* 이전 버전 내용:
*/

#include <stdio.h>
#include <stdlib.h>
#include "ALGraph.h"
// 인접 리스트 기반으로 구현을 하므로 단일 연결 리스트를 사용
#include "SingleLinkedList.h"

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
	pg->adjList = (List*)malloc(sizeof(List) * nv); // 정점의 수만큼 메모리 할당
	pg->numVertex = nv; // 입력받은 nv는 정점의 수
	pg->numEdge = 0; // 초기화시 간선의 수는 0
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
	if (pg->adjList != NULL)
		free(pg->adjList);
}

// 간선 추가(연결)
void AddEdge(ALGraph* pg, int fromV, int toV)
{
	LInsert(&(pg->adjList[fromV]), toV); // from->to
	LInsert(&(pg->adjList[toV]), fromV); // to->from

	pg->numEdge += 1;
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

			while(LNext(&(pg->adjList[i]), &vertex))
				printf("%c ", vertex += 65);
		}

		printf("\n");
	}
}