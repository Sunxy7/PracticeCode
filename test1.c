������A�е����ݺ�����B�е����ݽ��н�����������һ����
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
�����������Ӵ�С���
#include <stdio.h>
int main()
{
	int a = 0;
	int b = 0;
	int c = 0;
	int temp;
	printf("��������������");
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
�������������Լ��
#include<stdio.h>
int main()
{
	int a =0, b=0;
	int r ;
	printf("����������������");
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
��ȡһ�������������������е�ż��λ������λ���ֱ�������������С�
#include <stdio.h>
int main()
{
	int i, n;
	int arr[32];
	printf("������һ������");
	scanf_s("%d", &n);
	while (n)
	{
		for (i = 32;i >=0;i--)
		{
			arr[i] = n % 2;
			n = n / 2;
		}
	}
	printf("�����Ķ���������Ϊ��\n");
	for (i = 0;i < 32;i++)
	{
		printf(" %d ", arr[i]);
	}
	printf("\n�����Ķ���������ż��λΪ��\n");
	for (i = 0;i < 32;i+=2)
	{
		printf(" %d ", arr[i]);
	}
	printf("\n�����Ķ�������������λΪ��\n");
	for (i = 0;i < 32;i+=2)
	{
		printf(" %d ", arr[i]);
	}
	system("pause");
    return 0;
}