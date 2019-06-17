#include <vector>
#include <iostream>
using namespace std;

int countPrime(int n)
{
	int res = 0;
	vector<bool> prime(n, true);
	for (int i = 2; i < n; i++)
	{
		if (prime[i])
		{
			res++;
			for (int j = 2; i * j < n; j++)
			{
				prime[i*j] = false;
			}
		}
	}
	return res;
}

int main()
{
	cout << countPrime(10) << endl;
	system("pause");
	return 1;
}