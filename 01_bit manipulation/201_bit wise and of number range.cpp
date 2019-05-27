/*!
 * \file 201_bit wise and of number range.cpp
 *
 * \author yxy37
 * \date February 2019
 *
 * Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.
 * Input: [5,7]
 * Output: 4
 */
#include <iostream>
#include <stdint.h>

using namespace std;

class Solution
{
public:
	uint32_t bitWiseAndofNumberRange(uint32_t m, uint32_t n)
	{
		while (m < n)
		{
			n &= n - 1;
		}
		return n;
	}
};

void main()
{
	Solution a;
	uint32_t m = 5, n = 7;
	uint32_t result = a.bitWiseAndofNumberRange(m, n);
	cout << "Result is: " << result << endl;
	cin.get();
}