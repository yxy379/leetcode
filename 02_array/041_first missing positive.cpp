#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
	int firstMissing(vector<int> input)
	{
		sort(input.begin(), input.end());

		int res = 0;
		int i = 0;
		while ((i < input.size()) && (input[i] <= 0)) i++;

		for (; i < input.size(); i++)
		{
			if ((i > 0) && (input[i] == input[i - 1])) continue;

			if (input[i] - res != 1) return res + 1;
			else res = input[i];
		}
		return res + 1;
	}
};

int main()
{
	vector<int> input{ 7,8,9,11,12 };
	Solution a;
	int res = a.firstMissing(input);
	cout << res << endl;
	cin.get();
	return 1;
}