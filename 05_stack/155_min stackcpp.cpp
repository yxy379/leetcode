#include <iostream>
#include <stack>
using namespace std;

class MinStack
{
public:
	void push(int val)
	{
		if (st.empty()) min.push(val);
		else
		{
			if (val <= min.top()) min.push(val);
		}
		st.push(val);
	}

	void pop()
	{
		if (st.empty()) return;
		if (st.top() == min.top()) min.pop();
		st.pop();
	}

	int getMin()
	{
		return min.top();
	}

	int top()
	{
		return st.top();
	}

private:
	stack<int> min;
	stack<int> st;
};

int main()
{
	MinStack a;
	a.push(-2);
	a.push(0);
	a.push(-3);
	cout << a.getMin() << endl;	// return -3
	a.pop();
	cout << a.top() << endl;	// return 0
	cout << a.getMin() << endl; // return -2
	system("pause");
	return 1;
}