将数组A中的内容和数组B中的内容进行交换。（数组一样大）
#include <stdio.h>
int main()
{
	int arr1[] = {3,9,4,2,6};
	int arr2[] = {6,8,0,1,3};
	int i ,temp;
	for (i = 0;i < sizeof(arr1) / sizeof(arr1[0]);i++)
	{
		if (arr1[i] != arr2[i])
		{
			temp = arr1[i];
			arr1[i] = arr2[i];
			arr2[i] = temp;
		}
	}
	printf(" arr1:   ");
	for (i = 0;i < sizeof(arr1) / sizeof(arr1[0]);i++)
	printf(" %d", arr1[i]);
	printf("\n arr2:   ");
	for (i = 0;i < sizeof(arr2) / sizeof(arr2[0]);i++)
	printf(" %d", arr2[i]);
	system("pause");
	return 0;
}
将三个数按从大到小输出
#include <stdio.h>
int main()
{
	int a = 0;
	int b = 0;
	int c = 0;
	int temp;
	printf("请输入三个数：");
	scanf_s("%d %d %d", &a, &b, &c);
if (a < b)
{
	temp = a;
	a = b;
	b = temp;
}
if (b < c)
{
	temp = c;
	c = b;
	b = temp;
}
if (a < c)
{
	temp = c;
	c = a;
	a = temp;
}
	printf(" %d > %d > %d", a, b, c);
	system("pause");
	return 0;
}
求两个数的最大公约数
#include<stdio.h>
int main()
{
	int a =0, b=0;
	int r ;
	printf("请输入两个整数：");
	scanf_s("%d%d", &a, &b);
    r = a%b;
	while (r != 0 )
	{
		a = b;
		b = r;
		r = a%b;
	}
	printf("%d", b);
	system("pause");
	return 0;
}
获取一个数二进制序列中所有的偶数位和奇数位，分别输出二进制序列。
#include <stdio.h>
int main()
{
	int i, n;
	int arr[32];
	printf("请输入一个数：");
	scanf_s("%d", &n);
	while (n)
	{
		for (i = 32;i >=0;i--)
		{
			arr[i] = n % 2;
			n = n / 2;
		}
	}
	printf("该数的二进制序列为：\n");
	for (i = 0;i < 32;i++)
	{
		printf(" %d ", arr[i]);
	}
	printf("\n该数的二进制序列偶数位为：\n");
	for (i = 0;i < 32;i+=2)
	{
		printf(" %d ", arr[i]);
	}
	printf("\n该数的二进制序列奇数位为：\n");
	for (i = 0;i < 32;i+=2)
	{
		printf(" %d ", arr[i]);
	}
	system("pause");
    return 0;
}