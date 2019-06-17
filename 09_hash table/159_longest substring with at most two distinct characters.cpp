#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

int longestSubstring(string s)
{
	int len = 0, left = 0;
	unordered_map<char, int> m;
	for (int i = 0; i < s.size(); i++)
	{
		m[s[i]]++;
		while (m.size() > 2)
		{
			m[s[left]]--;
			if (m[s[left]] == 0) m.erase(s[left]);
			left++;
		}
		len = max(len, i - left + 1);
	}
	return len;
}

int main()
{
	cout << longestSubstring("eceba") << endl;
	system("pause");
	return 1;
}