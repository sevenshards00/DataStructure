/*
* �˰��� - ���� Ž��(Binary Search)
* ���ϸ�: RecursiveBinarySearch.c
* ���� ����: 0.1
* �ۼ���: Sevenshards
* �ۼ� ����: 2023-11-27
* ���� ���� �ۼ� ����:
* ���� ����: ��������� ������ ���� Ž�� �˰��� ����
* ���� ���� ����:
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int RecursiveBinarySearch(int arr[], int first, int last, int target)
{
	int mid;
	// first���� last�� Ŀ���� ��� = ���� ã�� ���� ��� - ����� Ż�� ���� ù ��°.
	if (first > last)
		return -1;

	// ���� ù��° �ε����� ������ �ε����� ������ �߾Ӱ��� �����Ѵ�.
	mid = (first + last) / 2;

	// Ž�� ����
	// ã�� ��� �ε��� ���� ��ȯ - ����� Ż�� ���� �� ��°.
	if (target == arr[mid])
		return mid;

	// ���� ã�� ���� ���
	else if (target > arr[mid]) // ��ǥ�� �� ���� �߾Ӱ����� ũ�ٸ�
		return RecursiveBinarySearch(arr, mid + 1, last, target); // mid ������ �������Ƿ� mid�� ���� �ε������� last���� �ٽ� Ž��
	else // ��ǥ�� �� ���� �߾Ӱ����� �۴ٸ�
		return RecursiveBinarySearch(arr, first, mid - 1, target); // mid������ �������Ƿ� first���� mid�� �ٷ� ���� �ε������� �ٽ� Ž�� 
}


int main()
{
	int arr[] = { 1,3,5,7,9 };
	int input, result;
	printf("ã�� �� : ");
	scanf("%d", &input);
	result = RecursiveBinarySearch(arr, 0, (sizeof(arr) / sizeof(int)) - 1, input);

	if (result == -1)
		printf("ã�� ����\n");
	else
		printf("%d ��° �ε����� ����\n", result);


	return 0;
}