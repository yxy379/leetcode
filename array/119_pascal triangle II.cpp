#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	vector<int> addRow(int n)
	{
		vector<int> prev;
		for (int i = 0; i <= n; i++)
		{
			vector<int> curr;
			curr.push_back(1);
			for (int j = 1; j <= i - 1; j++)
			{
				int prev2 = prev.at(j - 1);
				int prev1 = prev.at(j);
				curr.push_back(prev2 + prev1);
			}
			if (i >= 1)
			{
				curr.push_back(1);
			}
			prev = curr;
		}
		return prev;
	}
};

int main()
{
	Solution a;
	vector<int> res = a.addRow(3);
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << " ";
	system("pause");
	return 1;
}

