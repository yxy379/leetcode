#include <iostream>
#include <vector>
using namespace std;

int findDuplicate(vector<int>& nums)
{
	int res = 0;
	for (int i = 0; i < 32; i++)
	{
		int bit = (1 << i);
		int cnt1 = 0, cnt2 = 0;
		for (int k = 0; k < nums.size(); k++)
		{
			if ((k) & bit) cnt1++;
			if (nums[k] & bit) cnt2++;
		}
		if (cnt2 > cnt1) res += bit;
	}
	return res;
}

int main()
{
	vector<int> nums = { 1, 3, 4, 5, 5 };
	cout << findDuplicate(nums);
	system("pause");
	return 1;
}