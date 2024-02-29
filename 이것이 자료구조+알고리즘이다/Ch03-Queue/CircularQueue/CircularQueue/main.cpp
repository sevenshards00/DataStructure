/*
* 이것이 자료구조+알고리즘이다 - 큐(Queue)
* 파일명: CircularQueue.cpp
* 파일 버전: 0.11
* 작성자: Sevenshards
* 작성 일자: 2024-02-29
* 이전 버전 작성 일자: 2024-02-29
* 버전 내용: NextPosIdx 로직 수정
* 이전 버전 내용: 배열 기반 환형 큐 구현(C++, Template)
*/

#include <Windows.h>
#include <tchar.h>
#include <iostream>
using std::cout;

#include "CircularQueue.h"

int _tmain()
{
	CQueue<int> cq(100);

	
	for (int i = 0; i != 100; ++i)
		cq.push(i);

	int output;
	
	DWORD q_size = cq.size();

	for (int i = 0; i != q_size; ++i)
	{
		cq.pop(output);
		cout << output << '\n';
	}

	cout << "\n\n";

	for (int i = 99; i >= 0; --i)
		cq.push(i);

	q_size = cq.size();
	for (int i = 0; i != q_size; ++i)
	{
		cq.pop(output);
		cout << output << '\n';
	}

	return 0;
}