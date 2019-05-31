#include <iostream>
#include <unordered_map>
using namespace std;

class TwoSum
{
public:
	TwoSum() {}

	void add(int val)
	{
		++m[val];
	}

	bool find(int val)
	{
		for (auto x : m)
		{
			int target = val - x.first;
	
			if (((target!=x.first)&&(m.count(target)))||((target==x.first)&&(x.second>1)))
			{
				return true;
			}
		}
		return false;
	}
private:
	unordered_map<int, int> m;
};

int main()
{
	TwoSum a;
	a.add(1); 
	a.add(1);
	a.add(1);
	cout << a.find(1) << endl;
	cout << a.find(2) << endl;
	cout << a.find(3) << endl;

	unordered_map<int, int> c = { {1, 1}, {1, 2}, {3, 3} };
	for (auto x : c)
	{
		cout << x.first << " " << x.second << endl;
	}
	cout << c.count(1) << endl;
	system("pause");
	return 1;
}