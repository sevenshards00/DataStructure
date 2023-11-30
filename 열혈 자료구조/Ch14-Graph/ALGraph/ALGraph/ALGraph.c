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

#include <stdio.h>
#include <stdlib.h>
#include "ALGraph.h"
// ���� ����Ʈ ������� ������ �ϹǷ� ���� ���� ����Ʈ�� ���
#include "SingleLinkedList.h"

// ���ڴ� ����� ���¸� ���� �ϱ� ���ؼ� ���� ����(�켱���� �Ǻ�)�� �־���.
// ��� �־ �׸��̰� �ȳ־ �׸��� �κ��̴�.
// Ȥ�ö� �� ������ �ڵ带 ���� �����Ѵٸ� �� �Լ��� ���� �ȴ�.
int WhoisPrecede(int d1, int d2)
{
	// �������� ����
	if (d1 < d2)
		return 0; // d1�� �켱 ������ �ռ��ٸ� 0��
	else
		return 1; // d2�� �켱 ������ �ռ��ų� ���ٸ� 1��
}

// �׷��� �ڷᱸ���� ADT
// �ʱ�ȭ
void GraphInit(ALGraph* pg, int nv)
{
	pg->adjList = (List*)malloc(sizeof(List) * nv); // ������ ����ŭ �޸� �Ҵ�
	pg->numVertex = nv; // �Է¹��� nv�� ������ ��
	pg->numEdge = 0; // �ʱ�ȭ�� ������ ���� 0
	int i; // �ݺ������� ����� ���� i

	for (i = 0; i < nv; i++)
	{
		ListInit(&(pg->adjList[i])); // ������ ����ŭ List �ʱ�ȭ
		SetSortRule(&(pg->adjList[i]), WhoisPrecede); // �� List�� ���� ���� �Լ� ��� -> ���� ������ �Ⱦ��ٸ� ���� ��
	}
}

// �׷����� ���ҽ� ���� (����)
void GraphDestroy(ALGraph* pg)
{
	if (pg->adjList != NULL)
		free(pg->adjList);
}

// ���� �߰�(����)
void AddEdge(ALGraph* pg, int fromV, int toV)
{
	LInsert(&(pg->adjList[fromV]), toV); // from->to
	LInsert(&(pg->adjList[toV]), fromV); // to->from

	pg->numEdge += 1;
}
// ���� ���� ���
void ShowGraphEdgeInfo(ALGraph* pg)
{
	int i; // �ݺ����� ����� ���� i
	int vertex; // ����

	for (i = 0; i < pg->numVertex; i++)
	{
		printf("%c�� ����� ����: ", i + 65); // �ƽ�Ű �ڵ� 65�� 'A'

		if (LFirst(&(pg->adjList[i]), &vertex))
		{
			printf("%c ", vertex += 65);

			while(LNext(&(pg->adjList[i]), &vertex))
				printf("%c ", vertex += 65);
		}

		printf("\n");
	}
}