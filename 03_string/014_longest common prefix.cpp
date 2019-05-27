#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
	string longestCommonPrefix(vector<string> input)
	{
		if (input.empty()) return "";
		
		for (int i = 0; i < input[0].size(); i++)
		{
			for (int j = 0; j < input.size(); j++)
			{
				if ((i >= input[j].size()) || (input[j][i] != input[0][i]))
				{
					return input[0].substr(0, i);
				}
			}
		}
		//return input[0];
	}
};

int main()
{
	Solution a;
	vector<string> input{ "flower", "flowerere", "flowererereight" };
	cout << a.longestCommonPrefix(input) << endl;
	cin.get();
	return 0;
}