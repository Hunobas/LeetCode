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
    ListNode* swapPairs(ListNode* head)
    {
        vector<int> nodeVec = convertToVec(head);
        int n = nodeVec.size();

        if (n < 2)
            return head;
        if (n > 100)
            return nullptr;

        ListNode* newHead = nullptr;

        if (n % 2 == 1)
        {
            newHead = new ListNode(nodeVec[n - 1]);
            nodeVec.pop_back();
            n = nodeVec.size();
        }

        for (int i = n / 2 - 1; i >= 0; --i)
        {
            newHead = new ListNode(nodeVec[2 * i], newHead);
            newHead = new ListNode(nodeVec[2 * i + 1], newHead);
        }

        return newHead;
    }

    vector<int> convertToVec(ListNode* list)
    {
        ListNode* head = list;
        vector<int> res{};
        while (head)
        {
            res.push_back(head->val);
            head = head->next;
        }
        return res;
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
    if (!head)
    {
        cout << "[]" << endl;
        return;
    }
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
    vector<int> vec1{ 1, 2, 3, 4 };
    vector<int> vec2{ 1, 2, 3, 4, 5 };
    vector<int> vec3{};
    vector<int> vec4{ 1 };

    Solution sol;
    ListNode* res1 = sol.swapPairs(makeListNode(vec1));
    ListNode* res2 = sol.swapPairs(makeListNode(vec2));
    ListNode* res3 = sol.swapPairs(makeListNode(vec3));
    ListNode* res4 = sol.swapPairs(makeListNode(vec4));

    printListNode(res1);
    printListNode(res2);
    printListNode(res3);
    printListNode(res4);
}