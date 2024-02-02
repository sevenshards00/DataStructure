/*
* 이것이 자료구조+알고리즘이다 - 리스트(List) - 단일 연결 리스트
* 파일명: SingleLinkedListMain.cpp
* 파일 버전: 0.4
* 작성자: Sevenshards
* 작성 일자: 2024-02-01
* 이전 버전 작성 일자: 2024-02-01
* 버전 내용: 단일 연결 리스트 다시 구현
* 이전 버전 내용: STL의 forward_list 흉내내기 - 클래스명 변경 및 내부 구현 변경 (미완)
*/

#include "SingleLinkedList.h"

int _tmain(int argc, TCHAR *argv[])
{
	ForwardList<INT> intList;

	intList.push_front(2);
	intList.push_front(1);
	intList.push_back(5);
	intList.insert_after(1, 3);
	intList.insert_after(2, 4);

	INT i;
	intList.search(0, i);
	_tprintf(TEXT("begin: %d\n"), i);
	intList.search(4, i);
	_tprintf(TEXT("end: %d\n"), i);

	for (i = 0; i != intList.count(); ++i)
	{
		INT outData;
		intList.search(i, outData);
		_tprintf(TEXT("%d "), outData);
	}

	_tprintf(TEXT("\n"));

	INT nodeData;

	intList.pop_front(nodeData);
	_tprintf(TEXT("Remove Data: %d\n"), nodeData);
	intList.remove(1, nodeData);
	_tprintf(TEXT("Remove Data: %d\n"), nodeData);

	for (i = 0; i != intList.count(); ++i)
	{
		INT outData;
		intList.search(i, outData);
		_tprintf(TEXT("%d "), outData);
	}

	_tprintf(TEXT("\n"));
	_tprintf(TEXT("Node Count: %d\n"), intList.count());
	return 0;
}