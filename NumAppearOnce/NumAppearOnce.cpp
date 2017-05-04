#include <iostream>
using namespace std;

//int NumAppearOnce(int arr[],int len)//数组中一个数字只出现了一次，其他数字均出现了两次
//{
//	int i=0;
//	int ret=0;
//	for (i=0;i<len;i++)
//	{
//		ret ^= arr[i];
//	}
//	return ret;
//}

int FirstBitIsOne(int num)//
{
	int index=0;
	while ( (num & 1)==0 && index < 4*sizeof(int) )
	{
		num = num >> 1;
		index++;
	}
	return index;
}
bool BitIsOne(int num,int index)
{
	num=num >> index;
	return(num & 1);
}

void NumAppearOnce(int arr[],int len)//数组中两个数字只出现了一次，其他数字均出现了两次
{
	int i=0;
	int ret=0;//异或结果
	int index =0;//异或结果中为1的位
	int num1=0;//first appear once
	int num2=0;//second appear once
	for (i=0;i<len;i++)
	{
		ret ^=arr[i];
	}
	index = FirstBitIsOne(ret);
	for (i=0;i<len;i++)
	{
		if (BitIsOne(arr[i],index))
		{
			num1 ^=  arr[i];
		}
	}
	printf("first appear once num is %d\n",num1);
	for (i=0;i<len;i++)
	{
		if ( !BitIsOne(arr[i],index))
		{
			num2 ^=  arr[i];
		}
	}
	printf("second appear once num is %d\n",num2);

}

int main()
{
	int arr[16]={19,5,8,1,3,9,29,5,21,8,3,21,1,29,19,7};
	int len =sizeof(arr)/sizeof(arr[0]);
	NumAppearOnce(arr,len);
	system("pause");
	return 0;
}