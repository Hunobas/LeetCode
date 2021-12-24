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

    inline int getValOrZero(ListNode* node)
    {
        return node == nullptr ? 0 : node->val;
    }

    inline int getCount(ListNode* listnode)
    {
        int count = 0;
        for (; listnode != nullptr; listnode = listnode->next)
            count++;
        return count;
    }

    inline ListNode* getNext(ListNode*& listnode)
    {
        if (listnode == nullptr)
            return nullptr;
        return listnode->next;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        int maxCount = max(getCount(l1), getCount(l2));

        if (l1 == nullptr || l2 == nullptr)
            return nullptr;
        if (maxCount > 100)
            return nullptr;

        ListNode* l1Curr = l1;
        ListNode* l2Curr = l2;
        vector<int> resultVec;
        int carry = 0;
        auto areTwoNullptr = [](ListNode* l1, ListNode* l2) { return l1 == nullptr && l2 == nullptr; };

        resultVec.reserve(maxCount + 2);

        while (!areTwoNullptr(l1Curr, l2Curr))
        {
            int sum = getValOrZero(l1Curr) + getValOrZero(l2Curr) + carry;
            carry = sum / 10;
            sum %= 10;
            resultVec.push_back(sum);

            if (carry && areTwoNullptr(getNext(l1Curr), getNext(l2Curr)))
                resultVec.push_back(1);

            if (getNext(l1Curr) != nullptr)
                l1Curr = l1Curr->next;
            else
                l1Curr = nullptr;

            if (getNext(l2Curr) != nullptr)
                l2Curr = l2Curr->next;
            else
                l2Curr = nullptr;
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