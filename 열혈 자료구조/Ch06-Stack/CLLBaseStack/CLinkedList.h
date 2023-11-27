// 11.03 ���� ���� ����Ʈ
// ���� ��� ������� �������� �ʴ´�
// CLinkedList.h

#ifndef __C_LINKED_LIST_H__
#define __C_LINKED_LIST_H__

#define TRUE 1
#define FALSE 0

typedef int Data; // ���ǻ� �ϴ� int�� LData��

// ��� ����ü ����
typedef struct _node
{
	Data data;
	struct _node* next;
}Node;

// ����Ʈ ����ü ����
typedef struct _clinkedlist
{
	Node* list;
	Node* tail;
	Node* cur;
	Node* before;
	int numOfData;
} CLinkedList;

typedef CLinkedList List; // ���ǻ� List��

void ListInit(List* plist); // ����Ʈ �ʱ�ȭ

void LInsert(List* plist, Data data); // ��� ����

void LInsertFront(List* plist, Data data); // head�� ��� �߰�

int LFirst(List* plist, Data* pdata); // �� ó�� ��� ����

int LNext(List* plist, Data* pdata); // �� ó�� ��� ���� ���� ���� ��� ����

Data LRemove(List* plist); // ���� ���� ���� ��� ����

int LCount(List* plist); // ���� ��� ��ü ����

#endif