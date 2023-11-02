// 11.02 ���� ��ũ�� ����Ʈ
// CLinkedList.c
//

#include <stdlib.h>
#include "CLinkedList.h"

void ListInit(List* plist) // ����Ʈ �ʱ�ȭ
{
	plist->tail = NULL;
	plist->cur = NULL;
	plist->before = NULL;
	plist->numOfData = 0;
}
// ���� ��ũ�� ����Ʈ�� �ٲ� �κ�
// ���� �κ��� ���ؼ� �˰Ե� ���� tail �����͸� �ϳ��� ���� �������� ����������
// �����̶��� ������, �ᱹ tail�� ������ ��Ҹ� ����Ű���ְ�, tail->next�� �� ù��° ��Ҹ� ����Ų��.
//
void LInsert(List* plist, LData data) // tail�� ��� �߰�
{
	Node* newNode = (Node*)malloc(sizeof(Node)); // ���ο� ��� �޸� �Ҵ�
	newNode->data = data; // ������ �Է�

	// ������ ��� ������ ���ؼ��� ����
	if (plist->tail == NULL) // ���� ù ��° �����
	{
		plist->tail = newNode; // tail�� ù ��° ��带 ����Ű�� �ϰ�
		newNode->next = newNode; // ���ο� ��� ���� �ڽ��� ����Ű�� �Ѵ�
	}
	else
	{
		newNode->next = plist->tail->next; // ���ο� ���(tail��, ���� ������)�� ������ tail�� ����Ű�� ���� �ּ�(�� ù��° ���)�� �ְ�
		plist->tail->next = newNode; // tail�� ����Ű�� ���� �ּҴ� tail�ʿ� ���� ���ο� ��带 ����Ű�� �ض�
		plist->tail = newNode; // ���������� tail������ ���� �������Ƿ� tail�� ���� ���� ��带 �����Ѷ�
	}

	(plist->numOfData)++;
}
void LInsertFront(List* plist, LData data) // head�� ��� �߰�
{
	Node* newNode = (Node*)malloc(sizeof(Node)); // ���ο� ��� �޸� �Ҵ�
	newNode->data = data; // ������ �Է�

	// ������ ��� ������ ���ؼ��� ����
	if (plist->tail == NULL) // ���� ù ��° �����
	{
		plist->tail = newNode; // tail�� ù ��° ��带 ����Ű�� �ϰ�
		newNode->next = newNode; // ���ο� ��� ���� �ڽ��� ����Ű�� �Ѵ�
	}
	else
	{
		newNode->next = plist->tail->next; // ���ο� ���(head��, ���� ����)�� ������ tail�� ����Ű�� ���� �ּ�(�� ù��° ���)�� �ְ�
		plist->tail->next = newNode; // tail�� ����Ű�� ���� �ּҴ� head�ʿ� ���� ���ο� ��� (�� ù��° ���)�� ����Ű�� �ض�
	}

	(plist->numOfData)++;
}
int LFirst(List* plist, LData* pdata) // �� ó�� ������ ����
{
	if (plist->tail == NULL) // �����Ͱ� ���ٸ�
		return FALSE; // ��ȯ�� �����Ͱ� ����
	// �׻� ���Ģ�� �ϳ� ������ ����
	// �׳� ����Ʈ���� �׷���, ���⼭�� �׷����� before, cur ������
	// ���� ����Ʈ�� ��쿡�� tail�� ���� ��, tail->next�� ���� ù ��° ��带 ����Ų��
	//
	plist->before = plist->tail; // before�� ���� ��ġ���� �ϳ� ���̸�, First�̹Ƿ� tail�� ����Ų��.
	plist->cur = plist->tail->next; // cur�� ���� ��ġ�� ����Ű��, �� ù��° ��Һ��� �����ϹǷ� tail���� �ϳ� ���� ��ġ�� ����Ų��.

	*pdata = plist->cur->data;

	return TRUE;

}
int LNext(List* plist, LData* pdata) // �� ó�� ��� ���� ����
{
	// ���� ����Ʈ������ plist->cur->next == NULL �̶�� ���ǽ��� �־���.
	// �̴� ����Ʈ�� ���� Ȯ���ϱ� �����̾���, ���̸� �� �̻� ���� �ʿ䰡 ����.
	// ������ ���⼭�� tail�� NULL������ Ȯ���ϴµ� ���� ����Ʈ�̹Ƿ� ��� ���� ���� �ִ�.
	// �׷��� ���ǽ��� ���� �������� ȣ���� ����������.
	//
	if (plist->tail == NULL) // �����Ͱ� ���ٸ�
		return FALSE; // ��ȯ�� �����Ͱ� ����
	// �׻� ���Ģ�� �ϳ� ������ ����
	// �׳� ����Ʈ���� �׷���, ���⼭�� �׷����� before, cur ������
	// ���� ����Ʈ�� ��쿡�� tail�� ���� ��, tail->next�� ���� ù ��° ��带 ����Ų��
	//
	plist->before = plist->cur; // ����Ű�� �ִ� ��ġ�� before�� �ְ�
	plist->cur = plist->cur->next; // ����Ű�� ��ġ�� ���� ������ ���� ��ġ�� ����

	*pdata = plist->cur->data;

	return TRUE;
}
LData LRemove(List* plist) // ���� ���� ���� ��� ����
{
	Node* rNode = plist->cur;
	LData rData = plist->cur->data;

	if (rNode == plist->tail)
	{
		if (plist->tail == plist->tail->next)
			plist->tail = NULL;
		else
			plist->tail = plist->before;
	}

	plist->before->next = plist->cur->next;
	plist->cur = plist->before;

	free(rNode);
	(plist->numOfData)--;
	return rData;
}

int LCount(List* plist) // ����Ʈ�� ��� ���� ��ȯ
{
	return plist->numOfData;
}