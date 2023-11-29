/*
* �ڷᱸ�� - �ؽ� ���̺� (���̺� + �ؽ�)
* ���ϸ�: Table.c
* ���� ����: 0.2
* �ۼ���: Sevenshards
* �ۼ� ����: 2023-11-29
* ���� ���� �ۼ� ����: 2023-11-29
* ���� ����: �ؽ� �浹 ���� �ذ��� ���� ü�̴� ��� ����
* ���� ���� ����: ������ �ؽ� ���̺� ����
*/

#include <stdio.h>
#include <stdlib.h>
#include "Table.h"
#include "SingleLinkedList.h"

// �ʱ�ȭ
void TBLInit(Table* pt, HashFunc* pf)
{
	int i;

	// ��� ���� �ʱ�ȭ
	for (i = 0; i < MAX_TBL; i++)
		ListInit(&(pt->tbl[i]));

	// �ؽ� �Լ� ���
	pt->hf = pf;
}

// Ű�� ���� ����
void TBLInsert(Table* pt, Key k, Value v)
{
	int hv = pt->hf(k); // �ؽ� �Լ��� ���� ������ �ؽ� ��
	Slot newSlot = { k, v };

	if (TBLSearch(pt, k) != NULL) // Ű�� �ߺ��ȴٸ�
	{
		printf("Ű �ߺ�\n");
		return;
	}
	else
		LInsert(&(pt->tbl[hv]), newSlot);
}

// Ű�� �ٰŷ� ���̺��� ������ ����
Value TBLDelete(Table* pt, Key k)
{
	int hv = pt->hf(k); // �ؽ� �Լ��� ���� ������ �ؽ� ��
	Slot cSlot;

	if (LFirst(&(pt->tbl[hv]), &cSlot)) // ���� ����Ʈ�� �� ù��° ��� ��ȸ
	{
		if (cSlot.key == k) // Ű�� ���ٸ�
		{
			LRemove(&(pt->tbl[hv])); // ��� ����
			return cSlot.val;
		}
		else // �ƴ϶��
		{
			while (LNext(&(pt->tbl[hv]), &cSlot)) // ù ��° ���� ��带 ��ȸ
			{
				if (cSlot.key == k) // Ű�� ���ٸ�
				{
					LRemove(&(pt->tbl[hv])); // ��� ����
					return cSlot.val;
				}
			}
		}
	}

	return NULL; // ������ ���ߴٸ� NULL ��ȯ
}
// Ű�� �ٰŷ� ���̺��� ������ ��ȸ
Value TBLSearch(Table* pt, Key k)
{
	int hv = pt->hf(k); // �ؽ� �Լ��� ���� ������ �ؽ� ��
	Slot cSlot;

	if (LFirst(&(pt->tbl[hv]), &cSlot)) // ���� ����Ʈ�� �� ù��° ��� ��ȸ
	{
		if (cSlot.key == k) // Ű�� ���ٸ�
			return cSlot.val;
		else // �ƴ϶��
		{
			while (LNext(&(pt->tbl[hv]), &cSlot)) // ù ��° ���� ��带 ��ȸ
			{
				if (cSlot.key == k) // Ű�� ���ٸ�
					return cSlot.val;
			}
		}
	}

	return NULL; // ��ã�Ҵٸ� NULL ��ȯ
}