#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval
{
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

class Solution
{
public:
	bool meetingRooms(vector<Interval>& intervals)
	{
		sort(intervals.begin(), intervals.end(),
			[](const Interval& x, const Interval& y) {return x.start < y.start; });
		for (int i = 1; i < intervals.size(); i++)
		{
			if (intervals[i].start < intervals[i - 1].end)
			{
				return false;
			}
		}
		return true;
	}

};

int main()
{
	Solution a;
	vector<Interval> intervals{ {0, 30},{5, 10},{15, 20} };
	cout << a.meetingRooms(intervals);
	system("pause");
	return 1;
}
