#include <string>
#include <unordered_map>
#include <iostream>
#include <algorithm> // sort()

using namespace std;

class Solution
{
public:
	bool validAnagram(wstring str1, wstring str2)
	{
		sort(str1.begin(), str1.end());
		sort(str2.begin(), str2.end());
		return str1 == str2;
	}
};

class Solution2
{
public:
	bool validAnagram(string str1, string str2)
	{
		if (str1.size() != str2.size()) return false;

		unordered_map<char, int> count;
		for (int i = 0; i < str1.size(); i++)
		{
			count[str1[i]]++;
		}

		for (int j = 0; j < str2.size(); j++)
		{
			count[str2[j]]--;
			if (count[str2[j]] < 0) return false;
		}
		return true;
	}
};

int main()
{
	Solution a;
	//cout << a.validAnagram("anagrama", "nagaram") << endl;
	cout << a.validAnagram(L"你好", L"好你") << endl;
	system("pause");
	return 1;
}