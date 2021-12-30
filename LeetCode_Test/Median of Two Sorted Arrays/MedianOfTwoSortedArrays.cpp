#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cout;
using std::endl;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int length1 = nums1.size();
        int length2 = nums2.size();
        vector<int> merge;

        if (length1 < 0 && length1 > 1000 || length2 < 0 && length2 > 1000)
            return 0;

        for (int e : nums1)
        {
            if (e < -std::pow(10, 6) || e > std::pow(10, 6))
                return 0;
            merge.push_back(e);
        }
        for (int e : nums2)
        {
            if (e < -std::pow(10, 6) || e > std::pow(10, 6))
                return 0;
            merge.push_back(e);
        }
        
        int mergeLen = merge.size();
        if (mergeLen <= 0)
            return 0;

        std::sort(merge.begin(), merge.end());

        if (isOdd(mergeLen) == false)
            return (merge[mergeLen / 2 - 1] + merge[mergeLen / 2]) / 2.0f;
        else
            return merge[mergeLen / 2];
    }

    bool isOdd(const int& i)
    {
        if (i % 2 == 0)
            return false;
        return true;
    }
};

int main()
{
    vector<int> arr1{ 1, 3, 5, 7, 9 };
    vector<int> arr2{ 2, 4, 6, 8, 10 };

    Solution sol;

    cout << sol.findMedianSortedArrays(arr1, arr2) << endl;
}