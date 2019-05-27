#include <iostream>

using namespace std;

struct Node
{
	int data;
	Node* next;
};

Node* newNode(int data)
{
	Node* temp = new Node;
	temp->data = data;
	temp->next = NULL;
	return temp;
}

class Solution
{
public:
	Node* swapNodes(Node* node)
	{
		Node* head = newNode(0);
		head->next = node;
		Node* pre = head;
		Node* cur = head->next;

		while ((cur != NULL) && (cur->next != NULL))
		{
			pre->next = cur->next;
			cur->next = cur->next->next;
			pre->next->next = cur;

			pre = cur;
			cur = cur->next;
		}
		return head->next;
	}
};

int main()
{
	Node* node = newNode(1);
	node->next = newNode(2);
	node->next->next = newNode(3);
	node->next->next->next = newNode(4);
	node->next->next->next->next = newNode(5);

	Solution a;
	Node* res = a.swapNodes(node);
	while (res != NULL)
	{
		cout << res->data << " ";
		res = res->next;
	}
	system("pause");
	return 1;
}