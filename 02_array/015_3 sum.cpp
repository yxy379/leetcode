#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution
{
public:
	vector<vector<int>> threeSum(vector<int>& input)
	{
		vector<vector<int>> res{};
		sort(input.begin(), input.end());

		for (int i = 0; i < input.size() - 2; i++)
		{
			if (input[i] > 0) break;

			if (i > 0 && (input[i] == input[i - 1])) continue;

			int target = 0 - input[i];
			int m = i + 1, n = input.size() - 1;
			while (m < n)
			{
				if (input[m] + input[n] == target)
				{
					res.push_back({ input[i], input[m], input[n] });
					while ((m < n) && (input[m] == input[m + 1])) m++;
					while ((m < n) && (input[n] == input[n - 1])) n--;
					m++;
					n--;
				}
				else if (input[m] + input[n] < target)
				{
					m++;
				}
				else
					n--;
			}
		}
		return res;
	}
};

int main()
{
	Solution a;
	vector<int> input{ -1, 0, 1, 2, -1, -4 };
	vector<vector<int>> res = a.threeSum(input);
	cout << "The result is: " << endl;
	for (int i = 0; i < res.size(); i++)
	{
		for (int j = 0; j < res[i].size(); j++)
		{
			cout << res[i][j] << ", ";
		}
		cout << endl;
	}
	cin.get();
	return 0;
}