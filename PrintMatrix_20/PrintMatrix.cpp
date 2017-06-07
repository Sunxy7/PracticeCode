#include<iostream>
#include<cassert>
using namespace std;
void PrintMatrixInCircle(int **arr, int rows, int cols, int start)//打印矩阵的一圈
{
	int endX = cols - 1 - start;
	int endY = rows - 1 - start;
	int i = 0;
	if (endX >= start)//从左到右打印
	{
		for (i = start; i <= endX; i++)
		{
			cout << arr[start][i] << " ";
		}
	}
	if (endY>start)//从上到下打印
	{
		for (i = start + 1; i <= endY; i++)
		{
			cout << arr[i][endX] << " ";
		}
	}
	if (endX>start && endY>start)//从右向左打印
	{
		for (i = endX-1; i >= start; i--)
		{
			cout << arr[endY][i] << " ";
		}
	}
	if (endX>start && endY>start)//从下到上打印
	{
		for (i = endY-1; i >start; i--)
		{
			cout << arr[i][start] << " ";
		}
	}
	
}
void PrintMatrix(int ** arr,int rows,int cols)
{
	assert(arr);
	if (rows <= 0 || cols <= 0)
	{
		return;
	}
	int start = 0;
	while (rows>start*2 && cols>start*2)
	{
		PrintMatrixInCircle(arr, rows, cols, start);
		start++;
	}
	cout << endl;
}

int main()
{
	int arr1[1][5] = { 1,2,3,4,5 };
	int **p1 = new int*[1];
	for (int i = 0; i < 1; i++)
	{
		p1[i] = arr1[i];
	}
	PrintMatrix(p1, 1, 5);
	int arr2[4][4] = { {1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16} };
	int **p2 = new int*[4];
	for (int i = 0; i < 4; i++)
	{
		p2[i] = arr2[i];
	}
	PrintMatrix(p2, 4, 4);
	int arr3[5][1] = { {1},{2},{3},{4},{5} };
	int **p3 = new int*[5];
	for (int i = 0; i < 5; i++)
	{
		p3[i] = arr3[i];
	}
	PrintMatrix(p3, 5, 1);
	int arr4[1][1] = { 1 };
	int **p4 = new int*[1];
	for (int i = 0; i < 1; i++)
	{
		p4[i] = arr4[i];
	}
	PrintMatrix(p4, 1, 1);
	system("pause");
	return 0;
}