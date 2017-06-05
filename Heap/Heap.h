#pragma once
#include<iostream>
#include<vector>
using namespace std;

//利用仿函数提高代码复用性
template<class T=int>
class Greater
{
	bool operator()(T a, T b)
	{
		return a > b;
	}
};
template<class T=int>
class Less
{
	bool operator()(T a, T b)
	{
		return a < b;
	}
};
template<class T,class Compare=Less<T>>//默认建小堆
class Heap
{
public:
	Heap()
	{}
	Heap(int *arr, int n)//建堆
	{
		int i = 0;
		heap.reserve(n);
		for (i = 0; i < n; i++)//将数组中元素插入堆
		{
			heap.push_back(arr[i]);
		}
		for (i = (n - 2) / 2; i < n; i--)//从第一个非叶子结点开始调整
		{
			AdjustDown(i);
		}
	}
	void AdjustUp(int child)//向上调整算法
	{
		int father = (child - 1) / 2;
		while (father >= 0)
		{
			if (!Compare()(heap[father], heap[child]))
			{
				swap(heap[father], heap[child]);
			}
			child = father;
			father = (child - 1) / 2;
		}
	}
	void AdjustDown(int root)//向下调整算法
	{
		int child = root * 2 + 1;
		while (child <= heap.size())
		{
			if (Compare(heap[child + 1], heap[child]) && child+1<heap.size())
			{
				child++;
			}
			if (Compare(heap[child], heap[root]))
			{
				swap(heap[child], heap[root]);
			}
			else
			{
				break;
			}
			root = child;
			child = root * 2 + 1;
		}

	}
	void Push(int data)//插入元素
	{
		heap.push_back(data);
		AdjustUp(heap.size() - 1);
	}
	void Pop()//删除元素
	{
		//将最后一个元素与堆顶元素交换，删除最后一个元素，调整堆
		if (heap.size() == 1)//如果只有一个元素，直接删除
		{
			heap.pop_back();
		}
		else
		{
			swap(heap[0], heap[heap.size() - 1]);
			heap.pop_back();
			AdjustDown(0);
		}
	}
	
	T Top()//返回堆顶元素
	{
		return heap[0];
	}
	int Size()//堆大小
	{
		return heap.size();
	}
	bool IsEmpty()//判断堆是否为空
	{
		return heap.size() == 0;
	}
	void PrintHeap()//打印堆元素
	{
		int i = 0;
		for (i = 0; i < heap.size(); i++)
		{
			cout << heap[i] << " ";
		}
		cout << endl;
	}


private:
	vector<int> heap;
	
};
