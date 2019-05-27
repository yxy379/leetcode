#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums)
{
	if (nums.size() <= 2) return nums.size();
	int flag = 1, index = 0;
	for (int i = 1; i < nums.size(); i++)
	{
		if ((nums[index] == nums[i]) && (flag == 1))
		{
			nums[++index] = nums[i];
			flag = 2;
		}
		else if (nums[index] != nums[i])
		{
			nums[++index] = nums[i];
			flag = 1;
		}
	}
	return index + 1;
}

int main()
{
	vector<int> nums{ 0,0,1,1,1,1,2,3,3 };
	int length = removeDuplicates(nums);
	cout << length << endl;
	for (int i = 0; i < length; i++)
	{
		cout << nums[i] << " ";
	}
	system("pause");
	return 1;
}