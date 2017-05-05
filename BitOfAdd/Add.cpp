#include<iostream>
using namespace std;
int Add(int num1,int num2)
{
	int sum =0;
	int tmp =0;
	do 
	{
		sum =num1^num2;
		tmp =(num1 & num2)<<1;
		num1 =sum;
		num2 =tmp;
	} while (num2 != 0 );

	return num1;
}
int main()
{
	int num1 =5;
	int num2 =8;
	int sum =Add(5,8);
	cout<<num1<<" and "<<num2<<" sum is "<<sum<<endl;
	system("pause");
	return 0;
}