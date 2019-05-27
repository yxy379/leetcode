#include <iostream>
#include <string>
//#include <cctype>

using namespace std;

class Solution
{
public:
	bool isPalindrome(string str)
	{
		if (str.empty()) return true;

		int left = 0, right = str.size() - 1;
		while (left < right)
		{
			if (!isalnum(str[left])) left++;
			else if (!isalnum(str[right])) right--;
			else if (tolower(str[left]) != tolower(str[right])) return false;
			else {
				left++;
				right--;
			}
		}
		return true;
	}
};

int main()
{
	Solution a;
	cout << a.isPalindrome("A man, a plan, a 1canal: Panama") << endl;
	system("pause");
	return 1;
}