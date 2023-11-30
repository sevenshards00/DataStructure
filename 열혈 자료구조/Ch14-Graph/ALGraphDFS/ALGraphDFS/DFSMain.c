/*
* ���� �ڷᱸ�� - ���� ����Ʈ(Adjacent List) ��� ������ �׷���
* ���ϸ�: DFSMain.c
* ���� ����: 0.2
* �ۼ���: Sevenshards
* �ۼ� ����: 2023-11-30
* ���� ���� �ۼ� ����: 2023-11-30
* ���� ����: ���� �켱 Ž��(Depth First Search) �߰� ����
* ���� ���� ����: ������ ���� ����Ʈ ��� ������ �׷��� ���� (���� ���ϸ�: ALGraphMain.c)
*/

#include <stdio.h>
#include "ALGraphDFS.h"

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

	// A, C, E, G�� �������� DFS Ž��
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