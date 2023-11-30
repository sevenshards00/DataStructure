/*
* ���� �ڷᱸ�� - �迭 ����� ��(Heap)
* ���ϸ�: Heap.h
* ���� ����: 0.2
* �ۼ���: Sevenshards
* �ۼ� ����: 2023-11-24
* ���� ���� �ۼ� ����: 2023-11-24
* ���� ����: �켱 ���� �Ǵ� ������ ���� ������ �� �ֵ��� �Լ� �����ͷ� ����
* ���� ���� ����: ������ ���� ����
*/

#ifndef __HEAP_H__
#define __HEAP_H__

#define TRUE 1
#define FALSE 0

#define HEAP_LEN 100

#include "ALEdge.h"

typedef Edge HData; // ���� ����� �����͸� HData��� ��Ī
typedef int PriorityComp(HData d1, HData d2); // ������ ���� �켱 ����

// �� ����ü ����
typedef struct _heap
{
	PriorityComp* comp; // �켱 ���� ������ �Ǵ��� �Լ� ������ ���� ����
	int numOfData; // ���� ������ ����
	HData heapArr[HEAP_LEN]; // �迭 ����� ��
} Heap;

void HeapInit(Heap* ph, PriorityComp pc); // ���� �ʱ�ȭ
int HisEmpty(Heap* ph); // ���� ������� Ȯ��

void HInsert(Heap* ph, HData data); // ���� ������ ����
HData HDelete(Heap* ph); // ���� ������ ����

#endif