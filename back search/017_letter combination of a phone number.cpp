#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<string> findCombination(string number)
	{
		vector<string> res;
		string dict[] = { " ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
		string comb(number.size(), '\0');
		dfs(number, 0, dict, comb, res);
		return res;
	}

private:
	void dfs(string number, int index, string dict[], string& comb, vector<string>& res)
	{
		if (index == comb.size())
		{
			res.push_back(comb);
			return;
		}

		string letter = dict[number[index] - '0'];
		for (int i = 0; i < letter.size(); i++)
		{
			comb[index] = letter[i];
			dfs(number, index+1, dict, comb, res);
		}
	}
};

int main()
{
	Solution a;
	vector<string> res = a.findCombination("23");
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << " ";
	}
	cout << endl;
	system("pause");
	return 1;
}