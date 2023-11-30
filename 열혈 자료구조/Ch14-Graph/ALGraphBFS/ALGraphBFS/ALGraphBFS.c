/*
* ���� �ڷᱸ�� - ���� ����Ʈ(Adjacent List) ��� ������ �׷���
* ���ϸ�: ALGraphBFS.c
* ���� ����: 0.3
* �ۼ���: Sevenshards
* �ۼ� ����: 2023-11-30
* ���� ���� �ۼ� ����: 2023-11-30
* ���� ����: �ʺ� �켱 Ž��(Breadth First Search) �߰� ����
* ���� ���� ����: ���� �켱 Ž��(Depth First Search) �߰� ���� (���� ���ϸ�: ALGraphDFS.c)
*/

#include <stdio.h>
#include <stdlib.h>
#include "ALGraphBFS.h"
// ���� ����Ʈ ������� ������ �ϹǷ� ���� ���� ����Ʈ�� ���
#include "SingleLinkedList.h"
// DFS ������ ������ ���
#include "ArrayBaseStack.h"
// BFS ������ ť�� ���
#include "CircularQueue.h"

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
	pg->numVertex = nv; // �Է¹��� nv�� ������ ��
	pg->numEdge = 0; // �ʱ�ȭ�� ������ ���� 0
	pg->adjList = (List*)malloc(sizeof(List) * pg->numVertex); // ������ ����ŭ �޸� �Ҵ�
	pg->visitInfo = (int*)malloc(sizeof(int) * pg->numVertex); // ������ ����ŭ �޸� �Ҵ�
	memset(pg->visitInfo, 0, sizeof(int) * pg->numVertex); // �迭�� ��� ��Ҹ� 0���� �ʱ�ȭ
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
	if (pg->adjList != NULL) // NULL�� �ƴ϶�� �Ҵ��� �� ��Ȳ
		free(pg->adjList); // �Ҵ� ����
	if (pg->visitInfo != NULL) // NULL�� �ƴ϶�� �Ҵ��� �� ��Ȳ
		free(pg->visitInfo); // �Ҵ� ����
}

// ���� �߰�(����)
void AddEdge(ALGraph* pg, int fromV, int toV)
{
	LInsert(&(pg->adjList[fromV]), toV); // from->to
	LInsert(&(pg->adjList[toV]), fromV); // to->from
	pg->numEdge += 1; // ���� ���� �߰�
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

			while (LNext(&(pg->adjList[i]), &vertex))
				printf("%c ", vertex += 65);
		}

		printf("\n");
	}
}

// ������ �湮�� �����ϴ� �Լ�
// �� ��° ���ڷ� ���޵� �̸��� ������ �湮�� ����
int VisitVertex(ALGraph* pg, int visitV)
{
	if (pg->visitInfo[visitV] == 0) // ���� �湮���� �ʾҴٸ�
	{
		pg->visitInfo[visitV] = 1; // �湮�� ������ �ٲ۴�. 0�̸� ���� �ȵ鸥 ��, 1�̸� �鸥��. flag ����
		printf("%c ", visitV + 65); // �湮�� ������ �̸��� ���
		return TRUE; // �湮�� �����Ƿ� TRUE ��ȯ
	}

	return FALSE; // �湮�� �������Ƿ� FALSE ��ȯ
}

// ���� �켱 Ž��(DFS) ��� �׷����� ���� ���� ���
void DFSShowGraphVertex(ALGraph* pg, int startV)
{
	Stack stack; // ��� ������ ������ ����� ����
	int visitV = startV; // ���� �������� �湮�� ������ �ʱ�ȭ
	int nextV; // ������ �湮�� ����

	StackInit(&stack); // ������ �ʱ�ȭ
	VisitVertex(pg, visitV); // ���� ������ �湮
	// ���⼭ ���ÿ� �ִ� �κ��� ��� �ʿ䰡 ����.
	// ī�信�� ������ �亯�� Ȯ���غ� ����� ������ ���Ҵ�.
	// VisitVertex�� SPush�� ���� �̷�� ���� ����, ������ �������� ���� ���̶��.
	// ������ ������� �ϸ� ���ÿ��� ���� ������ �� �� ���� ���� Ȯ�εȴ�.
	// ����� �ּ� ó���ص� ������ ���� �ʴ´�.
	// SPush(&stack, visitV); // ���� ������ ������ ���ÿ� �ִ´�.

	// visitV�� ��� ������ ����� ������ �湮�� �õ��ϱ� ���� �ݺ���
	// ������ �������� '== TRUE' ����, ������ ��ȯ ����� TRUE, FALSE�̱� ������ �ڵ� �б� ���Ϸ��� �ִ°� ����
	while (LFirst(&(pg->adjList[visitV]), &nextV) == TRUE) // ���� ������ ����� ������ �ִٸ�
	{
		// ���� visitV�� ����� ������ ������ nextV�� ��� ����
		int visitFlag = FALSE; // �湮 flag�� FALSE�� �Ѵ�.

		if (VisitVertex(pg, nextV) == TRUE) // ���� ���� �湮�� �����ߴٸ�
		{
			SPush(&stack, visitV); // visitV�� ��� ������ ������ ���ÿ� �ִ´�.
			visitV = nextV; // �׸��� ������ �湮�� ������ ������ ����
			visitFlag = TRUE; // �湮�� ���������Ƿ� TRUE�� ����
		}
		else // �湮�� �������� ���ߴٸ�
		{
			// ������ �������� '== TRUE' ����, ������ ��ȯ ����� TRUE, FALSE�̱� ������ �ڵ� �б� ���Ϸ��� �ִ°� ����
			while (LNext(&(pg->adjList[visitV]), &nextV) == TRUE) // �ٸ� �湮�� ������ ã�´�.
			{
				if (VisitVertex(pg, nextV) == TRUE) // ���� �湮�� �����ߴٸ�
				{
					SPush(&stack, visitV); // visitV�� ��� ������ ������ ���ÿ� �ִ´�.
					visitV = nextV; // �׸��� ������ �湮�� ������ ������ ����
					visitFlag = TRUE; // �湮�� ���������Ƿ� TRUE�� ����
					break; // �湮�� ���������Ƿ� �ݺ� �ߴ�
				}
			}
		}

		if (visitFlag == FALSE) // �߰��� �湮�� ������ �ϳ��� ���ٸ�
		{
			if (SisEmpty(&stack)) // ������ ����ٸ� Ž���� ����� ��
				break;
			else // ������ ����ִ� ���°� �ƴ϶��
				visitV = SPop(&stack); // ������ ��η� ���ư��� ���� ���ÿ��� ������.

		}
	}

	// ���� Ž���� �ٽ� ������ �� �����Ƿ� �迭�� ������ �ʱ�ȭ
	memset(pg->visitInfo, 0, sizeof(int) * pg->numVertex); // �迭�� ��� ��Ҹ� 0���� �ʱ�ȭ
}

// �ʺ� �켱 Ž��(BFS) ��� �׷����� ���� ���� ���
void BFSShowGraphVertex(ALGraph* pg, int startV)
{
	Queue queue; // �湮�� ����(����)�� ����� �������� ť ����
	int visitV = startV; // ���� �������� �湮�� ������ �ʱ�ȭ
	int nextV; // ������ �湮�� ����

	QueueInit(&queue); // ť �ʱ�ȭ
	VisitVertex(pg, visitV); // ���� ���� �湮

	// visitV�� ��� ������ ����� ������ ��� ������ �湮�ϱ� ���� �ݺ���
	// ������ �������� '== TRUE' ����, ������ ��ȯ ����� TRUE, FALSE�̱� ������ �ڵ� �б� ���Ϸ��� �ִ°� ����
	while (LFirst(&(pg->adjList[visitV]), &nextV) == TRUE) // ���� ������ ����� ������ �ִٸ�
	{
		// ���� visitV�� ����� ������ ������ nextV�� ��� ����
		if (VisitVertex(pg, nextV) == TRUE) // ���� ���� �湮�� �����ߴٸ�
			QEnqueue(&queue, nextV); // nextV�� �湮�����Ƿ� ť�� ����
		
		// ������ �������� '== TRUE' ����, ������ ��ȯ ����� TRUE, FALSE�̱� ������ �ڵ� �б� ���Ϸ��� �ִ°� ����
		while (LNext(&(pg->adjList[visitV]), &nextV) == TRUE) // �̾ �湮�� ������ ã�´�.
		{
			if (VisitVertex(pg, nextV) == TRUE) // ���� �湮�� �����ߴٸ�
				QEnqueue(&queue, nextV); // nextV�� �湮�����Ƿ� ť�� ����
		}

		if (QisEmpty(&queue)) // ť�� ����ٸ� Ž���� ����� ��
			break;
		else // ť�� ����ִ� ���°� �ƴ϶��
			visitV = QDequeue(&queue); // ť���� �ϳ� ������ �ϳ� ������ �ٽ� �ݺ��� ����.
	}

	// ���� Ž���� �ٽ� ������ �� �����Ƿ� �迭�� ������ �ʱ�ȭ
	memset(pg->visitInfo, 0, sizeof(int) * pg->numVertex); // �迭�� ��� ��Ҹ� 0���� �ʱ�ȭ
}