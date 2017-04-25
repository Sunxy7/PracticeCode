#include <iostream>
#include<stdlib.h>
#include <time.h>
using namespace std;

void ShellSort(int arr[],int len)
{
	int i=0;
	int j=0;
	int k=0;
	int tmp=0;
	int gap=len/3;//增量，两个分组之间的距
	while (gap>0)
	{
		for (i=gap;i<len;i++)
		{
			tmp=arr[i];
			for (j=i-gap;j>=0;j-=gap)
			{
				if (arr[j]<tmp)
				{
					break;
				}
			}
			if (j<i-gap)
			{
				for (k=i-gap;k>j;k-=gap)
				{
					arr[k+gap]=arr[k];
				}
				arr[j+gap]=tmp;
			}
		}
		gap=gap/3;
	}
}
int main()
{
	int i=0;
	int arr[10]={92,5,61,77,10,9,18,4,6,3};
	int len =sizeof(arr)/sizeof(arr[0]);
	ShellSort(arr,len);
	for (i=0;i<len;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	system("pause");
	return 0;
}