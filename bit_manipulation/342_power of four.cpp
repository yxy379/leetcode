#include <iostream>
#include <math.h>
using namespace std;

class Solution
{
public:
	bool powerOfFour(int data)
	{
		if ((data > 0) && ((data&(data-1)) == 0) && ((data-1)%3 == 0))
		{
			return true;
		}
		else return false;
	}
};

int main()
{
	Solution a;
	cout << a.powerOfFour(16) << endl;
	system("pause");
	return 1;
}