#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<vector<int>> combination(int n, int k)
	{
		vector<int> curr;
		vector<vector<int>> res;
		dfs(n, k, 1, curr, res);
		return res;
	}
private:
	void dfs(int n, int k, int index, vector<int>& curr, vector<vector<int>>& res)
	{
		if (k == 0)
		{
			res.push_back(curr);
			return;
		}
		for (int i = index; i <= n; i++)
		{
			curr.push_back(i);
			dfs(n, k - 1, i + 1, curr, res);
			curr.pop_back();
		}
	}
};

int main()
{
	Solution a;
	vector<vector<int>> res = a.combination(4, 2);
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