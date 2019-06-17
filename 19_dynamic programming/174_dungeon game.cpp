#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dungeonGame(vector<vector<int>>& grid)
{
	int m = grid.size(), n = grid[0].size();
	vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));
	dp[m][n - 1] = 1, dp[m - 1][n] = 1;
	for (int i = m - 1; i >= 0; i--)
	{
		for (int j = n - 1; j >= 0; j--)
		{
			dp[i][j] = max(1, (min(dp[i + 1][j], dp[i][j + 1]) - grid[i][j]));
		}
	}
	return dp[0][0];
}

int main()
{
	vector<vector<int>> grid{ {1, -3, 3}, {0, -2, 0}, {-3, -3, -3} };
	cout << dungeonGame(grid) << endl;
	system("pause");
	return 1;
}