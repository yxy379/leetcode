#include <iostream>
#include <vector>
using namespace std;

int uniquePaths(vector<vector<int>>& obstacleGrid)
{
	if (obstacleGrid.empty() || obstacleGrid[0].empty() || obstacleGrid[0][0] == 1) return 0;
	int m = obstacleGrid.size(), n = obstacleGrid[0].size();
	vector<vector<long>> path(m + 1, vector<long>(n + 1, 0));
	path[0][1] = 1;
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (obstacleGrid[i-1][j-1] == 1) continue;
			path[i][j] = path[i][j - 1] + path[i - 1][j];
		}
	}
	return path[m][n];
}

int main()
{
	vector<vector<int>> grid{ {0, 0, 0}, {0, 1, 0}, {0, 0, 0} };
	cout << uniquePaths(grid) << endl;
	system("pause");
	return 1;
}