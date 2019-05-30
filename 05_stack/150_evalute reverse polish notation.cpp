#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

int evaluateRPN(vector<string>& s)
{
	if (s.size() == 1) return stoi(s[0]);
	stack<int> st;
	for (int i = 0; i < s.size(); i++)
	{
		if ((s[i] != "+") && (s[i] != "-") && (s[i] != "*") && (s[i] != "/"))
		{
			st.push(stoi(s[i]));
		}
		else
		{
			int num1 = st.top();
			st.pop();
			int num2 = st.top();
			st.pop();
			if (s[i] == "+") st.push(num1 + num2);
			if (s[i] == "-") st.push(num2 - num1);
			if (s[i] == "*") st.push(num2 * num1);
			if (s[i] == "/") st.push(num2 / num1);
		}
	}
	return st.top();
}

int main()
{
	vector<string> s = { "10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+" };
	cout << evaluateRPN(s) << endl;
	system("pause");
	return 1;
}