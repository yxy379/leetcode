#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	bool wordExist(vector<vector<char>>& board, string word)
	{
		if ((board.empty()) || (board[0].empty())) return false;
		int m = board.size(), n = board[0].size();
		vector<vector<bool>> visited(m, vector<bool>(n, false));
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (wordSearch(board, word, 0, i, j, visited)) return true;
			}
		}
		return false;
	}
private:
	bool wordSearch(vector<vector<char>>& board, string word, int index, int i, int j, vector<vector<bool>>& visited)
	{
		if (index == word.size()) return true;
		int m = board.size(), n = board[0].size();
		if ((i < 0) || (i >= m) || (j < 0) || (j >= n) || (visited[i][j]) || (board[i][j] != word[index])) return false;
		
		visited[i][j] = true;
		bool res = wordSearch(board, word, index + 1, i - 1, j, visited) ||
			wordSearch(board, word, index + 1, i, j - 1, visited) ||
			wordSearch(board, word, index + 1, i + 1, j, visited) ||
			wordSearch(board, word, index + 1, i, j + 1, visited);
		visited[i][j] = false;
		return res;
	}
};

int main()
{
	vector<vector<char>> board{ {'A','B','C','E'}, {'S','F','C','S'}, {'A','D','E','E'} };
	string word = "ABCCED";
	Solution a;
	cout << a.wordExist(board, word) << endl;
	system("pause");
	return 1;
}