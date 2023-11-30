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
#include "ALGraphKruskal.h"

int main()
{
	ALGraph graph; // �׷��� ����
	GraphInit(&graph, 6); // �׷��� �ʱ�ȭ

	// ���� ���� (���� �߰�)
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
	
	// A, B, C, D�� �������� DFS Ž��
	printf("DFS Ž��\n");
	DFSShowGraphVertex(&graph, A);
	printf("\n");
	DFSShowGraphVertex(&graph, B);
	printf("\n");
	DFSShowGraphVertex(&graph, C);
	printf("\n");
	DFSShowGraphVertex(&graph, D);
	printf("\n\n");

	printf("BFS Ž��\n");
	// A, B, C, D�� �������� BFS Ž��
	BFSShowGraphVertex(&graph, A);
	printf("\n");
	BFSShowGraphVertex(&graph, B);
	printf("\n");
	BFSShowGraphVertex(&graph, C);
	printf("\n");
	BFSShowGraphVertex(&graph, D);
	printf("\n\n");
	
	printf("�ּ� ���� Ʈ�� ����\n");
	ConKruskalMST(&graph);
	ShowGraphEdgeInfo(&graph);
	ShowGraphEdgeWeightInfo(&graph);
	printf("\n\n");

	GraphDestroy(&graph);
	return 0;
}