/*
* 이것이 자료구조+알고리즘이다 - 스택(Stack)
* 파일명: ListBaseStack.h
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-02-05
* 이전 버전 작성 일자:
* 버전 내용: 연결 리스트 기반 스택 구현(C++, Template)
* 이전 버전 내용:
*/

#include "ListBaseStack.h"

int _tmain(int argc, TCHAR *argv[])
{
	Stack<INT> intStack;
	Stack<TCHAR> tcharStack;

	for (int i = 0; i != 10; ++i)
		intStack.push(i);

	for (int i = 0; i != 10; ++i)
		tcharStack.push(TEXT('A') + i);

	INT idata;
	TCHAR tdata;

	for (int i = 0; i != 10; ++i)
	{
		intStack.peek(idata);
		_tprintf(TEXT("peek: %d\n"), idata);

		intStack.pop(idata);
		_tprintf(TEXT("pop: %d\n"), idata);
	}

	_tprintf(TEXT("\n\n"));

	for (int i = 0; i != 10; ++i)
	{
		tcharStack.peek(tdata);
		_tprintf(TEXT("peek: %c\n"), tdata);

		tcharStack.pop(tdata);
		_tprintf(TEXT("pop: %c\n"), tdata);
	}

	return 0;
}