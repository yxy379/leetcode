#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minCost(vector<int>& cost)
{
	vector<int> dp(cost.size() + 1, 0);
	for (int i = 2; i <= cost.size(); i++)
	{
		dp[i] = min((dp[i - 2] + cost[i - 2]), (dp[i - 1] + cost[i - 1]));
	}
	return dp[cost.size()];
}

int main()
{
	vector<int> cost{ 1, 100, 1, 1, 1, 100, 1, 1, 100, 1 };
	cout << minCost(cost) << endl;
	system("pause");
	return 1;
}