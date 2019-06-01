#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	void sudokuSolver(vector<vector<char>>& board)
	{
		if ((board.size() != 9) || (board[0].size() != 9)) return;
		dfs(board, 0, 0);
	}

	bool dfs(vector<vector<char>>& board, int i, int j)
	{
		if (i == 9) return true;
		if (j >= 9) return dfs(board, i + 1, 0);
		if (board[i][j] == '.')
		{
			for (int k = 1; k <= 9; k++)
			{
				board[i][j] = (char)(k + '0');
				if (isValid(board, i, j))
				{
					if (dfs(board, i, j + 1)) return true;
				}
				board[i][j] = '.';
			}
		}
		else
		{
			return dfs(board, i, j + 1);
		}
		return false;
	}

	bool isValid(vector<vector<char>>& board, int i, int j)
	{
		for (int row = 0; row <= 8; row++)
		{
			if ((row != i) && (board[row][j] == board[i][j])) return false;
		}
		for (int col = 0; col <= 8; col++)
		{
			if ((col != j) && (board[i][col] == board[i][j])) return false;
		}
		for (int r = i / 3 * 3; r < i / 3 * 3 + 3; r++)
		{
			for (int c = j / 3 * 3; c < j / 3 * 3 + 3; c++)
			{
				if ((r != i || c != j) && (board[r][c] == board[i][j])) return false;
			}
		}
		return true;
	}
};

int main()
{
	Solution a;
	vector<vector<char>> board{ {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
	{'6', '.', '.', '1', '9', '5', '.', '.', '.'},
	{'.', '9', '8', '.', '.', '.', '.', '6', '.'},
	{'8', '.', '.', '.', '6', '.', '.', '.', '3'},
	{'4', '.', '.', '8', '.', '3', '.', '.', '1'},
	{'7', '.', '.', '.', '2', '.', '.', '.', '6'},
	{'.', '6', '.', '.', '.', '.', '2', '8', '.'},
	{'.', '.', '.', '4', '1', '9', '.', '.', '5'},
	{'.', '.', '.', '.', '8', '.', '.', '7', '9'} };
	a.sudokuSolver(board);
	for (int i = 0; i < board.size(); i++)
	{
		for (int j = 0; j < board[i].size(); j++)
		{
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
	system("pause");
	return 1;
}