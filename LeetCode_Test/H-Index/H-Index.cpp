#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    void bubbleRSort(vector<int>& citations) {
        for (auto i = citations.rbegin(); i != citations.rend(); i++) {
            for (auto j = i + 1; j != citations.rend(); j++) {
                if (*i > *j) swap(*i, *j);
            }
        }
    }

public:
    int hIndex(vector<int>& citations) {
        bubbleRSort(citations);
        int hIndex = 0;
        for (int i = 0; i < citations.size(); i++) {
            if (citations[i] >= i+1) hIndex++;
        }
        return hIndex;
    }
};

int main() {
    Solution sol;

    vector<int> vec1{ 3, 0, 6, 1, 5 };
    vector<int> vec2{ 1,3,1 };
    vector<int> vec3{ 10,8,5, 4, 3 };
    vector<int> vec4{ 25, 8, 5, 3, 3 };

    cout << sol.hIndex(vec1) << endl;
    cout << sol.hIndex(vec2) << endl;
    cout << sol.hIndex(vec3) << endl;
    cout << sol.hIndex(vec4) << endl;

    return 0;
}