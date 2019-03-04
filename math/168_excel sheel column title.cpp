#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
	string excelTitle(int x)
	{
		string str;
		while (x)
		{
			str.push_back((x - 1) % 26 + 'A');
			x = (x - 1) / 26;
		}
		reverse(str.begin(), str.end());
		return str;
	}
};

int main()
{
	Solution a;
	cout << a.excelTitle(701) << endl;
	system("pause");
	return 1;
}