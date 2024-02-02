/*
* 이것이 자료구조+알고리즘이다 - 리스트(List) - 환형 이중 연결 리스트
* 파일명: CircularDoublyLinkedListMain.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-02-02
* 이전 버전 작성 일자:
* 버전 내용: 환형 이중 연결 리스트 구현(C++, Template)
* 이전 버전 내용:
*/

#include "CircularDoublyLinkedList.h"

int _tmain(int argc, TCHAR *argv[])
{
	List<INT> intList;

	intList.push_front(2);
	intList.push_front(1);
	intList.push_back(4);
	intList.push_back(5);
	intList.insert(1, 3);

	INT output;
	for (int i = 0; i != intList.count(); ++i)
	{
		intList.getNodeForward(i, output);
		_tprintf(TEXT("%d "), output);
	}
	_tprintf(TEXT("\n"));

	for (int i = 0; i != intList.count(); ++i)
	{
		intList.getNodeReverse(i, output);
		_tprintf(TEXT("%d "), output);
	}
	_tprintf(TEXT("\n"));

	_tprintf(TEXT("Count: %d \n"), intList.count());
	_tprintf(TEXT("\n"));

	intList.pop_front(output);
	_tprintf(TEXT("Pop front: %d \n"), output);
	_tprintf(TEXT("Count: %d \n"), intList.count());

	intList.pop_back(output);
	_tprintf(TEXT("Pop back: %d \n"), output);
	_tprintf(TEXT("Count: %d \n"), intList.count());

	intList.erase(1, output);
	_tprintf(TEXT("erase: %d \n"), output);
	_tprintf(TEXT("Count: %d \n"), intList.count());

	for (int i = 0; i != intList.count(); ++i)
	{
		intList.getNodeForward(i, output);
		_tprintf(TEXT("%d "), output);
	}
	_tprintf(TEXT("\n"));

	for (int i = 0; i != intList.count(); ++i)
	{
		intList.getNodeReverse(i, output);
		_tprintf(TEXT("%d "), output);
	}
	_tprintf(TEXT("\n"));

	return 0;
}