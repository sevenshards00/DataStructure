/*
* �ڷᱸ�� - �ؽ� ���̺� (���̺� + �ؽ�)
* ���ϸ�: Slot.h
* ���� ����: 0.2
* �ۼ���: Sevenshards
* �ۼ� ����: 2023-11-29
* ���� ���� �ۼ� ����: 2023-11-29
* ���� ����: �ؽ� �浹 ���� �ذ��� ���� ü�̴� ��� ����
* ���� ���� ����: ������ �ؽ� ���̺� ����
*/

#ifndef __SLOT_H__
#define __SLOT_H__

#include "Person.h"

typedef int Key; // �ֹε�Ϲ�ȣ�� ���������� int, �׸��� int���� Key��
typedef Person* Value; // Person�� ����ü ������ ������ Value��


// ���̺� ������ ����(Slot)
typedef struct _slot
{
	Key key; // Key
	Value val; // Value
} Slot;
#endif