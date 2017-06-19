#include"AVLTree.h"

int main()
{
	//int arr[] = { 15,3,7,11,9,25,17,14,16 };
	int arr[] = { 16,3,7,11,9,26,18,14,15 };
	AVLTree<int,int> t1;
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
 	 	t1.Insert(arr[i], i);
	}
	t1.InOrder();
	system("pause");
	return 0;
}