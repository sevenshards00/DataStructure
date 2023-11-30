/*
* ���� �ڷᱸ�� - ���� ����Ʈ(Adjacent List) ��� ������ �׷���
* ���ϸ�: ALGraphMain.c
* ���� ����: 0.1
* �ۼ���: Sevenshards
* �ۼ� ����: 2023-11-30
* ���� ���� �ۼ� ����:
* ���� ����: ������ ���� ����Ʈ ��� ������ �׷��� ����
* ���� ���� ����:
*/

#include <stdio.h>
#include "ALGraph.h"

int main()
{
	ALGraph graph; // �׷��� ����
	GraphInit(&graph, 5); // �׷��� �ʱ�ȭ

	// ���� ���� (���� �߰�)
	AddEdge(&graph, A, B);
	AddEdge(&graph, A, D);
	AddEdge(&graph, B, C);
	AddEdge(&graph, C, D);
	AddEdge(&graph, D, E);
	AddEdge(&graph, E, A);

	ShowGraphEdgeInfo(&graph);
	GraphDestroy(&graph);

	return 0;
}