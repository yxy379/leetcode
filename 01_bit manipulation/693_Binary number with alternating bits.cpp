#include <iostream>

using namespace std;

class Solution
{
public:
	bool alternatingBits(int num)
	{
		int bit = -1;
		while (num)
		{
			if (num & 1)
			{
				if (bit == 1) return false;
				else bit = 1;
			}
			else
			{
				if (bit == 0) return false;
				else bit = 0;
			}
			num >>= 1;
		}
		return true;
	}
};

int main()
{
	Solution a;
	cout << a.alternatingBits(5) << endl;
	system("pause");
	return 1;
}
