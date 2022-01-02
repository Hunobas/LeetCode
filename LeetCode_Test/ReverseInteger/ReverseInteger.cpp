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
            return x < std::numeric_limits<int>::min() || x > std::numeric_limits<int>::max();
        };
        if (isOutRange(x))
            return 0;

        string xStr = std::to_string(x);
        string resStr = "";
        
        if (xStr[0] == '-')
        {
            resStr += '-';
            for (int i = xStr.size() - 1; i > 0; --i)
                resStr += xStr[i];
        }
        else
            for (int i = xStr.size() - 1; i >= 0; --i)
                resStr += xStr[i];

        long long res = stoi(resStr);
        if (isOutRange(res))
            return 0;

        return (int)res;
    }

    long long stoi(const string& s)
    {
        long long res = 0;
        int order = s.size() - 1;

        for (int i = 0; i < s.size(); ++i, --order)
        {
            switch (s[i])
            {
            case '0':
                continue;
            case '1':
                res += 1 * pow(10, order);
                break;
            case '2':
                res += 2 * pow(10, order);
                break;
            case '3':
                res += 3 * pow(10, order);
                break;
            case '4':
                res += 4 * pow(10, order);
                break;
            case '5':
                res += 5 * pow(10, order);
                break;
            case '6':
                res += 6 * pow(10, order);
                break;
            case '7':
                res += 7 * pow(10, order);
                break;
            case '8':
                res += 8 * pow(10, order);
                break;
            case '9':
                res += 9 * pow(10, order);
                break;
            default:
                if (!(s[i] == '-' && i == 0))
                    res /= 10;
                continue;
            }
        }

        res = s[0] == '-' ? -res : res;
        return res;
    }

    long long pow(const int& under, const int& exp)
    {
        long long res = 1;
        for (int i = 0; i < exp; ++i)
            res *= under;
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