#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

//void InsertSort1(int arr[],int len)
//{
//	int i=0;
//	int j=0;
//	int k=0;
//	int tmp=0;
//	for(i=1;i<len;i++)//�����һ�����������򣬴ӵڶ�������ʼ�Һ��ʵ�λ�ò�����������
//	{
//		tmp=arr[i];
//		for(j=i-1;j>=0;j--)
//		{
//			if(tmp>=arr[j])
//				break;
//		}
//		if(j<i-1)
//		{
//			for (k=i-1;k>j;k--)
//			{
//				arr[k+1]=arr[k];
//			}
//		}
//		arr[j+1]=tmp;
//	}
//}
//void InsertSort2(int arr[],int len)
//{
//	int i=0;
//	int j=0;
//	int tmp=0;
//	for (i=1;i<len;i++)
//	{
//		tmp=arr[i];
//		j=i-1;
//		while (j>=0 && tmp<arr[j])
//		{
//			arr[j+1]=arr[j];
//			j--;
//		}
//		arr[j+1]=tmp;
//	}
//}
void InsertSort3(int arr[],int len )
{
	int i=0;
	int j=0;
	int tmp=0;
	for (i=1;i<len;i++)
	{
		for (j=i-1;j>=0;j--)
		{
			if (arr[j+1]<arr[j])
			{
				swap(arr[j+1],arr[j]);
			}
		}
	}
}

int main()
{
	int i=0;
	int arr[100]={0};
	int len=sizeof(arr)/sizeof(arr[0]);
	srand((unsigned)time(NULL));//������ͬ�����������
	for(i=0;i<len;i++)
	{
		arr[i]=rand()%101;//��1-100�����������ʼ������
	}
	//InsertSort1(arr,len);
	//InsertSort2(arr,len);
	InsertSort3(arr,len);
	for(i=0;i<len;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	system("pause");
	return 0;
}