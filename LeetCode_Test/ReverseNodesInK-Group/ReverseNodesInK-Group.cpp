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
    ListNode* reverseKGroup(ListNode* head, int k)
    {
        vector<int> nodeVec = convertToVec(head);
        int n = nodeVec.size();

        if (n < k || n > 5000)
            return nullptr;

        ListNode* newHead = nullptr;

        if (n % k != 0)
        {
            for (int i = 0; i < k * (n / k); ++i)
                head = head->next;
            newHead = head;
        }

        for (int i = n / k - 1; i >= 0; --i)
            for (int j = 0; j < k; ++j)
                newHead = new ListNode(nodeVec[k * i + j], newHead);

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
    ListNode* res1 = sol.reverseKGroup(makeListNode(vec1), 2);
    ListNode* res2 = sol.reverseKGroup(makeListNode(vec2), 2);
    ListNode* res3 = sol.reverseKGroup(makeListNode(vec3), 2);
    ListNode* res4 = sol.reverseKGroup(makeListNode(vec4), 2);
    ListNode* res5 = sol.reverseKGroup(makeListNode(vec2), 3);

    printListNode(res1);
    printListNode(res2);
    printListNode(res3);
    printListNode(res4);
    printListNode(res5);
}