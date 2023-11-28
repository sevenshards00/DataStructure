/*
* �˰��� - ���� Ž��(Interpolation Search)
* ���ϸ�: InterpolSearch.c
* ���� ����: 0.1
* �ۼ���: Sevenshards
* �ۼ� ����: 2023-11-27
* ���� ���� �ۼ� ����:
* ���� ����: ������ ������ ���� Ž�� �˰����� ������� ���� Ž�� ����
* ���� ���� ����:
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int InterpolationSearch(int arr[], int first, int last, int target)
{
	int pos; // ���� Ž�������� �߾Ӱ��� �ƴ� ��ʽĿ��� ������ ���� ������� Ž�� ��ġ�� ���Ѵ�.

	// ã���� �ϴ� ���� �迭�� ù ��° ������ �۰ų� ������ ������ ū ��� - ���� Ž�������� ��� Ż�� ���� ù ��°.
	if (target < arr[first] || target > arr[last])
		return -1;

	// ��ʽĿ� ���� ������ ���� ������� �� Ž�� ��ġ�� �����Ѵ�.
	pos = ((double)(target - arr[first]) / (arr[last] - arr[first]) * (last - first)) + first;

	// Ž�� ����
	// ã�� ��� �ε��� ���� ��ȯ - ����� Ż�� ���� �� ��°.
	if (target == arr[pos])
		return pos;

	// ���� ã�� ���� ���
	else if (target > arr[pos]) // ��ǥ�� �� ���� Ž�� ���� ��ġ�� ������ ũ�ٸ�
		return InterpolationSearch(arr, pos + 1, last, target); // pos ������ �������Ƿ� pos�� ���� �ε������� last���� �ٽ� Ž��
	else // ��ǥ�� �� ���� Ž�� ���� ��ġ�� ������ �۴ٸ�
		return InterpolationSearch(arr, first, pos - 1, target); // pos������ �������Ƿ� first���� pos�� �ٷ� ���� �ε������� �ٽ� Ž�� 
}


int main()
{
	int arr[] = { 1,3,5,7,9 };
	int result;

	// �迭 ���� ���� 2�� ã�� ���� ȣ�� -> ������ �����
	result = InterpolationSearch(arr, 0, sizeof(arr) / sizeof(int) - 1, 2);

	if (result == -1)
		printf("ã�� ����\n");
	else
		printf("%d ��° �ε����� ����\n", result);

	return 0;
}