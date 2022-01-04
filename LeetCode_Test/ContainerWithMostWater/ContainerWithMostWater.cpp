#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();

        if (n < 2 || n > pow(10, 5))
            return 0;
        for (int i : height)
            if (i < 0 || i > pow(10, 4))
                return 0;

        int res = 0;

        for (int i = 0; i < n - 1; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                int water = (j - i) * std::min(height[i], height[j]);
                if (water > res)
                    res = water;
            }
        }

        return res;
    }
};

int main()
{
    vector<int> height{ 1 };
    Solution sol;

    cout << sol.maxArea(height) << endl;
    
}