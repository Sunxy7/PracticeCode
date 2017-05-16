#include<iostream>
using namespace std;

void AdjustDown(int arr[], int i, int n)
{
	int j = i * 2 + 1;//子节点 
	while (j<n)
	{
		if (j+1<n && arr[j] > arr[j + 1])//子节点中找较小的
		{
			j++;
		}
		if (arr[i] < arr[j])
		{
			break;
		}
		swap(arr[i],arr[j]);
		i = j;
		j = i * 2 + 1;
	}
}
void MakeHeap(int arr[], int n)
{
	int i = 0;
	for (i = n / 2 - 1; i >= 0; i--)//((n-1)*2)+1 =n/2-1
	{
		AdjustDown(arr, i, n);
	}
}
void HeapSort(int arr[],int len)
{
	int i = 0;
	MakeHeap(arr, len);
	for (i = len - 1; i >= 0; i--)
	{
		swap(arr[i], arr[0]);
		AdjustDown(arr, 0, i);
	}

}
int main()
{
	int arr[] = {3,7,1,0,8,4,6 ,78,-90};
	int len = sizeof(arr) / sizeof(arr[0]);
	int i = 0;
	HeapSort(arr, len);
	//MakeHeap(arr, len);
	//Insert(arr, 7, 2);
	//Delete(arr, len);
	for (i = 0; i < len; i++)
	{
		cout << arr[i]<< " ";
	}
	cout << endl;
	system("pause");
	return 0;
}