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
	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
	{
		if (!list1)
			return list2;
		else if (!list2)
			return list1;

		ListNode *head1 = list1, *head2 = list2;
		ListNode dummy(INT_MIN);
		ListNode* tail = &dummy;

		while (head1 && head2)
		{
			if (head1->val <= head2->val)
			{
				tail->next = head1;
				head1 = head1->next;
			}
			else
			{
				tail->next = head2;
				head2 = head2->next;
			}
			tail = tail->next;
		}

		tail->next = head1 ? head1 : head2;
		return dummy.next;
	}
};

ListNode* makeListNode(vector<int> list)
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
	vector<int> vec1{ 1, 2, 4 };
	vector<int> vec2{ 1, 3, 4 };

	ListNode* node1 = makeListNode(vec1);
	ListNode* node2 = makeListNode(vec2);

	Solution sol;

	ListNode* res1 = sol.mergeTwoLists(node1, node2);
	printListNode(res1);
}