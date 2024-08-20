#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

struct ListNode {
	ListNode* next;
	ListNode* prev;
	int val;

	ListNode() : val(0), next(nullptr), prev(nullptr) {}
	ListNode(const int& x) : val(x), next(nullptr), prev(nullptr) {}
	ListNode(const int& x, ListNode* n) : val(x), next(n), prev(nullptr) {}
};

class LinkedList
{
private:
	ListNode* head;
	ListNode* tail;
	int length;

public:
	LinkedList() : head(nullptr), tail(nullptr), length(0) {}
	LinkedList(ListNode* node) : head(node), tail(node), length(1) {
		Initialize();
	}

	void Initialize() {
		head->prev = nullptr;
		head->next = tail;
		tail->prev = head;
		tail->next = nullptr;
	}

	ListNode* Append(ListNode* node) {
		if (head == nullptr || tail == nullptr) {
			head = tail = node;
			Initialize();
			return node;
		}

		tail->next = node;
		node->prev = tail;

		ListNode* curr = node;
		for (; curr->next != nullptr; curr = curr->next);
		tail = curr;

		length += 1;

		return node;
	}

	void Insert(ListNode* node, unsigned int num) {
		ListNode* curr = head;

		while (--num > 0) {
			if (curr == nullptr) {
				curr = Append(new ListNode(0));
			}
			curr = curr->next;
		}

		if (curr == nullptr) {
			node->prev;
			curr = node;
		}
	}
};

int main() {


	return 0;
}