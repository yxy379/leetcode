#include <string>
#include <iostream>

using namespace std;

class Solution
{
public:
	string countAndSay(int n)
	{
		if (n < 1) return "";

		string str = "1";
		for (int i = 1; i < n; i++)
		{
			string tmp = "";
			int count = 0;
			char current = str[0];
			int index = 0;
			while (index < str.size())
			{
				if (str[index] == current)
				{
					count++;
				}
				else
				{
					tmp += to_string(count) + current;
					current = str[index];
					count = 1;
				}
				index++;
			}
			tmp += to_string(count) + current;
			str = tmp;
		}
		return str;
	}
};

int main()
{
	Solution a;
	for (int i = 1; i < 13; i++)
	{
		cout << "i = " << i << ",\t" << "seq = " << a.countAndSay(i) << endl;
	}
	cin.get();
	return 0;

}