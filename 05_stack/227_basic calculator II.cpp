#include <iostream>
#include <stack>
using namespace std;

int calculator(string s)
{
	stack<int> st;
	long res = 0, num = 0;
	char op = '+';
	for (int i = 0; i < s.size(); i++)
	{
		if ((s[i] >= '0') && (s[i] <= '9'))
		{
			while ((s[i] >= '0') && (s[i] <= '9') && (i < s.size()))
			{
				num = num * 10 + (s[i] - '0');
				i++;
			}
			i--;
		}
		if ((s[i] == '+') || (s[i] == '-') || (s[i] == '*') || (s[i] == '/') || (i == s.size() - 1))
		{
			if (op == '+')
			{
				st.push(num);
				num = 0;
				op = s[i];
			}
			else if (op == '-')
			{
				st.push((-1 * num));
				num = 0;
				op = s[i];
			}
			else if (op == '*')
			{
				num = st.top()*num;
				st.pop();
				st.push(num);
				num = 0;
				op = s[i];
			}
			else if (op == '/')
			{
				num = st.top() / num;
				st.pop();
				st.push(num);
				num = 0;
				op = s[i];
			}
		}
	}
	while (!st.empty())
	{
		res += st.top();
		st.pop();
	}
	return res;
}

int main()
{
	cout << calculator(" 3 + 5 / 2 ") << endl;
	system("pause");
	return 1;
}