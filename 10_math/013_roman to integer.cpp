#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
	int romanToInt(string str)
	{
		unordered_map<char, int> rom_num = { 
			{'I', 1},
			{'V', 5},
			{'X', 10},
			{'L', 50},
			{'C', 100},
			{'D', 500}, 
			{'M', 1000}
		};
		int res = 0;
		for (int i = 0; i < str.size(); i++)
		{
			if ((i > 0) && (rom_num[str[i]] > rom_num[str[i - 1]]))
			{
				res += rom_num[str[i]] - 2 * rom_num[str[i - 1]];
			}
			else
			{
				res += rom_num[str[i]];
			}
		}
		return res;
	}
};

int main()
{
	Solution a;
	cout << a.romanToInt("MCMXCIV") << endl;
	system("pause");
	return 0;
}