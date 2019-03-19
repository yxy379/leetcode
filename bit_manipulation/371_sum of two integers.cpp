#include <iostream>

using namespace std;

class Solution
{
public:
	int sumTwoInt(int a, int b)
	{
		while(b)
		{
			int carry = (a & b) << 1;
			int add = a ^ b;
			a = add;
			b  = carry;
		}
		return a;
	}
};

int main()
{
	Solution a;
	cout << a.sumTwoInt(11, -1) << endl;
	system("pause");
	return 1;
}