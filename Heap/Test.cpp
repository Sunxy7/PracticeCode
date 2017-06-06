#include"Heap.h"

int main()
{
	int arr[] = { 10,4,19,7,8,16,17,0,1,5,12 };
	Heap<int> hp(arr,sizeof(arr)/sizeof(arr[0]));
	hp.PrintHeap();
	hp.Push(-1);
	hp.PrintHeap();
	hp.Push(12);
	hp.PrintHeap();
	cout<< "heap top:"<<hp.Top()<<endl;
	hp.Pop();
	hp.Pop();
	hp.PrintHeap();
	cout<<"heap size is:"<<hp.Size()<<endl;
	cout<<"is empty? "<<hp.IsEmpty()<<endl;
	system("pause");
	return 0;
}