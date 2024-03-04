/*
* 이것이 자료구조+알고리즘이다 - 트리(Tree)
* 파일명: main.cpp
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-03-04
* 이전 버전 작성 일자:
* 버전 내용: 이진 트리 구현(C++, Template) (구현중)
* 이전 버전 내용:
*/

#include <cstdio>
#include <Windows.h>
#include "CBinaryTree.h"
#include "CBinarySearchTree.h"

using namespace mylib_tree;

int main()
{
	CBinarySearchTree<int> CBTest;
	CBTest.Insert(2);
	CBTest.Insert(5);
	CBTest.Insert(9);
	CBTest.Insert(12);
	CBTest.Insert(18);
	CBTest.Insert(15);
	CBTest.Insert(13);
	CBTest.Insert(17);
	CBTest.Insert(19);

	CBTest.InOrder();

	return 0;
}