/*
* 비선형 자료구조 - 최소 비용 신장 트리(Minimum cost Spanning Tree)
* 파일명: ALEdge.h
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2023-11-30
* 이전 버전 작성 일자:
* 버전 내용: 최소 비용 신장트리(MST)를 만들기 위한 크루스칼(Kruskal) 알고리즘의 구현
* 이전 버전 내용:
*/

#ifndef __AL_EDGE_H__
#define __AL_EDGE_H__

// 간선의 가중치 정보를 저장하기 위한 구조체 Edge
typedef struct _edge
{
	int v1; // 간선이 연결하는 첫 번째 정점
	int v2; // 간선이 연결하는 두 번째 정점
	int weight; // 간선의 가중치
} Edge;

#endif
