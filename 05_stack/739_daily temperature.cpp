#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> dailyTemperatures(vector<int>& t)
{
	vector<int> res(t.size(), 0);
	for (int i = 0; i < t.size(); i++)
	{
		for (int j = i+1; j < t.size(); j++)
		{
			if (t[j] > t[i])
			{
				res[i] = j - i;
				break;
			}
		}
	}
	return res;
}

vector<int> dailyTemperatures1(vector<int>& t)
{
	vector<int> res(t.size(), 0);
	stack<int> st;
	for (int i = 0; i < t.size(); i++)
	{
		while ((!st.empty()) && (t[i] > t[st.top()]))
		{
			auto tmp = st.top();
			st.pop();
			res[tmp] = i - tmp;
		}
		st.push(i);
	}
	return res;
}

int main()
{
	vector<int> t{ 73,74,75,71,69,72,76,73 };
	vector<int> res = dailyTemperatures1(t);
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << " ";
	}
	system("pause");
	return 1;
}