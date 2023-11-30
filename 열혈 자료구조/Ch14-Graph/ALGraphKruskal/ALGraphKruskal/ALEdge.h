/*
* ���� �ڷᱸ�� - �ּ� ��� ���� Ʈ��(Minimum cost Spanning Tree)
* ���ϸ�: ALEdge.h
* ���� ����: 0.1
* �ۼ���: Sevenshards
* �ۼ� ����: 2023-11-30
* ���� ���� �ۼ� ����:
* ���� ����: �ּ� ��� ����Ʈ��(MST)�� ����� ���� ũ�罺Į(Kruskal) �˰����� ����
* ���� ���� ����:
*/

#ifndef __AL_EDGE_H__
#define __AL_EDGE_H__

// ������ ����ġ ������ �����ϱ� ���� ����ü Edge
typedef struct _edge
{
	int v1; // ������ �����ϴ� ù ��° ����
	int v2; // ������ �����ϴ� �� ��° ����
	int weight; // ������ ����ġ
} Edge;

#endif
