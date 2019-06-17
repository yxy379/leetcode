#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> findDuplicates(vector<int>& nums)
{
	vector<int> res{};
	if (nums.size() < 2) return res;
	if ((nums.size() == 2) && (nums[0] == nums[1])) return { nums[0] };
	sort(nums.begin(), nums.end());
	for (int i = 0; i < nums.size() - 1; i++)
	{
		if (nums[i + 1] == nums[i])
		{
			res.push_back(nums[i]);
		}
	}
	return res;
}

int main()
{
	vector<int> nums{ 4, 3, 2, 7, 8, 2, 3, 1 };
	vector<int> res = findDuplicates(nums);
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << " ";
	}
	system("pause");
	return 1;
}