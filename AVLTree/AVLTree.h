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
			else if(parent->_right==cur)
			{
				parent->_bf++;
			}
			//����ƽ�������ж��Ƿ���Ҫ�ٵ������Ƚڵ��ƽ�����ӻ������
			if (parent->_bf == 0)
			{
				break;
			}
			else if (parent->_bf == 1 || parent->_bf == -1)
			{
				cur = parent;
				parent = cur->_parent;
			}
			//���������AVL�������ʣ�����ת����
			else if (parent->_bf == -2)
			{
				if (parent->_left->_bf == -1)
				{
					RotateR(parent->_left);//���ҵ���
				}
				else if(parent->_left->_bf ==1)
				{
					RotateLR(parent->_left);//����˫��(�����������ҵ���)
				}
				else
				{
					printf("ƽ�������쳣\n");
					return false;
				}
			}
			else if (parent->_bf == 2)
			{
				if (parent->_right->_bf == 1)
				{
					RotateL(parent->_right);//������
				}
				else if(parent->_right->_bf==-1)
				{
					RotateRL(parent->_right);//����˫��(���ҵ�����������)
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
	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}
protected:
	void RotateL(Node * root)//������
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
	void RotateR(Node * root)//���ҵ���
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
	void RotateLR(Node * root)//����˫��
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
			printf("ƽ�������쳣\n");
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
			printf("ƽ�������쳣\n");
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