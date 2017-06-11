#include<iostream>
#include<stack>
using namespace std;
template<class T>
class Queue
{
public:
	Queue()
	{}
	~Queue()
	{}
	void AppendTail(const T data)//尾部插入节点
	{
		s1.push(data);
	}
	T DeleteHead()//头部删除节点
	{
		if (s2.empty())
		{
			while (!s1.empty())
			{
				s2.push(s1.top());
				s1.pop();
			} 
		}
		T ret = s2.top();
		s2.pop();
		return ret;
	}
private:
	stack<T> s1;
	stack<T> s2;
};
int main()
{
	Queue<int> q;
	q.AppendTail(1);
	q.AppendTail(2);
	q.AppendTail(3);
	cout << q.DeleteHead() << endl;
	cout << q.DeleteHead() << endl;
	q.AppendTail(4);
	q.AppendTail(5);
	cout << q.DeleteHead() << endl;
	cout << q.DeleteHead() << endl;
	cout << q.DeleteHead() << endl;


	system("pause");
	return 0;

}