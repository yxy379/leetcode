/*!
 * \file 191_number of 1 bits.cpp
 *
 * \author yxy37
 * \date February 2019
 *
 * Write a function that takes an unsigned integer and return the number of '1' bits 
 * it has (also known as the Hamming weight).
 * 
 * Input: 00000000000000000000000000001011
 * Output: 3
 */
#include <stdint.h>
#include <iostream>
#include <bitset>

using namespace std;

//class Solution
//{
//public:
//	uint32_t numberof1Bits(uint32_t input)
//	{
//		uint32_t sum = 0;
//		for (size_t i = 0; i < 32; i++)
//		{
//			if (input && 1 == 1)
//			{
//				sum++;
//			}
//			input = input >> 1;
//		}
//		return sum;
//	}
//};

class Solution
{
public: 
	uint32_t numberof1Bits(uint32_t input)
	{
		uint32_t result = 0;
		while (input != 0)
		{
			input = input & (input - 1);
			result++;
		}
		return result;
	}
};

void main()
{
	Solution a;
	uint32_t input = 55;
	uint32_t result = a.numberof1Bits(input);

	cout << "Input is " << bitset<32>(input) << endl;
	cout << "Number of 1 bits is: " << result << endl;
	cin.get();
}
