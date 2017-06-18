#pragma once
#include<iostream>
using namespace std;

template<class K, class V>
struct AVLTreeNode
{
	K _key;
	V _value;
	int _bf;   //平衡因子
	AVLTreeNode * _parent;
	AVLTreeNode * _left;
	AVLTreeNode * _right;
	AVLTreeNode(K k=K(),V v=V())
		:_key(k)
		,_value(v)
		,_bf(0)
		,_parent(NULL)
		,_left(NULL)
		,_right(NULL)
	{}
};
template<class K,class V>
class AVLTree
{
	typedef AVLTreeNode<K, V> Node;
public:
	AVLTree()
		:_root(NULL)
	{}
	bool Insert(const K key,const V value)
	{
		Node * cur = _root;
		Node * parent = NULL;
		if (cur == NULL)//_root为空/空树
		{
			_root = new Node(key, value);
			_root->_bf = 0;
			_root->_parent = NULL;
			return true;
		}
		while (cur)//找插入节点位置节
		{
			if (cur->_key < key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_key > key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else//key值已存在，更新该key值得value
			{
				cur->_value = value;
				return true;
			}
		}
		//插入节点
		Node * node = new Node(key, value);
		if (parent->_key > key)
		{
			parent->_left = node;
			node->_parent = parent;
			node->_bf = 0;
		}
		else
		{
			parent->_right = node;
			node->_parent = parent;
			node->_bf = 0;
		}
		//更新平衡因子
		cur = node;
		while (parent)
		{
			if (parent->_left == cur)
			{
				parent->_bf--;
			}
			else
			{
				parent->_bf++;
			}
			cur = parent;
			parent = cur->_parent;
			//如果不满足AVL树的性质，则旋转调整
			if (cur->_bf == -2)
			{
				if (cur->_left->_bf == -1)
				{
					RotateR(cur->_left);//向右单旋
				}
				else if(cur->_left->_bf ==1)
				{
					RotateLR(cur->_left);//左右双旋，先向左再向右旋
				}
				else
				{
					printf("平衡因子异常\n");
					return false;
				}
			}
			else if (cur->_bf == 2)
			{
				if (cur->_right->_bf == 1)
				{
					RotateL(cur->_right);//向左单旋
				}
				else if(cur->_right->_bf==-1)
				{
					RotateRL(cur->_right);//右左双旋
				}
				else
				{
					printf("平衡因子异常\n");
					return false;
				}
			}
			else
			{
				printf("平衡因子异常\n");
				return false;
			}
		}
	}
protected:
	void RotateL(Node * root)//向左单旋
	{
		Node *parent = root->_parent;
		Node *subL = root->_left;
		parent->_right = subL;
		subL->_parent = parent;
		if (parent == _root)
		{
			_root = root;
		}
		else
		{
			if (parent->_parent->_left == parent)
			{
				parent->_parent->_left = root;
			}
			else
			{
				parent->_parent->_right = root;
			}
			root->_parent = parent->_parent;
		}
		root->_left = parent;
		parent->_parent = root;
		parent->_bf = root->_bf = subL->_bf = 0;
	}
	void RotateR(Node * root)//向右单旋
	{
		Node * parent = root->_parent;
		Node * subR = root->_right;
		parent->_left = subR;
		subR->_parent = parent;
		if (parent == _root)
		{
			_root = root;
		}
		else
		{
			root->_parent = parent->_parent;
			if (parent->_parent->_left == parent)
			{
				parent->_parent->_left = root;
			}
			else
			{
				parent->_parent->_right = root;
			}
		}
		root->_right = parent;
		parent->_parent = root;
		root->_bf = parent->_bf = subR->_bf = 0;
	}
	void RotateLR(Node * root)//左右双旋
	{
		RotateL(root);
		RotateR(root);
	}
	void RotateRL(Node*root)
	{
		RotateR(root);
		RotateL(root);
	}
private:
	Node * _root;
};