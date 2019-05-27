#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
	vector<string> wordSearch(vector<vector<char>>& board, vector<string>& words)
	{
		vector<string> res;
		if ((board.empty()) || (board[0].empty())) return res;
		int m = board.size(), n = board[0].size();

		for (int x = 0; x < words.size(); x++)
		{
			bool tmp = false;
			vector<vector<bool>> visited(m, vector<bool>(n, false));
			for (int i = 0; i < m; i++)
			{
				for (int j = 0; j < n; j++)
				{
					if (wordExist(board, words[x], 0, i, j, visited)) tmp = true;
				}
			}
			if (tmp) res.push_back(words[x]);
		}
		return res;
	}
private:
	bool wordExist(vector<vector<char>>& board, string word, int index, int i, int j, vector<vector<bool>>& visited)
	{
		if (index == word.size()) return true;
		int m = board.size(), n = board[0].size();
		if ((i < 0) || (i >= m) || (j < 0) || (j >= n) || (visited[i][j]) || (board[i][j] != word[index])) return false;
		visited[i][j] = true;
		bool res = wordExist(board, word, index + 1, i - 1, j, visited) ||
			wordExist(board, word, index + 1, i, j - 1, visited) ||
			wordExist(board, word, index + 1, i + 1, j, visited) ||
			wordExist(board, word, index + 1, i, j + 1, visited);
		visited[i][j] = false;
		return res;
	}
};

int main()
{
	vector<vector<char>> board = { {'o','a','a','n'}, {'e','t','a','e'}, {'i','h','k','r'}, {'i','f','l','v'} };
	vector<string> words{ "oath","pea","eat","rain" };
	Solution a;
	vector<string> res = a.wordSearch(board, words);
 	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << endl;
	}
	system("pause");
	return 1;

}