#include<iostream>
#include<assert.h>
using namespace std;
void MergerArray(int arr[],int left,int mid,int right,int tmp[])//合并数组
{
	int i = left;
	int j = mid+1;
	int k = 0;
	while (i<=mid && j<=right)
	{
		if (arr[i] <= arr[j])
			tmp[k++] = arr[i++];
		else
			tmp[k++] = arr[j++];
	}
	while (i <= mid)
		tmp[k++] = arr[i++];
	while (j <= right)
		tmp[k++] = arr[j++];
	int n = 0;
	for (n = 0; n <k;n++)//把归并后的数组写入原数组
	{
		arr[left+n] = tmp[n];
	}
}

void MergerSort(int arr[],int begin,int end,int tmp[])
{
	if (begin < end)
	{
		int mid = (begin + end) / 2;
		MergerSort(arr, begin, mid , tmp);
		MergerSort(arr, mid+1, end, tmp);
		MergerArray(arr, begin, mid, end, tmp);
	}
	
}

int main()
{
	int i = 0;
	int arr[] = { 3,1,8,4,9,7,0,5,2,6 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int * tmp = new int[len];
	assert(tmp);
	MergerSort(arr,0,len-1,tmp);
	for (i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	delete[] tmp;
	system("pause");
	return 0;
}