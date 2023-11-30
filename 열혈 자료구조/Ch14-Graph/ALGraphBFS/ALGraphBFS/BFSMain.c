/*
* ���� �ڷᱸ�� - ���� ����Ʈ(Adjacent List) ��� ������ �׷���
* ���ϸ�: ALGraphBFS.h
* ���� ����: 0.3
* �ۼ���: Sevenshards
* �ۼ� ����: 2023-11-30
* ���� ���� �ۼ� ����: 2023-11-30
* ���� ����: �ʺ� �켱 Ž��(Breadth First Search) �߰� ����
* ���� ���� ����: ���� �켱 Ž��(Depth First Search) �߰� ���� (���� ���ϸ�: DFSMain.c)
*/

#include <stdio.h>
#include "ALGraphBFS.h"

int main()
{
	ALGraph graph; // �׷��� ����
	GraphInit(&graph, 7); // �׷��� �ʱ�ȭ

	// ���� ���� (���� �߰�)
	AddEdge(&graph, A, B);
	AddEdge(&graph, A, D);
	AddEdge(&graph, B, C);
	AddEdge(&graph, C, D);
	AddEdge(&graph, D, E);
	AddEdge(&graph, E, F);
	AddEdge(&graph, E, G);

	ShowGraphEdgeInfo(&graph);
	printf("\n");

	// A, C, E, G�� �������� DFS Ž��
	printf("DFS Ž��\n");
	DFSShowGraphVertex(&graph, A);
	printf("\n");
	DFSShowGraphVertex(&graph, C);
	printf("\n");
	DFSShowGraphVertex(&graph, E);
	printf("\n");
	DFSShowGraphVertex(&graph, G);
	printf("\n\n");

	printf("BFS Ž��\n");
	// A, C, E, G�� �������� BFS Ž��
	BFSShowGraphVertex(&graph, A);
	printf("\n");
	BFSShowGraphVertex(&graph, C);
	printf("\n");
	BFSShowGraphVertex(&graph, E);
	printf("\n");
	BFSShowGraphVertex(&graph, G);
	printf("\n\n");

	GraphDestroy(&graph);
	return 0;
}