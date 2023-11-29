/*
* ���� �ڷᱸ�� - ���� ���� ����Ʈ (���� ��� ���)
* ���ϸ�: SingleLinkedList.h
* ���� ����: 0.2
* �ۼ���: Sevenshards
* �ۼ� ����: 2023-11-29
* ���� ���� �ۼ� ����: 2023-11-29
* ���� ����: �ؽ� �浹 ���� �ذ��� ���� ü�̴� ��� ����
* ���� ���� ����: ���� ��� ��� ���� ���� ����Ʈ ����
*/
#ifndef __SINGLE_LINKED_LIST_H__
#define __SINGLE_LINKED_LIST_H__

#define TRUE 1 // ���� ��� 1
#define FALSE 0 // ������ ��� 0

#include "Slot.h"

typedef Slot LData; // � �����͸� ���� �𸣴� �ϴ��� LData�� ��ũ�� ����, ���ǻ� int

typedef struct _node
{
	LData data; // ��忡 ��� ������
	struct _node* next; // ���� ��带 ����Ű�� ���� ������
} Node;

typedef struct _linkedlist
{
	Node* head; // head�� ����Ű�� ������
	Node* cur; // ���� �����ϴ� ��ġ�� ����Ű�� ������
	Node* before; // ���纸�� �ϳ� ���� ��ġ�� ����Ű�� ������
	int numOfData; // ���� ����� ������ ���� Ȯ���ϱ� ���� ���
} LinkedList;

typedef LinkedList List;

void ListInit(List* plist); // ����Ʈ�� �ʱ�ȭ�� ���

void LInsert(List* plist, LData data); // ����Ʈ�� ��带 ���� ������ �� ���

int LFirst(List* plist, LData* pdata); // ����Ʈ�� �� ù��° �����͸� ������ �� ���

int LNext(List* plist, LData* pdata); // LFirst ������ �����͸� ������ �� ���

LData LRemove(List* plist); // LFirst, LNext�� ������ �����͸� �����ϰ� �޸� ������ ���, ���� ȣ�� �Ұ�

int LCount(List* plist); // ���� ����Ʈ�� ����� ��� �� Ȯ��

#endif