#include"BSTree.h"
void Test()
{
	BSTree st;
	/*st.Insert(5);
	st.Insert(7);
	st.Insert(3);
	st.Insert(4); 
	st.Insert(1); 
	st.Insert(6); 
	st.Insert(0);
	st.Insert(2);
	st.Insert(8);
	st.Insert(9);*/
	st.InsertR(5);
	st.InsertR(7);
	st.InsertR(3);
	st.InsertR(4);
	st.InsertR(1);
	st.InsertR(6);
	st.InsertR(0);
	st.InsertR(2);
	st.InsertR(8);
	st.InsertR(9);
	st.InOrder();
	/*cout<<"find 1 ? "<<st.Find(1)->_key<<endl;
	cout << "find 10 ? " << st.Find(10) << endl;
	cout << "find 7 ? " << st.Find(7)->_key << endl;
	cout << "find 5 ? " << st.Find(5)->_key << endl;
	cout << "find 0 ? " << st.Find(0)->_key << endl;*/
	cout << "find 1 ? " << st.FindR(1)->_key << endl;
	cout << "find 10 ? " << st.FindR(10) << endl;
	cout << "find 7 ? " << st.FindR(7)->_key << endl;
	cout << "find 5 ? " << st.FindR(5)->_key << endl;
	cout << "find 0 ? " << st.FindR(0)->_key << endl;
	st.InOrder();
	cout << "st.Remove(5)" <<st.Remove(5) << endl;
	cout << "st.Remove(2)" << st.Remove(2) << endl;
	cout << "st.Remove(8)" << st.Remove(8) << endl;
	cout << "st.Remove(1)" << st.Remove(1) << endl;
	cout << "st.Remove(4)" << st.Remove(4) << endl;
	cout << "st.Remove(1)" << st.Remove(1) << endl;
	cout << "st.Remove(10)" << st.Remove(10) << endl;
	st.InOrder();
	cout << "st.Remove(7)" << st.Remove(7) << endl;
	cout << "st.Remove(6)" << st.Remove(6) << endl;
	cout << "st.Remove(9)" << st.Remove(9) << endl;
	cout << "st.Remove(0)" << st.Remove(0) << endl;
	cout << "st.Remove(3)" << st.Remove(3) << endl;
	cout << "st.Remove(9)" << st.Remove(9) << endl;
	st.InOrder();
}
int main()
{
	Test();
	system("pause");
	return 0;
}