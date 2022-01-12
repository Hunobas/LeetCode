#include <iostream>
#include <vector>

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

        ListNode res(INT_MIN);
        ListNode* tail = &res;
        vector<ListNode*> done(lists.size(), nullptr);

        while (lists != done)
        {
            int i = 0;
            int minVal = INT_MAX;

            for (int j = 0; j < lists.size(); ++j)
                if (lists[j] != nullptr && minVal > lists[j]->val)
                {
                    i = j;
                    minVal = lists[j]->val;
                }

            tail->next = lists[i];
            tail = tail->next;
            lists[i] = lists[i]->next;
        }

        return res.next;
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