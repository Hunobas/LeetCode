#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode* head, * tail;

    ListNode() : val(0), next(nullptr), head(nullptr), tail(nullptr) {}
    ListNode(ListNode* node) : val(node->val), next(node->next), head(node->head), tail(node->tail) {}
    ListNode(const int& x) { addNode(x); }
    ListNode(const int& x, ListNode* _next) : val(x), next(_next), head(this), tail(_next) {}
    ListNode(const vector<int>& vec)
        : head(nullptr), tail(nullptr)
    {
        for (auto e : vec)
        {
            addNode(e);
        }
    }

    ~ListNode()
    {
        ListNode* curr = head;
        ListNode* next = nullptr;

        while (curr)
        {
            next = curr->next;
            delete curr;
            curr = next;
        }
        head = nullptr;
        tail = nullptr;
    }

    void addNode(const int& n)
    {
        if (n < 0 || n > 9)
            return;

        ListNode* temp = new ListNode;
        temp->val = n;
        temp->next = nullptr;

        if (head == nullptr)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = tail->next;
        }
    }

    void printListNodeVal()
    {
        ListNode* curr = head;

        cout << "[ ";
        while (curr != tail)
        {
            cout << curr->val << ", ";
            curr = curr->next;
        }
        cout << tail->val << " ]\n";
    }
};

class Solution {
public:
    inline bool isContinue(ListNode* l1, ListNode* l2)
    {
        return l1 == nullptr && l2 == nullptr;
    }

    inline int getValOrZero(ListNode* node)
    {
        return node == nullptr ? 0 : node->val;
    }

    inline int getCount(ListNode* l1)
    {
        int count = 0;
        ListNode* curr = nullptr;

        for (curr = l1->head; curr != l1->tail; curr = curr->next)
        {
            count++;
        }
        return ++count;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        int maxCount = max(getCount(l1), getCount(l2));

        if (l1->head == nullptr || l2->head == nullptr)
            return nullptr;
        if (maxCount > 100)
            return nullptr;

        ListNode* l1Curr = l1->head;
        ListNode* l2Curr = l2->head;
        vector<int> resultVec;
        bool isOverFlow = false;

        resultVec.reserve(maxCount + 2);

        for (; !isContinue(l1Curr, l2Curr); l1Curr = l1Curr->next, l2Curr = l2Curr->next)
        {
            int sum = getValOrZero(l1Curr) + getValOrZero(l2Curr);

            switch (isOverFlow)
            {
            case true:
                switch (sum > 8)
                {
                case true:
                    resultVec.push_back(sum - 9);
                    if (isContinue(l1Curr->next, l2Curr->next))
                    {
                        resultVec.push_back(1);
                        return new ListNode(resultVec);
                    }
                    isOverFlow = true;
                    break;
                case false:
                    resultVec.push_back(sum + 1);
                    isOverFlow = false;
                    break;
                }
                break;
            case false:
                switch (sum > 9)
                {
                case true:
                    resultVec.push_back(sum - 10);
                    if (isContinue(l1Curr->next, l2Curr->next))
                    {
                        resultVec.push_back(1);
                        return new ListNode(resultVec);
                    }
                    isOverFlow = true;
                    break;
                case false:
                    resultVec.push_back(sum);
                    isOverFlow = false;
                    break;
                }
                break;
            }
        }
        
        return new ListNode(resultVec);
    }
};

int main()
{
    vector<int> vec1 = { 3, 5, 4, 3, 2, 6};
    vector<int> vec2 = { 5, 6, 4, 2, 8, 8 };

    ListNode* l1 = new ListNode(vec1);
    ListNode* l2 = new ListNode(vec2);

    l1->printListNodeVal();
    l2->printListNodeVal();

    Solution sol;

    ListNode* l3 = sol.addTwoNumbers(l1, l2);
    l3->printListNodeVal();

    return 0;
}