#include <iostream>
#include <unordered_map>
#include <map>
#include <unordered_set>
using namespace std;

class Twitter
{
public:
	Twitter()
	{
		time = 0;
	}

	void postTweet(int userId, int tweetId)
	{
		follow(userId, userId);
		tweets[userId].insert({ ++time, tweetId });
	}

	vector<int> getNewsFeed(int userId)
	{
		vector<int> res;
		map<int, int> top10;
		for (auto id : friends[userId])
		{
			for (auto t : tweets[id])
			{
				top10.insert({ t.first, t.second });
				if (top10.size() > 10)
				{
					top10.erase(top10.begin());
				}
			}
		}
		for (auto t : top10)
		{
			res.insert(res.begin(), t.second);
		}
		return res;
	}

	void follow(int followerId, int followeeId)
	{
		friends[followerId].insert(followeeId);
	}

	void unfollow(int followerId, int followeeId)
	{
		if (followerId != followeeId)
		{
			friends[followerId].erase(followeeId);
		}
	}

private:
	int time;
	unordered_map<int, unordered_set<int>> friends; // userId -> frends unordered set
	unordered_map<int, map<int, int>> tweets;		// userId -> <time, tweets> map
};

int main()
{
	Twitter t;
	t.postTweet(1, 5); // user 1 posts a new tweet (id = 5)

	// user 1's news feed should return a list with 1 twwed id -> [5]
	vector<int> res1 = t.getNewsFeed(1);  
	for (auto r : res1) cout << r << " ";

	t.follow(1, 2);	   // user 1 follows user 2
	t.postTweet(2, 6); // user 2 posts a new tweet (id = 6)

	// should return [6, 5];
	vector<int> res2 = t.getNewsFeed(1);
	cout << endl;
	for (auto r : res2) cout << r << " ";

	t.unfollow(1, 2);	// user 1 unfollows user 2
	
	// should return [5];
	vector<int> res3 = t.getNewsFeed(1);
	cout << endl;
	for (auto r : res3) cout << r << " ";

	system("pause");
	return 1;
}