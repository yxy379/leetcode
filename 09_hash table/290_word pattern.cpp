#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
using namespace std;


bool wordPattern(string pattern, string strs) {
	unordered_map<char, string> ps;
	unordered_map<string, char> sp;

	istringstream in(strs);
	int i = 0;
	for (string str; in >> str; i++)
	{
		if ((ps.count(pattern[i])) && (ps[pattern[i]] != str)) return false;
		if ((sp.count(str)) && (sp[str] != pattern[i])) return false;
		ps[pattern[i]] = str;
		sp[str] = pattern[i];
	}
	return i == pattern.size();
}

int main()
{
	cout << wordPattern("abba", "dog cat cat dog") << endl;
	system("pause");
	return 1;
}
