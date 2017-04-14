#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <assert.h>
int my_calculator( char *p,int a,int b )
{
	assert(p);
	int tmp = 0;
		if (p== "-a")
				 tmp =  a+ b;
		if (p == "-s")
				 tmp = a - b;
		if (p == "-m")
			     tmp = a * b;
		if (p == "-d")
				 tmp = a / b;

	return tmp; 
}
int main()
{
	int num1 = 0;
	int num2 = 0;
	char c;
	char *p =&c;
	int ret = 0;
	printf("请输入要运算的值：（例：1+2)\n");
	scanf("%d%c%d", &num1, &c, &num2);
		if (c == '+')
		{
			p = "-a";
		}
		else if (c == '+')
		{
			p = "-s";
		}
		else if (c == '+')
		{
			p = "-m";
		}
		else if (c == '+')
		{
			p = "-d";
		}
		else
				printf("请输入正确的符号\n");

	ret= my_calculator(p, num1, num2);
	printf("%d\n", ret);
	system("pause");
	return 0;
}