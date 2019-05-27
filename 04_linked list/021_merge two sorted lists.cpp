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
	Node* mergeLists(Node* node1, Node* node2)
	{
		Node* head = newNode(0);
		Node* temp = head;
		while ((node1 != NULL) && (node2 != NULL))
		{
			if (node1->data <= node2->data)
			{
				temp->next = node1;
				node1 = node1->next;
			}
			else
			{
				temp->next = node2;
				node2 = node2->next;
			}
			temp = temp->next;
		}
		temp->next = node1 ? node1 : node2;
		return head->next;
	}
};

int main()
{
	Node* node1 = newNode(1);
	node1->next = newNode(2);
	node1->next->next = newNode(4);

	Node* node2 = newNode(1);
	node2->next = newNode(3);
	node2->next->next = newNode(4);

	Solution a;
	Node* res = a.mergeLists(node1, node2);
	while (res != NULL)
	{
		cout << res->data << " ";
		res = res->next;
	}
	system("pause");
	return 1;
}