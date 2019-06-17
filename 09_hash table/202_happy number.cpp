#include <unordered_set>
#include <iostream>
using namespace std;

bool isHappyNumber(int n)
{
	unordered_set<int> s;
	while (n != 1)
	{
		int sum = 0;
		while (n)
		{
			sum += (n % 10)*(n % 10);
			n /= 10;
		}
		n = sum;
		if (s.count(n)) break;
		s.insert(n);
	}
	return n == 1;
}

int main()
{
	cout << isHappyNumber(11) << endl;
	system("pause");
	return 1;
}