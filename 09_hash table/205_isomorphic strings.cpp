#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;


bool isIsomorphic(string s, string t) {
	unordered_map<char, char> st;
	unordered_map<char, char> ts;
	for (int i = 0; i < s.size(); i++)
	{
		if ((st.count(s[i])) && (t[i] != st[s[i]])) return false;
		if ((ts.count(t[i])) && (s[i] != ts[t[i]])) return false;
		st[s[i]] = t[i];
		ts[t[i]] = s[i];
	}
	return true;
}



int main()
{
	cout << isIsomorphic("egg", "add");
	system("pause");
	return 1;
}