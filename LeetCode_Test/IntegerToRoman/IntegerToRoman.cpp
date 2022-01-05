#include <iostream>
#include <string>
#include <vector>
#include <tuple>

using std::string;
using std::cout;
using std::endl;
using tcis = std::vector<std::tuple<char, int>>;

class Solution {
private:
    tcis romanTable;

public:
    Solution()
    {
        romanTable.push_back(std::make_tuple('I', 1));
        romanTable.push_back(std::make_tuple('V', 5));
        romanTable.push_back(std::make_tuple('X', 10));
        romanTable.push_back(std::make_tuple('L', 50));
        romanTable.push_back(std::make_tuple('C', 100));
        romanTable.push_back(std::make_tuple('D', 500));
        romanTable.push_back(std::make_tuple('M', 1000));
    }

    string intToRoman(int num) {
        if (num < 1 || num > 3999)
            return "";

        string res = "";

        for (int i = romanTable.size() - 1; i >= 0; --i)
        {
            int digit;

            if (i % 2)
            {
                digit = num / std::get<1>(romanTable[i - 1]);
                if (digit == 9)
                {
                    res += std::get<0>(romanTable[i - 1]);
                    res += std::get<0>(romanTable[i + 1]);
                    num %= std::get<1>(romanTable[i - 1]);
                    continue;
                }
            }
            digit = num / std::get<1>(romanTable[i]);

            if (digit == 4)
            {
                res += std::get<0>(romanTable[i]);
                res += std::get<0>(romanTable[i + 1]);
                num %= std::get<1>(romanTable[i]);
                continue;
            }

            while (digit-- != 0)
                res += std::get<0>(romanTable[i]);

            num %= std::get<1>(romanTable[i]);
        }

        return res;
    }
};

int main()
{
    int a = 3999;
    Solution sol;

    cout << sol.intToRoman(a) << endl;
}