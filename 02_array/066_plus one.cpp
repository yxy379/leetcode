#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	vector<int> plusOne(vector<int>& input)
	{
		reverse(input.begin(), input.end());
		int carry = 0;
		input[0]++;
		for (int i = 0; i < input.size(); i++)
		{
			input[i] += carry;
			carry = input[i] / 10;
			input[i] %= 10;
		}
		if (carry == 1)
		{
			input.push_back(1);
		}
		reverse(input.begin(), input.end());
		return input;
	}
};

int main()
{
	vector<int> input{ 9,9,9 };
	Solution a;
	vector<int> res = a.plusOne(input);
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << ", ";
	system("pause");
	return 1;
}