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
	Node* removeDuplicated(Node* node)
	{
		Node* head = newNode(0);
		head->next = node;
		while (node != NULL && node->next != NULL)
		{
			//cout << node->next->data;

			if (node->data == node->next->data)
			{
				Node* temp = node->next;
				node->next = node->next->next;
				delete temp;
			}
			else
			{
				node = node->next;
			}
		}

		return head->next;
	}
};

int main()
{
	Node* node = newNode(1);
	node->next = newNode(1);
	node->next->next = newNode(1);
	node->next->next->next = newNode(3);
	node->next->next->next->next = newNode(3);
	Solution a;
	Node* res = a.removeDuplicated(node);
	while (res != NULL)
	{
		cout << res->data << " ";
		res = res->next;
	}
	system("pause");
	return 1;
}