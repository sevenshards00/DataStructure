/*
* �ڷᱸ�� - �ؽ� ���̺� (���̺� + �ؽ�)
* ���ϸ�: UnderstandTable.c
* ���� ����: 0.1
* �ۼ���: Sevenshards
* �ۼ� ����: 2023-11-29
* ���� ���� �ۼ� ����:
* ���� ����: ���̺� �ڷᱸ���� ���� ���ظ� ���� �ڵ�
* ���� ���� ����:
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

typedef struct _empInfo
{
	int empNum; // ��� ��ȣ
	int age; // ����
} EmpInfo;

int main()
{
	EmpInfo empInfoArr[100];
	EmpInfo ei;
	int eNum;

	// ������ ����
	printf("����� ���� �Է�: ");
	scanf("%d %d", &(ei.empNum), &(ei.age));
	empInfoArr[ei.empNum] = ei;

	// ������ ��ȸ
	printf("Ȯ���� ����� ��� �Է�: ");
	scanf("%d", &eNum);

	ei = empInfoArr[eNum];
	printf("���: %d, ����: %d\n", ei.empNum, ei.age);
	return 0;
}