#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;
using std::cout;
using std::endl;

class Solution {
private:
    vector<string> sym{};
    vector<int> val{};

public:
    Solution()
    {
        sym = { "M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I" };
        val = { 1000,900,500,400,100,90,50,40,10,9,5,4,1 };
    }

    string intToRoman(int num) {

        string ans = "";
        int i = -1;

        while (num)
        {
            int q = num / val[++i];

            if (q)
                num = num % val[i];

            while (q)
            {
                ans = ans + sym[i];
                q--;
            }
        }

        return ans;
    }
};

int main()
{
    int a = 3333;
    Solution sol;
    cout << sol.intToRoman(a) << endl;
}