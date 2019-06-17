#include <iostream>
#include <vector>
using namespace std;

// dp
class Solution
{
public:
	int climbingStairs(int n)
	{
		if (n <= 1) return 1;
		vector<int> dp(n, 0);
		dp[0] = 1;
		dp[1] = 2;
		for (int i = 2; i < n; i++)
		{
			dp[i] = dp[i - 1] + dp[i - 2];
		}
		return dp[n - 1];
	}
};

// back tracking
class Solution1
{
public:
	int climbingStairs(int n)
	{
		vector<int> stairs(n + 1, 0);
		return helper(stairs, n);
	}
private:
	int helper(vector<int>& m, int n)
	{
		if (n <= 1) return 1;
		if (m[n] > 0) return m[n];
		return m[n] = helper(m, n - 1) + helper(m, n - 2);
	}
};

int main()
{
	Solution1 a;
	cout << a.climbingStairs(400) << endl;
	system("pause");
	return 1;
}