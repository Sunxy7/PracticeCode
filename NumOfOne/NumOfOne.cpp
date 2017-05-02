#include <iostream>
using namespace std;

//int NumOfOne(int num)
//{
//	int count=0;
//	unsigned int flag =1;
//	while (flag)
//	{
//		if (flag & num)
//		{
//			count++;
//		}
//		flag = flag << 1;
//	}
//	return count;
//}
int NumOfOne(int num)//ÓÅ»¯
{
	int count =0;
	while (num)
	{
		num =num&(num-1);
		count ++;
	}
	return count;
}

int main()
{
	int ret=NumOfOne(-7);
	cout<<ret<<endl;

	system("pause");
	return 0;
}