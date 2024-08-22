#include <iostream>

using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num == 1) {
            return true;
        }

        for (int i = 2; i <= num / 2; i++) {
            if (num % i == 0 && i == num / i) {
                return true;
            }
            unsigned long boundary = (unsigned long)i * i;
            if (boundary >= num) break;
        }

        return false;
    }
};

int main() {
    Solution sol;
    cout << (bool)sol.isPerfectSquare(16) << endl;
    cout << (bool)sol.isPerfectSquare(4) << endl;
    cout << (bool)sol.isPerfectSquare(9) << endl;
    cout << (bool)sol.isPerfectSquare(25) << endl;
    cout << (bool)sol.isPerfectSquare(49) << endl;
    cout << (bool)sol.isPerfectSquare(100000001) << endl;

	return 0;
}