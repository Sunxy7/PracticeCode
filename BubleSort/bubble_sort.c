#include <stdio.h>
void bubble_sort(int arr[], int sz)
{
	int i = 0,j=0;
	int tmp = 0;
	int flag = 1;
	for (i = 0;i < sz;i++)
	{
		for (j = 0;j < sz -1- i;j++)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = tmp;
				flag = 0;
			}
		}
		if (flag == 1)
			break;
	}
}
int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,0 };
	int i = 0;
	int sz = sizeof(arr) / sizeof(arr[1]);
	bubble_sort(arr, sz);
	for (i = 0;i < sz;i++)
	{
		printf("%d ", arr[i]);
	}
	system("pause");
	return 0;
}
