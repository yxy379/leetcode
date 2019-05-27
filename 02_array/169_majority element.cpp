#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution
{
public:
	int majorityElement(vector<int>& input)
	{
		unordered_map<int, int> count;
		for (int i = 0; i < input.size(); i++)
		{
			count[input[i]]++;
		}

		for (auto it : count)
		{
			if (it.second > input.size() / 2)
				return it.first;
		}
	}
};

class Solution1
{
public:
	int majorityElement(vector<int>& input)
	{
		sort(input.begin(), input.end());
		return input.at(input.size() / 2);

	}
};

int main()
{
	Solution1 a;
	vector<int> input{ 2,2,1,1,1,2,2 };
	cout << a.majorityElement(input) << endl;
	system("pause");
	return 1;
}