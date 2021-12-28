#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using std::string;
using std::cout;
using std::endl;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        if (s.size() < 0 || s.size() > 5 * std::pow(10, 4))
            return 0;

        std::vector<int> resultVec;
        int length = s.size();
        string result = "";

        resultVec.reserve(length);

        for (int i = 0; i < length; ++i)
        {
            for (int j = i; j < length; ++j)
            {
                if (result.find(s[j]) != string::npos)
                {
                    break;
                }

                result += s[j];
            }

            resultVec.push_back(result.size());
            result = "";
        }

        if (resultVec.empty() == false)
            return *std::max_element(resultVec.begin(), resultVec.end());
        else
            return 0;
    }
};

int main()
{
    Solution sol;

    string s1 = "abcabcbb";
    string s2 = "bbbbbb";
    string s3 = "";

    cout << sol.lengthOfLongestSubstring(s1) << endl << endl;
    cout << sol.lengthOfLongestSubstring(s2) << endl << endl;
    cout << sol.lengthOfLongestSubstring(s3) << endl << endl;

	return 0;
}