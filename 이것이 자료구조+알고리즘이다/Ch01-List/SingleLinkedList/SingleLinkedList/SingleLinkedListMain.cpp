/*
* 이것이 자료구조+알고리즘이다 - 리스트(List) - 단일 연결 리스트
* 파일명: SingleLinkedList.h
* 파일 버전: 0.2
* 작성자: Sevenshards
* 작성 일자: 2024-01-31
* 이전 버전 작성 일자: 2024-01-29
* 버전 내용: STL의 forward_list 흉내내기 - 클래스명 변경 및 내부 구현 변경 (미완)
* 이전 버전 내용: 단일 연결 리스트 구현
*/

#include "SingleLinkedList.h"

int _tmain(int argc, TCHAR *argv[])
{
	SingleLinkedList<INT> listInt;

	listInt.AppendFront(3);
	listInt.AppendFront(2);
	listInt.AppendFront(1);
	listInt.AppendBack(5);
	listInt.AppendBack(6);
	listInt.InsertNode(2, 4);

	DWORD i = 0;
	INT nodeData;
	while (true)
	{
		listInt.SearchNode(i++, &nodeData);
		_tprintf(TEXT("%d "), nodeData);
		
		if (i == listInt.Count())
			break;
	}

	_tprintf(TEXT("\n"));

	listInt.DestroyNode(2, &nodeData);
	_tprintf(TEXT("Remove Data: %d\n"), nodeData);


	i = 0;
	while (true)
	{
		listInt.SearchNode(i++, &nodeData);
		_tprintf(TEXT("%d "), nodeData);

		if (i == listInt.Count())
			break;
	}

	listInt.Count();

	return 0;
}