#include <string>
#include <iostream>

using namespace std;

class Solution
{
public:
	string zigzagConvert(string s, int numRows)
	{
		string res;
		if (numRows < 2) return s;
		for (int i = 0; i < numRows; i++)
		{
			for (int j = i; j < s.size(); j += 2 * (numRows - 1))
			{
				res.push_back(s[j]);
				
				if ((i > 0) && (i < numRows - 1))
				{
					if (j + 2 * (numRows - i - 1) < s.length())
					{
						res.push_back(s[j + 2 * (numRows - i - 1)]);
					}
				}
			}
		}
		return res;
	}
};

int main()
{
	Solution a;
	cout << a.zigzagConvert("PAYPALISHIRING", 3) << endl;
	cin.get();
	return 0;
}