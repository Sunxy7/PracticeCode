#include<iostream>
#include<cstring>
using namespace std;

void PrintNum(char *number)
{
	int i = 0;
	int len = strlen(number);
	bool isbegin = true;
	for (i = 0; i < len; i++)
	{
		if (isbegin ==true && number[i] != '0')
		{
			isbegin = false;
		}
		if(!isbegin)
		printf("%c", number[i]);
	}
	printf("\t");
}
bool Increment(char *number,int len)
{
	bool overflow = false;
	int flag= 0;
	int sum = 0;
	int i = 0;
	for (i = len - 1; i >= 0; i--)
	{
		int sum = number[i]-'0'+flag;
		if (i == len - 1)
		{
			sum++;
		}
		if (sum >= 10)
		{
			if (i == 0)//最高位产生进位，打印完成
			{
				overflow = true;
				break;
			}
			else
			{
				sum -= 10;
				flag=1;
				number[i] = sum + '0';
			}
		}
		else
		{
			number[i] = '0' + sum;
			break;
		}
			
	}
	return overflow;
}
void MaxOfDigit(int n)
{
	char *str = new char[n + 1];
	memset(str, '0', n);
	str[n] = '\0';
	while (!Increment(str,n))
	{
		PrintNum(str);
	}
	cout << endl;
}

int main()
{
	int n;
	cout << "please enter a number:" << endl;
	cin >> n;
	MaxOfDigit(n);
	system("pause");
	return 0;
}