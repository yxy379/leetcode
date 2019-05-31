// 006
// string, math
//#include <iostream>
//#include <string>
//
//using namespace std;
//
//class Solution
//{
//public:
//	string convert(string s, int numRows)
//	{
//		if (numRows < 2) return s;
//		string res;
//		for (int i = 0; i < numRows; i++)
//		{
//			for (int j = i; j < s.size(); j += 2 * numRows - 2)
//			{
//				res.push_back(s[j]);
//
//				if ((i >= 1) && (i <= (numRows - 2)) && (j + 2 * numRows - 2 - 2 * i < s.size()))
//				{
//					res.push_back(s[j + 2 * numRows - 2 - 2 * i]);
//				}
//			}
//		}
//
//		return res;
//	}
//};
//
//int main()
//{
//	Solution a;
//	cout << a.convert("PAYPALISHIRING", 2);
//	system("pause");
//	return 1;
//}


// 008
// string
//#include <iostream>
//#include <string>
//
//using namespace std;
//
//class Solution
//{
//public:
//	int str2int(string s)
//	{
//		int res = 0;
//		int sign = 1;
//		int i = 0;
//
//		if (s == "") return 0;
//
//		while (s[i] == ' ') i++;
//
//		if (i == s.size()) return 0;
//
//		if (s[i] == '+') i++;
//		if (s[i] == '-')
//		{
//			sign = -1;
//			i++;
//		}
//
//		for (; (i < s.size()) && (isdigit(s[i])); i++)
//		{
//			if (res > ((numeric_limits<int>::max() - (s[i] - '0')) / 10))
//			{
//				return sign > 0 ? numeric_limits<int>::max() : numeric_limits<int>::min();
//			}
//			res *= 10;
//			res += (s[i] - '0');
//		}
//		res *= sign;
//		return res;
//	}
//};
//
//int main()
//{
//	Solution a;
//	cout << a.str2int("   -91283472332") << endl;
//	system("pause");
//	return 1;
//}


// 014 
// string
//#include <iostream>
//#include <vector>
//#include <string>
//
//using namespace std;
//
//class Solution
//{
//public:
//	string commonPrefix(vector<string>& input)
//	{
//		if (input.empty()) return "";
//
//		string res = "";
//
//		for (int i = 0; i < input[0].size(); i++)
//		{
//			for (int j = 0; j < input.size(); j++)
//			{
//				if ((i >= input[j].size()) || (input[j][i] != input[0][i]))
//				{
//					return res;
//				}
//			}
//			res.push_back(input[0][i]);
//		}
//		return res;
//	}
//};
//
//int main()
//{
//	Solution a;
//	vector<string> input = { "flower","flow","flight" };
//	cout << a.commonPrefix(input) << endl;
//	system("pause");
//	return 1;
//}


// 028
// string
//#include <iostream>
//#include <string>
//
//using namespace std;
//
//class Solution
//{
//public:
//	int subString(string s, string needle)
//	{
//		if (needle.empty()) return 0;
//
//		for (int i = 0; i < s.size(); i++)
//		{
//			if ((i + needle.size()) > s.size()) break;
//			for (int j = 0; j < needle.size(); j++)
//			{
//				if (s[i + j] != needle[j]) break;
//
//				else if ((j == needle.size() - 1) && (s[i + j] == needle[j])) return i;
//			}
//		}
//		return -1; 
//
//	}
//};


// 038
// string
//#include <iostream>
//#include <string>
//
//using namespace std;
//
//class Solution
//{
//public:
//	string countAndSay(int n)
//	{
//		if (n < 1) return "";
//
//		string tmp = "1";
//		for (int i = 2; i <= n; i++)
//		{
//			string res = "";
//			int index = 0, count = 0;
//			char cur = tmp[0];
//			while (index < tmp.size())
//			{
//				if (tmp[index] == cur)
//				{
//					count++;
//				}
//				else
//				{
//					res += to_string(count);
//					res += cur;
//					cur = tmp[index];
//					count = 1;
//				}
//				index++;
//			}
//			res += to_string(count);
//			res += cur;
//			tmp = res;
//		}
//		return tmp;
//	}
//};
//
//int main()
//{
//	Solution a;
//	cout << a.countAndSay(4) << endl;
//	system("pause");
//	return 1;
//}


// 058
// string
//#include <iostream>
//#include <string>
//
//using namespace std;
//
//class Solution
//{
//public:
//	int lengthOfLastWord(string s)
//	{
//		if (s.empty()) return 0;
//
//		int j = s.size() - 1;
//		while ((j >= 0) && (s[j] == ' ')) j--;
//		
//		int length = 0;
//		while ((j>=0)&&(s[j]!=' '))
//		{
//			length++;
//			j--;
//		}
//		return length;
//	}
//};


// 067
// string
//#include <iostream>
//#include <bitset>
//#include <string>
//
//using namespace std;
//
//class Solution
//{
//public:
//	string addBinary(string s1, string s2)
//	{
//		reverse(s1.begin(), s1.end());
//		reverse(s2.begin(), s2.end());
//
//		string res = "";
//		int carry = 0;
//		for (int i = 0; (i < s1.size()) || (i < s2.size()); i++)
//		{
//			if (i < s1.size()) carry += (s1[i] - '0');
//			if (i < s2.size()) carry += (s2[i] - '0');
//			res.push_back(carry % 2 + '0');
//			carry /= 2;
//		}
//		if (carry)
//		{
//			res.push_back(carry + '0');
//		}
//		reverse(res.begin(), res.end());
//		return res;
//	}
//};
//
//int main()
//{
//	Solution a;
//	cout << a.addBinary("11", "1") << endl;
//	system("pause");
//	return 1;
//}


// 125 
// string, two pointer
//#include <iostream>
//#include <string>
//
//using namespace std;
//
//class Solution
//{
//public:
//	bool isPalindrome(string s)
//	{
//		if (s.empty()) return true;
//
//		int i = 0, j = s.size() - 1;
//		while (i < j)
//		{
//			while ((i < j) && (!isalnum(s[i]))) i++;
//			while ((i < j) && (!isalnum(s[j]))) j--;
//
//			if (tolower(s[i]) != tolower(s[j]))
//			{
//				return false;
//			}
//			i++;
//			j--;
//		}
//		return true;
//	}
//};
//
//int main()
//{
//	Solution a;
//	cout << a.isPalindrome("A man, a plan, a canal: Panama") << endl;
//	system("pause");
//	return 0;
//}


// 165
// string
//#include <iostream>
//#include <string>
//
//using namespace std;
//
//class Solution
//{
//public:
//	bool compareVersion(string s1, string s2)
//	{
//		for (int i = 0, j = 0; (i < s1.size()) || (j < s2.size()); i++, j++)
//		{
//			int v1 = 0, v2 = 0;
//
//			while ((i < s1.size()) && (s1[i] != '.'))
//			{
//				v1 = v1 * 10 + (s1[i] - '0');
//				i++;
//			}
//			while ((j < s2.size()) && (s2[j] != '0'))
//			{
//				v2 = v2 * 10 + (s2[j] - '0');
//				j++;
//			}
//
//			if (v1 != v2)
//				return v1 > v2 ? 1 : -1;
//		}
//		return 0;
//	}
//};
//
//int main()
//{
//	Solution a;
//	cout << a.compareVersion("1.01", "1.001") << endl;
//	system("pause");
//	return 1;
//}


// 242
// string, hash map
//#include <iostream>
//#include <string>
//#include <unordered_map>
//
//using namespace std;
//
//class Solution
//{
//public:
//	bool isAnagram(string s1, string s2)
//	{
//		unordered_map<char, int> count;
//
//		if (s1.size() != s2.size()) return false;
//
//		for (int i = 0; i < s1.size(); i++)
//		{
//			count[s1[i]]++;
//		}
//
//		for (int j = 0; j < s2.size(); j++)
//		{
//			count[s2[j]]--;
//			if (count[s2[j]] < 0) return false;
//		}
//		return true;
//	}
//};
//
//int main()
//{
//	Solution a;
//	cout << a.isAnagram("anagram", "nagaram") << endl;
//	system("pause");
//	return 1;
//}


// 383
// string, hash map
//#include <iostream>
//#include <string>
//#include <unordered_map>
//
//using namespace std;
//
//class Solution
//{
//public:
//	bool canConstruct(string ransom, string magazine)
//	{
//		unordered_map<char, int> count;
//		for (int i = 0; i < magazine.size(); i++)
//		{
//			count[magazine[i]]++;
//		}
//		for (int j = 0; j < ransom.size(); j++)
//		{
//			count[ransom[j]]--;
//			if (count[ransom[j]] < 0) return false;
//		}
//		return true;
//	}
//};
//
//int main()
//{
//	Solution a;
//	cout << a.canConstruct("aa", "aab") << endl;
//	system("pause");
//	return 1;
//}


// 405
// string, bit manipulation
//#include <iostream>
//#include <string>
//
//using namespace std;
//
//class Solution
//{
//public:
//	string int2hex(int num)
//	{
//		if (!num) return "0";
//
//		int tmp = 0;
//		string res = "";
//		while ( num && res.size()!=sizeof(int)*2)
//		{
//			tmp = num & 15;
//			if (tmp >= 10)
//			{
//				res.push_back(tmp - 10 + 'a');
//			}
//			else
//			{
//				res.push_back(tmp + '0');
//			}
//			num >>= 4;
//		}
//		reverse(res.begin(), res.end());
//		return res;
//	}
//};
//
//int main()
//{
//	Solution a;
//	cout << a.int2hex(-1) << endl;
//	cout << -10 / 3 << endl << -10 % 3 << endl;
//	system("pause");
//}


// 408
// string
//#include <iostream>
//#include <string>
//
//using namespace std;
//
//class Solution
//{
//public:
//	bool validAbbr(string s, string abbr)
//	{
//		int temp = 0, j = 0;
//		for (int i = 0; i < abbr.size(); i++)
//		{
//			if ((abbr[i] >= '0') && (abbr[i] <= '9'))
//			{
//				if ((abbr[i] == '0') && (temp == 0)) return false;
//				else
//				{
//					temp = temp * 10 + (abbr[i] - '0');
//				}
//			}
//			if ((abbr[i] >= 'a') && (abbr[i] <= 'z'))
//			{
//				j += temp;
//				if (abbr[i] != s[j]) return false;
//				j++;
//				temp = 0;
//			}
//		}
//		if (j + temp != s.size()) return false;
//		else return true;
//
//	}
//};
//
//int main()
//{
//	Solution a;
//	cout << a.validAbbr("internationalization", "i12iz4n") << endl;
//	system("pause");
//	return 1;
//}


// 415
// string
//#include <iostream>
//#include <string>
//
//using namespace std;
//
//class Solution
//{
//public:
//	string addString(string s1, string s2)
//	{
//		reverse(s1.begin(), s1.end());
//		reverse(s2.begin(), s2.end());
//
//		int carry = 0;
//		string res = "";
//		for (int i = 0; (i < s1.size()) || (i < s2.size()); i++)
//		{
//			if (i < s1.size()) carry += (s1[i] - '0');
//			if (i < s2.size()) carry += (s2[i] - '0');
//			res.push_back(carry % 10 + '0');
//			carry /= 10;
//		}
//		if (carry) res.push_back(carry + '0');
//		reverse(res.begin(), res.end());
//		return res;
//	}
//};
//
//int main()
//{
//	Solution a;
//	cout << a.addString("99", "99") << endl;
//	system("pause");
//	return 1;
//}


// 434
// string
//#include <iostream>
//#include <string>
//
//using namespace std;
//
//class Solution
//{
//public:
//	int numSegment(string s)
//	{
//		int res = 0;
//		int i = 0;
//		while(i<s.size())
//		{
//			while (((s[i] == ' ') || (s[i] == '\t') || (s[i] == '\n')) && (i < s.size()))
//			{
//				i++;
//			}
//			if (((s[i] != ' ') && (s[i] != '\t') && (s[i] != '\n')) && (i < s.size()))
//			{
//				res++;
//			}		
//			while (((s[i] != ' ') && (s[i] != '\t') && (s[i] != '\n')) && (i < s.size()))
//			{
//				i++;
//			}
//		}
//		return res;
//	}
//};
//
//int main()
//{
//	Solution a;
//	cout << a.numSegment("Hello, my name is John   ") << endl;
//	system("pause");
//	return 1;
//}


// 443
// string, double pointers
//#include <iostream>
//#include <vector>
//#include <string>
//
//using namespace std;
//
//class Solution
//{
//public:
//	int strCompress(vector<char>& input)
//	{
//		int cur = 0;
//		for (int i = 0, j = 0; i < input.size(); i = j)
//		{
//			while ((j < input.size()) && (input[j] == input[i])) j++;
//			input[cur++] = input[i];
//			if (j - i == 1) continue;
//			else
//			{
//				for (char c : to_string(j - i)) input[cur++] = c;
//			}
//		}
//		return cur;
//	}
//};
//
//int main()
//{
//	for (char c : to_string(13))
//	{
//		cout << c << endl;
//	}
//	Solution a;
//	vector<char> input{ 'a','b','b','b','b','b','b','b','b','b','b','a','a' };
//	cout << a.strCompress(input) << endl;
//	system("pause");
//	return 1;
//}


// 002
// linked list
//#include <iostream>
//
//using namespace std;
//
//struct node
//{
//	int data;
//	node* next;
//};
//
//node* newNode(int data)
//{
//	node* temp = new node;
//	temp->data = data;
//	temp->next = NULL;
//	return temp;
//}
//
//class Solution
//{
//public:
//	node* addTwoNum(node* n1, node* n2)
//	{
//		node* head = newNode(0);
//		node* res = head;
//		int carry = 0;
//		while ((n1 != NULL) || (n2 != NULL))
//		{
//			if (n1 != NULL)
//			{
//				carry += n1->data;
//				n1 = n1->next;
//			}
//			if (n2 != NULL)
//			{
//				carry += n2->data;
//				n2 = n2->next;
//			}
//
//			res->next = newNode(carry % 10);
//			carry /= 10;
//			res = res->next;
//		}
//		if (carry) res->next = newNode(carry);
//		return head->next;
//	}
//};
//
//int main()
//{
//	node* n1 = newNode(2);
//	n1->next = newNode(4);
//	n1->next->next = newNode(3);
//	node* n2 = newNode(5);
//	n2->next = newNode(6);
//	n2->next->next = newNode(4);
//	Solution a;
//	node* res = a.addTwoNum(n1, n2);
//	while (res != NULL)
//	{
//		cout << res->data << " ";
//		res = res->next;
//	}
//	system("pause");
//	return 1;
//}


// circular linked list?
// linked list
//#include <iostream>
//
//using namespace std;
//
//struct Node
//{
//	int data;
//	Node* next;
//};
//
//Node* newNode(int num)
//{
//	Node* temp = new Node;
//	temp->data = num;
//	temp->next = NULL;
//	return temp;
//}
//
//class Solution
//{
//public:
//	bool isCircular(Node* n)
//	{
//		if (n == NULL) return true;
//
//		Node* tmp = n->next;
//		while ((n != NULL) && (n != tmp))
//		{
//			tmp = tmp->next;
//		}
//		return tmp == n;
//	}
//};


// 021
// linked list
//#include <iostream>
//using namespace std;
//
//struct Node
//{
//	int data;
//	Node* next;
//};
//
//Node* newNode(int num)
//{
//	Node* temp = new Node;
//	temp->data = num;
//	temp->next = NULL;
//	return temp;
//}
//
//class Solution
//{
//public:
//	Node* mergeSortedLists(Node* n1, Node* n2)
//	{
//		Node* head = newNode(-1);
//		Node* res = head;
//		while ((n1 != NULL) && (n2 != NULL))
//		{
//			if (n1->data < n2->data)
//			{
//				res->next = n1;
//				n1 = n1->next;
//			}
//			else
//			{
//				res->next = n2;
//				n2 = n2->next;
//			}
//			res = res->next;
//		}
//		res->next = n1 ? n1 : n2;
//		return head->next;
//	}
//};
//
//int main()
//{
//	Node* n1 = newNode(1);
//	n1->next = newNode(2);
//	n1->next->next = newNode(4);
//	Node* n2 = newNode(1);
//	n2->next = newNode(3);
//	n2->next->next = newNode(4);
//	Solution a;
//	Node* res = a.mergeSortedLists(n1, n2);
//	while (res != NULL)
//	{
//		cout << res->data << " ";
//		res = res->next;
//	}
//	system("pause");
//	return 1;
//}


// 24
// linked list
//#include <iostream>
//using namespace std;
//
//struct Node
//{
//	int data;
//	Node* next;
//};
//
//Node* newNode(int num)
//{
//	Node* temp = new Node;
//	temp->data = num;
//	temp->next = NULL;
//	return temp;
//}
//
//class Solution
//{
//public:
//	Node* swayNodes(Node* n)
//	{
//		Node* head = newNode(-1);
//		head->next = n;
//
//		Node* pre = head;
//		Node* cur = n;
//
//		while ((cur != NULL) && (cur->next != NULL))
//		{
//			pre->next = cur->next;
//			cur->next = cur->next->next;
//			pre->next->next = cur;
//
//			pre = cur;
//			cur = cur->next;
//		}
//		return head->next;
//	}
//};
//
//int main()
//{
//	Node* n1 = newNode(1);
//	n1->next = newNode(2);
//	n1->next->next = newNode(3);
//	n1->next->next->next = newNode(4);
//	n1->next->next->next->next = newNode(5);
//	Solution a;
//	Node* res = a.swayNodes(n1);
//	while (res != NULL)
//	{
//		cout << res->data << " ";
//		res = res->next;
//	}
//	system("pause");
//	return 1;
//}


// 83
// linked list
//#include <iostream>
//using namespace std;
//
//struct Node
//{
//	int data;
//	Node* next;
//};
//
//Node* newNode(int num)
//{
//	Node* temp = new Node;
//	temp->data = num;
//	temp->next = NULL;
//	return temp;
//}
//
//class Solution
//{
//public:
//	Node* deleteDuplicate(Node* n)
//	{
//		Node* head = newNode(-1);
//		head->next = n;
//
//		Node* pre = head;
//		Node* cur = n;
//		while ((cur != NULL) && (cur->next != NULL))
//		{
//			if (cur->data == cur->next->data)
//			{
//				pre->next = cur->next;
//				//cur = NULL;
//				cur = pre->next;
//			}
//			else
//			{
//				pre = cur;
//				cur = cur->next;
//			}
//		}
//		return head->next;
//	}
//};
//
//int main()
//{
//	Node* n1 = newNode(1);
//	n1->next = newNode(1);
//	n1->next->next = newNode(2);
//	n1->next->next->next = newNode(2);
//	n1->next->next->next->next = newNode(2);
//	Solution a;
//	Node* res = a.deleteDuplicate(n1);
//	while (res != NULL)
//	{
//		cout << res->data << " ";
//		res = res->next;
//	}
//	system("pause");
//	return 1;
//}


// 189
// vector
//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//class Solution
//{
//public:
//	vector<int> rotateArray(vector<int>& input, int k)
//	{
//		for (int i = 0; i < input.size() - k; i++)
//		{
//			input.push_back(input[0]);
//			input.erase(input.begin());
//		}
//		return input;
//	}
//};
//
//int main()
//{
//	vector<int> input{ 1, 2, 3, 4, 5 };
//	Solution a;
//	vector<int> res = a.rotateArray(input, 3);
//	for (int i = 0; i < res.size(); i++)
//	{
//		cout << res[i] << " ";
//	}
//	system("pause");
//	return 1;
//}


// 169
// vecotr, hash map
//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <unordered_map>
//
//using namespace std;
//
//class Solution
//{
//public:
//	int majorityElement(vector<int>& input)
//	{
//		sort(input.begin(), input.end());
//		return input.at(input.size() / 2);
//	}
//};
//
//class Solution1
//{
//public:
//	int majorityElement(vector<int>& input)
//	{
//		unordered_map<int, int> count;
//		for (int i = 0; i < input.size(); i++)
//		{
//			count[input[i]]++;
//		}
//
//		for (auto it:count)
//		{
//			if (it.second > input.size() / 2) return it.first;
//		}
//	}
//};
//
//int main()
//{
//	vector<int> input{ 1, 1, 2, 2, 1 };
//	Solution1 a;
//	cout << a.majorityElement(input) << endl;
//	system("pause");
//	return 1;
//}


// 121 
// vector
////#include <iostream>
////#include <vector>
////#include <algorithm>
////using namespace std;
////
////class Solution
////{
////public:
////	int profit(vector<int>& stock)
////	{
////		int profit = 0;
////		int minPrice = stock[0];
////		for (int i = 1; i < stock.size(); i++)
////		{
////			profit = max(stock[i] - minPrice, profit);
////			minPrice = min(stock[i], minPrice);
////		}
////		return profit;
////	}
////};
////
////int main()
////{
////	vector<int> stock{ 3, 1, 2, 5, 9 };
////	Solution a;
////	cout << a.profit(stock) << endl;
////	system("pause");
////	return 1;
////}


// 118
// vector
//#include <iostream>
//#include <vector>
//using namespace std;
//
//class Solution
//{
//public:
//	vector<vector<int>> pascal(int k)
//	{
//		vector<vector<int>> res;
//		vector<int> prev;
//		for (int i = 1; i <= k; i++)
//		{
//			vector<int> curr;
//			curr.push_back(1);
//			for (int j = 1; j < i - 1; j++)
//			{
//				int prev1 = prev[j - 1];
//				int prev2 = prev[j];
//				curr.push_back(prev1 + prev2);
//			}
//			if (i > 1)
//			{
//				curr.push_back(1);
//			}
//			res.push_back(curr);
//			prev = curr;
//		}
//		return res;
//	}
//};
//
//int main()
//{
//	Solution a;
//	vector<vector<int>> res = a.pascal(5);
//	for (int i = 0; i < res.size(); i++)
//	{
//		for (int j = 0; j < res[i].size(); j++)
//		{
//			cout << res[i][j] << " ";
//		}
//		cout << endl;
//	}
//	system("pause");
//	return 1;
//}


// 119
// vecotr
//#include <iostream>
//#include <vector>
//using namespace std;
//
//class Solution
//{
//public:
//	vector<int> addRow(int k)
//	{
//		vector<int> prev;
//		for (int i = 1; i <= k; i++)
//		{
//			vector<int> curr;
//			curr.push_back(1);
//			for (int j = 1; j < i - 1; j++)
//			{
//				int prev1 = prev[j - 1];
//				int prev2 = prev[j];
//				curr.push_back(prev1 + prev2);
//			}
//			if (i > 1)
//			{
//				curr.push_back(1);
//			}
//			prev = curr;
//		}
//		return prev;
//	}
//};
//
//int main()
//{
//	Solution a;
//	vector<int> res = a.addRow(5);
//	for (int i = 0; i < res.size(); i++)
//	{
//		cout << res[i] << " ";
//	}
//	system("pause");
//	return 1;
//}


// 061
// vector
//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//class Solution
//{
//public:
//	vector<int> plusOne(vector<int>& input)
//	{
//		int carry = 0;
//		input[input.size() - 1] += 1;
//		for (int i = input.size() - 1; i >= 0; i--)
//		{
//			input[i] += carry;
//			
//			carry = input[i] / 10;
//			input[i] %= 10;
//		}
//		if (carry)
//		{
//			input.insert(input.begin(), carry);
//		}
//		return input;
//	}
//};
//
//int main()
//{
//	vector<int> input{ 9, 9, 9 };
//	Solution a;
//	vector<int> res = a.plusOne(input);
//	for (int i = 0; i < res.size(); i++)
//	{
//		cout << res[i] << " ";
//	}
//	system("pause");
//	return 1;
//}


// 693
// bit
//#include <iostream>
////#include <bitset>
//using namespace std;
//
//class Solution
//{
//public:
//	bool isAlternative(int input)
//	{
//		int bit = -1;
//		while (input)
//		{
//			if (input & 1 == 1)
//			{
//				if (bit == 1) return false;
//				else bit = 1;
//			}
//			else
//			{
//				if (bit == 0) return false;
//				else bit = 0;
//			}
//			input = input >> 1;
//		}
//		return true;
//	}
//};
//
//int main()
//{
//	Solution a;
//	cout << a.isAlternative(5) << endl;
//	system("pause");
//	return 1;
//}


// 645 
// bit
//#include <iostream>
//#include <vector>
//using namespace std;
//
//class Solution
//{
//public:
//	vector<int> mismatch(vector<int>& input)
//	{
//		vector<int> res(2, 0), count(input.size(), 0);
//		for (int i = 0; i < input.size(); i++)
//		{
//			count[input[i] - 1]++;
//		}
//		for (int i = 0; i < count.size(); i++)
//		{
//			if ((res[0] != 0) && (res[1] != 0)) return res;
//			if (count[i] == 2) res[0] = i + 1;
//			else if (count[i] == 0) res[1] = i + 1;
//		}
//		return res;
//	}
//};
//
//int main()
//{
//	Solution a;
//	vector<int> input{ 1, 2, 2, 4 };
//	vector<int> res = a.mismatch(input);
//	for (int i = 0; i < res.size(); i++)
//	{
//		cout << res[i] << " ";
//	}
//	system("pause");
//	return 1;
//}


// 461
//#include <iostream>
//#include <vector>
//#include <string>
//#include <bitset>
//#include <algorithm>
//using namespace std;
//
//class Solution
//{
//public:
//	vector<int> plusOne(vector<int>& num)
//	{
//		reverse(num.begin(), num.end());
//		num[0]++;
//		int carry = 0;
//		for (int i = 0; i < num.size(); i++)
//		{
//			num[i] += carry;
//			carry = num[i] / 10;
//			num[i] %= 10;
//		}
//		if (carry)
//		{
//			num.push_back(carry);
//		}
//		reverse(num.begin(), num.end());
//		return num;
//	}
//
//};
//
//int main()
//{
//	vector<int> num{1, 2, 3};
//	num.push_back(1);
//	for (int i = 0; i < num.size(); i++)
//	{
//		cout << num[i] << " ";
//	}
//	system("pause");
//}

// 012
//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//
//string intToRoman(int x)
//{
//	vector<int> num{ 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
//	vector<string> rom{ "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
//	string res;
//	int i = 0;
//	while (x)
//	{
//		while (x / num[i])
//		{
//			res.append(rom[i]);
//			x -= num[i];
//		}
//		i++;
//	}
//	return res;
//}
//
//int main()
//{
//	cout << intToRoman(1994) << endl;
//	system("pause");
//	return 1;
//}

// 013
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int romanToInt(string s)
{
	unordered_map <char, int> m
	{
		{'I', 1},
		{'V', 5},
		{'X', 10},
		{'L', 50},
		{'C', 100},
		{'D', 500},
		{'M', 1000}
	};
	int res = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if ((i > 0) && (m[s[i]] > m[s[i - 1]]))
		{
			res = res + m[s[i]] - 2 * m[s[i - 1]];
		}
		else
		{
			res += m[s[i]];
		}
	}
	return res;
}

int main()
{
	cout << romanToInt("MCMXCIV") << endl;
	system("pause");
	return 1;
}