#include <string>
#include <iostream>

using namespace std;

class Solution
{
public:
	bool validAbbr(string word, string abbr)
	{
		int j = 0;
		int temp = 0;
		for (int i = 0; i < abbr.size(); i++)
		{
			if ((abbr[i] >= '0') && (abbr[i] <= '9'))
			{
				if ((abbr[i] == '0') && (temp == 0)) return false;
				temp = temp * 10 + (abbr[i] - '0');
			}
			else if (abbr[i] >= 'a'&&abbr[i] <= 'z')
			{
				j += temp;
				if (abbr[i] != word[j]) return false;
				else 
				{
					j++;
					temp = 0;
				}
			}
	
		}

		if (j + temp == word.size()) return true;
		else return false;
	}
};

int main()
{
	Solution a;
	cout << a.validAbbr("internationalizationaaa", "i12iz4n3") << endl;
	system("pause");
	return 1;
}