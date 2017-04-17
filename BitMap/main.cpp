#include"BitMap.h"
//#include<bitset>

int main()
{
	BitMap  bt(100);
	//bitset<100> bt;
	
	bt.set(10);
	bt.set(0);
	bt.set(1);
	bt.set(2);

	cout << bt.test(1) << endl;
	cout << bt.test(10) << endl;
	cout << bt.test(0) << endl;
	cout << bt.test(2) << endl;
	//bt.reset(1);
	bt.reset(2);

	system("pause");
	return 0;
}