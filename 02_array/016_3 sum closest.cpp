#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
	int threeSumClosest(vector<int> input, int target)
	{
		sort(input.begin(), input.end());

		int min_diff = numeric_limits<int>::max();
		int res = numeric_limits<int>::max();
		for (int i = 0; i < input.size() - 2; i++)
		{
			if ((i > 0) && (input[i] == input[i - 1])) continue;

			int c = target - input[i];
			int a = i + 1, b = input.size() - 1;
			while (a < b)
			{
				int sum = input[a] + input[b];
				if (sum == c)
				{
					return target;
				}
				else if (sum < c)
				{
					++a;
				}
				else
				{
					--b;
				}

				if (abs(sum - c) < min_diff)
				{
					min_diff = abs(sum - c);
					res = sum + input[i];
				}
			}
		}

		return res;
	}
};

class Solution1 {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		int diff = INT_MAX;
		int res = INT_MAX;
		//if (nums.size()<3) return 0;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size() - 2; i++) {
			if ((i > 0) && (nums[i] == nums[i - 1])) continue;
			int sum = target - nums[i];
			int m = i + 1, n = nums.size() - 1;
			while (m < n)
			{
				if ((nums[m] + nums[n]) == sum)
				{
					return target;
				}
				else if ((nums[m] + nums[n]) < sum)
				{
					m++;
				}
				else
				{
					n--;
				}
				if (diff > abs(nums[m] + nums[n] - sum)) {
					diff = abs(nums[m] + nums[n] - sum);
					res = nums[i] + nums[m] + nums[n];
				}

			}
		}
		return res;
	}
};

int main()
{
	vector<int> input{ -1, 2, 1, -4 };
	int target = 1;
	Solution1 a;
	int res = a.threeSumClosest(input, target);
	cout << res << endl;
	cin.get();
	return 0;
}