#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
	vector<vector<int>> permutations(vector<int>& nums)
	{
		vector<vector<int>> res;
		vector<int> curr, visited(nums.size(), 0);
		sort(nums.begin(), nums.end());
		dfs(nums, 0, visited, curr, res);
		return res;
	}

private:
	void dfs(vector<int>& nums, int level, vector<int>& visited, vector<int>& curr, vector<vector<int>>& res)
	{
		if (level == nums.size())
		{
			res.push_back(curr);
			return;
		}
		for (int i = 0; i < nums.size(); i++)
		{
			if ((i > 0) && (nums[i] == nums[i - 1]) && (visited[i - i] == 0)) continue;
			if (visited[i] == 1) continue;
			curr.push_back(nums[i]);
			visited[i] = 1;
			dfs(nums, level + 1, visited, curr, res);
			curr.pop_back();
			visited[i] = 0;
		}
	}
};

int main()
{
	vector<int> nums{ 1, 1, 2 };
	Solution a;
	vector<vector<int>> res = a.permutations(nums);
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
