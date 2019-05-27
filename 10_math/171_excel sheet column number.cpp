#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
	int excelToNumber(string str)
	{
		int result = 0;
		for (int i = str.size()-1; i >= 0; i--)
		{
			result += (str[i] - 'A' + 1) * pow(26, str.size() -1 - i);
		}
		return result;
	}
};

int main()
{
	Solution a;
	cout << a.excelToNumber("AB") << endl;
	system("pause");
	return 1;
}