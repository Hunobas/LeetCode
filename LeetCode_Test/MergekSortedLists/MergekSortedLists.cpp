#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cout;
using std::endl;

struct ListNode {
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(const int& x) : val(x), next(nullptr) {}
    ListNode(const int& x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty())
            return nullptr;

        while (lists.size() > 1)
        {
            lists[0] = mergeTwoLists(lists[0], lists[1]);
            lists.erase(lists.begin() + 1);
        }

        return lists[0];
    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        if (!list1)
            return list2;
        else if (!list2)
            return list1;

        ListNode* head1 = list1, * head2 = list2;
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
    vector<vector<int>> vec1{ {1, 4, 5}, {1, 3, 4}, {2, 6} };
    vector<ListNode*> list1;

    for (auto v : vec1)
        list1.push_back(makeListNode(v));

    Solution sol;

    ListNode* res1 = sol.mergeKLists(list1);
    
    printListNode(res1);
}