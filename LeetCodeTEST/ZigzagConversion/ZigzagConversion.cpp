#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;
using std::cout;
using std::endl;

class Solution {
public:
    string convert(string s, int numRows) {
        int length = s.size();

        if (length < 1 || length > 1000)
            return "";
        if (numRows < 1 || numRows > 1000)
            return "";

        if (numRows == 1)
            return s;

        int set = 2 * numRows - 2;
        int numZig = length / set;
        int remainder = length % set;

        vector<string> resArr(numRows, "");
        int sIndex = 0;

        for (int i = 0; i < numZig; ++i)
        {
            for (int j = 0; j < numRows; ++j)
                resArr[j] += s[sIndex++];
            for (int j = 0; j < numRows - 2; ++j)
                resArr[numRows - j - 2] += s[sIndex++];
        }

        if (remainder == 0);
        else if (remainder - numRows <= 0)
            for (int i = 0; i < remainder; ++i)
                resArr[i] += s[sIndex++];
        else
        {
            for (int i = 0; i < numRows; ++i)
                resArr[i] += s[sIndex++];
            for (int i = 0; i < remainder - numRows; ++i)
                resArr[numRows - i - 2] += s[sIndex++];
        }

        string result = "";
        for (auto e : resArr)
            result += e;

        return result;
    }
};

int main()
{
    string s = "PAYPALISHIRING";

    Solution sol;
    cout << sol.convert(s, 2) << endl;
    cout << sol.convert(s, 3) << endl;
    cout << sol.convert(s, 4) << endl;
    cout << sol.convert(s, 5) << endl;
    cout << sol.convert(s, 6) << endl;

    return 0;
}
