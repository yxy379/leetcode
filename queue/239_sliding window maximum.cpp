#include <vector>
#include <deque>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
	vector<double> slidingMax(vector<double>& num, int k)
	{
		vector<double> res;
		deque <double> q;

		for (int i = 0; i < num.size(); i++)
		{
			if (!q.empty() && (q.front() == i - k)) q.pop_front();
			while (!q.empty() && (num[q.back()] < num[i])) q.pop_back();
			q.push_back(i);

			if (i >= k - 1) res.push_back(num[q.front()]);
		}
		return res;
	}
};

int main()
{
	vector<double> num{ 1, 3, -1, -3, 5, 3, 6, 7 };
	Solution a;
	vector<double> res = a.slidingMax(num, 3);
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << " ";
	}
	system("pause");
	return 0;
}