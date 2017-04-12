#include <stdio.h>
//int fib(int n)
//{
//	int fib1 =1;
//	int fib2 =1;
//	int fib = 1;
//	int i = 0;
//	while (n > 2)
//	{
//
//		fib = fib1 + fib2;
//		fib1 = fib2;
//		fib2 = fib;
//		n--;
//		/*fib1 = fib1 + fib2;
//		fib2 = fib1 - fib2;
//		n--;*/
//	}
//	return fib ;
//}
int fib(int n)
{
	if (n <= 2)
		return 1;
	else
	{
		return fib(n - 1) + fib(n - 2);
	}
}
int main()
{
	int n = 0;
	int ret = 0;
	printf("请输入要求 Fibionacci 数列的第几个数：\n");
	scanf("%d", &n);
	ret = fib(n);
	printf("%d \n", ret);
	system("pause");
	return 0;
}