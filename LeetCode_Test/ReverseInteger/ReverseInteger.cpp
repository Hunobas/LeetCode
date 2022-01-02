#include <iostream>
#include <limits>

using std::cout;
using std::endl;

class Solution {
public:
    int reverse(int x) {
        auto isOutRange = [](const long long& x) {
            return x > std::numeric_limits<int>::max() || x < std::numeric_limits<int>::min();
        };
        if (isOutRange(x))
            return 0;

        int res = 0;

        while (x != 0)
        {
            int remainder = x % 10;
            x /= 10;
            if (isOutRange((long long)res * 10))
                return 0;
            res = res * 10 + remainder;
        }

        return res;
    }
};

int main()
{
    int a = 123;
    int b = 321;
    int c = 1236147269;
    int d = -1943;

    Solution sol;

    cout << sol.reverse(a) << endl;
    cout << sol.reverse(b) << endl;
    cout << sol.reverse(c) << endl;
    cout << sol.reverse(d) << endl;

    return 0;
}