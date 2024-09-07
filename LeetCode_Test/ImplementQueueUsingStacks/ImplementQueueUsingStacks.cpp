#include <iostream>
#include <string>
#include <vector>

using namespace std;

class MyQueue {
private:
    vector<int> m_que;

public:
    MyQueue() {
        m_que = vector<int>();
    }

    void push(int x) {
        m_que.push_back(x);
    }

    int pop() {
        if (m_que.size() < 1) return 0;

        int top = m_que[0];
        m_que.erase(m_que.begin());
        return top;
    }

    int peek() {
        if (m_que.size() < 1) return 0;
        return m_que.front();
    }

    bool empty() {
        return m_que.empty();
    }
};

int main() {
    MyQueue que;
    cout << que.peek() << endl;
    cout << que.pop() << endl;
    cout << que.empty() << endl;
    que.push(1);
    cout << que.empty() << endl;
    cout << que.peek() << endl;
    cout << que.pop() << endl;
    cout << que.empty() << endl;

	return 0;
}