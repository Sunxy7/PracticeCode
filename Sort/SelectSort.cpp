#include <iostream>
#include<stdlib.h>
#include <time.h>
using namespace std;
//void SelectSort(int arr[], int len)
//{
//	int i = 0;
//	int j = 0;
//	int min = 0;
//	for (i = 0; i < len; i++)
//	{
//		min = i;
//		for (j = i + 1; j < len; j++)//������������СԪ��
//		{
//			if (arr[j] < arr[min])
//			{
//				min = j;
//			}
//		}
//		if (i != min)//����������ĵ�һ��λ�ò�����СԪ�زŽ���
//		{
//			swap(arr[i], arr[min]);
//		}
//	}
//}
//void SelectSort(int arr[],int len)
//{
//	int min=0;//��СԪ���±�
//	int max=len-1;//���Ԫ���±�
//	int i=0;
//	while (min <= max)
//	{
//		i=min+1;
//		while (i>=min && i<=max )
//		{
//			if (arr[min]>arr[max])
//			{
//				swap(arr[min],arr[max]);
//			}
//			if(arr[i]<arr[min])
//			{
//				swap(arr[i],arr[min]);
//			}
//			if (arr[i]>arr[max])
//			{
//				swap(arr[i],arr[max]);
//			}
//			i++;
//		}
//		min++;
//		max--;
//	}
//}
void SelectSort(int arr[], int len)
{
	int min = 0;
	int max = len-1;
	int i = 0;
	int minIndex = 0;
	int maxIndex = 0;
	while(min<max)
	{
		int minIndex = min;
		int maxIndex = max;
		if (arr[min] > arr[max])//����arr[min]Ϊ���Ԫ�أ�arr[max]Ϊ��СԪ�أ���������ҵ����
		{
			swap(arr[min], arr[max]);
		}
		for (i = min; i <=max; i++)
		{
			if (arr[i] < arr[minIndex])
				minIndex = i;
			if (arr[i] > arr[maxIndex])
				maxIndex = i;
		}
		if(minIndex!=min)
		{ 
			swap(arr[minIndex], arr[min]);
		}
		if (maxIndex != max)
		{
			swap(arr[maxIndex], arr[max]);
		}
		min++;
		max--;
	}	
}
int main()
{
	int i=0;
	//int arr[]={ 6,2,9,1,7,3,4,0,8,5 };
	int arr[] = { 0,55,45,20,46,27,31,3,2,0,1,5,11,34,53,27,29,47,8,6,5,5,5,60,4,8,8,7,4,32,9 };
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