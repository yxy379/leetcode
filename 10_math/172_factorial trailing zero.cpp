#include <iostream>

using namespace std;

class Solution
{
public:
	int fractorialTrailingZeros(int x)
	{
		int num = 1;
		for (int i = x; i >= 1; i--)
		{
			num *= i;
		}
		int res = 0;
		while (num % 10 == 0)
		{
			num /= 10;
			res++;
		}
		return res;
	}
};

class Solution2
{
public:
	int fractorialTrailingZeros(int x)
	{
		int res = 0;
		while (x)
		{
			res += x / 5;
			x /= 5;
		}
		return res;
	}
};

int main()
{
	Solution2 a;
	cout << a.fractorialTrailingZeros(10) << endl;
	system("pause");
	return 1;
}