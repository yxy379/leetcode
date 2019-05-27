#include <string>
#include <iostream>

using namespace std;

class Solution
{
public:
	int compareVersion(string str1, string str2)
	{
		int m = str1.size(), n = str2.size();

		for (int i = 0, j = 0; i < m || j < n; i++, j++)
		{
			int v1 = 0, v2 = 0;
			while ((i < m) && (str1[i] != '.'))
			{
				v1 = v1 * 10 + (str1[i] - '0');
				i++;
			}
			while ((j < n) && (str2[j] != '.'))
			{
				v2 = v2 * 10 + (str2[j] - '0');
				j++;
			}
			if (v1 != v2)
				return v1 > v2 ? 1 : -1;
		}
		return 0;
	}
};

int main()
{
	Solution a;
	cout << a.compareVersion("1.01", "1.001") << endl;
	system("pause");
	return 1;
}