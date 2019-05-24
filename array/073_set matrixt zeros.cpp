#include <iostream>
#include <vector>
using namespace std;

void setZeros(vector<vector<int>>& mat)
{
	if ((mat.empty()) || (mat[0].empty())) return;
	int m = mat.size() - 1, n = mat[0].size() - 1;
	bool rowFlag = false, colFlag = false;

	for (int i = 0; i <= m; i++)
	{
		if (mat[i][0] == 0) rowFlag = true;
	}
	for (int j = 0; j <= n; j++)
	{
		if (mat[0][j] == 0) colFlag = true;
	}

	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (mat[i][j] == 0)
			{
				mat[0][j] = 0;
				mat[i][0] = 0;
			}
		}
	}

	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if ((mat[0][j] == 0) || (mat[i][0] == 0))
			{
				mat[i][j] = 0;
			}
		}
	}

	if (rowFlag)
	{
		for (int i = 0; i <= m; i++)
		{
			mat[i][0] = 0;
		}
	}
	if (colFlag)
	{
		for (int j = 0; j <= n; j++)
		{
			mat[0][j] = 0;
		}
	}
}

int main()
{
	vector<vector<int>> mat{ {1, 1, 1}, {1, 0, 1}, {1, 1, 1} };
	setZeros(mat);
	for (int i = 0; i < mat.size(); i++)
	{
		for (int j = 0; j < mat[i].size(); j++)
		{
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}
	system("pause");
	return 1;
}