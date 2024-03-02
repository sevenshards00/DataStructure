/*
* 이것이 자료구조+알고리즘이다 - 큐(Queue)
* 파일명: Main.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-03-02
* 이전 버전 작성 일자:
* 버전 내용: 리스트 기반 큐 구현(C++, Template)
* 이전 버전 내용:
*/

#include <Windows.h>
#include <tchar.h>
#include <iostream>
using std::cout;

#include "ListQueue.h"

int _tmain()
{
	CListQueue<int> cq;


	for (int i = 0; i != 100; ++i)
		cq.push(i);

	int output;

	DWORD q_size = cq.size();

	for (int i = 0; i != q_size; ++i)
	{
		cq.front(output);
		cout << output << '\n';
		cq.pop();
	}

	cout << "\n\n";

	for (int i = 99; i >= 0; --i)
		cq.push(i);

	q_size = cq.size();
	for (int i = 0; i != q_size; ++i)
	{
		cq.front(output);
		cout << output << '\n';
		cq.pop();
	}

	return 0;
}