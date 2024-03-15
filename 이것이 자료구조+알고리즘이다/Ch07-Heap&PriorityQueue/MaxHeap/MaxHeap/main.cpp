/*
* 이것이 자료구조+알고리즘이다 - 힙 & 우선순위 큐
* 파일명: main.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-03-15
* 이전 버전 작성 일자:
* 버전 내용: 최대 힙 구현 (C++, Template)
* 이전 버전 내용:
*/

#include <cstdlib>

#include "MaxHeap.h"
using namespace mylib;

int main()
{
	int arr[] = { 4, 1, 3, 2, 16, 9, 10, 14, 8, 7 };
	Heap<int> h_intarr(arr, sizeof(arr)/sizeof(int));
	h_intarr.Print();
	return 0;
}