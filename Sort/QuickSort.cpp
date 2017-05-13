#include<iostream>
using namespace std;

void QuickSort(int arr[],int left,int right )
{
	if (left < right)
	{
		int i = left;
		int j = right;
		int div = arr[i];
		while (i < j)
		{
			while (i<j && arr[j] > div)
			{
				j--;
			}
			arr[i] = arr[j];
			while (i < j && arr[i] <= div)
			{
				i++;
			}
			arr[j] = arr[i];
		}
		arr[i] = div;
		QuickSort(arr, left, i - 1);
		QuickSort(arr, i + 1, right);
	}
	
}
int main()
{
	int i;
	int arr[10] = {4,5,8,3,7,1,2,9,0,6};
	int len = sizeof(arr)/sizeof(arr[0]);
	QuickSort(arr, 0, len - 1);
	for (i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}