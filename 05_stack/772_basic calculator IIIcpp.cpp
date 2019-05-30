#include <iostream>
#include <string>
using namespace std;

int calculator(string s)
{
	int res = 0, cur = 0, num = 0;
	char op = '+';
	for (int i = 0; i < s.size(); i++)
	{
		if ((s[i] >= '0') && (s[i] <= '9'))
		{
			num = num * 10 + (s[i] - '0');
		}

		if (s[i] == '(')
		{
			int j = i, cnt = 0;
			for (; i < s.size(); i++)
			{
				if (s[i] == '(') cnt++;
				if (s[i] == ')') cnt--;
				if (cnt == 0) break;
			}
			num = calculator(s.substr(j + 1, i - j - 1));
		}

		if ((s[i] == '+') || (s[i] == '-') || (s[i] == '*') || (s[i] == '/') || (i == s.size() - 1))
		{
			switch (op)
			{
			case '+': cur += num; break;
			case '-': cur -= num; break;
			case '*': cur *= num; break;
			case '/': cur /= num; break;
			}
			if ((s[i] == '+') || (s[i] == '-') || (i == s.size() - 1))
			{
				res += cur;
				cur = 0;
			}
			op = s[i];
			num = 0;
		}
	}
	return res;
}

int main()
{
	cout << calculator("(2+6* 3+5- (3*14/7+2)*5)+3");
	system("pause");
	return 1;
}