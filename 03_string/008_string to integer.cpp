#include <string>
#include <iostream>

using namespace std;

class Solution
{
public:
	int string2integer(string s)
	{
		if (s.empty()) return 0;

		int ans = 0;
		int sign = 1;
		int i = 0;

		while ((s[i] == ' ') || (s[i] == '\t')) i++;

		if (i == s.length()) return 0;

		if (s[i] == '+') i++;
		else if (s[i] == '-')
		{
			sign = -1;
			i++;
		}

		for (; (i < s.length()) && (isdigit(s[i])); i++)
		{
			if ((ans) > (numeric_limits<int>::max()- (s[i] - '0'))/10)
			{
				return sign > 0 ? numeric_limits<int>::max() : numeric_limits<int>::min();
			}
			ans *= 10;
			ans += s[i] - '0';
		}
		ans *= sign;
		return ans;
	}
};

int main()
{
	Solution a;
	cout << numeric_limits<int>::max() << " " << numeric_limits<int>::min() << endl;
	cout << a.string2integer("-91283472332") << endl;
	cin.get();
	return 0;
}