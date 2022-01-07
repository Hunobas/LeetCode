#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cout;
using std::endl;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        int n = nums.size();
        vector<vector<int>> resVec{};

        if (n < 0 || n > 3000)
            return resVec;
        for (int num : nums)
            if (num < -pow(10, 5) || num > pow(10, 5))
                return resVec;

        for (int i = 0; i < n - 2; ++i)
        {
            for (int j = i + 1; j < n - 1; ++j)
            {
                int ij = nums[i] + nums[j];

                for (int k = j + 1; k < n; ++k)
                {
                    vector<int> res{};
                    if (!(ij + nums[k]))
                    {
                        res.push_back(nums[i]);
                        res.push_back(nums[j]);
                        res.push_back(nums[k]);
                        std::sort(res.begin(), res.end());

                        if (isContain(resVec, res))
                            continue;
                        resVec.push_back(res);
                    }
                }
            }
        }

        return resVec;
    }

    template<typename T>
    bool isContain(vector<T> objects, T object)
    {
        for (T v : objects)
            if (v == object)
                return true;
        return false;
    }
};

void printResVec(vector<vector<int>> resVec)
{
    cout << "[";
    for (auto v : resVec)
    {
        cout << "[";
        for (auto i : v)
        {
            cout << i << ", ";
        }
        cout << "], ";
    }
    cout << "]" << endl;
}

int main()
{
    vector<int> nums1{ -1, 0, 1, 2, -1, -4 };
    vector<int> nums2{13, 4, -6, -7, -15, -1, 0, -1, 0, -12, -12, 9, 3, -14, -2, -5, -6, 7, 8, 2, -4, 6, -5, -10, -4, -9, -14, -14, 12, -13, -7, 3, 7, 2, 11, 7, 9, -4, 13, -6, -1, -14, -12, 9, 9, -6, -11, 10, -14, 13, -2, -11, -4, 8, -6, 0, 7, -12, 1, 4, 12, 9, 14, -4, -3, 11, 10, -9, -8, 8, 0, -1, 1, 3, -15, -12, 4, 12, 13, 6, 10, -4, 10, 13, 12, 12, -2, 4, 7, 7, -15, -4, 1, -15, 8, 5, 3, 3, 11, 2, -11, -12, -14, 5, -1, 9, 0, -12, 6, -1, 1, 1, 2, -3};
    vector<int> nums3{ 0 };
    vector<int> nums4{ 0, 0, 0, 0 };
    vector<int> nums5{ -2, 0, 0, 2, 2 };

    Solution sol;

    vector<vector<int>> res1 = sol.threeSum(nums1);
    vector<vector<int>> res2 = sol.threeSum(nums2);
    vector<vector<int>> res3 = sol.threeSum(nums3);
    vector<vector<int>> res4 = sol.threeSum(nums4);
    vector<vector<int>> res5 = sol.threeSum(nums5);

    printResVec(res1);
    printResVec(res2);
    printResVec(res3);
    printResVec(res4);
    printResVec(res5);
}