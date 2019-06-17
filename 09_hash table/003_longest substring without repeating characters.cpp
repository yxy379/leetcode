#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

int longestSubstring(string s)
{
	unordered_map<char, int> m;
	int len = 0, left = -1;
	for (int i = 0; i < s.size(); i++)
	{
		if ((m.count(s[i])) && (m[s[i]] > left))
		{
			left = m[s[i]];
		}
		m[s[i]] = i;
		len = max(len, i - left);
	}
	return len;
}

int main()
{
	cout << longestSubstring("pwwkew") << endl;	// "bbbbbb"
	system("pause");
	return 1;
}