#include<iostream>
#include<cassert>
using namespace std;

void Reverse(char *start, char *end)
{
	assert(start);
	assert(end);
	while (start < end)
	{
		char tmp = *start;
		*start = *end;
		*end = tmp;
		start++;
		end--;
	}
}
void LeftRotate(char *str,int n)//½«×Ö·û´®str×óĞınÎ»
{
	assert(str);
	int len = strlen(str);
	if (len > 0 && len >= n && n >= 0)
	{
		char *FirstStart = str;
		char *FirstEnd = str + n - 1;
		char *SecondStart = str + n;
		char *SecondEnd = str + len - 1;
		Reverse(FirstStart, FirstEnd);
		Reverse(SecondStart, SecondEnd);
		Reverse(FirstStart, SecondEnd);
	}

}
int main()
{
	char str[] = "abcdefgh";
	LeftRotate(str, 3);
	cout << str << endl;
	system("pause");
	return 0;
}