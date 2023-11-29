/*
* �ڷᱸ�� - �ؽ� ���̺� (���̺� + �ؽ�)
* ���ϸ�: Person.c
* ���� ����: 0.1
* �ۼ���: Sevenshards
* �ۼ� ����: 2023-11-29
* ���� ���� �ۼ� ����:
* ���� ����: ������ �ؽ� ���̺� ����
* ���� ���� ����:
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Person.h"

int GetSSN(Person* p) // ��ü ���� ���� -> ������ �Լ� (Getter)
{
	return p->ssn;
}
void ShowPersonInfo(Person* p) // ��ü ���� ���� -> const �Լ�
{
	printf("�ֹε�Ϲ�ȣ: %d\n", p->ssn);
	printf("�̸�: %s\n", p->name);
	printf("�ּ�: %s\n", p->addr);
}
Person* MakePersonData(int ssn, char* name, char* addr) // ��ü ���� ���� -> ������
{
	Person* newP = (Person*)malloc(sizeof(Person));
	newP->ssn = ssn;
	strcpy(newP->name, name);
	strcpy(newP->addr, addr);
	return newP;
}