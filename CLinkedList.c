// 11.03 ���� ���� ����Ʈ
// ���� ��� ������� �������� �ʴ´�
// CLinkedList.c

#include <stdlib.h>
#include "CLinkedList.h"

void ListInit(List* plist) // ����Ʈ �ʱ�ȭ
{
	plist->tail = NULL;
	plist->numOfData = 0;
}

// �߸� ®��.
// head�����θ� �����Ͱ� ���ٰ� �����ϰ� �̵� �ڵ带 ���.
// �̰� tail������ ���� ��� ������ ����
//
void LInsert(List* plist, Data data) // ��� ����
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	if (plist->tail == NULL) // ���� ����Ʈ�� ����ִٸ�
	{
		plist->tail = newNode; // ���ο� ��带 tail�� ����Ű�� �Ѵ�
		newNode->next = plist->tail; // �׸��� ���ο� ��带 tail�� ����Ű�� �Ͽ� �ڽ��� ����Ű�� �Ѵ�
	}
	else
	{
		newNode->next = plist->tail->next; // ���ο� ����� ������ �� ù��° ��带 ����Ű���� tail->next ���� �ְ�
		plist->tail->next = newNode; // �׸��� ���� tail�� ����Ű�� �ִ�(���ο� ��庸�� �ϳ� ���� ���) ����� next�� ���ο� ��带 ����Ű�� �Ѵ�.
		plist->tail = newNode; // ����������, tail�� ���ο� ��带 �����Ѽ� ���� �������� ��带 ����Ű�� �Ѵ�.

	}
	// tail������ ���� ���ο� ���� ���� �������̴�.
	// ���� �����ʿ� ���Ա� ������ ���ο� ���� �� ù��°, ���� �������� ��带 �����Ѿ� �Ѵ�.
	newNode->next = plist->tail->next; // �׷��� ù ��°�δ� ���ο� ����� next�� tail->next, ���� ���� ��带 ����Ű�� �Ѵ�.

	(plist->numOfData)++;
}

// ���� ��ũ�� ����Ʈ�� �ϸ鼭 �̰� ��ó �������� �ʰ� �־���.
// ���� ������ �͵� ����� ������ �ڵ忴��.
// ���� �����Ѱ� Front �����̾���, ���� �ִ� �͵� �Ϻ����� �ʴ�.
//
void LInsertFront(List* plist, Data data) // head�� ��� �߰�
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
int LFirst(List* plist, Data* pdata) // �� ó�� ��� ����
{
	if (plist->tail == NULL) // ����Ʈ�� ����ִٸ�
		return FALSE; // ��� ���� ����
	// �װ� �ƴ϶��

	plist->cur = plist->tail->next; // �� ù��°(���� ����) ��带 ����Ű�� �ϰ�
	plist->before = plist->tail; // �ϳ� ���� ���(tail)�� ����Ű�� �Ѵ�

	*pdata = plist->cur->data; // ���� ����Ű�� ����� ���� �����´�.

	return TRUE; // ������ ���� ����.

}

int LNext(List* plist, Data* pdata) // �� ó�� ��� ���� ���� ���� ��� ����
{
	// ���� ��ũ�� ����Ʈ�̹Ƿ� ���� NULL���� ���� �ʿ�� ����. ���� ȣ���� �����ϹǷ�
	// �׷��� Ȥ�� �𸣴� ���ǽ��� �޾Ƶдٸ�
	if (plist->tail == NULL) // ����Ʈ�� ����ִٸ�
		return FALSE; // ��� ���� ����

	// �� ���� ����
	// �Ʊ�� �Ȱ��� ��ġ��.
	// C�� ���������� �����ϴµ�, �̰� ���ϸ� ����ü �� ��¼�ڴ°ų�
	// ������ ���� ��ġ�� �ְ�, �׸��� �� ������ �� ĭ �ű�� �׸��� �����͸� �о��
	// �ȱ׷��� ��������, �̻��� �����Ͱ� ���´�
	// ���� ��
	//
	plist->before = plist->cur; // ������ ��ġ�� ���� ��ġ�� �ٲ۴�
	plist->cur = plist->cur->next; // ���� ��ġ���� �ϳ� ���� ��带 ����Ű�� �ϰ�
	*pdata = plist->cur->data; // ���� ����Ű�� ����� ���� �����´�.

	return TRUE;
}

Data LRemove(List* plist) // ���� ���� ���� ��� ����
{
	// ���Ⱑ �߿��� ����Ʈ
	// 1) tail�� ����� ���
	// ���� data�� �����ִµ�, tail�� ����� ����� tail�� �ϳ� ������ �Ű���� �Ѵ�.
	// 2) �����Ͱ� ���������� �� �ϳ� ������ �� ����� ���
	// �̶��� ���������� ���� ��嵵 tail�� ����. ����Ʈ�� ������� ����̹Ƿ� tail�� NULL�� ����Ű���� �Ѵ�
	// 3) �װ͵� �ƴ϶�� �׳� ���� ���� ���� ����Ʈó�� ������ �ٲ��ָ� �ȴ�.
	//

	Node* rNode = plist->cur; // ���� ��带 ���� ����Ű�� ����
	Data rData = plist->cur->data; // �׸��� ���� ���� ��尡 ������ �ִ� ������

	if (plist->cur == plist->tail) // �ϴ� ���� ����Ű�� ��ġ�� tail�̶��
	{
		if (plist->tail == plist->tail->next) // tail�� tail->next�� ���ٸ�? ���������� �� �ϳ� ���� ��尡 �ȴ�
		{
			plist->tail = NULL;; // �� �̻� ����Ű�� ���� ���� �ϰ�
		}
		plist->tail = plist->before; // ���� ����Ű�� ����� �ϳ� ������ �ű��
	}

	plist->before->next = plist->cur->next;
	plist->cur = plist->before;

	free(rNode);
	(plist->numOfData)--; // ��ü ��� �� ����
	return rData;
}

int LCount(List* plist) // ���� ��� ��ü ����
{
	return plist->numOfData;
}