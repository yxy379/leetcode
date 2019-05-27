#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	vector<vector<int>> rotateImage(vector<vector<int>>& input)
	{
		int n = input.size() - 1;

		for (int i = 0; i < input.size() / 2; i++)
		{
			for (int j = i; j < input[i].size() - 1 - i; j++)
			{
				int temp = input[i][j];
				input[i][j] = input[n - j][i];
				input[n - j][i] = input[n - i][n - j];
				input[n - i][n - j] = input[j][n - i];
				input[j][n - i] = temp;
			}
		}
	}
};