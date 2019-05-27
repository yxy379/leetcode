#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> spiralMat(int n)
{
	if (n <= 0) return {};
	vector<vector<int>> res(n, vector<int>(n, 0));

	int l = 0, r = n - 1, u = 0, d = n - 1;
	int data = 1;
	res[0][0] = data;
	char direction = 'r';
	int i = 0, j = 0;
	while ((l <= r) && (u <= d))
	{
		switch (direction)
		{
		case 'r':
		{
			while (j < r) res[i][++j] = ++data;
			direction = 'd';
			u++;
			break;
		}
		case 'd':
		{
			while (i < d) res[++i][j] = ++data;
			direction = 'l';
			r--;
			break;
		}
		case 'l':
		{
			while (j > l) res[i][--j] = ++data;
			direction = 'u';
			d--;
			break;
		}
		case 'u':
		{
			while (i > u) res[--i][j] = ++data;
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
	vector<vector<int>> res = spiralMat(5);
	for (int i = 0; i < res.size(); i++)
	{
		for (int j = 0; j < res[i].size(); j++)
		{
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
	system("pause");
	return 1;
}