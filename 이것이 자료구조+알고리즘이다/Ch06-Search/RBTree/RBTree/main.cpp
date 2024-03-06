/*
* 이것이 자료구조+알고리즘이다 - 탐색(Search)
* 파일명: main.cpp
* 파일 버전: 0.13
* 작성자: Sevenshards
* 작성 일자: 2024-03-06
* 이전 버전 작성 일자: 2024-03-05
* 버전 내용: 레드 블랙 트리로 확장 (C++, Template)
* 이전 버전 내용: Transplant 함수 로직 수정 및 자잘한 부분 변경
*/

#include <iostream>
#include <Windows.h>
#include "ITree.h"
#include "CBSTree.h"
#include "RBTree.h"

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
	CBSTest.Delete(23);


	CBSTest.PreOrderPrint();
	CBSTest.InOrderPrint();
	CBSTest.PostOrderPrint();
	CBSTest.Count();

	RBTree<int> RBTest;

	RBTest.Insert(23);
	RBTest.Insert(11);
	RBTest.Insert(1);
	RBTest.Insert(16);
	RBTest.Insert(13);
	RBTest.Insert(20);
	RBTest.Insert(15);
	RBTest.Insert(139);
	RBTest.Insert(67);

	RBTest.Count();


	RBTest.PreOrderPrint();
	RBTest.InOrderPrint();
	RBTest.PostOrderPrint();
	RBTest.Count();
	return 0;
}