#include <vector>
#include <iostream>
#include <unordered_set>
using namespace std;

class Solution
{
public:
	int maxXor(vector<int>& num)
	{
		int res = 0, mask = 0;
		for (int i = 31; i >= 0; i--)
		{
			mask |= (1 << i);
			unordered_set<int> s;
			for (int val : num)
			{
				s.insert(mask&val);
			}

			int t = res | (1 << i);
			for (int val : s)
			{
				if (s.count(t^val))
				{
					res = t;
					break;
				}
			}
		}
		return res;
	}
};

int main()
{
	vector<int> num{ 3, 10, 5, 25, 2, 8 };
	Solution a;
	cout << a.maxXor(num) << endl;
	system("pause");
	return 1;
}