// 11.02 ���� ���� ����Ʈ
// DBLinkedList.h

#ifndef __DB_LINKED_LIST_H__
#define __DB_LINKED_LIST_H__

#define TRUE 1
#define FALSE 0

typedef int LData;

// ���� ���� ����Ʈ�� ��� ����ü
typedef struct _node
{
	LData data; // ������
	struct _node* next; // ���� ��� ��ġ
	struct _node* prev; // ���� ��� ��ġ
} Node;

typedef struct _dblinkedlist
{
	Node* head; // ���, �� ó�� ��带 ����Ŵ
	Node* cur; // ���� ���� ���� ��ġ
	int numOfData; // ����Ʈ�� ����ִ� ��� ����
} DBLinkedList;

typedef DBLinkedList List; // ���ǻ� List�� ��Ī ���̱� ���� typedef

void ListInit(List* plist); // ����Ʈ �ʱ�ȭ

void LInsert(List* plist, LData data); // ��� ����

int LFirst(List* plist, LData* pdata); // ����Ʈ�� �� ó�� ��� ����

int LNext(List* plist, LData* pdata); // ����Ʈ�� �� ó�� ��� ���� ���� ����

int LPrev(List* plist, LData* pdata); // ���� ��� ����

LData LRemove(List* plist); // ��� ����, �̰� �ϴ� é�� ������ ���� �����غ����

int LCount(List* plist); // ���� ����Ʈ�� �ִ� ����� �� ��ȯ

#endif