#pragma once
#include<iostream>
#include<cassert>
#include<stack>
using namespace std;
template<class T>
struct BinaryTreeNode
{
	T value;
	BinaryTreeNode * left;
	BinaryTreeNode * right;
	BinaryTreeNode(T v =T())
		:value(v)
		,left(NULL)
		,right(NULL)
	{}
};
template<class T>
class BinaryTree
{
	typedef BinaryTreeNode<T> Node;
public:
	BinaryTree()
		:_root(NULL)
	{}
	BinaryTree(T* arr, size_t size, int invalid)
	{
		assert(arr);
		int index = 0;
		_root=_CreateBinaryTree(arr, size,index,invalid);
	}
	//BinaryTree(Node * bt)
	//{
	//	root=_CreateBinaryTree(bt);
	//}
	void PrevOrderR()//前序遍历-递归
	{
		_PrevOrderR(_root);
	}
	void PrevOrder()//前序遍历-非递归
	{
		_PrevOrder(_root);
	}
	void InOrderR()//中序遍历-递归
	{
		_InOrderR(_root);
	}
	void InOrder()//中序遍历-非递归
	{
		_InOrder(_root);
	}
	void PostOrderR()//后序遍历-递归
	{
		_postOrderR(_root);
	}
	void PostOrder()//后序遍历-非递归
	{
		_postOrder(_root);
	}
	void LevelOrder()//层序遍历
	{
		_LevelOrder(_root);
	}
	~BinaryTree()
	{
		_Distory(_root);
	}

protected:
	Node *_CreateBinaryTree(T *arr, int size,int index ,char invalid)
	{
		Node * root = NULL;
		if (index < size && arr[index]!=invalid)
		{
		    root = new Node(arr[index]);
			root->left = _CreateBinaryTree(arr,size, ++index, invalid);
			root->right = _CreateBinaryTree(arr, size,++index, invalid);
		}
		return root;
	}
	/*Node *_CreateBinaryTree(Node *bt)
	{

	}*/
	void _PrevOrderR(Node * root)
	{
		Node * cur = root;
		while (cur)
		{
			cout << cur->value << " ";
			_PrevOrder(cur->left);
			_PrevOrder(cur->right);
		}
	}
	void _PrevOrder(Node * root)
	{
		stack<Node *> s;
		Node * cur = root;
		while (cur || s.empty())
		{
			while (cur)
			{
				cout << cur->value << " ";
				s.push(cur);
				cur = cur->left;
			}
			Node * top = s.top();
			s.pop();
			cur = top->right;
		}
	}
	void _InOrderR(Node *root)
	{
		Node* cur = root;
		while (cur)
		{
			_InOrder(cur->left);
			cout << cur->value << " ";
			_InOrder(cur->right);
		}
	}
	void _InOrder(Node * root)
	{
		stack<Node *>s;
		Node * cur = root;
		while (cur || s.empty())
		{
			while (cur)
			{
				s.push(cur);
			}

		}

	}
	void _PostOrder(Node *root)
	{
		Node * cur = root;
		while (cur)
		{
			_PostOrder(cur->left);
			_PostOrder(cur->right);
			cout << cur->value << " ";
		}
	}
	void _LevelOrder(Node *root)
	{
		Node * cur = root;

	}

private:
	Node * _root;
};