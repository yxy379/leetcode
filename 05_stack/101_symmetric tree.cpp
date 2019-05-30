#include <iostream>
#include <stack>
using namespace std;

struct treeNode
{
	int val; 
	treeNode* left;
	treeNode* right;
	treeNode(int val) : val(val), left(NULL), right(NULL) {}
};

// iterative
class Solution1
{
public:
	bool isSymmetric(treeNode* root)
	{
		if (!root) return true;

		stack<treeNode*> s;
		s.push(root->left);
		s.push(root->right);
		while (!s.empty())
		{
			auto right = s.top();
			s.pop();
			auto left = s.top();
			s.pop();
			if ((!right) && (!left)) continue;
			if ((!right) || (!left) || (left->val != right->val)) return false;
			s.push(left->left);
			s.push(right->right);
			s.push(left->right);
			s.push(right->left);
		}
		return true;
	}
};

// recursive
class Solution2
{
public:
	bool isSymmetric(treeNode* root)
	{
		if (!root) return true;
		return isSymmetric(root->left, root->right);
	}
private:
	bool isSymmetric(treeNode* left, treeNode* right)
	{
		if ((!left) && (!right)) return true;
		if ((!left) || (!right) || (left->val != right->val)) return false;
		return isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
	}
};

int main()
{
	Solution2 a;
	treeNode* node = new treeNode(1);
	node->left = new treeNode(2);
	node->right = new treeNode(2);
	node->left->left = new treeNode(3);
	node->left->right = new treeNode(4);
	node->right->left = new treeNode(4);
	node->right->right = new treeNode(3);
	cout << a.isSymmetric(node) << endl;
	delete node;
	system("pause");
	return 1;
}