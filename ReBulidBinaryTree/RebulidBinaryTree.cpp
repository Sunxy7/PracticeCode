#include<iostream>
using namespace std;
struct BinaryTreeNode
{
	int value;
	BinaryTreeNode * left;
	BinaryTreeNode * right;
	BinaryTreeNode(int v=int())
		:value(v)
		,left(NULL)
		,right(NULL)
	{}
};
class ReBulidBinaryTree
{
public:
	typedef BinaryTreeNode Node;
	Node * ReBulid(int *PrevStart, int * PrevEnd, int * InStart, int *InEnd)
	{
		Node * root = new Node(PrevStart[0]);
		root->left = root->right = NULL;
		if (PrevStart == PrevEnd && InStart == InEnd)
		{
			return root;
		}
		//中序遍历序列中找根节点
		int * rootInorder = InStart;
		while (rootInorder <=InEnd && *rootInorder != PrevStart[0])
		{
			rootInorder++;
		}
		if (rootInorder > InEnd)//没有找到根节点
		{
			cout<<"input error"<<endl;
			return NULL;
		}
		int LeftLen = rootInorder - InStart;
		if (LeftLen > 0)
		{
			root->left = ReBulid(PrevStart + 1, PrevStart + LeftLen, InStart, rootInorder - 1);
		}
		if (rootInorder < InEnd)
		{
			root->right = ReBulid(PrevStart + LeftLen + 1, PrevEnd, rootInorder + 1, InEnd);
		}
		return root;
	}
	Node * ReBulidTree(int* PrevOrder, int *InOrder, int len)
	{
		if (PrevOrder == NULL || InOrder == NULL || len <= 0)
		{
			return NULL;
		}
		_root= ReBulid(PrevOrder, PrevOrder + len - 1, InOrder, InOrder + len - 1);
	}
	void PostOrder()
	{
		PostOrder(_root);
	}
	void PostOrder(Node *root)
	{
		if (root)
		{
			PostOrder(root->left);
			PostOrder(root->right);
			cout << root->value << " ";
		}
	}
private:
	Node * _root;
};


int main()
{
	int PrevOrder[] = { 1,2,4,7,3,5,6,8 };
	int InOrder[] = { 4,7,2,1,5,3,8,6 };
	int PrevLen = sizeof(PrevOrder) / sizeof(PrevOrder[0]);
	int InLen = sizeof(InOrder) / sizeof(InOrder[0]);
	if (PrevLen != InLen)
	{
		cout << "input error!" << endl;
		return -1;
	}
	ReBulidBinaryTree rb;
	rb.ReBulidTree(PrevOrder, InOrder, PrevLen);
	rb.PostOrder();
	cout << endl;
	system("pause");
	return 0;
}



