#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CLinkedList.h"
#include "Employee.h"

Employee* WhoIsNightDuty(List* plist, char* name, int day);
void ShowEmployeeInfo(Employee* emp);

int main()
{
	int i;
	Employee* pemp;

	// ����Ʈ �ʱ�ȭ
	List list;
	ListInit(&list);

	// ��� 4�� ���
	// ���ڿ� ����� �ݵ�� strcpy!
	// �����ؼ� �ִ� ������ ���� ���� ����
	pemp = (Employee*)malloc(sizeof(Employee));
	pemp->empNum = 111111;
	strcpy(pemp->name,"Lee");
	LInsert(&list, pemp);

	pemp = (Employee*)malloc(sizeof(Employee));
	pemp->empNum = 222222;
	strcpy(pemp->name, "Kim");
	LInsert(&list, pemp);

	pemp = (Employee*)malloc(sizeof(Employee));
	pemp->empNum = 333333;
	strcpy(pemp->name, "Park");
	LInsert(&list, pemp);

	pemp = (Employee*)malloc(sizeof(Employee));
	pemp->empNum = 444444;
	strcpy(pemp->name, "Choi");
	LInsert(&list, pemp);

	// �߱� ������ ����� �κ�
	// ù ��°�� Lee�� 3�� �� ������ �����ΰ�
	// �� ��°�� Park�� 15�� �� �߱� ������ �����ΰ��� Ȯ��
	//
	pemp = WhoIsNightDuty(&list, "Lee", 3);
	ShowEmployeeInfo(pemp);

	pemp = WhoIsNightDuty(&list, "Park", 15);
	ShowEmployeeInfo(pemp);

	// �ϳ��� �޸𸮸� ����
	// �� �κе� ����ص־� �ϴ� ����, �� ó������ �ϳ��ϳ� �ݺ��ؼ� �޸𸮸� �����ش�.
	//
	if (LFirst(&list, &pemp))
	{
		free(pemp);

		for (i = 0; i < LCount(&list) - 1; i++)
		{
			if(LNext(&list, &pemp))
				free(pemp);
		}
			
	}

	return 0;
}

// ��� ���Ⱑ �� �����ϱ� �����Ƽ� ���� ģ �κ��̴�.
// �����ϰ� ���ϸ� ��¥ �����ϱ� �����Ҵ�.
// �׸��� ���� �ߴ� ū �Ǽ��� �ִ�.
// �Ű������δ� ����Ʈ ������ ������ �޾ұ� ������ ���� &plist�� �� �ʿ䰡 ������.
// plist ��ü�� �̹� �ּҰ��̴ϱ�.
// �ٵ� �ű⼭ �� &�� ���̸�? �����ͺ��� plist�� �ּҰ��� ������ plist�� ������ �ִ� �ּҰ��� �����°� �ƴϴ�
// ���� ������ ��¥
//
Employee* WhoIsNightDuty(List* plist, char* name, int day)
{
	int i, num;
	// LFirst�� ���� �����ϴ� ���� �ޱ� ���� Employee ����ü ������ ���� ���
	// ����ü ������ ������ ���� ������? ����Ʈ�� ����ü�� �ּҰ� �ְ� �װ� �������ؼ� �����ϸ� �Ǵϱ�.
	// ret_emp->��� ���� �������.
	//
	Employee* ret_emp;

	// ���⼭�� ����Ʈ�� ������ ���� ��ȯ.
	// �翬�� 4�� ���ðŴ�.
	num = LCount(plist);

	// ���⼭���� ���ڿ� �񱳸� ���� ����
	// �� ó�� ����Ʈ�� �����͸� �����ϰ�, ����� ������ ������ �ִ� ����ü�� �ּҸ� �޾ƿ´�.
	//
	LFirst(plist, &ret_emp);

	// �׸��� �� ó�� ����� �̸��� �Է¹��� �̸��� ��
	// ���⼭ strcmp�� ���� ���̸� 0�� ��ȯ�Ѵ�.
	// ���� 0�� �ƴ϶��? ���� �̸��� �ƴ϶�� ��
	//
	if (strcmp(ret_emp->name, name) != 0)
	{
		// ���� �ݺ��� ���� ����Ʈ�� ù ��° ���� ��忡 �ϳ��� �����Ͽ� �̸��� ���Ѵ�.
		//
		for (i = 0; i < num - 1; i++)
		{
			LNext(plist, &ret_emp);
			
			// ���⼭�� ���������� �̸��� ���Ѵ�.
			// ���� �̸��� �ִٸ� �� �ݺ����� �������� ���� ���̰�
			//
			if (strcmp(ret_emp->name, name) != 0)
				break;
		}
		// ��ġ�ϴ� �̸��� ���ٸ�?
		// NULL�� ��ȯ�ϸ鼭 �Լ��� �������´�.
		//
		if (i >= num - 1)
			return NULL;
	}

	// �̸��� ã�Ҵٸ� ������ ��¥�� ����Ѵ�.
	// ���⼭ ���� ��ũ�� ����Ʈ�̱� ������ ���� LFirst�� �� �ʿ䰡 ��������.
	// �� �̸��� ã�� Ŀ�� ���� ���ĺ��� �� ��¥���� �� �˻��� �ϰ�
	//
	for (i = 0; i < day; i++)
		LNext(plist, &ret_emp);

	// ���� �����ϰ� �ִ� ������ ���� ��ȯ���ָ� �ȴ�.
	return ret_emp;

}

// ���⼭�� ���������� �Ű������� ����ü ������ ������ ����ؼ� �޴´�.
// emp->��� ������ ������ ����.
//
void ShowEmployeeInfo(Employee* emp)
{
	printf("Employee Number: %d\n", emp->empNum);
	printf("Employee Name: %s\n", emp->name);
}