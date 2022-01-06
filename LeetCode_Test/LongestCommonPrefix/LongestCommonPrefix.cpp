#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;
using std::cout;
using std::endl;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() < 1 || strs.size() > 200)
            return "";
        for (string str : strs)
            if (str.size() < 0 || str.size() > 200)
                return "";

        string res = "";
    
        for (int i = 0; i < strs[0].size(); ++i)
        {
            for (int j = 1; j < strs.size(); ++j)
                if (strs[0][i] != strs[j][i])
                    return res;

            res += strs[0][i];
        }

        return res;
    }
};

int main()
{
    vector<string> strs1 = { "flower", "flow", "flight" };
    vector<string> strs2 = { "dog","racecar","car" };

    Solution sol;

    cout << sol.longestCommonPrefix(strs1) << endl;
    cout << sol.longestCommonPrefix(strs2) << endl;
}