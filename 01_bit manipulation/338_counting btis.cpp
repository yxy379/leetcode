#include <vector>
#include <iostream>
using namespace std;

vector<int> countingBits(int num)
{
	vector<int> res(num + 1, 0);
	for (int i = 1; i <= num; i++)
	{
		res[i] = res[i&(i - 1)] + 1;
	}
	return res;
}

int main()
{
	vector<int> res = countingBits(5);
	for(int i = 0; i < res.size(); i++)
	{
		cout << res[i] << " ";
	}
	system("pause");
	return 1;
}