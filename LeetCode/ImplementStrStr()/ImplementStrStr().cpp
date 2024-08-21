#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

class Solution {
public:
    int strStr(string haystack, string needle)
    {
        if (haystack.empty() && needle.empty())
            return 0;

        for (int i = 0; i < int(haystack.size() - needle.size()) + 1; ++i)
        {
            if (haystack.substr(i, needle.size()) == needle)
                return i;
        }

        return -1;
    }
};

int main()
{
    string haystack1 = "hello";
    string needle1 = "ll";

    Solution sol;

    cout << sol.strStr(haystack1, needle1) << endl;
}