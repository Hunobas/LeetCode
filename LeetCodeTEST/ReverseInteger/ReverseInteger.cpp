#include <iostream>
#include <string>
#include <limits>

using std::string;
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
            if (isOutRange((long long)res * 10 + remainder))
                return 0;
            res = res * 10 + remainder;
        }

        return res;
    }
};

int main()
{
    int a = -123;
    int b = 23;
    int c = 1534236469;

    Solution sol;

    cout << sol.reverse(a) << endl;
    cout << sol.reverse(b) << endl;
    cout << sol.reverse(c) << endl;

    /*string s1 = "-12364";
    string s1dot = "102364";
    string s2 = "-123-064";
    string s3 = "-1s23%64";

    cout << sol.stoi(s1) << endl;
    cout << sol.stoi(s1dot) << endl;
    cout << sol.stoi(s2) << endl;
    cout << sol.stoi(s3) << endl;*/

	return 0;
}