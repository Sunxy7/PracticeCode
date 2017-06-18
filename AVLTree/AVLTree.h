#pragma once
#include<iostream>
using namespace std;

template<class K, class V>
struct AVLTreeNode
{
	K _key;
	V _value;
	int _bf;   //ƽ������
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
		if (cur == NULL)//_rootΪ��/����
		{
			_root = new Node(key, value);
			_root->_bf = 0;
			_root->_parent = NULL;
			return true;
		}
		while (cur)//�Ҳ���ڵ�λ�ý�
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
			else//keyֵ�Ѵ��ڣ����¸�keyֵ��value
			{
				cur->_value = value;
				return true;
			}
		}
		//����ڵ�
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
		//����ƽ������
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
			//���������AVL�������ʣ�����ת����
			if (cur->_bf == -2)
			{
				if (cur->_left->_bf == -1)
				{
					RotateR(cur->_left);//���ҵ���
				}
				else if(cur->_left->_bf ==1)
				{
					RotateLR(cur->_left);//����˫������������������
				}
				else
				{
					printf("ƽ�������쳣\n");
					return false;
				}
			}
			else if (cur->_bf == 2)
			{
				if (cur->_right->_bf == 1)
				{
					RotateL(cur->_right);//������
				}
				else if(cur->_right->_bf==-1)
				{
					RotateRL(cur->_right);//����˫��
				}
				else
				{
					printf("ƽ�������쳣\n");
					return false;
				}
			}
			else
			{
				printf("ƽ�������쳣\n");
				return false;
			}
		}
	}
protected:
	void RotateL(Node * root)//������
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
	void RotateR(Node * root)//���ҵ���
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
	void RotateLR(Node * root)//����˫��
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