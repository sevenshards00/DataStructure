/*
* 이것이 자료구조+알고리즘이다 - 힙 & 우선순위 큐
* 파일명: Heap.h
* 파일 버전: 0.1
* 작성자: Sevenshards
* 작성 일자: 2024-03-15
* 이전 버전 작성 일자: 
* 버전 내용: 최대 힙 구현 (C++, Template)
* 이전 버전 내용: 
*/

#pragma once

#define IN
#define OUT

#include <iostream>

namespace mylib
{
	template <typename T>
	class Heap
	{
	public:
		Heap() = delete;
		explicit Heap(T arr[], int len) : m_capacity(len)
		{
			m_arr = (T *)malloc(sizeof(T) * (m_capacity + 1));
			
			if (m_arr == nullptr)
				return;

			for (int i = 1; i != m_capacity + 1; ++i)
				m_arr[i] = arr[i - 1];

			BuildMaxHeap(m_arr);

		}
		void MaxHeapify(IN T arr[], IN int idx)
		{
			while (true)
			{
				int l_idx = GetLeftIdx(idx);
				int r_idx = GetRightIdx(idx);
				int max_idx;
				if (l_idx <= m_capacity && arr[l_idx] > arr[idx])
					max_idx = l_idx;
				else
					max_idx = idx;

				if (r_idx <= m_capacity && arr[r_idx] > arr[max_idx])
					max_idx = r_idx;

				if (max_idx == idx)
					return;

				Swap(idx, max_idx);
				idx = max_idx;
			}
		}

		void BuildMaxHeap(T arr[])
		{
			for (int i = m_capacity / 2; i != 0; --i)
				MaxHeapify(arr, i);
		}

		void Print()
		{
			for (int i = 1; i != m_capacity; ++i)
				std::cout << m_arr[i] << ' ';
			std::cout << '\n';
		}

	private:
		T *m_arr;
		int m_capacity;

		int GetParentIdx(IN const int &idx)
		{
			return idx / 2;
		}

		int GetLeftIdx(IN const int &idx)
		{
			return idx * 2;
		}

		int GetRightIdx(IN const int &idx)
		{
			return (idx * 2) + 1;
		}

		void Swap(IN const int &idx1, IN const int &idx2)
		{
			T temp = m_arr[idx1];
			m_arr[idx1] = m_arr[idx2];
			m_arr[idx2] = temp;
		}
	};
}