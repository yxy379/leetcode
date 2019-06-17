#include <iostream>
#include <vector>
using namespace std;

int islandPerimeter(vector<vector<int>>& grid)
{
	if ((grid.empty()) || (grid[0].empty())) return 0;
	int res = 0;
	for (int i = 0; i < grid.size(); i++)
	{
		for (int j = 0; j < grid[i].size(); j++)
		{
			if (grid[i][j] == 0) continue;
			if ((j == 0) || (grid[i][j - 1] == 0)) res++;
			if ((j == grid[i].size() - 1) || (grid[i][j + 1] == 0)) res++;
			if ((i == 0) || (grid[i - 1][j] == 0)) res++;
			if ((i == grid.size() - 1) || (grid[i + 1][j] == 0)) res++;
		}
	}
	return res;
}

int main()
{
	vector<vector<int>> grid{ {0,1,0,0}, {1,1,1,0}, {0,1,0,0},{1,1,0,0} };
	cout << islandPerimeter(grid) << endl;
	system("pause");
	return 1;
}