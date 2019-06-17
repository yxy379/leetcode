#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

bool containsDuplicate(vector<int>& nums)
{
	unordered_set<int> s;
	for (int i = 0; i < nums.size(); i++)
	{
		if (s.count(nums[i])) return true;
		s.insert(nums[i]);
	}
	return false;
}

int main()
{
	vector<int> nums{ 1, 3, 2, 1 };
	cout << containsDuplicate(nums) << endl;
	system("pause");
	return 1;
}