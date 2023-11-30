/*
* ���� �ڷᱸ�� - ���� ����Ʈ(Adjacent List) ��� ������ �׷���
* ���ϸ�: ALGraph.h
* ���� ����: 0.1
* �ۼ���: Sevenshards
* �ۼ� ����: 2023-11-30
* ���� ���� �ۼ� ����:
* ���� ����: ������ ���� ����Ʈ ��� ������ �׷��� ����
* ���� ���� ����:
*/

#ifndef __ALGRAPH_H__
#define __ALGRAPH_H__

// ���� ����Ʈ ������� ������ �ϹǷ� ���� ���� ����Ʈ�� ���
#include "SingleLinkedList.h"

// ������ �̸��� ���ȭ
// A�� 0���� �ʱ�ȭ�Ǿ� 1�� ����
enum {A, B, C, D, E, F, G, H, I, J};

// ������ ���� ����Ʈ(Undirected Adjacent List) �׷��� ����ü
typedef struct _ual
{
	int numVertex; // ������ ��
	int numEdge; // ������ ��
	List* adjList; // ������ ����(� ������ ����Ǿ������� ���� ����)
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

#endif