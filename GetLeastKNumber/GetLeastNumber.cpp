#include<iostream>
#include<vector>
#include<set>
using namespace std;

typedef multiset<int,greater<int>> Set;
typedef multiset<int,greater<int>>::iterator Iterator;

void GetLeastKNumber(const vector<int>& input,Set &leastNum,int k)
{
	if (k < 1 || input.size() < k)
		return;
	vector<int>::iterator it = input.begin();
	for (; it != input.end(); ++it)
	{
		if (leastNum.size() < k)
		{
			leastNum.insert(*it);
		}
		else
		{
			Set ItGreat = leastNum.begin();
			if (*it < (*leastNum.begin()))
			{
				leastNum.erase(ItGreat);
				leastNum.insert(*it);
			}
		}
	}
}

int main()
{
	int arr[] = { 1,7,2,0,6,8,3,9,11,5,6 };
	vector<int> input;
	Set leastNum;
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		input.insert(arr[i]);
	}
	for (vector<int>::iterator it = input.begin(); it != input.end(); it++)
	{
		cout << *it << " ";
	}
	cout<<endl;
	GetLeastKNumber(input,leastNum,4);
	for (Iterator it = leastNum.begin(); it != leastNum.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}