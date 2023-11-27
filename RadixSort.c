/*
* 알고리즘 - 기수 정렬(Radix Sort)
* 파일명: RadixSort.c
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2023-11-27
* 이전 버전 작성 일자:
* 버전 내용: 간단한 기수 정렬(LSD, Least Significant Digit) 구현
* 이전 버전 내용:
*/

#include <stdio.h>
#include "ListBaseQueue.h"

#define BUCKET_NUM 10

void RadixSort(int arr[], int num, int maxLen)
{
	// 매개변수 maxLen에는 정렬대상 중 가장 긴 데이터의 길이 정보가 전달
	Queue buckets[BUCKET_NUM];
	int bucket_idx; // 버킷에 사용할 인덱스
	int pos;
	int digit_idx; // 자릿수에 사용할 인덱스
	int divfac = 1; // 자릿수에 사용할 변수
	int radix;

	// 10개의 버킷 초기화
	for (bucket_idx = 0; bucket_idx < BUCKET_NUM; bucket_idx++)
		QueueInit(&buckets[bucket_idx]);

	// 가장 긴 데이터의 길이만큼 반복
	for (pos = 0; pos < maxLen; pos++)
	{
		for (digit_idx = 0; digit_idx < num; digit_idx++)
		{
			// N번째 자리의 숫자 추출
			radix = (arr[digit_idx] / divfac) % 10;

			// 추출한 숫자를 근거로 버킷에 데이터를 저장
			QEnqueue(&buckets[radix], arr[digit_idx]);
		}

		// 버킷의 수 만큼 반복
		for (bucket_idx = 0, digit_idx = 0; bucket_idx < BUCKET_NUM; bucket_idx++)
		{
			// 버킷에 저장된 것을 순서대로 다 꺼내서 다시 arr에 저장
			while (!QisEmpty(&buckets[bucket_idx]))
				arr[digit_idx++] = QDequeue(&buckets[bucket_idx]);
		}

		// N번째 자리의 숫자 추출을 위해서 피제수의 증가
		divfac *= 10;
	}
}

int main()
{
	int arr[7] = { 13, 212, 14, 7141, 10987, 6, 15 };
	int i;
	int len = sizeof(arr) / sizeof(int);

	RadixSort(arr, len, 5);

	for (i = 0; i < len; i++)
		printf("%d ", arr[i]);

	printf("\n");

	return 0;
}