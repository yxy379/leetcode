#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution
{
public:
	string addBinary(string bin1, string bin2)
	{
		reverse(bin1.begin(), bin1.end());
		reverse(bin2.begin(), bin2.end());

		string sum;
		int n = max(bin1.size(), bin2.size());
		int carry = 0;
		for (int i = 0; i < n; i++)
		{
			if (i < bin1.size()) carry += bin1[i] - '0';
			if (i < bin2.size()) carry += bin2[i] - '0';
			sum.push_back(carry % 2 + '0');
			carry /= 2;
		}
		if (carry) sum.push_back('1');
		reverse(sum.begin(), sum.end());
		return sum;
	}
};

int main()
{
	Solution a;
	string bin1 = "1010", bin2 = "1011";
	cout << a.addBinary(bin1, bin2) << endl;
	cin.get();
	return 0;
}