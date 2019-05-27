#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<vector<int>>combinationSum(int k, int target)
	{
		vector<int> curr;
		vector<vector<int>> res;
		dfs(k, target, 1, curr, res);
		return res;
	}
private:
	void dfs(int k, int target, int start, vector<int>& curr, vector<vector<int>>& res)
	{
		if (target < 0) return;
		if ((curr.size() == k) && (target == 0))
		{
			res.push_back(curr);
			return;
		}
		for (int i = start; i <= 9; i++)
		{
			curr.push_back(i);
			dfs(k, target - i, i + 1, curr, res);
			curr.pop_back();
		}
	}
};

int main()
{
	Solution a;
	vector<vector<int>> res = a.combinationSum(3, 9);
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

