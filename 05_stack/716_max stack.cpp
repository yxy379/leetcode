#include <iostream>
#include <stack>
using namespace std;

class MaxStack
{
public:
	MaxStack() {}

	void push(int x)
	{
		if (st.empty())
		{
			maxSt.push(x);
		}
		if (maxSt.top() <= x)
		{
			maxSt.push(x);
		}
		st.push(x);
	}

	int pop()
	{
		if (maxSt.top() == st.top())
		{
			maxSt.pop();
		}
		int tmp = st.top();
		st.pop();
		return tmp;
	}

	int top()
	{
		return st.top();
	}

	int peekMax()
	{
		return maxSt.top();
	}

	int popMax()
	{
		int tmp = maxSt.top();
		stack<int> t;
		while (st.top() != maxSt.top())
		{
			t.push(st.top());
			st.pop();
		}
		st.pop();
		maxSt.pop();
		while (!t.empty())
		{
			st.push(t.top());
			t.pop();
		}
		return tmp;
	}

private:
	stack<int> st;
	stack<int> maxSt;
};

int main()
{
	MaxStack stack;
	stack.push(5);
	stack.push(1);
	stack.push(5);
	cout << stack.top() << endl;	// return 5
	cout << stack.popMax() << endl;	// return 5
	cout << stack.top() << endl;	// return 1
	cout << stack.peekMax() << endl;// return 5
	stack.pop();
	cout << stack.top() << endl;			// return 5
	system("pause");
	return 1;
}