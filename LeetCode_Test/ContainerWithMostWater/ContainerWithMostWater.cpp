#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cout;
using std::endl;
using std::max_element;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();

        if (n < 2 || n > pow(10, 5))
            return 0;
        for (int i : height)
            if (i < 0 || i > pow(10, 4))
                return 0;

        int half = n / 2;
        vector<float> left;
        vector<float> right;
        left.reserve(half + 2);
        right.reserve(half + 2);
        float distance = 0;
        float center = (n - 1) / 2.0f;

        for (int i = 0; i < half; ++i)
        {
            distance = (center - i) + height[i];
            left.push_back(distance);
        }
        for (int i = half; i < n; ++i)
        {
            distance = -(center - i) + height[i];
            right.push_back(distance);
        }

        auto temp = left;
        auto lmax = max_element(temp.begin(), temp.end()) - temp.begin();
        temp[lmax] = 0;
        auto lsec = --max_element(temp.rbegin(), temp.rend()).base() - temp.begin();

        temp = right;
        auto rmax = --max_element(temp.rbegin(), temp.rend()).base() - temp.begin();
        temp[rmax] = 0;
        auto rsec = max_element(temp.begin(), temp.end()) - temp.begin();

        vector<int> res(6);
        res.push_back((half + rmax - lmax) * std::min(height[lmax], height[half + rmax]));
        res.push_back((half + rmax - lsec) * std::min(height[lsec], height[half + rmax]));
        res.push_back((half + rsec - lmax) * std::min(height[lmax], height[half + rsec]));
        res.push_back((half + rsec - lsec) * std::min(height[lsec], height[half + rsec]));
        res.push_back((std::abs(lmax - lsec)) * std::min(height[lmax], height[lsec]));
        res.push_back((std::abs(rmax - rsec)) * std::min(height[half + rmax], height[half + rsec]));

        return *max_element(res.begin(), res.end());
    }
};

int main()
{
    vector<int> height1{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }; // 25
    vector<int> height2{ 2, 3, 4, 5, 18, 17, 6 }; // 17
    vector<int> height3{ 8, 10, 14, 0, 13, 10, 9, 9, 11, 11 }; // 80
    Solution sol;

    cout << sol.maxArea(height1) << endl;
    cout << sol.maxArea(height2) << endl;
    cout << sol.maxArea(height3) << endl;
}