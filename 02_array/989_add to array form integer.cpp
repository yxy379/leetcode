#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> addToArrayForm(vector<int>& A, int K)
{
	int carry = 0;
	if (A.empty())
	{
		A.push_back(K);
		reverse(A.begin(), A.end());
	}
	else
	{
		reverse(A.begin(), A.end());
		A[0] += K;
	}
	for (int i = 0; i < A.size(); i++)
	{
		A[i] += carry;
		carry = A[i] / 10;
		A[i] %= 10;
	}
	while (carry)
	{
		A.push_back(carry % 10);
		carry /= 10;
	}
	reverse(A.begin(), A.end());
	return A;
}

int main()
{
	vector<int> A = {9};
	int K = 10000;
	addToArrayForm(A, K);
	for (int i = 0; i < A.size(); i++)
	{
		cout << A[i] << " ";
	}
	system("pause");
	return 1;
}