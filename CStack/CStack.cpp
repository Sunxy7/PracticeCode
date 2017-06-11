#include<iostream>
#include<queue>
using namespace std;
template<class T>
class Stack
{
public:
	Stack()
	{}
	~Stack()
	{}
	void AppendTail(const T data)
	{
		if (q1.empty())
		{
			q2.push(data);
		}
		else
		{
			q1.push(data);
		}
	}
	T DeleteHead()
	{
		T ret=0;
		if (q1.empty() && q2.empty())
		{
			cout << "stack is empty!" << endl;
			return ret;
		}
		if (q1.empty())
		{
			while (q2.size()>1)
			{
				q1.push(q2.front());
				q2.pop();
			}
			ret = q2.front();
			q2.pop();
		}
		else 
		{
			while (q1.size()>1)
			{
				q2.push(q1.front());
				q1.pop();
			}
			ret = q1.front();
			q1.pop();
		}
		return ret;
	}
private:
	queue<T> q1;
	queue<T> q2;
};
int main()
{
	Stack<int> s;
	s.AppendTail(1);
	s.AppendTail(2);
	s.AppendTail(3);
	cout << s.DeleteHead() << endl;
	cout << s.DeleteHead() << endl;
	s.AppendTail(4);
	cout << s.DeleteHead() << endl;
	cout << s.DeleteHead() << endl;
	cout << s.DeleteHead() << endl;
	system("pause");
	return 0;
}