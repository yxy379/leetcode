#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

int longestSubstring(string s, int k)
{
	int left = 0, len = 0;
	unordered_map<char, int> m;
	for (int i = 0; i < s.size(); i++)
	{
		m[s[i]]++;
		while (m.size() > k)
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
	cout << longestSubstring("eceba", 2) << endl;
	system("pause");
	return 1;
}