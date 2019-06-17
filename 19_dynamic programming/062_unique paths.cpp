#include <iostream>
#include <vector>
using namespace std;

int uniquePaths(int m, int n)
{
	vector<vector<int>> path(m+1, vector<int>(n+1, 0));
	if ((m < 1) || (n < 1)) return 0;
	for (int i = 1; i <= m; i++) path[i][1] = 1;
	for (int j = 1; j <= n; j++) path[1][j] = 1;
	
	path[2][1] = 1;
	path[1][2] = 1;

	for (int i = 2; i <= m; i++)
	{
		for (int j = 2; j <= n; j++)
		{
			path[i][j] = path[i - 1][j] + path[i][j - 1];
		}
	}
	return path[m][n];
}

int main()
{
	cout << uniquePaths(7, 3) << endl;
	system("pause");
	return 1;
}