#include<iostream>
using namespace std;
bool IsEqual(double n1, double n2)
{
	if ((n1 - n2) > -0.0000001 && (n1 - n2) < 0.0000001)
		return true;
	else
		return false;
}
double Power(double base, int exponent)
{
	if (IsEqual(base, 0.0) && exponent<0)
	{
		printf("input is invalid\n");
		return 0;
	}
	if (exponent == 0|| base == 1)
	{
		return 1;
	}
	unsigned int absexponent = (unsigned int) exponent;
	if (exponent < 0)
	{
		absexponent = (unsigned int)(-exponent);
	}
	double result = base;
	for (int i = 1; i < absexponent; i++)
	{
		result *= base;
	}
	if (exponent < 0)
		result = 1.0 / result;
	return result;
}

int main()
{
	cout << Power(0, 0) << endl;
	cout << Power(1, 0) << endl;
	cout << Power(1, 1) << endl;
	cout << Power(0, -1) << endl;
	cout << Power(2, -1) << endl;
	cout << Power(2, 10) << endl;
	cout << Power(2, -2) << endl;
	system("pause");
	return 0;
}