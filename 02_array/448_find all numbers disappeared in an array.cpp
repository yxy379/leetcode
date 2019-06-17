#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> findDisappeared(vector<int>& nums)
{
	vector<int> res;
	for (int i = 0; i < nums.size(); i++)
	{
		int tmp = abs(nums[i]) - 1;
		nums[tmp] = nums[tmp] > 0 ? -nums[tmp] : nums[tmp];
	}
	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] > 0) res.push_back(i + 1);
	}
	return res;
}

int main()
{
	vector<int> nums{ 4, 3, 2, 7, 8, 2, 3, 1 };
	vector<int> res = findDisappeared(nums);
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << " ";
	}
	system("pause");
	return 1;
}