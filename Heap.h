/*
* ���� �ڷᱸ�� - �迭 ����� ��(Heap)
* ���ϸ�: Heap.h
* ���� ����: 0.1
* �ۼ���: Sevenshards
* �ۼ� ����: 2023-11-24
* ���� ���� �ۼ� ����:
* ���� ����: ������ ���� ����
* ���� ���� ����:
*/

#ifndef __HEAP_H__
#define __HEAP_H__

#define TRUE 1
#define FALSE 0

#define HEAP_LEN 100

typedef char HData; // ���� ����� �����͸� HData��� ��Ī
typedef int Priority; // ������ ���� �켱 ����

// ������ ���� ���� ���(Element) ����ü ����
typedef struct _heapelement
{
	Priority pr;
	HData data;
} HeapElem;

// �� ����ü ����
typedef struct _heap
{
	int numOfData; // ���� ������ ����
	HeapElem heapArr[HEAP_LEN];
} Heap;

void HeapInit(Heap* ph); // ���� �ʱ�ȭ
int HisEmpty(Heap* ph); // ���� ������� Ȯ��

void HInsert(Heap* ph, HData data, Priority pr); // ���� ������ ����
HData HDelete(Heap* ph); // ���� ������ ����

#endif