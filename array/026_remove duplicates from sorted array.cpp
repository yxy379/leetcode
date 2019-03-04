#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	int removeDuplicates(vector<int>& input)
	{
		int sum = 0;
		for (int i = 0; i < input.size(); i++)
		{
			if ((i > 0) && (input[i] == input[i - 1])) continue;
			sum++;
		}
		return sum;
	}
};

int main()
{
	vector<int> input{ 0,0,1,1,1,2,2,3,3,4 };
	int res = 0;
	Solution a;
	res = a.removeDuplicates(input);
	cout << res << endl;
	cin.get();
	return 0;
}