// 11.02 ���� ��� ��� ���� ��ũ�� ����Ʈ
// DDBLinkedList.h

#ifndef __DDB_LINKED_LIST_H__
#define __DDB_LINKED_LIST_H__

#define TRUE 1 // ��¥ C�� Bool Ÿ���� �������� �����Ƿ� �̰� TRUE�� ��ü
#define FALSE 0 // �������� ������ �̰� FALSE ������ ��ü

typedef int LData; // ���ǻ� int�� LData�� ����. � �����͸� �ִ� �� �κи� �ٲ��ָ� ��

// Node ����ü ����
typedef struct _node
{
	LData data;
	struct _node* next;
	struct _node* prev;
} Node;

// ����Ʈ ����ü ����
typedef struct _ddblist
{
	Node* head;
	Node* tail;
	Node* cur;
	int numOfData;
} DDBList;

typedef DDBList List; // ���ǻ� List��� ������ typedef ����

void ListInit(List* plist); // ����Ʈ �ʱ�ȭ�� ���

void LInsert(List* plist, LData data); // ��� ����

int LFirst(List* plist, LData* pdata); // �� ó�� ��� ����

int LNext(List* plist, LData* pdata); // �� ó�� ���� ��� ����

int LPrev(List* plist, LData* pdata); // �� ó�� ���� ���� ������ ��带 �������� ���� ��� ����

LData LRemove(List* plist); // ��� ����

int LCount(List* plist); // ���� ����Ʈ�� �ִ� ����� ��

#endif