// 11.02 ���� ��ũ�� ����Ʈ
// CLinkedList.h
//

#ifndef __C_LINKED_LIST_H__
#define __C_LINKED_LIST_H__

#define TRUE 1
#define FALSE 0

typedef int LData;

typedef struct _node
{
	LData data;
	struct _node* next;
} Node;

typedef struct _clinkedlist
{
	Node* tail; // tail�� ����Ű�� ��ġ
	Node* cur; // ���� ������ ���� ����Ű�� ��� ��ġ
	Node* before; // ���� ������ ���� ����Ű�� ��庸�� �ϳ� ���� ��ġ
	int numOfData; // ����Ʈ�� ����� ��� ����
} CLinkedList;

typedef CLinkedList List; // ���ǻ� List��� ���� ���� typedef ����

void ListInit(List* plist); // ����Ʈ �ʱ�ȭ

// ���� ��ũ�� ����Ʈ�� �ٲ� �κ�
void LInsert(List* plist, LData data); // tail�� ��� �߰�
void LInsertFront(List* plist, LData data); // head�� ��� �߰�

int LFirst(List* plist, LData* data); // �� ó�� ������ ����
int LNext(List* plist, LData* data); // �� ó�� ��� ���� ����

LData LRemove(List* plist); // ���� ���� ���� ��� ����

int LCount(List* plist); // ����Ʈ�� ��� ���� ��ȯ

#endif