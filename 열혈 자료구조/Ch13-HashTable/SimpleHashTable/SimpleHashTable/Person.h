/*
* �ڷᱸ�� - �ؽ� ���̺� (���̺� + �ؽ�)
* ���ϸ�: Person.h
* ���� ����: 0.1
* �ۼ���: Sevenshards
* �ۼ� ����: 2023-11-29
* ���� ���� �ۼ� ����:
* ���� ����: ������ �ؽ� ���̺� ����
* ���� ���� ����:
*/

#ifndef __PERSON_H__
#define __PERSON_H__

#define STR_LEN 50

typedef struct _person
{
	int ssn; // �ֹε�Ϲ�ȣ (Key)
	char name[STR_LEN]; // �̸� (Value)
	char addr[STR_LEN]; // �ּ� (Value)
} Person;

int GetSSN(Person* p); // ��ü ���� ���� -> ������ �Լ� (Getter)
void ShowPersonInfo(Person* p); // ��ü ���� ���� -> const �Լ�
Person* MakePersonData(int ssn, char* name, char* addr); // ��ü ���� ���� -> ������

#endif