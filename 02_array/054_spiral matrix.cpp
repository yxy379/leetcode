#include <iostream>
#include <vector>
using namespace std;


vector<int> spiralMatrix(vector<vector<int>>& mat)
{
	int u = 0, d = mat.size() - 1, l = 0, r = mat[0].size() - 1;
	vector<int> res;
	if (mat.empty()) return res;
	res.push_back(mat[0][0]);

	int i = 0, j = 0;
	char direction = 'r';
	while ((l <= r) && (u <= d))
	{
		switch (direction)
		{
		case 'r':
		{
			while (j < r)
			{
				res.push_back(mat[i][j + 1]);
				j++;
			}
			direction = 'd';
			u++;
			break;
		}

		case 'd':
		{
			while (i < d)
			{
				res.push_back(mat[i + 1][j]);
				i++;
			}
			direction = 'l';
			r--;
			break;
		}

		case 'l':
		{
			while (j > l)
			{
				res.push_back(mat[i][j - 1]);
				j--;
			}
			direction = 'u';
			d--;
			break;
		}

		case 'u':
		{
			while (i > u)
			{
				res.push_back(mat[i - 1][j]);
				i--;
			}
			direction = 'r';
			l++;
			break;
		}
		}
	}
	return res;
}

int main()
{
	vector<vector<int>> mat{ {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12} };
	vector<int> res = spiralMatrix(mat);
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << " ";
	}
	system("pause");
	return 1;
}
