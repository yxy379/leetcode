#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
	int buySellStock(vector<int> stock)
	{
		int profit = 0;
		for (int i = 0; i < stock.size() - 1; i++)
		{
			for (int j = i + 1; j < stock.size(); j++)
			{
				if (stock[j] > stock[i])
				{
					profit = max(stock[j] - stock[i], profit);
				}
			}
		}
		return profit;
	}
};

class Solution1
{
public:
	int buySellStock(vector<int> stock)
	{
		int profit = 0;
		int minPrice = stock[0];
		for (int i = 1; i < stock.size(); i++)
		{
			profit = max(stock[i] - minPrice, profit);
			minPrice = min(minPrice, stock[i]);
		}
		return profit;
	}
};

int main()
{
	Solution1 a;
	cout << a.buySellStock({ 7, 1, 5, 3, 6, 4 }) << endl; // 7,6,4,3,1
	system("pause");
	return 1;
}