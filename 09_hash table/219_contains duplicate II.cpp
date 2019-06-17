#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool containsNearbyDuplicate(vector<int>& nums, int k) {
	unordered_map<int, int> m;
	for (int i = 0; i < nums.size(); i++)
	{
		if (m.count(nums[i]))
		{
			if (i - m[nums[i]] <= k) return true;
		}
		m[nums[i]] = i;
	}
	return false;
}

int main()
{
	vector<int> nums{ 1, 2, 3, 1, 2, 3 };
	int k = 2;
	cout << containsNearbyDuplicate(nums, 2) << endl;
	system("pause");
	return 1;
}