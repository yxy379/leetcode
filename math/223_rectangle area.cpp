#include <iostream>
#include <algorithm>

using namespace std;

class Solution
{
public:
	int computeArea(int A, int B, int C, int D,
		int E, int F, int G, int H)
	{
		return (D - B) * (C - A) +
			(G - E) * (H - F) -
			max(0, (min(C, G) - max(A, E))) *
			max(0, (min(D, H) - max(B, F)));

	}
};

int main()
{
	Solution a;
	cout << a.computeArea(-3, 0, 3, 4, 0, -1, 9, 2) << endl;
	system("pause");
	return 1;
}