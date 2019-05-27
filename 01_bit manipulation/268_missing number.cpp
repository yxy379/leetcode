#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	int missingNumber(vector<int>& input)
	{
		int sum = 0;
		for (int i = 0; i < input.size(); i++)
		{
			sum += input[i];
		}
		return 0.5*input.size()*(input.size() + 1) - sum;
	}
};

class Solution1
{
public:
	int missingNumber(vector<int>& input)
	{
		int result = 0;
		for (int i = 0; i < input.size(); i++)
		{
			result ^= (i + 1) ^ input[i];
		}
		return result;
	}
};

int main()
{
	Solution1 a;
	vector<int> input{ 1, 0, 3 };
	int result = a.missingNumber(input);
	cout << "The missing number is: " << result << endl;
	cin.get();
	return 0;
}