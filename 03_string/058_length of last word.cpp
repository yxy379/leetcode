#include <string>
#include <iostream>

using namespace std;

class Solution
{
public:
	int lengthOfLastWord(string s)
	{
		int i = s.size() - 1;
		while ((i >= 0) && (s[i] == ' ')) --i;

		int length = 0;
		while ((i >= 0) && (s[i] != ' '))
		{
			length++;
			i--;
		}
		return length;
	}
};

int main()
{
	Solution a;
	cout << a.lengthOfLastWord("Hello world    ") << endl;
	cin.get();
	return 0;
}