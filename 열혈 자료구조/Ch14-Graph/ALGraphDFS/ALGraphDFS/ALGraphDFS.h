/*
* ���� �ڷᱸ�� - ���� ����Ʈ(Adjacent List) ��� ������ �׷���
* ���ϸ�: ALGraphDFS.h
* ���� ����: 0.2
* �ۼ���: Sevenshards
* �ۼ� ����: 2023-11-30
* ���� ���� �ۼ� ����: 2023-11-30
* ���� ����: ���� �켱 Ž��(Depth First Search) �߰� ����
* ���� ���� ����: ������ ���� ����Ʈ ��� ������ �׷��� ���� (���� ���ϸ�: ALGraph.h)
*/

#ifndef __ALGRAPH_H__
#define __ALGRAPH_H__

// ���� ����Ʈ ������� ������ �ϹǷ� ���� ���� ����Ʈ�� ���
#include "SingleLinkedList.h"

// ������ �̸��� ���ȭ
// A�� 0���� �ʱ�ȭ�Ǿ� 1�� ����
enum { A, B, C, D, E, F, G, H, I, J };

// ������ ���� ����Ʈ(Undirected Adjacent List) �׷��� ����ü
typedef struct _ual
{
	int numVertex; // ������ ��
	int numEdge; // ������ ��
	List* adjList; // ������ ����(� ������ ����Ǿ������� ���� ����)
	int* visitInfo; // �湮 ����(���� �湮 ���� ����) -> �湮 ������ ����ϱ� ���� �迭
} ALGraph;

// �׷��� �ڷᱸ���� ADT
// �ʱ�ȭ
void GraphInit(ALGraph* pg, int nv);

// �׷����� ���ҽ� ���� (����)
void GraphDestroy(ALGraph* pg);

// ���� �߰�(����)
void AddEdge(ALGraph* pg, int fromV, int toV);

// ���� ���� ���
void ShowGraphEdgeInfo(ALGraph* pg);

// ���� �켱 Ž��(DFS) ��� �׷����� ���� ���� ���
void DFSShowGraphVertex(ALGraph* pg, int startV);
#endif