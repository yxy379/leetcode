#include <string>
#include <iostream>

using namespace std;

class Solution
{
public:
	string addStrings(string str1, string str2)
	{
		reverse(str1.begin(), str1.end());
		reverse(str2.begin(), str2.end());

		int m = str1.size() >= str2.size() ? str1.size() : str2.size();
		int carry = 0;
		string res;
		for (int i = 0; i < m; i++)
		{
			if (i < str1.size()) carry += (str1[i] - '0');
			if (i < str2.size()) carry += (str2[i] - '0');
			res.push_back(carry % 10 + '0');
			carry /= 10;
		}
		if (carry) res.push_back(carry + '0');
		reverse(res.begin(), res.end());
		return res;
	}
};

int main()
{
	Solution a;
	cout << a.addStrings("99", "99") << endl;
	system("pause");
	return 1;
}