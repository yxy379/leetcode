#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
	string integerToRoman(int x)
	{
		vector<string> rom = { "M", "CM", "D", "CD", "C",
			"XC", "L", "XL", "X", "IX", "V", "IV", "I" };

		vector<int> num = { 1000, 900, 500, 400, 100,
			90, 50, 40, 10, 9, 5, 4, 1 };

		string res;
		int i = 0;
		while (x > 0)
		{
			int times = x / num[i];
			while (times)
			{
				x -= num[i];
				res.append(rom[i]);
				times--;
			}
			i++;
		}
		return res;
	}
};

int main()
{
	Solution a;
	cout << a.integerToRoman(1994) << endl;
	system("pause");
	return 1;
}