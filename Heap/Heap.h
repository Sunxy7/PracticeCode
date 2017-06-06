#pragma once
#include<iostream>
#include<vector>
using namespace std;

//���÷º�����ߴ��븴����
template<class T=int>
class Greater
{
public:
	bool operator()(T a, T b)
	{
		return a > b;
	}
};
template<class T=int>
class Less
{
public:
	bool operator()(T a, T b)
	{
		return a < b;
	}
};
template<class T,class Compare=Less<T>>//Ĭ�Ͻ�С��
class Heap
{
public:
	Heap()
	{}
	Heap(int *arr, int n)//����
	{
		int i = 0;
		heap.reserve(n);
		for (i = 0; i < n; i++)//��������Ԫ�ز����
		{
			heap.push_back(arr[i]);
		}
		for (i = (n - 2) / 2; i < n &&i>=0; i--)//�ӵ�һ����Ҷ�ӽ�㿪ʼ����
		{
			AdjustDown(i);
		}
	}
	void AdjustUp(int child)//���ϵ����㷨
	{
		int father = (child - 1) / 2;
		Compare Com;
		while (child >0)
		{
			//if (heap[child]< heap[father])
			if (!Com(heap[father], heap[child]))
			{
				swap(heap[father], heap[child]);
			}
			child = father;
			father = (child - 1) / 2;
		}
	}
	void AdjustDown(int root)//���µ����㷨
	{
		int child = root * 2 + 1;
		Compare Com;
		while (child <= heap.size()-1)
		{
			//if ((child + 1 <= heap.size() - 1)&&(heap[child+1]<heap[child]))
			if (child + 1<heap.size() &&Com(heap[child + 1], heap[child]))
			{
				child++;
			}
			//if (heap[child]<heap[root])
			if (Com(heap[child], heap[root]))
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
	void Push(int data)//����Ԫ��
	{
		heap.push_back(data);
		AdjustUp(heap.size() - 1);
	}
	void Pop()//ɾ��Ԫ��
	{
		//�����һ��Ԫ����Ѷ�Ԫ�ؽ�����ɾ�����һ��Ԫ�أ�������
		if (heap.size() == 1)//���ֻ��һ��Ԫ�أ�ֱ��ɾ��
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
	
	T Top()//���ضѶ�Ԫ��
	{
		return heap[0];
	}
	int Size()//�Ѵ�С
	{
		return heap.size();
	}
	bool IsEmpty()//�ж϶��Ƿ�Ϊ��
	{
		return heap.size() == 0;
	}
	void PrintHeap()//��ӡ��Ԫ��
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
