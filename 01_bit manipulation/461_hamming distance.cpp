#include <iostream>

using namespace std;

class Solution
{
public:
	int hammingDistance(int a, int b)
	{
		int temp = a ^ b;
		int result = 0;
		while (temp)
		{
			temp = temp & (temp - 1);
			result++;
		}
		return result;
	}
};

int main()
{
	Solution a;
	cout << a.hammingDistance(1, 4) << endl;
	system("pause");
	return 1;
}