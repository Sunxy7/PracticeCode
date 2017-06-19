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
			else if(parent->_right==cur)
			{
				parent->_bf++;
			}
			//根据平衡因子判断是否需要再调整祖先节点的平衡因子或调整树
			if (parent->_bf == 0)
			{
				break;
			}
			else if (parent->_bf == 1 || parent->_bf == -1)
			{
				cur = parent;
				parent = cur->_parent;
			}
			//如果不满足AVL树的性质，则旋转调整
			else if (parent->_bf == -2)
			{
				if (parent->_left->_bf == -1)
				{
					RotateR(parent->_left);//向右单旋
				}
				else if(parent->_left->_bf ==1)
				{
					RotateLR(parent->_left);//左右双旋(先左单旋再向右单旋)
				}
				else
				{
					printf("平衡因子异常\n");
					return false;
				}
			}
			else if (parent->_bf == 2)
			{
				if (parent->_right->_bf == 1)
				{
					RotateL(parent->_right);//向左单旋
				}
				else if(parent->_right->_bf==-1)
				{
					RotateRL(parent->_right);//右左双旋(先右单旋，再左单旋)
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
	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}
protected:
	void RotateL(Node * root)//向左单旋
	{
		Node *parent = root->_parent;
		Node *subL = root->_left;
		parent->_right = subL;
		if (subL)
		{
			subL->_parent = parent;
		}
		if (parent == _root)
		{
			_root = root;
			root->_parent = NULL;
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
		if (subL)
		{
			subL->_bf = 0;
		}
		parent->_bf = root->_bf = 0;
	}
	void RotateR(Node * root)//向右单旋
	{
		Node * parent = root->_parent;
		Node * subR = root->_right;
		parent->_left = subR;
		if (subR)
		{
			subR->_parent = parent;
		}
		if (parent == _root)
		{
			_root = root;
			root->_parent = NULL;
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
		if (subR)
		{
			subR->_bf = 0;
		}
		root->_bf = parent->_bf = 0;
	}
	void RotateLR(Node * root)//左右双旋
	{
		RotateL(root->_right);
		RotateR(root->_parent);
		Node* cur = root->_parent;
		if (cur->_bf == 0)
		{
			cur->_left->_bf = 0;
			cur->_right->_bf = 0;
		}
		else if(cur->_bf == 1)
		{
			cur->_bf = 0;
			cur->_left->_bf = -1;
			cur->_right->_bf = 0;
		}
		else if (cur->_bf == -1)
		{
			cur->_bf = 0;
			cur->_left->_bf = 0;
			cur->_right->_bf = 1;
		}
		else
		{
			printf("平衡因子异常\n");
			return;
		}
	}
	void RotateRL(Node*root)
	{
		RotateR(root->_left);
		RotateL(root->_parent);
		Node* cur = root->_parent;
		if (cur->_bf == 0)
		{
			cur->_left->_bf = 0;
			cur->_right->_bf = 0;
		}
		else if (cur->_bf == 1)
		{
			cur->_bf = 0;
			cur->_left->_bf = -1;
			cur->_right->_bf = 0;
		}
		else if (cur->_bf == -1)
		{
			cur->_bf = 0;
			cur->_left->_bf = 0;
			cur->_right->_bf = 1;
		}
		else
		{
			printf("平衡因子异常\n");
			return;
		}
	}
	void _InOrder(Node * root)
	{
		if (root == NULL)
		{
			return;
		}
		_InOrder(root->_left);
		cout << "key:" << root->_key << "value:" << root->_value<<" ";
		_InOrder(root->_right);
	}
private:
	Node * _root;
};