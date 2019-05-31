#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target)
{
	vector<int> res;
	unordered_map<int, int> m;
	for (int i = 0; i < nums.size(); i++)
	{
		m[nums[i]] = i + 1;
	}

	for (int i = 0; i < nums.size(); i++)
	{
		if ((m.count(target - nums[i])) && (m[target - nums[i]] != i + 1))
		{
			res.push_back(i + 1);
			res.push_back(m[target - nums[i]]);
			break;
		}
	}
	return res;
}

vector<int> twoSum1(vector<int>& nums, int target)
{
	int l = 0, r = nums.size() - 1;
	while (l < r)
	{
		if (nums[l] + nums[r] == target) return { l + 1, r + 1 };
		else if (nums[l] + nums[r] < target) l++;
		else r--;
	}
	return {};
}

int main()
{
	vector<int> nums{ 2, 7, 11, 15 };
	int target = 9;
	vector<int> res = twoSum1(nums, target);
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << " ";
	}
	system("pause");
	return 1;
}