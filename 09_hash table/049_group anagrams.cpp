#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& s)
{
	vector<vector<string>> res;
	unordered_map<string, vector<string>> m;
	for (auto str:s)
	{
		string tmp = str;
		sort(tmp.begin(), tmp.end());
		m[tmp].push_back(str);
	}
	for (auto a : m)
	{
		res.push_back(a.second);
	}
	return res;
}

int main()
{
	vector<string> str{ "eat", "tea", "tan", "ate", "nat", "bat" };
	vector<vector<string>> res = groupAnagrams(str);
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