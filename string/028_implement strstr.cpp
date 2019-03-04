#include <string>
#include <iostream>

using namespace std;

class Solution
{
public:
	int strStr(string haystack, string needle)
	{
		int m = haystack.size(), n = needle.size();

		if (n == 0) return 0;

		for (int i = 0; i < m; i++)
		{
			if (i + n > m) break;
			for (int j = 0; j < n; j++)
			{
				if (haystack[i + j] != needle[j]) break;
				 
				else if ((j = n - 1) && (haystack[i + j] == needle[j])) return i;
			}
		}
		return -1;
	}
};

int main()
{
	Solution a;
	cout << a.strStr("aaaaa", "bba") << endl;
	cin.get();
	return 0;
}