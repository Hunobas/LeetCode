#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

class Solution {
public:
    bool isMatch(string s, string p) {
        if (s.size() < 1 || s.size() > 20)
            return false;
        if (p.size() < 1 || p.size() > 30)
            return false;
        for (char c : s)
            if (c < 97 || c > 122)
                return false;
        for (char c : p)
            if ((c < 97 || c > 122) && c != '.' && c != '*')
                return false;
        if (s.size() == 1 && p.size() == 1 && s[0] == p[0])
            return true;

        for (int i = 1; i < p.size(); ++i)
            if (p[i] == '*' && s[i - 1] != p[i - 1] && p[i - 1] != '.' && p[i - 1] != '*')
                p.erase(i-- - 1, 2);

        for (int i = 1; i < p.size(); ++i)
            if (p[i] == '*' && s.size() != p.size())
                p.erase(i-- - 1, 2);

        // boom! I gave up.

        if (s.size() != p.size())
            return false;

        for (int i = 0; i < p.size(); ++i)
        {
            if (s[i] == p[i])
                continue;
            else if (p[i] == '.')
                continue;
            else if (p[i] == '*' && s[i] == p[i - 1])
                continue;
            else if (p[i] == '*' && p[i - 1] == '.')
                continue;
            else
                return false;
        }

        return true;
    }
};

int main()
{
    string s1 = "aaa";
    string p1 = "ab*a*c*a";

    Solution sol;

    cout << sol.isMatch(s1, p1) << endl;

}