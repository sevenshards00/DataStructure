/*
* 이것이 자료구조+알고리즘이다 - 큐(Queue)
* 파일명: CircularQueue.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-02-29
* 이전 버전 작성 일자:
* 버전 내용: 배열 기반 환형 큐 구현(C++, Template)
* 이전 버전 내용:
*/

#include <Windows.h>
#include <tchar.h>
#include <iostream>
using std::cout;

#include "CircularQueue.h"

int _tmain()
{
	CQueue<int> cq(100);
	cq.push(1);
	cq.push(2);
	cq.push(3);
	cq.push(4);
	cq.push(5);

	int output;
	DWORD q_size = cq.size();
	for (int i = 0; i != q_size; ++i)
	{
		cq.front(output);
		cq.pop(output);
		cout << output << '\n';
	}

	cq.pop(output);
	cout << output << '\n';

	return 0;
}