/*
* �ڷᱸ�� - �ؽ� ���̺� (���̺� + �ؽ�)
* ���ϸ�: SimpleHashMain.c
* ���� ����: 0.1
* �ۼ���: Sevenshards
* �ۼ� ����: 2023-11-29
* ���� ���� �ۼ� ����:
* ���� ����: ������ �ؽ� ���̺� ����
* ���� ���� ����:
*/

#include <stdio.h>
#include <stdlib.h>
#include "Person.h"
#include "Table.h"

// ����� ���� �ؽ� �Լ�
int MyHashFunc(int k)
{
	return k % 100;
}

int main()
{
	Table myTbl;
	Person* np;
	Person* sp;
	Person* rp;

	TBLInit(&myTbl, MyHashFunc);

	// ������ �Է�
	np = MakePersonData(20120003, "Lee", "Seoul");
	TBLInsert(&myTbl, GetSSN(np), np);

	np = MakePersonData(20130012, "Kim", "Jeju");
	TBLInsert(&myTbl, GetSSN(np), np);

	np = MakePersonData(20170049, "Han", "Kangwon");
	TBLInsert(&myTbl, GetSSN(np), np);

	// ������ ��ȸ
	sp = TBLSearch(&myTbl, 20120003);
	if (sp != NULL) // NULL�� �ƴ϶�� -> ����� ��ȸ�� �Ǿ��ٸ�
		ShowPersonInfo(sp); // ���� ���
	sp = TBLSearch(&myTbl, 20130012);
	if (sp != NULL) // NULL�� �ƴ϶�� -> ����� ��ȸ�� �Ǿ��ٸ�
		ShowPersonInfo(sp); // ���� ���
	sp = TBLSearch(&myTbl, 20170049);
	if (sp != NULL) // NULL�� �ƴ϶�� -> ����� ��ȸ�� �Ǿ��ٸ�
		ShowPersonInfo(sp); // ���� ���

	// ������ ����
	rp = TBLDelete(&myTbl, 20120003);
	if (rp != NULL) // NULL�� �ƴ϶�� -> ��ȯ�� �Ǿ��ٸ�
		free(rp); // �޸� �Ҵ� ����
	rp = TBLDelete(&myTbl, 20130012);
	if (rp != NULL) // NULL�� �ƴ϶�� -> ��ȯ�� �Ǿ��ٸ�
		free(rp); // �޸� �Ҵ� ����
	rp = TBLDelete(&myTbl, 20170049);
	if (rp != NULL) // NULL�� �ƴ϶�� -> ��ȯ�� �Ǿ��ٸ�
		free(rp); // �޸� �Ҵ� ����
	return 0;
}