#include <string>
#include <iostream>

using namespace std;

class Solution
{
public:
	string int2hex(int num)
	{
		string res = "";
		if (!num) return "0";

		while (num && res.size() != sizeof(int) * 2)
		{
			int hex = num & 15;
			if (hex > 10)
			{
				res.push_back(hex - 10 + 'a');
			}
			else
			{
				res.push_back(hex + '0');
			}
			num >>= 4;
			cout << num << endl;
		}
		reverse(res.begin(), res.end());
		return res;
	}
};

int main()
{
	Solution a;
	cout << a.int2hex(111) << endl;
	system("pause");
	return 1;
}