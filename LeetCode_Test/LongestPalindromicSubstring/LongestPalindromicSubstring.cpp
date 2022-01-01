#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using std::cout;
using std::endl;
using std::string;

class Solution {
public:
    string longestPalindrome(string s) {

        if (s.size() < 1 || s.size() > 1000)
            return "";
        for (auto c : s)
            if (isdigit(c) || isalpha(c))
                continue;
            else
                return "";

        string result{ s[0] };
        
        for (int i = 0; i < s.size() - 1; ++i)
        {
            for (int j = s.size() - 1; j > i; --j)
            {
                string temp = "";

                if (s[i] == s[j])
                {
                    int itmp = i;
                    int jtmp = j;

                    while (itmp < jtmp)
                    {
                        itmp++; jtmp--;

                        if (s[itmp] == s[jtmp])
                            continue;
                        else
                            goto NotPalindrome;
                    }

                    for (int k = i; k <= j; ++k)
                        temp += s[k];
                    result = temp.size() > result.size() ? temp : result;
                    if (result.size() > s.size() / 2)
                        return result;
                }
                
            NotPalindrome:;
            }
        }

        return result;
    }
};

int main()
{
    string s1 = "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb";

    Solution sol;

    cout << sol.longestPalindrome(s1) << endl;
	return 0;
}