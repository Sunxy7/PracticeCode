#include <iostream>
#include<stdlib.h>
#include <time.h>
using namespace std;
 
void SelectSort(int arr[],int len)
{
	int min=0;//最小元素下标
	int max=len-1;//最大元素下标
	int i=0;
	while (min <= max)
	{
		i=min+1;
		while (i>=min && i<=max )
		{
			if (arr[min]>arr[max])
			{
				swap(arr[min],arr[max]);
			}
			if(arr[i]<arr[min])
			{
				swap(arr[i],arr[min]);
			}
			if (arr[i]>arr[max])
			{
				swap(arr[i],arr[max]);
			}
			i++;
		}
		min++;
		max--;
	}
}

int main()
{
	int i=0;
	int arr[10]={6,4,9,2,0,1,5,3,7,8};
	int len =sizeof(arr)/sizeof(arr[0]);
	SelectSort(arr,len);
	for (i=0;i<len;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	system("pause");
	return 0;
}