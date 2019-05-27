#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
	vector<string> letterPermutation(string input)
	{
		vector<string> res;
		dfs(input, 0, res);
		return res;
	}
private:
	void dfs(string& input, int pos, vector<string>& res)
	{
		if (pos == input.size())
		{
			res.push_back(input);
			return;
		}

		dfs(input, pos + 1, res);
		if (input[pos] > '9')
		{
			input[pos] ^= 32;
			dfs(input, pos + 1, res);
		}
	}
};

int main()
{
	string input = "a1b2";
	Solution a;
	vector<string> res = a.letterPermutation(input);
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << endl;
	}
	system("pause");
	return 1;
}