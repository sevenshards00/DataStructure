/*
* 비선형 자료구조 - 인접 리스트(Adjacent List) 기반 무방향 그래프
* 파일명: DFSMain.c
* 파일 버전: 0.2
* 작성자: Sevenshards
* 작성 일자: 2023-11-30
* 이전 버전 작성 일자: 2023-11-30
* 버전 내용: 깊이 우선 탐색(Depth First Search) 추가 구현
* 이전 버전 내용: 간단한 인접 리스트 기반 무방향 그래프 구현 (이전 파일명: ALGraphMain.c)
*/

#include <stdio.h>
#include "ALGraphDFS.h"

int main()
{
	ALGraph graph; // 그래프 생성
	GraphInit(&graph, 7); // 그래프 초기화

	// 정점 연결 (간선 추가)
	AddEdge(&graph, A, B);
	AddEdge(&graph, A, D);
	AddEdge(&graph, B, C);
	AddEdge(&graph, C, D);
	AddEdge(&graph, D, E);
	AddEdge(&graph, E, F);
	AddEdge(&graph, E, G);

	ShowGraphEdgeInfo(&graph);

	// A, C, E, G를 시작으로 DFS 탐색
	DFSShowGraphVertex(&graph, A);
	printf("\n");
	DFSShowGraphVertex(&graph, C);
	printf("\n");
	DFSShowGraphVertex(&graph, E);
	printf("\n");
	DFSShowGraphVertex(&graph, G);
	printf("\n");

	GraphDestroy(&graph);
	return 0;
}