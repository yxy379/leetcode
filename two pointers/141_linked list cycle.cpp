#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* next;
};

Node* newNode(int x)
{
	Node* temp = new Node;
	temp->data = x;
	temp->next = NULL;
	return temp;
}

class Solution
{
public:
	bool hasCycle(Node* n)
	{
		if (n == NULL ) return false;

		Node* slow = n;
		Node* fast = n;
		while ((fast->next != NULL) && (fast->next->next != NULL))
		{
			slow = slow->next;
			fast = fast->next->next;
			if (slow == fast) return true;
		}
		return false;
	}
};