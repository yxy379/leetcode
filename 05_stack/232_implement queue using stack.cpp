#include <iostream>
#include <stack>
#include <queue>
using namespace std;

class QueueUsingStack
{
public:
	QueueUsingStack() {}

	void push(int x)
	{
		stack<int> t;
		while (!s.empty())
		{
			t.push(s.top());
			s.pop();
		}
		s.push(x);
		while (!t.empty())
		{
			s.push(t.top());
			t.pop();
		}
	}

	void pop()
	{
		s.pop();
	}

	int peek()
	{
		return s.top();
	}

	bool empty()
	{
		return s.empty();
	}

private:
	stack<int> s;
};

int main()
{
	QueueUsingStack q;
	q.push(1);
	q.push(2);
	cout << q.peek() << endl;	// return 1
	q.pop();
	cout << q.empty() << endl;	// return false
	system("pause");
	return 1;
}


