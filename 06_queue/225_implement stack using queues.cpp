#include <iostream>
#include <queue>
using namespace std;

class MyStack
{
public:
	void push(int x)
	{
		queue<int> tmp;
		while (!q.empty())
		{
			tmp.push(q.front());
			q.pop();
		}
		q.push(x);
		while (!tmp.empty())
		{
			q.push(tmp.front());
			tmp.pop();
		}
	}

	void pop()
	{
		q.pop();
	}

	int top()
	{
		return q.front();
	}

	bool empty()
	{
		return q.empty();
	}


private:
	queue<int> q;
};

int main()
{
	MyStack s;
	s.push(1);
	s.push(2);
	cout << s.top() << endl;	// return 2
	s.pop();
	cout << s.empty() << endl;	// return 0
	system("pause");
	return 1;
}