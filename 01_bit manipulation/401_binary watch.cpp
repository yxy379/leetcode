#include <iostream>
#include <bitset>
//#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<string> binaryWatch(int n)
	{
		vector<string> res;
		for (int h = 0; h < 12; h++)
		{
			for (int m = 0; m < 60; m++)
			{
				if (bitset<10>(h << 6 | m).count() == n)
				{
					res.push_back(to_string(h) + (m < 10 ? ":0" : ":") + to_string(m));
				}
			}
		}
		return res;
	}
};


int main()
{
	Solution a;
	vector<string> res = a.binaryWatch(1);
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << ", ";
	system("Pause");
	return 1;
}