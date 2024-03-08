/*
* 이것이 자료구조+알고리즘이다 - 탐색(Search)
* 파일명: main.cpp
* 파일 버전: 0.15
* 작성자: Sevenshards
* 작성 일자: 2024-03-08
* 이전 버전 작성 일자: 2024-03-07
* 버전 내용: AVL 트리 확장 구현 완료 (C++, Template)
* 이전 버전 내용: 레드 블랙 트리 구현 완료 (C++, Template)
*/

#include <iostream>
#include <Windows.h>
#include "ITree.h"
#include "CBSTree.h"
#include "RBTree.h"
#include "AVLTree.h"

using namespace mylib_tree;

int main()
{
	CBSTree<int> CBSTest;

	std::wcout << L"Binary Search Tree Test\n";
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
	CBSTest.PreOrderPrint();
	CBSTest.InOrderPrint();
	CBSTest.PostOrderPrint();

	CBSTest.Delete(16);
	CBSTest.Delete(23);

	CBSTest.Count();
	CBSTest.PreOrderPrint();
	CBSTest.InOrderPrint();
	CBSTest.PostOrderPrint();
	std::wcout << L"\n\n";

	std::wcout << L"Red Black Tree Test\n";
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

	RBTest.Delete(16);
	RBTest.Delete(23);

	RBTest.Count();
	RBTest.PreOrderPrint();
	RBTest.InOrderPrint();
	RBTest.PostOrderPrint();

	std::wcout << L"\n\n";
	std::wcout << L"AVL Tree Test\n";
	AVLTree<int> AVLTest;

	AVLTest.Insert(23);
	AVLTest.Insert(11);
	AVLTest.Insert(1);
	AVLTest.Insert(16);
	AVLTest.Insert(13);
	AVLTest.Insert(20);
	AVLTest.Insert(15);
	AVLTest.Insert(139);
	AVLTest.Insert(67);
	
	AVLTest.Count();
	AVLTest.PreOrderPrint();
	AVLTest.InOrderPrint();
	AVLTest.PostOrderPrint();
	
	AVLTest.Delete(16);
	AVLTest.Delete(23);
	
	AVLTest.Count();
	AVLTest.PreOrderPrint();
	AVLTest.InOrderPrint();
	AVLTest.PostOrderPrint();
	
	return 0;
}