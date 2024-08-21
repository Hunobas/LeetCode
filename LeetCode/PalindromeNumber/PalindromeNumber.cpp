#include <iostream>

using std::cout;
using std::endl;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || x % 10 == 0 && x != 0)
            return false;

        int xLeft = x;
        int xRight = x;
        int leftOrder = 1;
        int rightOrder = 1;

        while (leftOrder <= x / 10)
            leftOrder *= 10;

        while (leftOrder >= rightOrder)
        {
            if (xLeft / leftOrder != xRight % 10)
                return false;

            xLeft %= leftOrder;
            xRight /= 10;
            leftOrder /= 10;
            rightOrder *= 10;
        }

        return true;
    }
};

int main()
{
    int a = 123;
    int b = 121;
    int c = 123454321;
    int d = -121;
    int e = 11;
    int f = 00;

    Solution sol;

    cout << sol.isPalindrome(a) << endl;
    cout << sol.isPalindrome(b) << endl;
    cout << sol.isPalindrome(c) << endl;
    cout << sol.isPalindrome(d) << endl;
    cout << sol.isPalindrome(e) << endl;
    cout << sol.isPalindrome(f) << endl;
}