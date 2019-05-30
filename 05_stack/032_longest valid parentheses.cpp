#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int longestValidParentheses(string s)
{
	int start = 0, res = 0;
	stack<int> st;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '(') st.push(i);
		else if (s[i] == ')')
		{
			if (st.empty()) start = i + 1;
			else
			{
				st.pop();
				res = st.empty() ? max(res, i - start + 1) : max(res, i - st.top());
			}
		}
	}
	return res;
}

int main()
{
	string s = ")(()))";	// ")()())"
	cout << longestValidParentheses(s) << endl;
	system("pause");
	return 1;
}