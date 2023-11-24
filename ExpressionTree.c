/*
* 비선형 자료구조 - 수식 트리 (이진 트리의 응용)
* 파일명: ExpressionTree.c
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2023-11-24
* 이전 버전 작성 일자:
* 버전 내용: 수식 트리 구현 및 계산 결과 프로그램 작성
* 이전 버전 내용:
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h> // 문자열 관련 함수 사용을 위해 헤더파일 포함
#include <ctype.h> // isdigit() 함수 사용을 위해 헤더파일 포함
#include "BinaryTree.h" // 수식 트리도 이진 트리의 일종.
#include "ListBaseStack.h" // 스택을 이용하여 수식 트리를 구성하므로 헤더파일 포함

// 수식 트리 구성
BTreeNode* MakeExpTree(char exp[])
{
	Stack stack; // 트리 생성에 사용할 스택 선언
	BTreeNode* pnode; // 트리를 만들 노드 선언

	int expLen = strlen(exp); // 입력받은 수식의 길이
	int i; // 반복문에 사용될 변수 i

	StackInit(&stack); // 스택 초기화

	for (i = 0; i < expLen; i++) // 수식을 토큰으로 나눠가며 수식 트리 생성
	{
		pnode = MakeBTreeNode(); // 수식 트리를 구성할 새로운 노드를 생성

		if (isdigit(exp[i])) // 만약 피연산자라면
			SetData(pnode, exp[i] - '0'); // 노드의 데이터를 저장, exp[i]는 문자이므로 문자 '0'과의 차가 실제 정수값이다.
		else // 연산자라면
		{
			MakeRightSubTree(pnode, SPop(&stack)); // 스택에서 먼저 나온 노드(또는 서브트리)를 오른쪽 자식 노드로 연결하고
			MakeLeftSubTree(pnode, SPop(&stack)); // 그 다음 스택에서 나온 노드(또는 서브트리)를 왼쪽 자식 노드로 연결한다.
			SetData(pnode, exp[i]); // 그리고 연산자를 노드에 저장한다.
		}

		SPush(&stack, pnode); // 위의 과정을 거치고 나면 스택에 집어넣는다.
	}

	return SPop(&stack); // 마지막으로 수식트리가 완성이 되면 최상단 루트 노드의 주소값을 반환한다.
}

int EvaluateExpTree(BTreeNode* bt) // 수식 트리를 이용한 계산
{
	int op1, op2; // 피연산자1, 2로 사용할 변수

	if (GetLeftSubTree(bt) == NULL && GetRightSubTree(bt) == NULL) // 단말노드, 즉 피연산자라면
		return GetData(bt); // 피연산자 값을 반환한다

	op1 = EvaluateExpTree(GetLeftSubTree(bt)); // 왼쪽 서브트리의 계산된 값을 피연산자로 받는다 (재귀)
	op2 = EvaluateExpTree(GetRightSubTree(bt)); // 오른쪽 서브트리의 계산된 값을 피연산자로 받는다 (재귀)

	switch (GetData(bt)) // 연산자의 종류에 따라 계산
	{
	case '+':
		return op1 + op2;
	case '-':
		return op1 - op2;
	case '*':
		return op1 * op2;
	case '/':
		return op1 / op2;
	}

	return 0;
}

void ShowNodeData(int data)
{
	if (0 <= data && data <= 9)
		printf("%d ", data);
	else
		printf("%c ", data);
}

// 생성한 수식 트리가 맞게 되었는가 확인하기 위해 만든 출력부
void ShowPrefixTypeExp(BTreeNode* bt) // 전위 표기법 기반 출력
{
	PreorderTraversal(bt, ShowNodeData); // 전위 순회, 그리고 순회하면서 하는 동작은 ShowNodeData.
}

void ShowInfixTypeExp(BTreeNode* bt) // 중위 표기법 기반 출력
{

	if (bt == NULL) // 만약 공집합 노드(NULL)이라면? 재귀의 탈출 조건이 된다.
		return;

	if (bt->left != NULL || bt->right != NULL) // 연산자를 대상으로 왼쪽이나 오른쪽에 피연산자가 있을 때, 괄호'('를 열고 
		printf("(");

	// 재귀를 이용하는 것이 핵심이다!
	ShowInfixTypeExp(bt->left); // 1) 첫 번째 피연산자 출력
	ShowNodeData(bt->data); // 2) 연산자 출력
	ShowInfixTypeExp(bt->right); // 3) 두 번째 피연산자 출력

	if (bt->left != NULL || bt->right != NULL) // 연산자를 대상으로 왼쪽이나 오른쪽에 피연산자가 있으면 괄호 ')'를 닫는다.
		printf(")");
}

void ShowPostfixTypeExp(BTreeNode* bt) // 후위 표기법 기반 출력
{
	PostorderTraversal(bt, ShowNodeData); // 전위 순회, 그리고 순회하면서 하는 동작은 ShowNodeData.
}