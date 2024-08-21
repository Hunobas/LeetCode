#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Solution {
public:
    int myAtoi(string s)
    {
        if (s.size() < 0 || s.size() > 200)
            return 0;

        int res = 0;
        int sign = 1;

        while (s[0] == ' ')
            s = s.substr(1, s.size() - 1);
        if (s == "-2147483648")
            return INT_MIN;
        switch (s[0])
        {
        case '+':
            s = s.substr(1, s.size() - 1);
            sign = 1;
            break;
        case '-':
            s = s.substr(1, s.size() - 1);
            sign = -1;
            break;
        default:
            break;
        }

        for (int i = 0; i < s.size() && res != INT_MAX && res != INT_MIN; ++i)
        {
            switch (s[i])
            {
            case '0':
                if (res != 0)
                    res = calcAndCheckOverFlow(res, 0, sign);
                break;
            case '1':
                res = calcAndCheckOverFlow(res, 1, sign);
                break;
            case '2':
                res = calcAndCheckOverFlow(res, 2, sign);
                break;
            case '3':
                res = calcAndCheckOverFlow(res, 3, sign);
                break;
            case '4':
                res = calcAndCheckOverFlow(res, 4, sign);
                break;
            case '5':
                res = calcAndCheckOverFlow(res, 5, sign);
                break;
            case '6':
                res = calcAndCheckOverFlow(res, 6, sign);
                break;
            case '7':
                res = calcAndCheckOverFlow(res, 7, sign);
                break;
            case '8':
                res = calcAndCheckOverFlow(res, 8, sign);
                break;
            case '9':
                res = calcAndCheckOverFlow(res, 9, sign);
                break;
            default:
                return sign * res;
            }
        }
        if (sign == 1 && res == INT_MAX)
            return INT_MAX;
        if (sign == -1 && res == INT_MIN)
            return INT_MIN;

        return sign * res;
    }

    int calcAndCheckOverFlow(const int& res, const int& num, const int& sign)
    {
        if (sign == 1 && sign * res > (INT_MAX - num) / 10)
            return INT_MAX;
        if (sign * res < ((long long)INT_MIN + num) / 10)
            return INT_MIN;
        return res * 10 + num;
    }
};

int main()
{
    string s1 = "42";
    string s2 = "   -42";
    string s3 = "-91283472332";

    Solution sol;

    cout << sol.myAtoi(s1) << endl;
    cout << sol.myAtoi(s2) << endl;
    cout << sol.myAtoi(s3) << endl;

	return 0;
}