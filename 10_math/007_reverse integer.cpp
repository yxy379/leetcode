#include <iostream>

using namespace std;

class Solution
{
public:
	int reverseInteger(int x)
	{
		int res = 0;
		while (x)
		{
			if (abs(res) > INT_MAX / 10) return 0;
			res = res * 10 + x % 10;
			x /= 10;
		}
		return res;
	}
};

int main()
{
	Solution a;
	cout << a.reverseInteger(123) << endl; // 2^31-1=2147483647
	system("pause");
	return 1;
}