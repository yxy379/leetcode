#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution
{
public:
	bool canConstruct(string str1, string str2)
	{
		int m = str1.size(), n = str2.size();
		unordered_map<char, int> count;
		for (int j = 0; j < n; j++)
		{
			++count[str2[j]];
		}
		for (int i = 0; i < m; i++)
		{
			--count[str1[i]];
			if (count[str1[i]] < 0) return false;
		}
		return true;
	}
};

int main()
{
	Solution a;
	cout << a.canConstruct("aa", "cbtdyayca") << endl;
	system("pause");
	return 1;

}