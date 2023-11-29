/*
* �ڷᱸ�� - �ؽ� ���̺� (���̺� + �ؽ�)
* ���ϸ�: ChaninedTableMain.c
* ���� ����: 0.1
* �ۼ���: Sevenshards
* �ۼ� ����: 2023-11-29
* ���� ���� �ۼ� ����:
* ���� ����: �ؽ� �浹 ���� �ذ��� ���� ü�̴� ��� ����
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
	np = MakePersonData(900254, "Lee", "Seoul");
	TBLInsert(&myTbl, GetSSN(np), np);

	np = MakePersonData(900139, "Kim", "Jeju");
	TBLInsert(&myTbl, GetSSN(np), np);

	np = MakePersonData(900827, "Han", "Kangwon");
	TBLInsert(&myTbl, GetSSN(np), np);

	// ������ ��ȸ
	sp = TBLSearch(&myTbl, 900254);
	if (sp != NULL) // NULL�� �ƴ϶�� -> ����� ��ȸ�� �Ǿ��ٸ�
		ShowPersonInfo(sp); // ���� ���
	sp = TBLSearch(&myTbl, 900139);
	if (sp != NULL) // NULL�� �ƴ϶�� -> ����� ��ȸ�� �Ǿ��ٸ�
		ShowPersonInfo(sp); // ���� ���
	sp = TBLSearch(&myTbl, 900827);
	if (sp != NULL) // NULL�� �ƴ϶�� -> ����� ��ȸ�� �Ǿ��ٸ�
		ShowPersonInfo(sp); // ���� ���

	// ������ ����
	rp = TBLDelete(&myTbl, 900254);
	if (rp != NULL) // NULL�� �ƴ϶�� -> ��ȯ�� �Ǿ��ٸ�
		free(rp); // �޸� �Ҵ� ����
	rp = TBLDelete(&myTbl, 900139);
	if (rp != NULL) // NULL�� �ƴ϶�� -> ��ȯ�� �Ǿ��ٸ�
		free(rp); // �޸� �Ҵ� ����
	rp = TBLDelete(&myTbl, 900827);
	if (rp != NULL) // NULL�� �ƴ϶�� -> ��ȯ�� �Ǿ��ٸ�
		free(rp); // �޸� �Ҵ� ����
	return 0;
}