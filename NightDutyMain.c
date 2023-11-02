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

	// 리스트 초기화
	List list;
	ListInit(&list);

	// 사원 4명 등록
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

	Employee* WhoIsNightDuty(List * plist, char* name, int day);

	pemp = WhoIsNightDuty(&list, "Lee", 3);
	ShowEmployeeInfo(pemp);

	pemp = WhoIsNightDuty(&list, "Park", 3);
	ShowEmployeeInfo(pemp);

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

Employee* WhoIsNightDuty(List* plist, char* name, int day)
{
	int i, num;
	Employee* ret_emp;

	num = LCount(plist);

	LFirst(plist, &ret_emp);

	if (strcmp(ret_emp->name, name) != 0)
	{
		for (i = 0; i < num - 1; i++)
		{
			LNext(plist, &ret_emp);
			
			if (strcmp(ret_emp->name, name) != 0)
				break;
		}
		if (i >= num - 1)
			return NULL;
	}

	for (i = 0; i < day; i++)
		LNext(plist, &ret_emp);

	return ret_emp;

}
void ShowEmployeeInfo(Employee* emp)
{
	printf("Employee Number: %d\n", emp->empNum);
	printf("Employee Name: %s\n", emp->name);
}