#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
	vector<vector<int>> combinationSum(vector<int>& nums, int target)
	{
		vector<int> cur;
		vector<vector<int>> res;
		sort(nums.begin(), nums.end());
		dfs(nums, target, 0, cur, res);
		return res;
	}
private:
	void dfs(vector<int>&nums, int target, int start, vector<int>& cur, vector<vector<int>>& res)
	{
		if (target < 0) return;
		if (target == 0)
		{
			res.push_back(cur);
			return;
		}

		for (int i = start; i < nums.size(); i++)
		{
			if ((i > start) && (nums[i] == nums[i - 1])) continue;
			cur.push_back(nums[i]);
			dfs(nums, target - nums[i],  i + 1, cur, res);
			cur.pop_back();
		}
	}
};

int main()
{
	vector<int> nums{ 10,1,2,7,6,1,5 };
	int target = 8;
	Solution a;
	vector<vector<int>> res = a.combinationSum(nums, target);
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