#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	vector<int> mergeSortedArray(vector<int>& A, int m,
		vector<int>& B, int n)
	{
		int pa = m - 1, pb = n - 1, pc = m + n - 1;
		while ((pa >= 0) && (pb >= 0))
		{
			if (A[pa] > B[pb])
			{
				A[pc--] = A[pa--];
			}
			else
			{
				A[pc--] = B[pb--];
			}
		}

		while (pa >= 0) A[pc--] = A[pa--];
		while (pb >= 0) A[pc--] = B[pb--];
		return A;
	}
};

int main()
{
	Solution a;
	vector<int> A{ 1,2,3,0,0,0 };
	vector<int> B{ 2,5,6 };
	vector<int> res = a.mergeSortedArray(A, 3, B, 3);
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << ", ";
	system("pause");
	return 1;
}