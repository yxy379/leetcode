#include <iostream>
using namespace std;

bool isUlgy(int num)
{
	while (num >= 2)
	{
		if (num % 2 == 0) num /= 2;
		else if (num % 3 == 0) num /= 3;
		else if (num % 5 == 0) num /= 5;
		else return false;
	}
	return num == 1;
}

int main()
{
	cout << isUlgy(6) << endl;
	system("pause");
	return 1;
}