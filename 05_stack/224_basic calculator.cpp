#include <iostream>
#include <stack>
using namespace std;

int calculator(string s)
{
	stack<int> st;
	int res = 0, sign = 1;
	for (int i = 0; i < s.size(); i++)
	{
		if ((s[i] >= '0') && (s[i] <= '9'))
		{
			int num = 0;
			while ((s[i] >= '0') && (s[i] <= '9') && (i < s.size()))
			{
				num = num * 10 + (s[i] - '0');
				i++;
			}
			res += num * sign;
			i--;
		}
		else if (s[i] == '+')
		{
			sign = 1;
		}
		else if (s[i] == '-')
		{
			sign = -1;
		}
		else if (s[i] == '(')
		{
			st.push(res);
			st.push(sign);
			res = 0;
			sign = 1;
		}
		else if (s[i] == ')')
		{
			res *= st.top();
			st.pop();
			res += st.top();
			st.pop();
		}
	}
	return res;
}

int main()
{
	cout << calculator("   (1+(4+5+2)-3)+(6+8)");
	system("pause");
	return 1;
}