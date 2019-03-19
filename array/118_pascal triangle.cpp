#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	vector<vector<int>> pascalTriangle(int n)
	{
		vector<vector<int>> res;
		vector<int> prev;
		
		for (int i = 1; i <= n; i++)
		{
			vector<int> curr;
			curr.push_back(1);
			for (int j = 1; j < i - 1; j++)
			{
				int prev2 = prev.at(j - 1);
				int prev1 = prev.at(j);
				curr.push_back(prev2 + prev1);
			}
			if (i > 1)
			{
				curr.push_back(1);
			}
			prev = curr;
			res.push_back(curr);
		}
		return res;
	}
};

int main()
{
	Solution a;
	vector<vector<int>> res = a.pascalTriangle(30);
	for (int i = 0; i < res.size(); i++)
	{
		for (int j = 0; j < res[i].size(); j++)
		{
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
	system("pause");
	return 1;
}