#pragma once
#include<iostream>
using namespace std;

struct BSTreeNode
{
	int _key;
	BSTreeNode *_left;
	BSTreeNode * _right;
	BSTreeNode(int k=int())
		:_key(k)
		,_left(NULL)
		,_right(NULL)
	{}
};

class BSTree
{
	typedef BSTreeNode Node;
public:
	BSTree()
		:_root(NULL)
	{}
	bool Insert(int key)//插入-非递归
	{
		Node * cur = _root;
		Node * parent = NULL;
		while(cur)
		{
			if(cur->_key < key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_key > key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else //cur->_key==key 节点存在
			{
				return false;
			}
		}
		cur = new Node(key);
		if (parent == NULL)
		{
			_root = cur;
		}
		else
		{
			if (parent->_key > key)
			{
				parent->_left = cur;
			}
			else
			{
				parent->_right = cur;
			}
		}
		return true;
	}
	bool InsertR(int key)//插入-递归
	{
		return _InsertR(_root, key);
	}
	Node* Find(int key)//查找-非递归
	{
		Node *cur = _root;
		while (cur)
		{
			if (cur->_key < key)
			{
				cur = cur->_right;
			}
			else if(cur->_key>key)
			{
				cur = cur->_left;
			}
			else
			{
				return cur;
			}
		}
		return NULL;
	}
	Node * FindR(int key)//查找-递归
	{
		return _FindR(_root, key);
	}
	bool Remove(int key)//删除-非递归
	{
		Node * cur = _root;
		Node * parent = NULL;
		Node *del = NULL;
		while (cur)
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
			else
			{
				if (cur->_left == NULL)//左为空or叶子结点
				{
					del = cur;
					if (cur == _root)//parent==NULL删除根节点
					{
						_root = cur->_right;
					}
					else if (parent->_left==cur)
					{
						parent->_left = cur->_right;
					}
					else
					{
						parent->_right = cur->_right;
					}
				}
				else if (cur->_right == NULL)//右为空
				{
					del = cur;
					if (cur == _root)//删除根节点
					{
						_root = cur->_left;
					}
					else if (parent->_left == cur)
					{
						parent->_left = cur->_left;
					}
					else
					{
						parent->_right = cur->_left;
					}
				}
				else//左右都不为空
				{
					//找右孩子的最左节点替换该节点
					Node * subLeft = cur->_right;
					while (subLeft->_left)
					{
						parent = subLeft;
						subLeft = subLeft->_left;
					}
					del = subLeft;
					cur->_key = subLeft->_key;
					if (subLeft == cur->_right)//cur->_right无左孩子
					{
						cur->_right = subLeft->_right;
					}
					else
					{
						parent->_left = subLeft->_right;
					}
				}
				delete del;
				del = NULL;
				return true;
			}
		}
		return false;
	}
	bool RemoveR(int key)//删除-递归
	{
		return _RemoveR(_root,key);
	}
	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}
	protected:
		bool _InsertR(Node *& root, int key)//插入-递归
		{
			if (root == NULL)
			{
				root = new Node(key);
				return true;
			}
			else
			{
				if (root->_key > key)
				{
					return _InsertR(root->_left, key);
				}
				else if (root->_key < key)
				{
					return _InsertR(root->_right, key);
				}
				else//该数存在
				{
					return false;
				}
			}	
		}
		Node* _FindR(Node *& root, int key)//查找-递归
		{
			while (root)
			{
				if (root->_key == key)
				{
					return root;
				}
				else if (root->_key > key)
				{
					return _FindR(root->_left,key);
				}
				else
				{
					return _FindR(root->_right, key);
				}
			}
			return NULL;	
		}
		bool _RemoveR(Node * &root,int key)//删除-递归
		{
			while (root)
			{
				if (root->_key > key)
				{
					return _RemoveR(root->_right, key);
				}
				else if (root->_key < key)
				{
					return _RemoveR(root->_left, key);
				}
				else
				{
					Node *parent = NULL;
					Node * del = NULL;
					if (root->_left == NULL)//左为空or叶子结点
					{
						del = root;
						if (root == _root)//parent==NULL删除根节点
						{
							_root = root->_right;
						}
						else if (parent->_left == root)
						{
							parent->_left = root->_right;
						}
						else
						{
							parent->_right = root->_right;
						}
					}
					else if (root->_right == NULL)//右为空
					{
						del = root;
						if (root == _root)//删除根节点
						{
							_root = root->_left;
						}
						else if (parent->_left == root)
						{
							parent->_left = root->_left;
						}
						else
						{
							parent->_right = root->_left;
						}
					}
					else//左右都不为空
					{
						//找右孩子的最左节点替换该节点
						Node * subLeft = root->_right;
						while (subLeft->_left)
						{
							parent = subLeft;
							subLeft = subLeft->_left;
						}
						del = subLeft;
						root->_key = subLeft->_key;
						if (subLeft == root->_right)//cur->_right无左孩子
						{
							root->_right = subLeft->_right;
						}
						else
						{
							parent->_left = subLeft->_right;
						}
					}
					delete del;
					del = NULL;
					return true;
				}
			}
			return false;
		}
		void _InOrder(Node * root)
		{
			if (root)
			{
				_InOrder(root->_left);
				cout << root->_key << " ";
				_InOrder(root->_right);
			}
		}
private:
	Node * _root;
};
