#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
	vector<vector<int>> fourSum(vector<int>& input, int target)
	{
		sort(input.begin(), input.end());

		vector<vector<int>> res{};
		for (int i = 0; i < input.size() - 3; i++)
		{
			if ((i > 0) && (input[i] == input[i - 1])) continue;
			for (int j = i + 1; j < input.size() - 2; j++)
			{
				if ((j > i + 1) && (input[j] == input[j - 1])) continue;
				int a = j + 1, b = input.size() - 1;
				while (a < b)
				{
					int sum = input[i] + input[j] + input[a] + input[b];
					if (sum == target)
					{
						res.push_back({ input[i], input[j], input[a], input[b] });
						while ((a < b) && (input[a] == input[a + 1])) a++;
						while ((a < b) && (input[b] == input[b - 1])) b--;
						a++;
						b--;
					}
					else if (sum < target)
						a++;
					else
						b--;
				}
			}
		}
		return res;
	}
};

int main()
{
	Solution a;
	vector<int> input{ 0, 0, 0, 0 }; // {0, 0, 0, 0}
	int target = 0;
	vector<vector<int>> res{};
	res = a.fourSum(input, target);
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