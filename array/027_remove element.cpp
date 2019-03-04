#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
	int removeElement(vector<int>& input, int target)
	{
		sort(input.begin(), input.end());

		int res = 0;
		for (int i = 0; i < input.size(); i++)
		{
			if (input[i] == target) continue;
			res++;
		}
		return res;
	}
};

int main()
{
	Solution a;
	vector<int> input{ 0,1,2,2,3,0,4,2 };
	int target = 2;
	int res = a.removeElement(input, target);
	cout << res << endl;
	cin.get();
	return 0;
}