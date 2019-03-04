/*!
 * \file 137_single number II.cpp
 *
 * \author yxy37
 * \date February 2019
 *
 * Given a non-empty array of integers, every element appears three times except for one, 
 * which appears exactly once. Find that single one.
 * Input: [2,2,3,2] 
 * Output: 3
 * 
 * \note Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
 */

/*
#include <iostream>
#include <vector>

using namespace std;
class Solution 
{
public:
	int singleNumber(vector<int>& nums)
	{
		int one = 0, two = 0;
		for (const auto&i : nums)
		{
			int test =~i;
			int new_one = (~i&one) | (i&~one&~two);
			int new_two = (~i&two) | (i&one);
			one = new_one, two = new_two;
		}
		return one;
	}
};
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	int singleNumber(vector<int>& nums)
	{
		int ones = 0, twos = 0;
		for (size_t i = 0; i < nums.size(); i++)
		{
			int ones_next = ((~twos)&(~ones)&(nums[i])) | ((~twos)&(ones)&(~nums[i]));
			int twos_next = ((~twos)&(ones)&(nums[i])) | ((twos)&(~ones)&(~nums[i]));

			ones = ones_next;
			twos = twos_next;
		}
		return ones;
	}
};

int main()
{
	vector<int> v{ 2, 2, 3, 2 };
	Solution a;
	int result = a.singleNumber(v);
	cout << result << endl;
	cin.get();
	return 1;
}