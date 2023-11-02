// 11.02 ���� ���� ����Ʈ
// DBLinkedList.c
#include <stdlib.h>
#include "DBLinkedList.h"

void ListInit(List* plist) // ����Ʈ �ʱ�ȭ
{
	plist->head = NULL;
	plist->numOfData = 0;
}

void LInsert(List* plist, LData data) // ��� ����
{
	// ���ο� ��� ���� �� ������ �Է�
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	// ���ο� ����� ������ head�� ����Ű�� ������ �����Ѷ�
	// �̰� �� ���� ���̽��� ������ ���ƾ� �Ѵ�.
	// ���� �ʱ�ȭ�� ���� �ƹ��͵� ���� ���¿��� ���ʷ� �����Ǵ� �����? NULL ���� ����
	// ������ �װ� �ƴ϶��? ���� head�� ����Ű�� ��带 ����Ű�� �ȴ�.
	// ���� ���ο� ����� next���� head�� ����Ű�� ��带 ����ų �� �ְ� �ȴ�.
	//
	newNode->next = plist->head; 
	// �׷��� �� �κп��� ���ǽ����� �����.
	// ���� �ʱ�ȭ ������ ��Ȳ�� �ƴ϶��?
	// head�� prev�� ���ο� ��带 ����Ű���� �Ѵ�
	//
	if (plist->head != NULL)
		plist->head->prev = newNode;

	// ���⵵ ������ó�� �� ���� ���̽��� ������ ���ƾ� �Ѵ�.
	// ���� ���ǽ��� �������� �ʰ� �Ѿ�Դٸ�?
	// �ʱ�ȭ�� ���Ķ�� ���� �ǰ� ���� ������ ����� prev���� NULL�� ����, head�� �� ��带 ����Ų��
	// �׷��� ���� ���ǽ��� �����ϰ� �Ѿ�Դٶ�� �ϸ�? head�� ����Ű�� �ִ� ����� prev�� ���� �� ���� ����ȴ�.
	// �׸��� �� ����� prev���� NULL���� �ְ�, head�� ���ο� ��带 ����Ű�� �ȴ�.
	//
	newNode->prev = NULL;
	plist->head = newNode;

	(plist->numOfData)++;
}

int LFirst(List* plist, LData* pdata) // ����Ʈ�� �� ó�� ��� ����
{
	if (plist->head == NULL) // ���� ����Ʈ�� ����ٸ�?
		return FALSE; // ������ ��ȸ �Ұ�

	plist->cur = plist->head; // cur�� ù ��° ��带 ����Ű���� ��
	*pdata = plist->cur->data; // ù ��° ����� �����͸� ����

	return TRUE; // ������ ��ȸ ����
}

int LNext(List* plist, LData* pdata) // ����Ʈ�� �� ó�� ��� ���� ���� ����
{
	if (plist->cur->next == NULL) // �ڿ� ���� ��尡 ���ٸ�?
		return FALSE; // ������ ��ȸ ����
	
	plist->cur = plist->cur->next; // cur�� �����ʷ� �̵�
	*pdata = plist->cur->data; // ���� ��ġ�� ��� �����͸� ����

	return TRUE;
}

int LPrev(List* plist, LData* pdata) // ���� ��� ����
{
	if (plist->cur->prev == NULL) // �տ� ���� ��尡 ���ٸ�?
		return FALSE; // ������ ��ȸ ����

	plist->cur = plist->cur->prev; // cur�� �������� �̵�
	*pdata = plist->cur->data; // ���� ��ġ�� �����͸� ����

	return TRUE;
}

LData LRemove(List* plist) // ��� ����, �̰� �ϴ� é�� ������ ���� �����غ����
{
	Node* rNode = plist->cur;
	LData rData = plist->cur->data;

	// �� ù ��° ��带 ����ٰ� �ϸ�
	if (plist->cur == plist->head)
	{
		plist->cur = plist->cur->next;
		plist->head = plist->cur;
		plist->cur->prev = NULL;
	}
	else if (plist->cur->next == NULL)
	{
		plist->cur = plist->cur->prev;
		plist->cur->next = NULL;
	}
	else
	{
		plist->cur->prev->next = plist->cur->next;
		plist->cur->next->prev = plist->cur->prev;
		plist->cur = plist->cur->prev;
	}

	free(rNode);
	(plist->numOfData)--;
	return rData;
}

int LCount(List* plist) // ���� ����Ʈ�� �ִ� ����� �� ��ȯ
{
	return plist->numOfData;
}