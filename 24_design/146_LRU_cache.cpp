#include <iostream>
#include <unordered_map>
using namespace std;

struct LRUCacheNode
{
	int key;
	int val;
	LRUCacheNode* prev;
	LRUCacheNode* next;
	
LRUCacheNode(): key(0), val(0), prev(NULL), next(NULL){}
};

class LRUCache
{
private:
	unordered_map<int, LRUCacheNode*> m;
	LRUCacheNode* head; // 
	LRUCacheNode* tail; // LRU node's next
	int count;
	int capacity;
public:
	LRUCache(int size);
	~LRUCache();
	int get(int key);
	void set(int key, int val);
private:
	void detachNode(LRUCacheNode* node);		
	void insertToFront(LRUCacheNode* node);
	void deleteNode();						// delete node at end (LRU)
};

LRUCache::LRUCache(int size)
{
	capacity = size;
	count = 0;
	head = new LRUCacheNode;
	tail = new LRUCacheNode;
	head->prev = NULL;
	head->next = tail;
	tail->prev = head;
	tail->next = NULL;
}

LRUCache::~LRUCache()
{
	delete head;
	delete tail;
}

void LRUCache::detachNode(LRUCacheNode* node)
{
	node->prev->next = node->next;
	node->next->prev = node->prev;
}

void LRUCache::insertToFront(LRUCacheNode* node)
{
	node->next = head->next;
	node->prev = head;
	head->next = node;
	node->next->prev = node; // needed! 
}

void LRUCache::deleteNode()
{
	LRUCacheNode* node = tail->prev;
	detachNode(node);
	m.erase(node->key);
	count--;
}

int LRUCache::get(int key)
{
	if (m.find(key) == m.end()) return -1;
	else
	{
		detachNode(m[key]);
		insertToFront(m[key]);
		return m[key]->val;
	}
}

void LRUCache::set(int key, int val)
{
	if (m.find(key) == m.end())
	{
		if (count == capacity)
		{
			deleteNode();
		}
		LRUCacheNode* node = new LRUCacheNode;
		node->key = key;
		node->val = val;
		m[key] = node;
		insertToFront(node);
		++count;
	}
	else
	{
		m[key]->val = val;
		detachNode(m[key]);
		insertToFront(m[key]);
	}
}

int main()
{
	LRUCache a(2);
	a.set(1, 1);
	a.set(2, 2);
	cout << a.get(1) << endl;
	a.set(3, 3);
	cout << a.get(2) << endl;
	cout << a.get(3) << endl;
	a.set(4, 4);
	cout << a.get(1) << endl;
	cout << a.get(3) << endl;
	cout << a.get(4) << endl;
	system("pause");
	return 1;

}