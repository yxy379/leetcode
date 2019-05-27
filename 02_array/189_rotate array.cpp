#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	vector<int> rotateArray(vector<int>& input, int k)
	{
		int temp;
		for (int i = 1; i <= k; i++)
		{
			temp = input[input.size() - 1];
			for (int j = input.size()-1; j >0; j--)
			{
				input[j] = input[j - 1];
			}
			input[0] = temp;
		}
		return input;
	}
};

class Solution1
{
public:
	vector<int> rotateArray(vector<int>& input, int k)
	{
		for (int i = 0; i < input.size() - k; i++)
		{
			input.push_back(input[0]);
			input.erase(input.begin());
		}
		return input;
	}
};

int main()
{
	Solution1 a;
	vector<int> input = { 1,2,3,4,5,6,7 };
	vector<int> res = a.rotateArray(input, 3);
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << " ";
	system("Pause"); 
	return 1;
}