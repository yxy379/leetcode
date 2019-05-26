#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<vector<int>> combinationSum(vector<int>& nums, int target)
	{
		vector<vector<int>> res;
		vector<int> cur;
		dfs(nums, target, 0, cur, res);
		return res;
	}
private:
	void dfs(vector<int>& nums, int target, int start, vector<int>& cur, vector<vector<int>>& res)
	{
		if (target < 0) return;
		if (target == 0) 
		{
			res.push_back(cur); return;
		}

		for (int i = start; i < nums.size(); i++)
		{
			cur.push_back(nums[i]);
			dfs(nums, target - nums[i], i, cur, res);
			cur.pop_back();
		}
	}
};

int main()
{
	Solution a;
	vector<int> nums{ 2, 3, 5 };
	vector<vector<int>> res = a.combinationSum(nums, 8);
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