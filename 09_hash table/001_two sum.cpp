#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target)
{
	vector<int> res;
	unordered_map<int, int> m;
	for (int i = 0; i < nums.size(); i++) 
	{
		m[nums[i]] = i;
	}
	for (int i = 0; i < nums.size(); i++)
	{
		if ((m.count(target - nums[i])) && (m[target - nums[i]] != i))
		{
			res.push_back(i);
			res.push_back(m[target - nums[i]]);
			break;
		}
	}
	return res;
}

int main()
{
	vector<int> nums{ 2, 7, 11, 15 }; 
	int target = 9;
	vector<int> res = twoSum(nums, target);
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << " ";
	}
	system("pause");
	return 1;
}