#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h> 
int main()
{
	int arr1[100];
	int arr2[100];
	int m, n;
	int min = 100;
	scanf("&d", &m);
	scanf("&d", &n);
	for (int i = 0; i<m; i++)
	{
		scanf("%d", &arr1[i]);
	}
	for (int j = 0; j<n; j++)
	{
		scanf("&d",&arr2[j]);
		//arr2[j] = j;
	}

	for (int a = 0; a<m; a++)
	{
		for (int b = 0; b<n; b++)
		{
			int tmp = arr1[a] - arr2[b];
			if (tmp<0)
				tmp = -tmp;
			if (min>tmp)
				min = tmp;
		}
	}
	printf(" %d  \n", min);
	return 0;
}