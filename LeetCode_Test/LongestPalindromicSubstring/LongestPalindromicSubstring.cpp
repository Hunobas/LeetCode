#include <iostream>
#include <string>
#include <cctype>

using std::cout;
using std::endl;
using std::string;

class Solution {
public:
    string longestPalindrome(string s) {


        if (s.size() < 1 || s.size() > 1000)
            return "";

        int isConsistOfOneChar = 0;
        for (auto c : s)
        {
            if (c == s[0])
                isConsistOfOneChar++;

            if (isdigit(c) || isalpha(c))
                continue;
            else
                return "";
        }
        if (isConsistOfOneChar == s.size())
            return s;

        string result = "";
        int resultLen = result.size();

        for (int i = 0; i < s.size(); ++i)
        {
            int iLeft = i;
            int iRight = i;

            // odd palindrome
            while (iLeft >= 0 && iRight < s.size() && s[iLeft] == s[iRight])
            {
                string temp = s.substr(iLeft, iRight - iLeft + 1);
                if (temp.size() > resultLen)
                {
                    result = temp;
                    resultLen = temp.size();
                }
                iLeft--;
                iRight++;
            }

            // even palindrome
            iLeft = i;
            iRight = i + 1;
            while (iLeft >= 0 && iRight < s.size() && s[iLeft] == s[iRight])
            {
                string temp = s.substr(iLeft, iRight - iLeft + 1);
                if (temp.size() > resultLen)
                {
                    result = temp;
                    resultLen = temp.size();
                }
                iLeft--;
                iRight++;
            }
        }

        return result;
    }
};

int main()
{
    string s1 = "eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee";
    string s2 = "abbaabccba";
    string s3 = "sibalama";
    string s4 = "whattahw";
    string s5 = "ababcccbaba";


    Solution sol;

    cout << sol.longestPalindrome(s1) << endl;
    cout << sol.longestPalindrome(s2) << endl;
    cout << sol.longestPalindrome(s3) << endl;
    cout << sol.longestPalindrome(s4) << endl;
    cout << sol.longestPalindrome(s5) << endl;
	return 0;
}