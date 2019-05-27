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
	Node* detectCycle(Node* n)
	{
		if (n == NULL) return n;

		Node* slow = n;
		Node* fast = n;
		while ((fast->next != NULL) && (fast->next->next != NULL))
		{
			slow = slow->next;
			fast = fast->next->next;
			if (fast == slow) break;
		}
		if ((fast->next == NULL) || (fast->next->next == NULL)) return NULL;
		Node* tmp = n;
		while (slow != tmp)
		{
			slow = slow->next;
			tmp = tmp->next;
		}
		return tmp;
	}
};


