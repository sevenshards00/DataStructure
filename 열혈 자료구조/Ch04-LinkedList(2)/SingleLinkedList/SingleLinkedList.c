/*
* ���� �ڷᱸ�� - ���� ���� ����Ʈ (���� ��� ���)
* ���ϸ�: SingleLinkedList.c
* ���� ����: 0.3
* �ۼ���: Sevenshards
* �ۼ� ����: 2023-11-30
* ���� ���� �ۼ� ����: 2023-11-29
* ���� ����: ���� ���� ���� �߰� �� ���� ����
* ���� ���� ����: �ؽ� �浹 ���� �ذ��� ���� ü�̴� ��� ����
*/

#include <stdlib.h>
#include "SingleLinkedList.h"

// ����Ʈ�� �ʱ�ȭ�� ���
void ListInit(List* plist)
{
	plist->head = (Node*)malloc(sizeof(Node)); // ���� ��带 �ٷ� ����Ű�� �Ѵ�.
	plist->head->next = NULL; // ���� ��尡 ����Ű�� ������ NULL��
	plist->numOfData = 0; // �׸��� ���̳�带 �����ϰ� ���� ������ ���� ����ؾ��ϹǷ� 0�̴�. -1�� �ƴϴ�.
	plist->comp = NULL; // �ʱ�ȭ�� �켱���� �Ǻ��� ���� �Լ��� �������� �����̹Ƿ� NULL
}

void FInsert(List* plist, LData data) // ���� ���� ���� ����Ʈ�� ��带 ������ �� ���
{
	Node* newNode = (Node*)malloc(sizeof(Node)); // ���ο� ��� �޸� �Ҵ�
	newNode->data = data; // ��忡 ������ �Է�
	newNode->next = plist->head->next; // head���� �����Ͱ� ���� ������, ���̳�� ������ ����Ű�� �ִ� ���� ���ο� ��尡 ����Ű�� �ؾ���
	plist->head->next = newNode; // head�������� ���Ƿ� ���̳�� ������ ���ο� ��带 ����Ű�� ��
	(plist->numOfData)++; // ������ �� ����
}

// ���� ���ؿ� ���缭 ����Ʈ�� ��带 ������ �� ��� (Sort Insert)
void SInsert(List* plist, LData data)
{
	Node* newNode = (Node*)malloc(sizeof(Node)); // ���ο� ��� �޸� �Ҵ�
	newNode->data = data; // ��忡 ������ �Է�
	Node* cur = plist->head; // ������ ���� ����ϴ� ���� ��ġ(current), ���� ��ġ�� ���̳��
	
	// �� ��尡 �� ��ġ�� ã�� ���� �ݺ��� ����
	// �� �̻� ���� ��尡 ���� ������, �׸��� �� ��忡 �� �����Ϳ� ���� ����� �����͸� ���Ͽ� ���ؿ� ���� ������ �ݺ�
	while (cur->next != NULL && plist->comp(data, cur->next->data) != 0)
	{
		cur = cur->next; // ���� ���ؿ� �´� ��ġ���� ���� ���� �̵�
	}

	// �ݺ����� �����ٸ� ��带 ������ ��ġ(cursor)�� ã�� ��
	newNode->next = cur->next; // cur�� ���� ��ġ�� ���ο� ��尡 ���� ������, cur�� ������ ���ο� ��尡 ����Ű���� �ؾ���
	cur->next = newNode; // �׸��� cur�� next�� ���ο� ��带 ����Ű�� ��
	(plist->numOfData)++; // ������ �� ����
}

// ����Ʈ�� ��带 ���� ������ �� ���
void LInsert(List* plist, LData data)
{
	if (plist->comp == NULL) // ���� ������ ���ٸ�
		FInsert(plist, data); // FInsert ȣ��
	else // ���� ������ �ִٸ�
		SInsert(plist, data); // SInsert ȣ��
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

	
	plist->before = plist->cur; // before�� ���� ����Ű�� ��� ��ġ�� ����
	plist->cur = plist->cur->next; // ���� ����Ű�� ��ġ�� �ϳ� ������ �̵�
	*pdata = plist->cur->data; // ���� ����Ű�� ��ġ�� ������ ���� -> ������ ���� ��ġ�� �߸� �����Ͽ���

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
// ����Ʈ�� ���� ���� �Լ��� ���
void SetSortRule(List* plist, CompareFunc pcomp)
{
	plist->comp = pcomp;
}