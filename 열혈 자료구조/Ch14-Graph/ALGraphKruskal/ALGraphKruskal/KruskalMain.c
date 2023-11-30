/*
* 비선형 자료구조 - 인접 리스트(Adjacent List) 기반 무방향 그래프
* 파일명: ALGraphBFS.h
* 파일 버전: 0.3
* 작성자: Sevenshards
* 작성 일자: 2023-11-30
* 이전 버전 작성 일자: 2023-11-30
* 버전 내용: 너비 우선 탐색(Breadth First Search) 추가 구현
* 이전 버전 내용: 깊이 우선 탐색(Depth First Search) 추가 구현 (이전 파일명: DFSMain.c)
*/

#include <stdio.h>
#include "ALGraphKruskal.h"

int main()
{
	ALGraph graph; // 그래프 생성
	GraphInit(&graph, 6); // 그래프 초기화

	// 정점 연결 (간선 추가)
	AddEdge(&graph, A, B, 9);
	AddEdge(&graph, B, C, 2);
	AddEdge(&graph, A, C, 12);
	AddEdge(&graph, A, D, 8);
	AddEdge(&graph, D, C, 6);
	AddEdge(&graph, A, F, 11);
	AddEdge(&graph, F, D, 4);
	AddEdge(&graph, D, E, 3);
	AddEdge(&graph, E, C, 7);
	AddEdge(&graph, F, E, 13);

	ShowGraphEdgeInfo(&graph);
	printf("\n");
	
	// A, B, C, D를 시작으로 DFS 탐색
	printf("DFS 탐색\n");
	DFSShowGraphVertex(&graph, A);
	printf("\n");
	DFSShowGraphVertex(&graph, B);
	printf("\n");
	DFSShowGraphVertex(&graph, C);
	printf("\n");
	DFSShowGraphVertex(&graph, D);
	printf("\n\n");

	printf("BFS 탐색\n");
	// A, B, C, D를 시작으로 BFS 탐색
	BFSShowGraphVertex(&graph, A);
	printf("\n");
	BFSShowGraphVertex(&graph, B);
	printf("\n");
	BFSShowGraphVertex(&graph, C);
	printf("\n");
	BFSShowGraphVertex(&graph, D);
	printf("\n\n");
	
	printf("최소 신장 트리 생성\n");
	ConKruskalMST(&graph);
	ShowGraphEdgeInfo(&graph);
	ShowGraphEdgeWeightInfo(&graph);
	printf("\n\n");

	GraphDestroy(&graph);
	return 0;
}