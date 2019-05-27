#include <iostream>

using namespace std;

class Solution
{
public:
	char findDifference(string s, string t)
	{
		int res = t[0] - 'a';
		for(int i = 0; i < s.size(); i++)
		{
			res ^= (s[i] - 'a') ^ (t[i + 1] - 'a');
		}
		return res + 'a';
	}
};

int main()
{
	Solution a;
	cout << a.findDifference("abcd", "bdeca") << endl;
	system("pause");
	return 1;
}