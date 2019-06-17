#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minPathSum(vector<vector<int>>& x)
{
	if ((x.empty()) || (x[0].empty())) return 0;
	int m = x.size(), n = x[0].size();
	vector<vector<int>> res(m, vector<int>(n, 0));
	res[0][0] = x[0][0];
	
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if ((i == 0) && (j > 0)) res[i][j] = res[i][j - 1] + x[i][j];
			else if ((j == 0) && (i > 0)) res[i][j] = res[i - 1][j] + x[i][j];
			else if ((i > 0) && (j > 0)) res[i][j] = min(res[i - 1][j] + x[i][j], res[i][j - 1] + x[i][j]);
		}
	}
	return res[m-1][n-1];
}

int main()
{
	vector<vector<int>> x{ {1, 3, 1}, {1, 5, 1}, {4, 2, 1} };
	cout << minPathSum(x) << endl;
	system("pause");
	return 1;
}