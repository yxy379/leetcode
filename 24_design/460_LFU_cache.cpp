#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

class LFUCache
{
private:
	unordered_map<int, pair<int, int>> m;			// key -> {val, freq}
	unordered_map<int, list<int>::iterator> mIter;	// key -> key list iterator
	unordered_map<int, list<int>> fm;				// freq -> key list
	int capacity, minFreq;
public:

	LFUCache(int size)
	{
		capacity = size;
	}

	int get(int key)
	{
		// 1. determine if the keyue is in m
		//if (m.count(key) == 0) return -1;
		if (m.find(key) == m.end()) return -1;
		else
		{
			// 2. erase corresponding data in fm
			fm[m[key].second].erase(mIter[key]);

			// 3. update m
			++m[key].second;

			// 4. add data to fm
			fm[m[key].second].push_back(key);

			// 5. update data in mIter
			mIter[key] = --fm[m[key].second].end();

			// 6. determine minFreq
			if (fm[minFreq].size() == 0) ++minFreq;

			// 7. return value
			return m[key].first;
		}
	}

	void put(int key, int val)
	{
		if (capacity <= 0) return;
		// 1. if key not in m, update val and return
		if (get(key) != -1)
		{
			m[key].first = val;
			return;
		}
		else
		{
			// 2. if m.size() >= cap
			if (m.size() >= capacity)
			{
				// 2a). erase m's minFreq corresponding list first element
				m.erase(fm[minFreq].front());
				// 2b). erase mIter corresonding data
				mIter.erase(fm[minFreq].front());
				// 2c) erase fm list first element
				fm[minFreq].pop_front();
			}

			// 3. in m, add key -> {val, freq}
			m[key] = { val, 1 };

			// 4. in fm, add 1 correspoinding list val at end
			fm[1].push_back(key);

			// 5. in mIter, save fm[1] list position
			mIter[key] = --fm[1].end();

			// 6. reset minFreq to 1
			minFreq = 1;
		}
	}
};

int main()
{
	LFUCache a(2);
	a.put(1, 1);
	a.put(2, 2);
	cout<< a.get(1) << endl;	// return 1
	a.put(3, 3); // evicts key 2
	cout << a.get(2) << endl;	// return -1
	cout << a.get(3) << endl;	// return 3
	a.put(4, 4); // evicts key 1
	cout << a.get(1) <<endl;	// return -1
	cout << a.get(3) << endl;	// return 3
	cout << a.get(4) << endl;	// return 4
	system("pause");
	return 1;
}