#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	Solution(int window)
	{
		_window = window;
	}

	double movingAverage(double data)
	{
		double sum = 0.0;
		num.push_back(data);
		if (num.size() < _window)
		{
			for (int i = 0; i < num.size(); i++)
			{
				sum += num[i];
			}
			return sum / num.size();
		}
		else
		{
			for (int i = num.size() - 1; i >= int(num.size() - _window); --i)
			{
				//cout << num.size() - _window<<endl;
				//cout << i << "\t"<< num.size() - _window <<(i >= (num.size() - _window))<<endl;
				sum += num[i];
			}
			num.erase(num.begin());
			return sum / _window;
		}
	}
private:
	int _window;
	vector<double> num;
};

int main()
{
	Solution a(10);
	for (int i = 0; i < 20; i++)
	{
		cout << i + 1 << " run... output = " << a.movingAverage(i + 1) << endl;
	}

	system("pause");
	return 1;
}