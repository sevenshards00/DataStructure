/*
* �ڷᱸ�� - �ؽ� ���̺� (���̺� + �ؽ�)
* ���ϸ�: Table.h
* ���� ����: 0.2
* �ۼ���: Sevenshards
* �ۼ� ����: 2023-11-29
* ���� ���� �ۼ� ����: 2023-11-29
* ���� ����: �ؽ� �浹 ���� �ذ��� ���� ü�̴� ��� ����
* ���� ���� ����: ������ �ؽ� ���̺� ����
*/

#ifndef __TABLE_H__
#define __TABLE_H__

#include "Slot.h"
#include "SingleLinkedList.h"

#define MAX_TBL 100

typedef int HashFunc(Key k); // �Լ� �����ͷ� ���� ����(HashFunc) typedef ����

// ���̺� ����ü
typedef struct _table
{
	List tbl[MAX_TBL];
	HashFunc* hf;
} Table;

// �ʱ�ȭ
void TableInit(Table* pt, HashFunc* pf);

// Ű�� ���� ����
void TBLInsert(Table* pt, Key k, Value v);

// Ű�� �ٰŷ� ���̺��� ������ ����
Value TBLDelete(Table* pt, Key k);
// Ű�� �ٰŷ� ���̺��� ������ ��ȸ
Value TBLSearch(Table* pt, Key k);

#endif