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
	// 문자열 복사는 반드시 strcpy!
	// 대입해서 넣는 병신짓 하지 말자 제발
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

	// 야근 순번을 물어보는 부분
	// 첫 번째는 Lee의 3일 후 당직은 누구인가
	// 두 번째는 Park의 15일 후 야근 당직은 누구인가를 확인
	//
	pemp = WhoIsNightDuty(&list, "Lee", 3);
	ShowEmployeeInfo(pemp);

	pemp = WhoIsNightDuty(&list, "Park", 15);
	ShowEmployeeInfo(pemp);

	// 하나씩 메모리를 해제
	// 이 부분도 기억해둬야 하는 것이, 맨 처음부터 하나하나 반복해서 메모리를 지워준다.
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

// 사실 여기가 좀 생각하기 귀찮아서 따라 친 부분이다.
// 솔직하게 말하면 진짜 생각하기 귀찮았다.
// 그리고 내가 했던 큰 실수가 있다.
// 매개변수로는 리스트 포인터 변수로 받았기 때문에 굳이 &plist를 할 필요가 없었다.
// plist 자체가 이미 주소값이니까.
// 근데 거기서 또 &를 붙이면? 포인터변수 plist의 주소값이 나오지 plist가 가지고 있는 주소값이 나오는게 아니다
// 정신 차리자 진짜
//
Employee* WhoIsNightDuty(List* plist, char* name, int day)
{
	int i, num;
	// LFirst에 의해 참조하는 값을 받기 위해 Employee 구조체 포인터 변수 사용
	// 구조체 포인터 변수를 쓰는 이유는? 리스트에 구조체의 주소가 있고 그걸 역참조해서 접근하면 되니까.
	// ret_emp->멤버 같은 방법으로.
	//
	Employee* ret_emp;

	// 여기서는 리스트의 데이터 수를 반환.
	// 당연히 4가 나올거다.
	num = LCount(plist);

	// 여기서부터 문자열 비교를 위한 시작
	// 맨 처음 리스트의 데이터를 참조하고, 사원의 정보를 가지고 있는 구조체의 주소를 받아온다.
	//
	LFirst(plist, &ret_emp);

	// 그리고 맨 처음 사원의 이름과 입력받은 이름을 비교
	// 여기서 strcmp는 같은 값이면 0을 반환한다.
	// 따라서 0이 아니라면? 같은 이름이 아니라는 것
	//
	if (strcmp(ret_emp->name, name) != 0)
	{
		// 이후 반복을 통해 리스트의 첫 번째 이후 노드에 하나씩 접근하여 이름을 비교한다.
		//
		for (i = 0; i < num - 1; i++)
		{
			LNext(plist, &ret_emp);
			
			// 여기서도 마찬가지로 이름을 비교한다.
			// 같은 이름이 있다면 이 반복문을 수행하지 않을 것이고
			//
			if (strcmp(ret_emp->name, name) != 0)
				break;
		}
		// 일치하는 이름이 없다면?
		// NULL을 반환하면서 함수를 빠져나온다.
		//
		if (i >= num - 1)
			return NULL;
	}

	// 이름을 찾았다면 다음은 날짜를 계산한다.
	// 여기서 원형 링크드 리스트이기 때문에 굳이 LFirst를 할 필요가 없어진다.
	// 그 이름을 찾은 커서 시점 이후부터 그 날짜까지 쭉 검색을 하고
	//
	for (i = 0; i < day; i++)
		LNext(plist, &ret_emp);

	// 현재 참조하고 있는 데이터 값을 반환해주면 된다.
	return ret_emp;

}

// 여기서도 마찬가지로 매개변수는 구조체 포인터 변수를 사용해서 받는다.
// emp->멤버 식으로 접근이 가능.
//
void ShowEmployeeInfo(Employee* emp)
{
	printf("Employee Number: %d\n", emp->empNum);
	printf("Employee Name: %s\n", emp->name);
}