#include <string>
#include <iostream>

using namespace std;

class Solution
{
public:
	int countSegments(string str)
	{
		int count = 0;
		if (str.empty()) return 0;
		
		for (int i = 1; i < str.size(); i++)
		{
			if (((str[i] == ' ') || (str[i] == '\t')) &&
				(str[i - 1] != ' ') && str[i - 1] != '\t') count++;
		}
		if ((str[str.size() - 1] == ' ') || (str[str.size() - 1] == '\t')) return count;
		else return count - 1;
	}
};

int main()
{
	Solution a;
	cout << a.countSegments("Hello, my name is John ") << endl;
	system("pause");
	return 1;
}