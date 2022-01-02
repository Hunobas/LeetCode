#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(const int& x) : val(x), next(nullptr) {}
    ListNode(const int& x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* makeListNode(const vector<int>& vec)
    {
        ListNode* genesis = new ListNode(vec[vec.size() - 1]);
        for (int i = vec.size() - 2; i >= 0; --i)
            genesis = new ListNode(vec[i], genesis);
        return genesis;
    }

    inline int getCount(ListNode* listnode)
    {
        int count = 0;
        for (; listnode != nullptr; listnode = listnode->next)
            count++;
        return count;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        int maxCount = max(getCount(l1), getCount(l2));

        if (l1 == nullptr || l2 == nullptr)
            return nullptr;
        if (maxCount > 100)
            return nullptr;

        vector<int> resultVec;
        int carry = 0;

        resultVec.reserve(maxCount + 2);

        while (l1 || l2 || carry)
        {
            int val1 = l1 ? l1->val : 0;
            int val2 = l2 ? l2->val : 0;

            int sum = val1 + val2 + carry;
            carry = sum / 10;
            sum %= 10;
            resultVec.push_back(sum);

            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
        }
        
        return makeListNode(resultVec);
    }

    void printListNodeVal(ListNode* listnode)
    {
        cout << "[ ";
        for (; listnode != nullptr; listnode = listnode->next)
        {
            cout << listnode->val << ", ";
        }
        cout << " ]\n";
    }
};

int main()
{
    vector<int> vec1 = { 9, 9, 9, 9, 9, 9 };
    vector<int> vec2 = { 9, 9, 9, 9 };
    
    Solution sol;

    ListNode* l1 = sol.makeListNode(vec1);
    ListNode* l2 = sol.makeListNode(vec2);

    sol.printListNodeVal(l1);
    sol.printListNodeVal(l2);

    ListNode* l3 = sol.addTwoNumbers(l1, l2);
    sol.printListNodeVal(l3);

    return 0;
}