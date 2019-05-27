#include <string>
#include <iostream>

using namespace std;

class Solution
{
public:
	string multiplyStrings(string num1, string num2)
	{
		if (num1.empty() || num2.empty()) return "";

		reverse(num1.begin(), num1.end());
		reverse(num2.begin(), num2.end());

		string res(num1.size() + num2.size(), '0');

		for (int j = 0; j < num2.size(); j++)
		{
			int val = num2[j] - '0';
			int carry = 0;
			for (int i = 0; i < num1.size(); i++)
			{
				carry += (num1[i] - '0') * val + (res[i + j] - '0');
				res[i + j] = carry % 10 + '0';
				carry /= 10;
			}
			if (carry != 0) res[num1.size() + j] = carry + '0';
		}

		reverse(res.begin(), res.end());

		int count = 0;
		while ((count < res.size() - 1) && (res[count] == '0')) count++;
		res.erase(0, count);
		return res;
	}
};

int main()
{
	string num1 = "123", num2 = "456";
	Solution a;
	cout << num1 << " x " << num2 << " = " << a.multiplyStrings(num2, num1) << endl;
	cin.get();
	return 0;
}