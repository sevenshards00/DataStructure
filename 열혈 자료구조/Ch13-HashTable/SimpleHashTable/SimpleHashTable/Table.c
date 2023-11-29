/*
* �ڷᱸ�� - �ؽ� ���̺� (���̺� + �ؽ�)
* ���ϸ�: Table.c
* ���� ����: 0.1
* �ۼ���: Sevenshards
* �ۼ� ����: 2023-11-29
* ���� ���� �ۼ� ����:
* ���� ����: ������ �ؽ� ���̺� ����
* ���� ���� ����:
*/

#include <stdio.h>
#include <stdlib.h>
#include "Table.h"

// �ʱ�ȭ
void TBLInit(Table* pt, HashFunc* pf)
{
	int i;

	// ��� ���� �ʱ�ȭ
	for (i = 0; i < MAX_TBL; i++)
		(pt->tbl[i]).status = EMPTY;

	// �ؽ� �Լ� ���
	pt->hf = pf;
}

// Ű�� ���� ����
void TBLInsert(Table* pt, Key k, Value v)
{
	int hv = pt->hf(k); // �ؽ� �Լ��� ���� ������ �ؽ� ��
	pt->tbl[hv].val = v;
	pt->tbl[hv].key = k;
	pt->tbl[hv].status = INUSE;
}

// Ű�� �ٰŷ� ���̺��� ������ ����
Value TBLDelete(Table* pt, Key k)
{
	int hv = pt->hf(k); // �ؽ� �Լ��� ���� ������ �ؽ� ��

	if ((pt->tbl[hv]).status != INUSE) // ������ INUSE�� �ƴ϶��
		return NULL; // ã�� ����
	else
	{
		(pt->tbl[hv]).status = DELETED; // DELETED�� ����
		return (pt->tbl[hv]).val; // ���� ��� �� ��ȯ
	}
}
// Ű�� �ٰŷ� ���̺��� ������ ��ȸ
Value TBLSearch(Table* pt, Key k)
{
	int hv = pt->hf(k); // �ؽ� �Լ��� ���� ������ �ؽ� ��

	if ((pt->tbl[hv]).status != INUSE) // ������ INUSE�� �ƴ϶��
		return NULL; // ã�� ����
	else
		return (pt->tbl[hv]).val; // ��ȸ ��� �� ��ȯ
}