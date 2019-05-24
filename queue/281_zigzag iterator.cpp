#include <queue>
#include <iostream>
using namespace std;

class ZigzagIterator
{
public:
	ZigzagIterator(vector<int>& v1, vector<int>& v2)
	{
		if (!v1.empty())
		{
			q.push(make_pair(v1.begin(), v1.end()));
		}
		if (!v2.empty())
		{
			q.push(make_pair(v2.begin(), v2.end()));
		}
	}

	int next()
	{
		auto it = q.front().first, end = q.front().second;
		q.pop();
		if (it + 1 != end)
		{
			q.push(make_pair(it + 1, end));
		}
		return *it;
	}

	bool hasNext()
	{
		return !q.empty();
	}

private:
	queue<pair<vector<int>::iterator, vector<int>::iterator>> q;
};

int main()
{
	vector<int> v1{ 1, 2 }, v2{ 3, 4, 5, 6 };
	ZigzagIterator a(v1, v2);
	while (a.hasNext())
	{
		cout << a.next() << " ";
	}
	system("pause");
	return 1;
}