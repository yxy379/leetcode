#include <queue>
#include <iostream>
using namespace std;

class Movingaverage
{
public:
	Movingaverage(int size)
	{
		window = size;
		sum = 0;
	}

	double get(double val)
	{
		sum += val;
		stream.push(val);
		if (stream.size() > window)
		{
			sum -= stream.front();
			stream.pop();
		}
		return sum / window;
	}
private:
	double sum;
	int window;
	queue<double> stream;
};

int main()
{
	Movingaverage a(3);
	cout << a.get(1) << endl;
	cout << a.get(2) << endl;
	cout << a.get(3) << endl;
	cout << a.get(4) << endl;
	system("pause");
	return 1;
}