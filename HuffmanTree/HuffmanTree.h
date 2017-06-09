#pragma once
#include"Heap.h"

template <class T>
struct HuffmanTreeNode
{
	T weight;
	HuffmanTreeNode<T> * parent;
	HuffmanTreeNode<T> * left;
	HuffmanTreeNode<T> * right;
	HuffmanTreeNode(T w=T())
		:weight(w)
		,parent(NULL)
		,left(NULL)
		,right(NULL)
	{}
};
template<class T>
class HuffmanTree
{
	typedef HuffmanTreeNode<T> Node;
public:
	HuffmanTree()
		:root(NULL)
	{}
	HuffmanTree(T*arr, size_t size)
	{
		root = CreatHuffmanTree(arr, size);
	}
	Node * GetRoot()
	{
		return root;
	}
	~HuffmanTree()
	{
		Distory(root);
	}

protected:
	Node * CreatHuffmanTree(T * arr, size_t size)
	{
		struct WeightLess
		{
			bool operator()(Node * Left, Node * Right)
			{
				return Left->weight < Right->weight;
			}
		};
		Heap<Node *, WeightLess> MinHeap(arr,size);
		for (int i = 0; i < size; i++)
		{
			Node * tmp = new Node(arr[i]);
			MinHeap.Push(tmp);
		}
		while (MinHeap.Size() > 1)
		{
			Node * left = MinHeap.Top();
			MinHeap.Pop();
			Node * right= MinHeap.Top();
			MinHeap.Pop();
			Node *parent = new Node(left->weight + right->weight);
			parent->left = left;
			parent->right = right;
			left->parent = parent;
			right->parent = parent;
			MinHeap.Push(parent);
		}
		return MinHeap.Top();
	}
	
	void Distory(Node * root)
	{
		 if (root == NULL)
		 {
			 return;
		 }
		 Node * cur = root;
		 while (cur)
		 {
			 Distory(cur->left);
			 Distory(cur->right);
		 }
		 delete cur;
		 cur = NULL;
		 return;
	}
private:
	Node * root;
};