#include <iostream>
#include <vector>
using namespace std;

bool isSudoku(vector<vector<char>>& s)
{
	int m = s.size(), n = s[0].size();
	vector<vector<bool>> rowFlag(m, vector<bool>(n, false));
	vector<vector<bool>> colFlag(m, vector<bool>(n ,false));
	vector<vector<bool>> subFlag(m, vector<bool>(n, false));

	for (int i = 0; i < s.size(); i++)
	{
		for (int j = 0; j < s[i].size(); j++)
		{
			if ((s[i][j] >= '1') && (s[i][j] <= '9'))
			{
				int c = s[i][j] - '1';
				if ((rowFlag[i][c]) || (colFlag[c][j]) || (subFlag[3 * (i / 3) + j / 3][c])) return false;
				rowFlag[i][c] = true;
				colFlag[c][j] = true;
				subFlag[3 * (i / 3) + j / 3][c] = true;
			}
		}
	}
	return true;
}

int main()
{
	vector<vector<char>> s{ {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
	{'6', '.', '.', '1', '9', '5', '.', '.', '.'},
	{'.', '9', '8', '.', '.', '.', '.', '6', '.'},
	{'8', '.', '.', '.', '6', '.', '.', '.', '3'},
	{'4', '.', '.', '8', '.', '3', '.', '.', '1'},
	{'7', '.', '.', '.', '2', '.', '.', '.', '6'},
	{'.', '6', '.', '.', '.', '.', '2', '8', '.'},
	{'.', '.', '.', '4', '1', '9', '.', '.', '5'},
	{'.', '.', '.', '.', '8', '.', '.', '7', '9'} };
	vector<vector<int>> x{ {}, {1, 2}, {3, 4} };
	if (x.empty() || x[0].empty()) cout << "x empty" << endl;
	cout << isSudoku(s) << endl;
	system("pause");
	return 1;
}