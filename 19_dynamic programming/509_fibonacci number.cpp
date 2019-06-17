#include <iostream>
#include <vector>
using namespace std;

int fibonacci(int n)
{
	vector<int> f(n+1, 0);
	if (n < 1) return 0;
	f[0] = 0;
	f[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		f[i] = f[i - 1] + f[i - 2];
	}
	return f[n];
}

int fibonacci1(int n)
{
	if (n < 1) return 0;
	int a = 0, b = 1;
	int res = 1;
	for (int i = 2; i <= n; i++)
	{
		res = a + b;
		a = b;
		b = res;
	}
	return res;


}

int main()
{
	cout << fibonacci1(1) << endl;
	system("pause");
	return 1;
}