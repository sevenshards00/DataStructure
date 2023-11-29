/*
* �ڷᱸ�� - �ؽ� ���̺� (���̺� + �ؽ�)
* ���ϸ�: Slot.h
* ���� ����: 0.1
* �ۼ���: Sevenshards
* �ۼ� ����: 2023-11-29
* ���� ���� �ۼ� ����:
* ���� ����: ������ �ؽ� ���̺� ����
* ���� ���� ����:
*/

#ifndef __SLOT_H__
#define __SLOT_H__

#include "Person.h"

typedef int Key; // �ֹε�Ϲ�ȣ�� ���������� int, �׸��� int���� Key��
typedef Person* Value; // Person�� ����ü ������ ������ Value��

enum SlotStatus {EMPTY, DELETED, INUSE};

// ���̺� ������ ����(Slot)
typedef struct _slot
{
	Key key; // Key
	Value val; // Value
	enum Slotstatus status;
} Slot;
#endif