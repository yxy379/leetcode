#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int superUglyNumber(int n, vector<int>& primes)
{
	vector<int> res(1, 1);
	vector<int> idx(primes.size(), 0);
	
	while (res.size() < n)
	{
		vector<int> tmp;
		int x = INT_MAX;
		for (int i = 0; i < primes.size(); i++)
		{
			tmp.push_back(primes[i] * res[idx[i]]);
		}
		for (int i = 0; i < primes.size(); i++)
		{
			x = min(x, tmp[i]);
		}
		for (int i = 0; i < primes.size(); i++)
		{
			if (x == tmp[i]) ++idx[i];
		}
		res.push_back(x);
	}
	return res[n - 1];
}

int main()
{
	vector<int> primes{ 2, 7, 13, 19 };
	int n = 12;
	cout << superUglyNumber(n, primes) << endl;
	system("pause");
	return 1;
}