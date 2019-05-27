#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int longestConsecutiveSeuqnce(vector<int>& nums)
{
	unordered_map<int, bool> count;
	for (auto num : nums) count[num] = true;
	int res = 0;
	for (auto num : nums)
	{
		int len = 1;
		int tmp = num + 1;
		while (count.count(tmp))
		{
			count.erase(tmp);
			tmp++;
			len++;
		}
		tmp = num - 1;
		while (count.count(tmp))
		{
			count.erase(tmp);
			tmp--;
			len++;
		}
		res = max(res, len);
	}
	return res;
}

int main()
{
	vector<int> nums{ 100, 4, 200, 1, 3, 2 };
	cout << longestConsecutiveSeuqnce(nums) << endl;
	system("pause");
	return 1;
}