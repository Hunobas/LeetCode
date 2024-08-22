#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";

        string result;
        // 부호 처리
        if ((numerator < 0) ^ (denominator < 0)) result += "-";

        long long n = abs((long long)numerator);
        long long d = abs((long long)denominator);

        // 정수 부분 계산
        result += to_string(n / d);
        long long remainder = n % d;

        if (remainder == 0) return result;

        result += ".";
        string decimal;

        while (remainder != 0) {
            remainder *= 10;
            decimal += to_string(remainder / d);
            remainder %= d;

            // 반복되는 패턴 찾기
            for (int len = 1; len <= decimal.length() / 2; len++) {
                string pattern = decimal.substr(decimal.length() - len);
                size_t pos = decimal.rfind(pattern, decimal.length() - len - 1);
                if (pos != string::npos && pos >= decimal.length() - 2 * len) {
                    return result + decimal.substr(0, pos) + "(" + pattern + ")";
                }
            }
        }

        return result + decimal;
    }
};

int main() {
    Solution sol;

    cout << sol.fractionToDecimal(67, 129) << endl;

    return 0;
}