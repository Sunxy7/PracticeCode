#pragma once
#include<iostream>
using namespace std;
void AdjustHeap(int arr[],int i)//插入节点i
{
	int j = (i - 1) / 2;//父节点下标
	int tmp = arr[i];
	while (j>=0 && i!=0)
	{
		if (tmp > arr[j])
			break;
		arr[i] = arr[j];
		i = j;
		j = (i - 1) / 2;
	}
	arr[i] = tmp;
}
void AdjustDown(int arr[],int i,int n)//删除节点i，共有n个节点
{
	int j = i * 2 + 1;//父节点
	int tmp = arr[i];
	while (j<n)
	{
		if (arr[j] > arr[j + 1])//子节点中找较小的
		{
			j++;
		}
		if (tmp < arr[j])
		{
			break;
		}
		arr[i] = arr[j];
		i = j;
		j = i * 2 + 1;
	}
	arr[i] = tmp;
}
void Insert(int arr[],int i,int num)
{
	arr[i] = num;
	AdjustHeap(arr, i);
}
void Delete(int arr[], int n)
{
	swap(arr[0], arr[n - 1]);
	AdjustDown(arr,0,n);
}
void MakeHeap(int arr[], int n)
{
	int i = 0;
	for (i = n / 2 - 1; i >= 0; i--)//((n-1)*2)+1 =n/2-1
	{
		AdjustDown(arr, i, n);
	}
}