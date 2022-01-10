#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

struct ListNode {
	int val;
	ListNode* next;

	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n)
	{
		ListNode* temp = head;
		int nodeLen = 0;
		while (temp)
		{
			nodeLen++;
			temp = temp->next;
		}

		if (nodeLen < 1 || nodeLen > 30 || n > nodeLen || n < 1)
			return nullptr;
		else if (nodeLen == n)
			return head->next;

		temp = head;
		int headCount = nodeLen - n - 1;

		while (temp->next && headCount-- > 0)
			temp = temp->next;

		if (temp->next->next != nullptr)
			temp->next = temp->next->next;
		else
			temp->next = nullptr;

		return head;
	}
};

ListNode* makeListNode(const vector<int>& list)
{
	if (list.empty())
		return nullptr;
	ListNode* head = new ListNode(list[list.size() - 1]);
	for (int i = list.size() - 2; i >= 0; --i)
		head = new ListNode(list[i], head);
	return head;
}

void printListNode(ListNode* head)
{
	cout << "[ ";
	while (head->next)
	{
		cout << head->val << ", ";
		head = head->next;
	}
	cout << head->val << " ]" << endl;
}

int main()
{
	vector<int> vec{ 1, 2, 3, 4, 5 };
	ListNode* head = makeListNode(vec);
	printListNode(head);

	Solution sol;

	sol.removeNthFromEnd(head, 2);
	printListNode(head);
}