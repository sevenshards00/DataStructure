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

#ifndef __ALGRAPH_H__
#define __ALGRAPH_H__

// 인접 리스트 기반으로 구현을 하므로 단일 연결 리스트를 사용
#include "SingleLinkedList.h"

// 정점의 이름을 상수화
// A는 0으로 초기화되어 1씩 증가
enum {A, B, C, D, E, F, G, H, I, J};

// 무방향 인접 리스트(Undirected Adjacent List) 그래프 구조체
typedef struct _ual
{
	int numVertex; // 정점의 수
	int numEdge; // 간선의 수
	List* adjList; // 간선의 정보(어떤 정점과 연결되었는지에 대한 정보)
} ALGraph;

// 그래프 자료구조의 ADT
// 초기화
void GraphInit(ALGraph* pg, int nv);

// 그래프의 리소스 해제 (삭제)
void GraphDestroy(ALGraph* pg);

// 간선 추가(연결)
void AddEdge(ALGraph* pg, int fromV, int toV);

// 간선 정보 출력
void ShowGraphEdgeInfo(ALGraph* pg);

#endif