#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int triangle(vector<vector<int>>& triangle)
{
	if ((triangle.empty()) || (triangle[0].empty())) return 0;
	vector<int> dp = triangle.back();
	
	
	for (int i = triangle.size()-2; i >= 0; i--)
	{
		for (int j = 0; j <= i; j++)
		{
			dp[j] = min(dp[j], dp[j + 1]) + triangle[i][j];
		}
	}
	return dp[0];
}

int main()
{
	vector<vector<int>> m{ {-1}, {2, 3}, {1, -1, -3}, {5, 3, -1, 2} };
	cout << triangle(m) << endl;
	system("pause");
	return 1;
}