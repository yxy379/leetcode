#include <iostream>
#include <string>
#include <unordered_map>
#include <set>
#include <vector>
using namespace std;

vector<vector<string>> groupShifted(vector<string>& strs)
{
	vector<vector<string>> res;
	unordered_map<string, multiset<string>> m;
	for (auto str : strs)
	{
		string t = "";
		for (auto c : str)
		{
			t += to_string((c - str[0] + 26) % 26) + ","; // key...
		}
		m[t].insert(str);
	}
	for (auto it = m.begin(); it != m.end(); it++)
	{
		res.push_back(vector<string>(it->second.begin(), it->second.end()));
	}
	return res;
}

int main()
{
	vector<string> strs{ "abc", "bcd", "acef", "xyz", "az", "ba", "a", "z" };
	vector<vector<string>> res = groupShifted(strs);
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