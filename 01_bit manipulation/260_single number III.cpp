/*!
 * \file 260_single number III.cpp
 *
 * \author yxy37
 * \date February 2019
 *
 * Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. 
 * Find the two elements that appear only once.
 * Input:  [1,2,1,3,2,5]
 * Output: [3,5]
 *
 * \note 1. The order of the result is not important. So in the above example, [5, 3] is also correct.
 *       2. Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	vector<int> singleNumber(vector<int>& input)
	{
		// store xor result
		int temp = 0;
		for (int i = 0; i < input.size(); i++)
		{
			temp ^= input[i];
		}

		// get last different bit position
		int diff = temp &(~(temp - 1));

		vector<int> result(2, 0);
		for (int j = 0; j < input.size(); j++)
		{
			if (diff&input[j])
			{
				result[0] ^= input[j];
			}
			else
			{
				result[1] ^= input[j];
			}
		}
		return result;
	}
};

int main()
{
	Solution a;
	vector <int> input{1, 2, 1, 3, 2, 5};
	vector<int> result = a.singleNumber(input);
	cout << "The results are: " << result[0] << ", " << result[1] << endl; 
	cin.get();
	return 0;
}
