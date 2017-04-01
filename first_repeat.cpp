#include<iostream>
#include<string>
using namespace std;

class FindFirstRepeat
{
public:
	char find_first_repeat(string A, int n)
	{
		char buf[256] = {0};
		int index = 0;
		for (int i = 0; i < A.size(); i++)
		{
			index = A[i];
			if ((buf[index]==0))
			{
				buf[index]++;
			}
			else
			{
				return index;
			}
		}
		return -1;
	}
};

int main()
{
	string str = "ab223cdddd";
	FindFirstRepeat rp;
	cout << "first repeat num is: "<<rp.find_first_repeat(str, str.size()) << endl;
	system("pause");
	return 0;
}