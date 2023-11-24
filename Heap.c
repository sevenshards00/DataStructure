/*
* 비선형 자료구조 - 배열 기반의 힙(Heap)
* 파일명: Heap.c
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2023-11-24
* 이전 버전 작성 일자:
* 버전 내용: 간단한 힙의 구현
* 이전 버전 내용:
*/
#include "Heap.h"

// 힙의 초기화
void HeapInit(Heap* ph)
{
	ph->numOfData = 0;
}

// 힙이 비었는지 확인
int HisEmpty(Heap* ph)
{
	if (ph->numOfData == 0)
		return TRUE;
	else
		return FALSE;
}

// 부모 노드의 인덱스 값 반환
// 부모 노드의 인덱스 값 = 자식 노드의 인덱스 값 / 2 (정수형 나눗셈)
int GetParentIDX(int idx)
{
	return idx / 2;
}

// 왼쪽 자식 노드의 인덱스 값 반환
// 왼쪽 자식 노드의 인덱스 값 = 부모 노드의 인덱스 값 * 2
int GetLChildIDX(int idx)
{
	return idx * 2;
}

// 오른쪽 자식 노드의 인덱스 값 반환
// 오른쪽 자식 노드의 인덱스 값 = (부모 노드의 인덱스 값 * 2) + 1
int GetRChildIDX(int idx)
{
	return GetLChildIDX(idx) + 1;
}

// 두 개의 자식 노드 중 높은 우선순위의 자식 노드 인덱스 값 반환
// 우선 순위의 경우 정수 값이 작을수록 높은 우선순위를 나타낸다고 가정
int GetHiPriChildIDX(Heap* ph, int idx)
{
	// 힙은 "완전 이진트리" 이므로 오른쪽 자식노드만 있는 경우는 절대 없음.
	// 자식 노드가 하나도 없다면, 단말 노드가 됨.
	// 만약 왼쪽 자식 노드의 인덱스가 힙에 저장된 노드의 수를 넘어섰다면?
	// 해당 노드는 단말 노드가 되므로 0을 반환
	if (GetLChildIDX(idx) > ph->numOfData) // 자식 노드가 없는 경우 (단말 노드일 경우)
		return 0;
	// 자식 노드가 하나 뿐일 경우는 왼쪽 자식 노드이며, 힙의 마지막 노드가 된다.
	// 그렇기 때문에 조건식을 아래와 같이 주면 자식 노드가 하나인 상황을 판별할 수 있음.
	else if (GetLChildIDX == ph->numOfData) // 왼쪽 자식 노드만 존재하는 경우
		return GetLChildIDX(idx);
	else // 왼쪽, 오른쪽 자식 노드가 다 있는 경우.
	{
		if (ph->heapArr[GetLChildIDX(idx)].pr > ph->heapArr[GetRChildIDX(idx)].pr)
			return GetRChildIDX(idx); // 오른쪽 자식 노드의 우선 순위가 높다면
		else
			return GetLChildIDX(idx); // 왼쪽 자식 노드의 우선 순위가 높다면
	}
}

// 힙에 데이터 삽입
void HInsert(Heap* ph, HData data, Priority pr)
{
	int idx = ph->numOfData + 1; // 가장 마지막 노드로 생성되므로 현재 데이터 갯수보다 하나 큰 인덱스로 초기화
	HeapElem newElem = { pr, data }; // 새로운 노드를 생성한다

	// 새로운 노드가 저장될 위치가 루트 노드의 위치가 아닐때까지 반복문을 수행
	while (idx != 1)
	{
		// 새로 생성된 노드와 부모 노드의 우선순위를 비교
		if (pr < (ph->heapArr[GetParentIDX(idx)].pr)) // 새로 생성된 노드의 우선 순위가 높다면
		{
			ph->heapArr[idx] = ph->heapArr[GetParentIDX(idx)]; // 기존의 부모 노드의 레벨을 하나 내린다 -> 실제로 레벨을 내림
			idx = GetParentIDX(idx); // 새로 생성된 노드의 레벨을 하나 올린다 -> 인덱스만 변경, 실제로 레벨이 올라간 상황은 아님
		}
		else
			break; // 우선 순위가 높지 않다면 반복문 종료
	}
	// 반복문 종료 후
	ph->heapArr[idx] = newElem; // 위의 반복문에 의해 갱신된 idx 위치에 새로 생성된 노드를 저장
	ph->numOfData += 1; // 데이터 갯수 증가
}

// 힙에 데이터 삭제
HData HDelete(Heap* ph) 
{
	HData rData = (ph->heapArr[1]).data; // 루트 노드를 삭제하므로 힙에서 인덱스가 1인 데이터를 가져온다.
	HeapElem lastElem = ph->heapArr[ph->numOfData]; // 그리고 힙에서 마지막 노드를 가리키기 위해 인덱스는 numOfData로 한다.

	int parentIdx = 1; // 마지막 노드를 루트 노드로 올려보내게 되므로 인덱스를 1로 초기화, 마지막 노드가 저장될 위치 정보가 담기는 변수
	int childIdx; // 비교를 위해 사용할 자식 노드 인덱스 변수


	// 루트 노드부터 시작해서 자식 노드와 우선 순위를 비교
	while (childIdx = GetHiPriChildIDX(ph, parentIdx))
	{
		if (lastElem.pr <= ph->heapArr[childIdx].pr) // 마지막 노드와 우선 순위를 비교
			break; // 마지막 노드의 우선순위가 높다면 반복문 종료
		ph->heapArr[parentIdx] = ph->heapArr[childIdx]; // 그렇지 않다면 현재 자식 노드의 레벨을 하나 올린다. -> 실제로 레벨을 올림
		parentIdx = childIdx; // 그리고 마지막 노드가 저장될 위치를 한 레벨 아래로 낮춘다. -> 인덱스만 변경, 실제로 변경은 안함
	}

	// 반복문이 끝나고 난 후
	ph->heapArr[parentIdx] = lastElem; // 위에서 갱신된 parentIdx 위치에 마지막 노드를 해당 위치에 저장 
	ph->numOfData -= 1; // 데이터 갯수 감소
	return rData; // 루트 노드의 데이터 반환
}