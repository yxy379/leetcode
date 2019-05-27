#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
	vector<vector<int>> subsets(vector<int>& nums)
	{
		vector<vector<int>> res;
		vector<int> curr;
		sort(nums.begin(), nums.end());
		for (int i = 0; i <= nums.size(); i++)
		{
			dfs(nums, 0, i, curr, res);
		}
		return res;
	}
private:
	void dfs(vector<int>&nums, int index, int target, vector<int>& curr, vector<vector<int>>& res)
	{
		if (target == 0)
		{
			res.push_back(curr);
			return;
		}
		for (int i = index; i < nums.size(); i++)
		{
			curr.push_back(nums[i]);
			dfs(nums, i + 1, target - 1, curr, res);
			curr.pop_back();
		}
	}
};

int main()
{
	vector<int> nums{ 1, 2, 3 };
	Solution a;
	vector<vector<int>> res = a.subsets(nums);
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