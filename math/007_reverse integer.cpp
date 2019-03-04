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
			auto prev = res;
			res *= 10;
			res += x % 10;
			if (res / 10 != prev)
			{
				res = 0;
				break;
			}
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