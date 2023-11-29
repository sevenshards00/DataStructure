/*
* ���� �ڷᱸ�� - ���� ���� ����Ʈ (���� ��� ���)
* ���ϸ�: SingleLinkedList.c
* ���� ����: 0.1
* �ۼ���: Sevenshards
* �ۼ� ����: 2023-11-02
* ���� ���� �ۼ� ����:
* ���� ����: ���� ��� ��� ���� ���� ����Ʈ ����
* ���� ���� ����:
*/

#include <stdlib.h>
#include "SingleLinkedList.h"

// ����Ʈ�� �ʱ�ȭ�� ���
void ListInit(List* plist)
{
	plist->head = (Node*)malloc(sizeof(Node)); // ���� ��带 �ٷ� ����Ű�� �Ѵ�.
	plist->head->next = NULL; // ���� ��尡 ����Ű�� ������ NULL��
	plist->numOfData = 0; // �׸��� ���̳�带 �����ϰ� ���� ������ ���� ����ؾ��ϹǷ� 0�̴�. -1�� �ƴϴ�.
}

// ����Ʈ�� ��带 ���� ������ �� ���
void LInsert(List* plist, LData data)
{
	Node* newNode = malloc(sizeof(Node)); // ���ο� ��� �޸� �Ҵ�
	newNode->data = data; // ��忡 ������ �Է�

	// �߸� �� �κ�. ���⸦ �߸� �Ἥ �� ������.
	// newNode->next = NULL; // ���ο� ��尡 ����Ű�� ���� ���� �����Ƿ� NULL
	newNode->next = plist->head->next; // head���� �����Ͱ� ���� ������, �׻� ���̳�� ������ ����Ű�� �ִ� ���� ���ο� ��尡 ����Ű�� �ؾ���
	plist->head->next = newNode; // head�������� ���Ƿ� ���̳�� ������ ���ο� ��带 ����Ű�� ��
	(plist->numOfData)++; // ������ �� ����
}

// ����Ʈ�� �� ù��° �����͸� ������ �� ���
int LFirst(List* plist, LData* pdata)
{
	// �� �ʿ� ������. �Ű����� �����Ƿ� �װ� ���� ��
	// LData nData; // ����� �����͸� �ޱ� ���� ����
	if (plist->head->next == NULL) // ���� ���̳�� ���Ŀ� ����Ű�� ��尡 ���ٸ�
		return FALSE; // �����Ͱ� ����

	plist->cur = plist->head->next; // ���� ��ġ�� ���� ��带 ����Ű�� �Ѵ�
	plist->before = plist->head; // �׸��� before�� ���� ��ġ ���� ���̳�带 ����Ų��

	*pdata = plist->cur->data; // ���� ��ġ�� �����͸� ����

	return TRUE; // ������ ������ �����ߴ�

}

// LFirst ������ �����͸� ������ �� ���
int LNext(List* plist, LData* pdata)
{
	// ���������� �� �ʿ� ������. �Ű����� �����Ƿ� �װ� ���� ��
	// LData nData; // ����� �����͸� �ޱ� ���� ����
	if (plist->cur->next == NULL) // ���� ��ġ ������ ����Ű�� ��尡 ���ٸ�
		return FALSE; // �����Ͱ� ����

	*pdata = plist->cur->data; // ���� ����Ű�� ��ġ�� ������ ����
	plist->before = plist->cur; // before�� ���� ����Ű�� ��� ��ġ�� ����
	plist->cur = plist->cur->next; // ���� ����Ű�� ��ġ�� �ϳ� ������ �̵�

	return TRUE; // ������ ���� ����
}

// LFirst, LNext�� ������ �����͸� �����ϰ� �޸� ������ ���, ���� ȣ�� �Ұ�
LData LRemove(List* plist)
{
	LData rdata; // ������ ����� ������
	Node* rNode; // ���� ���� ����, ������ ��带 ��� ���� ��� ������

	rdata = plist->cur->data; // ���� ������ �����͸� ���
	rNode = plist->cur; // ������ ���� ���� �������� ��带 ����Ų��

	plist->before->next = plist->cur->next; // �׸��� ���� ���� ���� ����Ű�� ����� �ڸ� ����
	plist->cur = plist->before; // �׸��� ���� �������� ��ġ�� �ϳ� ������ �ű��

	free(rNode); // ���⼭ �޸𸮸� �������ְ�
	(plist->numOfData)--; // ������ �� ����
	return rdata; // �����͸� ��ȯ�Ѵ�.
}

// ���� ����Ʈ�� ����� ��� �� Ȯ��
int LCount(List* plist)
{
	return plist->numOfData;
}