// c++ program to check if a linked list is curcular
#include<iostream>

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
	Node* addTwoNumbers(Node* node1, Node* node2)
	{
		int carry = 0;
		Node* head = newNode(0);
		Node* res = head;
		while ((node1 != NULL) || (node2 != NULL))
		{
			if (node1 != NULL)
			{
				carry += node1->data;
				node1 = node1->next;
			}
			if (node2 != NULL)
			{
				carry += node2->data;
				node2 = node2->next;
			}
			res->next = newNode(carry % 10);
			res = res->next;
			carry /= 10;
			//node1 = node1->next;
			//node2 = node2->next;		
		}
		if (carry) res->next = newNode(carry);
		return head->next;
	}

	bool isCircular(Node* head)
	{
		if (head == NULL) return true;

		Node* node = head->next;
		while ((node != NULL) && (node != head))
		{
			node = node->next;
		}
		return (node == head);
	}
};

int main()
{
	Node* head = newNode(1);
	head->next = newNode(2);
	head->next = newNode(3);
	//head->next = head;
	cout << "This linked list ";
	Solution a;
	a.isCircular(head) ? cout << " is circular!" : cout << "is not curcular!" << endl;

	Node *node1 = newNode(2);
	node1->next = newNode(4);
	node1->next->next = newNode(3);

	Node *node2 = newNode(5);
	node2->next = newNode(6);
	node2->next->next = newNode(9);

	Node *res = a.addTwoNumbers(node1, node2);
	while (res != NULL)
	{
		cout << res->data << " ";
		res = res->next;
	}
	system("pause");
	return 1;
}