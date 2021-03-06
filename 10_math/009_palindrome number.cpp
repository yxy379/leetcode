#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
	bool palindromeNumber(int x)
	{
		if (x < 0) return false;

		string num = to_string(x);
		int i = 0, j = num.size() - 1;

		while (i < j)
		{
			if (num[i] != num[j]) return false;
			i++;
			j--;
		}
		return true;
	}
};

class Solution2
{
public:
	bool palindromeNumber(int x)
	{
		if (x < 0) return false;
		
		int temp = x, reverse = 0;
		while (temp)
		{
			if (abs(reverse)>INT_MAX) return false;
			else
			{
				reverse = reverse * 10 + temp % 10;
				temp /= 10;
			}
		}
		return reverse == x;
	}
};

int main()
{
	Solution2 a;
	cout << a.palindromeNumber(121) << endl; // -121
	system("pause");
	return 1;
}