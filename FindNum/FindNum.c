#include <stdio.h>

int FindNum(int num,int arr[4][5],int rows,int cols)
{
	int row = 0;
	int col =cols -1;
	while(row<rows && col>=0)
	{
		if(num < arr[row][col])
		{
			col--;
		}
		else if(num > arr[row][col])
		{
			row++;
		}
		else
		{
			return 1;
		}
	}
	return 0;
}
int main()
{
	int arr[4][5]={{1,2,3,4,5},{3,4,5,6,7},{5,6,7,8,9},{7,8,9,10,11}};
	int ret = FindNum(2,arr,4,5);
	if (ret == 1)
	{
		printf("num is exist!\n");
	}
	else
	{
		printf("num is not find!\n");
	}
	system("pause");
	return 0;
}