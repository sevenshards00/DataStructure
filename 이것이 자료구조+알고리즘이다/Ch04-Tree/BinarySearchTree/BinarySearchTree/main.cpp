/*
* 이것이 자료구조+알고리즘이다 - 트리(Tree)
* 파일명: main.cpp
* 파일 버전: 0.11
* 작성자: Sevenshards
* 작성 일자: 2024-03-05
* 이전 버전 작성 일자:
* 버전 내용: 주석 및 노드 갯수 반환하는 함수 추가
* 이전 버전 내용: 이진 탐색 트리 구현(C++, Template)
*/

#include <iostream>
#include <Windows.h>
#include "ITree.h"
#include "BinarySearchTree.h"

using namespace mylib_tree;

int main()
{
	CBSTree<int> CBSTest;

	CBSTest.Insert(23);
	CBSTest.Insert(11);
	CBSTest.Insert(1);
	CBSTest.Insert(16);
	CBSTest.Insert(13);
	CBSTest.Insert(20);
	CBSTest.Insert(15);
	CBSTest.Insert(139);
	CBSTest.Insert(67);

	CBSTest.Count();

	CBSTest.Delete(16);

	int *find = new int;
	CBSTest.Search(67, find);

	std::wcout << *find << L'\n';

	CBSTest.PreOrder();
	CBSTest.InOrder();
	CBSTest.PostOrder();
	CBSTest.Count();
	return 0;
}