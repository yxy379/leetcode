#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
	int maxLength(vector<string>& input)
	{
		vector<int> temp(input.size(), 0);
		int result = 0;
		for (int i = 0; i < input.size(); i++)
		{
			for (int j = 0; j < input[i].size(); j++)
			{
				temp[i] |= (1 << (input[i][j] - 'a'));
				//cout << input[i][j];
			}

			for (int k = 0; k < i; k++)
			{
				if ((temp[i] & temp[k]) == 0) // (temp[i] & temp[k])!!!
				{
					result = max(result, static_cast<int>(input[i].size()*input[k].size()));
				}
			}
		}
		return result;
	}
};

int main()
{
	Solution a;
	vector<string> input{ "abcw", "baz", "foo", "bar", "xtfn", "abcdef" };
	int result = a.maxLength(input);
	cout << "The result is: " << result << endl;
	cin.get();
	return 0;
}