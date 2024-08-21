#include <iostream>
#include <string>
#include <math.h>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {

    }
};

int main() {
    string s;
    cin >> s;

    int globalNum = 0;
    int result = 0;

    for (int i = s.length() - 1; i >= 0; i--) {
        int currNum = 0;

        switch (s[i]) {
            case 'I':
                currNum = 1;
                break;
            case 'V':
                currNum = 5;
                break;
            case 'X':
                currNum = 10;
                break;
            case 'L':
                currNum = 50;
                break;
            case 'C':
                currNum = 100;
                break;
            case 'D':
                currNum = 500;
                break;
            case 'M':
                currNum = 1000;
                break;
        }
        if (currNum >= globalNum) {
            result += currNum;
        }
        else {
            result -= currNum;
        }

        globalNum = currNum;
    }
    cout << result << endl;

    return 0;
}