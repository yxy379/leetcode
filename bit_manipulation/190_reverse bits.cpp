/*!
 * \file 190_reverse bits.cpp
 *
 * \author yxy37
 * \date February 2019
 *
 * Reverse bits of a given 32 bits unsigned integer
 * Input: 00000010100101000001111010011100
 * Output: 00111001011110000010100101000000
 *
 * \note Note that in some languages such as Java, there is no unsigned integer type. In this case, 
 * both input and output will be given as signed integer type and should not affect your implementation, 
 * as the internal binary representation of the integer is the same whether it is signed or unsigned.
 */



/*
class Solution
{
public:
	uint32_t reverseBit(uint32_t n)
	{
		uint32_t result = 0;
		int count = 32;
		while(count--)
		{
			result << 1;
			result |= n & 1;
			n >> 1;
		}
		return result;
	}
};
*/

#include <stdint.h>
#include <iostream>
#include <bitset>
using namespace std;

class Solution
{
public:
	uint32_t reverseBits(uint32_t input)
	{
		size_t count = 32;
		uint32_t result = 0;
		for (size_t i = 0; i < count; i++)
		{
			if (input & 1 == 1)
			{
				result = result << 1;
				result++;
			}
			else
			{
				result = result << 1;
			}
			input = input >> 1;
		}
		return result;
	}
};

int main()
{
	Solution a;
	uint32_t input = 55;
	uint32_t result = a.reverseBits(input);
	cout << "Input is " << bitset<32>(input) << endl;
	cout << "Output is " << bitset<32>(result) << endl;
	cin.get();
	return 1;
}