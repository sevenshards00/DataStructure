// 11.02 ���� ��� ��� ���� ��ũ�� ����Ʈ
// DDBLinkedList.c

#ifndef __DDB_LINKED_LIST_H__
#define __DDB_LINKED_LIST_H__

#define TRUE 1
#define FALSE 0

typedef int LData;

typedef struct _node
{
	LData data;
	struct _node* next;
	struct _node* prev;
} Node;

typedef struct _ddblist
{
	Node* head;
	Node* tail;
	Node* cur;
	int numOfData;
} DDBList;

typedef DDBList List;

#include <stdlib.h>
#include "DDBLinkedList.h"

// ����Ʈ �ʱ�ȭ�� ���
void ListInit(List* plist)
{
	// head�� tail�� ���� ��� �޸� �Ҵ�
	plist->head = (Node*)malloc(sizeof(Node));
	plist->tail = (Node*)malloc(sizeof(Node));

	// head�� prev�� NULL, next�� tail�� ����Ű��
	plist->head->prev = NULL;
	plist->head->next = plist->tail;
	// tail�� next�� NULL, prev�� head�� ����Ű��
	plist->tail->prev = plist->head;
	plist->tail->next = NULL;
	
	// ���� �������� ������ 0���� ����
	plist->numOfData = 0;

}
// ��� ����
void LInsert(List* plist, LData data)
{	
	Node* newNode = (Node*)malloc(sizeof(Node)); // ���ο� ��� ����
	newNode->data = data; // �Ű� ������ ���� �� ����� data�� ����
	
	newNode->prev = plist->tail->prev; // 1) tail�� ����Ű�� ���� ��带 ���ο� ����� prev ������ �־��ְ�
	plist->tail->prev->next = newNode; // 2) tail�� ������ ����Ű�� �ִ� ���� �ּҰ��� ���ο� ��带 ����Ű�� �Ѵ�

	newNode->next = plist->tail; // 3) ���ο� ����� next�� tail�� ����Ű�� �Ѵ�.
	plist->tail->prev = newNode; // 4) ���������� tail�� prev�� ���ο� ��带 ����Ű�� �Ѵ�

	(plist->numOfData)++; // ��� ���� ����

}
// �� ó�� ��� ����
int LFirst(List* plist, LData* pdata)
{
	if (plist->head == plist->tail) // head�� tail�� ����Ű�°� ���ٸ�
		return FALSE; // ��尡 ���� ���̹Ƿ� FALSE ��ȯ
	
	plist->cur = plist->head->next; // ���� ��ġ cur�� head�� ������ �ΰ� (�ʱ�ȭ)
	*pdata = plist->cur->data; // �����͸� �����Ͽ� �����´�

	return TRUE; // ������ ��ȯ ����
}
// �� ó�� ���� ��� ����
int LNext(List* plist, LData* pdata)
{
	if (plist->cur->next == plist->tail) // cur�� ������ tail�� ����Ų�ٸ�
		return FALSE; // �� �̻� ������ ��尡 ���� ���̹Ƿ� FALSE ��ȯ

	plist->cur = plist->cur->next; // ���� ��ġ cur�� ������ �ΰ�
	*pdata = plist->cur->data; // �����͸� �����Ͽ� �����´�

	return TRUE; // ������ ��ȯ ����
}
// �� ó�� ���� ���� ������ ��带 �������� ���� ��� ����
int LPrev(List* plist, LData* pdata)
{
	if (plist->cur->prev == plist->head) // cur�� ���� ��尡 head�� ����Ų�ٸ�
		return FALSE; // �� �̻� ������ ��尡 ���� ���̹Ƿ� FALSE ��ȯ

	plist->cur = plist->cur->prev; // ���� ��ġ cur�� ������ �ΰ�
	*pdata = plist->cur->data; // �����͸� �����Ͽ� �����´�

	return TRUE; // ������ ��ȯ ����
}
// ��� ����
// ���� ������ ���� ȣ���� ���� �ȵȴٴ� ��
// LFirst�� LNext ���Ŀ� ȣ���� �Ǿ�� �Ѵ�
LData LRemove(List* plist)
{
	Node* rNode = plist->cur; // ���� ������ ��� ��ġ
	LData rData = plist->cur->data; // ������ ��尡 ������ �ִ� ������

	plist->cur->prev->next = plist->cur->next; // ���� ����Ű�� �ִ� ���� ��尡 ����Ű�� ���� ��带 ���� ��尡 ����Ű�� ���� ����
	plist->cur->next->prev = plist->cur->prev; // ���� ����Ű�� �ִ� ���� ��尡 ����Ű�� ���� ��带 ���� ��尡 ����Ű�� ���� ����

	plist->cur = plist->cur->prev; // ���� ��ġ�� �ϳ� ������

	(plist->numOfData)--; // ��� ���� ����

	free(rNode); // �Ҵ�� ��� �޸� ����
	
	return rData; // ����� ������ ��ȯ
}
// ���� ����Ʈ�� �ִ� ����� ��
int LCount(List* plist)
{
	return plist->numOfData;
}

#endif