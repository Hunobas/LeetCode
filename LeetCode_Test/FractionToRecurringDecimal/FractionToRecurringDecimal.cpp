#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
private:
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) {
            return "0";
        }

        string result;

        if (numerator < 0 ^ denominator < 0) {
            result += '-';
        }

        long long n = abs((long long)numerator);
        long long d = abs((long long)denominator);

        result += to_string(n / d);
        long long remainder = n % d;

        if (remainder == 0) return result;

        result += '.';
        string decimal;
        unordered_map<long long, int> seem;

        while (remainder != 0) {
            if (seem.count(remainder) != 0) {
                decimal.insert(seem[remainder], "(");
                decimal += ')';
                break;
            }
            seem[remainder] = decimal.length();
            remainder *= 10;
            decimal += to_string(remainder / d);
            remainder %= d;
        }

        return result + decimal;
    }
};

int main() {
    Solution sol;

    cout << sol.fractionToDecimal(1, 2) << endl;
    cout << sol.fractionToDecimal(2, 1) << endl;
    cout << sol.fractionToDecimal(4, 333) << endl;
    cout << sol.fractionToDecimal(-5, 80) << endl;
    cout << sol.fractionToDecimal(80, -5) << endl;

    return 0;
}