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
//bool Increment(char *number,int len)
//{
//	bool overflow = false;
//	int flag= 0;
//	int sum = 0;
//	int i = 0;
//	for (i = len - 1; i >= 0; i--)
//	{
//		int sum = number[i]-'0'+flag;
//		if (i == len - 1)
//		{
//			sum++;
//		}
//		if (sum >= 10)
//		{
//			if (i == 0)//最高位产生进位，打印完成
//			{
//				overflow = true;
//				break;
//			}
//			else
//			{
//				sum -= 10;
//				flag=1;
//				number[i] = sum + '0';
//			}
//		}
//		else
//		{
//			number[i] = '0' + sum;
//			break;
//		}
//			
//	}
//	return overflow;
//}
//void MaxOfDigit(int n)
//{
//	char *str = new char[n + 1];
//	memset(str, '0', n);
//	str[n] = '\0';
//	while (!Increment(str,n))
//	{
//		PrintNum(str);
//	}
//	cout << endl;
//  delete[] str; 
//}
void IncrementR(char *num, int len, int index)
{
	int i = 0;
	if (len <= 0 || index < 0)
	{
		return;
	}
	if (index == len - 1)
	{
		PrintNum(num);
		return;
	}
	for (i = 0; i < len; i++)
	{
		num[index+1] = i + '0';
		IncrementR(num, len, index +1);
	}
}
void MaxToDigitR(int n)
{
	if (n <= 0 )
	{
		return;
	}
	char *num = new char[n + 1];
	memset(num, '0', n);
	num[n] = '\0';
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		num[0] = i + '0';
		IncrementR(num,n,0);
	}
	cout << endl;
	delete[] num;
}

int main()
{
	int n;
	cout << "please enter a number:" << endl;
	cin >> n;
	//MaxOfDigit(n);
	MaxToDigitR(n);
	system("pause");
	return 0;
}