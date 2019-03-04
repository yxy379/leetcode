/*!
 * \file 231_power of two.cpp
 *
 * \author yxy37
 * \date February 2019
 *
 * Given an integer, write a function to determine if it is a power of two.
 * Input: 1
 * Output: true
 */
#include <iostream>

using namespace std;

class Solution
{
public:
	bool isPowerofTwo(int input)
	{
		return (input > 0) && ((input&(input - 1)) == 0);
	}
};

int main()
{
	Solution a;
	int input = 4;
	bool result = a.isPowerofTwo(input);
	cout << input << " is power of two: " << boolalpha << result << endl;
	cin.get();
	return 1;
}