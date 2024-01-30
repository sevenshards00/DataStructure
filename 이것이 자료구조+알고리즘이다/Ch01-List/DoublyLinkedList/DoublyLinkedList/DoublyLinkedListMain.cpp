/*
* 이것이 자료구조+알고리즘이다 - 리스트(List) - 이중 연결 리스트
* 파일명: DoublyLinkedListMain.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-01-30
* 이전 버전 작성 일자:
* 버전 내용: 이중 연결 리스트 구현
* 이전 버전 내용:
*/

#include "DoublyLinkedList.h"

int _tmain(int argc, TCHAR *argv[])
{
	DoublyLinkedList<INT> DLLInt;

	DLLInt.AppendFront(3);
	DLLInt.AppendFront(2);
	DLLInt.AppendFront(1);
	DLLInt.AppendRear(5);
	DLLInt.AppendRear(6);
	DLLInt.InsertNode(2, 4);

	DWORD i = 0;
	INT nodeData;
	while (true)
	{
		DLLInt.SearchNodeForward(i, &nodeData);
		_tprintf(TEXT("Forward: %d\n"), nodeData);

		DLLInt.SearchNodeReverse(i, &nodeData);
		_tprintf(TEXT("Reverse: %d\n"), nodeData);

		if (i++ == DLLInt.Count())
			break;
	}

	_tprintf(TEXT("\n"));

	DLLInt.DestroyNode(2, &nodeData);
	_tprintf(TEXT("Remove Data: %d\n"), nodeData);


	i = 0;
	while (true)
	{
		DLLInt.SearchNodeForward(i, &nodeData);
		_tprintf(TEXT("Forward: %d\n"), nodeData);

		DLLInt.SearchNodeReverse(i, &nodeData);
		_tprintf(TEXT("Reverse: %d\n"), nodeData);

		if (i++ == DLLInt.Count())
			break;
	}

	DLLInt.Count();

	return 0;
}