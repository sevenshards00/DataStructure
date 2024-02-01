/*
* 이것이 자료구조+알고리즘이다 - 리스트(List) - 단일 연결 리스트
* 파일명: SingleLinkedListMain.cpp
* 파일 버전: 0.3
* 작성자: Sevenshards
* 작성 일자: 2024-02-01
* 이전 버전 작성 일자: 2024-01-31
* 버전 내용: STL의 forward_list 흉내내기 (프로토타입 완성)
* 이전 버전 내용: STL의 forward_list 흉내내기 - 클래스명 변경 및 내부 구현 변경 (미완)
*/

#include "SingleLinkedList.h"

int _tmain(int argc, TCHAR *argv[])
{
	ForwardList<INT> intList;

	intList.push_front(1);
	intList.push_front(2);
	intList.push_front(5);
	intList.insert_after(intList.begin(), 3);
	intList.insert_after(intList.begin(), 4);

	DWORD i = 0;
	Node<INT> *intList_begin = intList.begin();
	Node<INT> *intList_end = intList.end();

	_tprintf(TEXT("begin: %d\n"), intList_begin->data);
	_tprintf(TEXT("end: %d\n"), intList_end->data);

	for(i = 0; i != intList.Count(); ++i)
	{
		_tprintf(TEXT("%d "), intList_begin -> data);
		intList_begin = intList_begin->next;
	}

	_tprintf(TEXT("\n"));

	INT nodeData;

	intList.pop_front(&nodeData);
	_tprintf(TEXT("Remove Data: %d\n"), nodeData);
	intList.erase_after(intList.begin(), &nodeData);
	_tprintf(TEXT("Remove Data: %d\n"), nodeData);


	intList_begin = intList.begin();

	for (i = 0; i != intList.Count(); ++i)
	{
		_tprintf(TEXT("%d "), intList_begin->data);
		intList_begin = intList_begin->next;
	}

	_tprintf(TEXT("\n"));
	_tprintf(TEXT("Node Count: %d\n"), intList.Count());

	return 0;
}