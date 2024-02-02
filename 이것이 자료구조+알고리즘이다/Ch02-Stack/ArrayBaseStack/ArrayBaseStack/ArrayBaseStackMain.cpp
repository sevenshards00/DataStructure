/*
* 이것이 자료구조+알고리즘이다 - 스택(Stack)
* 파일명: ArrayBaseStackMain.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-02-02
* 이전 버전 작성 일자:
* 버전 내용: 배열 기반 스택 구현(C++, Template)
* 이전 버전 내용:
*/

#include "ArrayBaseStack.h"

int _tmain(int argc, TCHAR *argv[])
{
	Stack<INT> intStack(10);
	Stack<TCHAR> tcharStack(10);

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