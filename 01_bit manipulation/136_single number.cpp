/*!
 * \file 136_single number.cpp
 *
 * \author yxy37
 * \date February 2019
 *
 * Given a non-empty array of integers, every element appears twice except for one. Find that single one.
 * Input: [2,2,1] Output: 1
 * Input: [4,1,2,1,2] Output: 4
 * \note Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory
 */

#include <iostream>
#include <vector>
#include <numeric>
#include <functional>

class Solution
{
public:
	int singleNumber(std::vector<int>& nums)
	{
		return accumulate(nums.cbegin(), nums.cend(),
			0, std::bit_xor<int>());
	}
};


class Solution1
{
public:
	int singleNumber(std::vector<int>& nums)
	{
		int result = nums[0];
		for (int i = 1; i < nums.size(); i++)
		{
			result ^= nums[i];
		}
		return result;
	}
};


int main()
{
	std::vector<int> v{ 4, 1, 2, 1, 2};
	Solution1 a;
	int result = a.singleNumber(v);
	std::cout << result << std::endl;
	std::cin.get();
	return 0;
}