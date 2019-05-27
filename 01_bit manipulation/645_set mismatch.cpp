#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> setMismatch(vector<int>& input)
	{
		vector<int> res;
		int dup, mis;
		for (int i = 0; i < input.size(); i++)
		{
			for (int j = i + 1; j < input.size(); j++)
			{
				if (input[j] == input[i])
				{
					dup = input[j];
				}
			}
		}
		res.push_back(dup);

		int sum = 0;
		for (int i = 0; i < input.size(); i++)
		{
			sum += input[i];
		}
		mis = (1 + input.size())*input.size() / 2 - (sum - dup);
		res.push_back(mis);

		return res;
	}
};

int main()
{
	vector<int> input{ 1, 2, 2, 4 };
	Solution a;
	vector<int> res = a.setMismatch(input);
	
	cout << res[0] << ", " << res[1] << endl;
	system("Pause");
	return 1;
}