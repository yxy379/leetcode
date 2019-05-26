#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
	vector<vector<int>> subsets(vector<int>& nums)
	{
		vector<int> curr;
		vector<vector<int>> res;
		sort(nums.begin(), nums.end());
		//res.push_back(curr);
		dfs(nums, 0, curr, res);
		return res;
	}
private:
	void dfs(vector<int>& nums, int index, vector<int>& curr, vector<vector<int>>& res)
	{
		res.push_back(curr);
		for (int i = index; i < nums.size(); i++)
		{	
			if ((i > index) && (nums[i] == nums[i - 1])) continue;
			curr.push_back(nums[i]);
			//res.push_back(curr);
			dfs(nums, i + 1, curr, res);
			curr.pop_back();
		}
	}
};

int main()
{
	vector<int> nums{ 1, 2, 2 };
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
