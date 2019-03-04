#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
	void nextPermutation(vector<int>& input)
	{
		next_permutation(input.begin(), input.end());
	}
};

class Solution1
{
public:
	void nextPermutation(vector<int>& input)
	{
		int keyIndex = input.size() - 1;
		while ((keyIndex > 0) && (input[keyIndex] <= input[keyIndex - 1]))
		{
			keyIndex--;
		}

		if (keyIndex == 0)
		{
			sort(input.begin(), input.end());
		}
		else
		{
			int minNum = input[keyIndex - 1];
			for (int i = input.size() - 1; i > keyIndex - 1; i--)
			{
				if (input[i] > minNum)
				{
					int temp;
					temp = input[i];
					input[i] = input[keyIndex - 1];
					input[keyIndex - 1] = temp;
					break;
				}
			}
		}
		sort(input.begin() + keyIndex, input.end());
	}
};

int main()
{
	vector<int> input{ 3,2,5,4,2,1 };
	Solution1 a;
	a.nextPermutation(input);
	for (int i = 0; i < input.size(); i++)
		cout << input[i] << ", ";
	cin.get();
	return 0;
}