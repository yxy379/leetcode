#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	int stringCompression(vector<char>& input)
	{
		int n = input.size();
		int j = 0, cur = 0;
		for (int i = 0; i < n; i++)
		{
			if ((i + 1 == n) || (input[i] != input[i+1]))
			{
				input[j] = input[i];
				j++;
				if (i - cur > 0)
				{
					auto n = i - cur + 1, cnt = 0;
					while (n > 0)
					{
						input[j] = n % 10 + '0';
						j++;
						n /= 10;
						cnt++;
					}
					reverse(input.begin() + j - cnt, input.begin() + j);
				}
				cur = i + 1;
			}
		}

		return j;
	}
};

int main()
{
	Solution a;
	vector<char> input{ 'a','b','b','b','b','b','b','b','b','b','b','a','a' };
	//cout << a.stringCompression(input) << endl;
	int n = a.stringCompression(input);
	for (int i = 0; i < n; i++)
		cout << input[i] << ' ';
	system("pause");
	return 1;
}