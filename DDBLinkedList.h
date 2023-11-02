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

void ListInit(List* plist);

void LInsert(List* plist, LData data);

int LFirst(List* plist, LData* pdata);

int LNext(List* plist, LData* pdata);

int LPrev(List* plist, LData* pdata);

LData LRemove(List* plist);

int LCount(List* plist);

#endif