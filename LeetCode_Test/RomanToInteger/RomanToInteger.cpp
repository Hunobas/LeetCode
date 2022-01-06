#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;
using std::cout;
using std::endl;

class Solution {
private:
    vector<int> vals;
    vector<string> syms;

public:
    Solution()
    {
        vals = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
        syms = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
    }

    int romanToInt(string s)
    {
        int res = 0;

        for (int i = 0; i < syms.size(); ++i)
        {
            string comp = "";
            comp += s[0];

            if (i % 2)
                comp += s[1];

            while (syms[i] == comp)
            {
                res += vals[i];
                s = s.substr(comp.size(), s.size() - comp.size());
                comp = s[0];
            }
        }

        return res;
    }
};

int main()
{
    string a = "III";
    string b = "LVIII";
    string c = "MCMXCIV";

    Solution sol;

    cout << sol.romanToInt(a) << endl;
    cout << sol.romanToInt(b) << endl;
    cout << sol.romanToInt(c) << endl;
}