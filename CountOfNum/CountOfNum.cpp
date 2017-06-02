#include<iostream>
using namespace std;

//int CountOfNum(int arr[], int len,int num)
//{
//	int count = 0;
//	int i = 0;
//	for (i = 0; i < len; i++)
//	{
//		if (arr[i] == num)
//		{
//			count++;
//		}
//	}
//	return count;
//}
int GetFirstNum(int arr[], int num, int start, int end)
{
	if (start < end)
	{
		int mid = (start + end) / 2;
		if (arr[mid] == num)
		{
			if ((mid>0 && arr[mid - 1] != num) || (mid == 0))
			{
				return mid;
			}
			else
			{
				end--;
			}
		}
		else if (arr[mid] < num)
		{
			start++;
		}
		else  //arr[mid]>num
		{
			end--;
		}
		return GetFirstNum(arr, num, start, end);
	}
	return -1;
}

int GetLastNum(int arr[], int num, int start, int end)
{
	if (start < end)
	{
		int mid = (start + end) / 2;
		if (arr[mid] == num)
		{
			if ((mid < end &&arr[mid + 1] != num) || mid == end)
			{
				return mid;
			}
			else
			{
				end++;
			}
		}
		else if (arr[mid] < num)
		{
			start++;
		}
		else   //arr[mid]>num
		{
			end--;
		}
		return GetLastNum(arr, num, start, end);
	}
	return -1;
}
int CountOfNum(int arr[], int len, int num)
{
	int first = GetFirstNum(arr, num, 0, len-1);
	int last = GetLastNum(arr, num, 0, len-1);
	if (first == -1 || last == -1)
	{
		return -1;
	}
	int count = last - first + 1;
	return count;
}

int main()
{
	int arr[] = { 1,2,3,3,3,3,3,4,4,4,5,6,6,7 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int ret=CountOfNum(arr,len, 3);
	if (ret == -1)
	{
		cout << "num is not found!" << endl;
	}
	else
	{
		cout << ret << endl;
	}
	
	system("pause");
	return 0;
}