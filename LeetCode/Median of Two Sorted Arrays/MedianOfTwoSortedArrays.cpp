#include <iostream>
#include <vector>
#include <limits>

using std::vector;
using std::cout;
using std::endl;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        constexpr int imin = std::numeric_limits<int>::min();
        constexpr int imax = std::numeric_limits<int>::max();

        for (auto i : nums1)
            if (i < -std::pow(10, 6) || i > std::pow(10, 6))
                return 0;
        for (auto j : nums2)
            if (j < -std::pow(10, 6) || j > std::pow(10, 6))
                return 0;

        if (nums1.size() > nums2.size()) std::swap(nums1, nums2);

        int length1 = nums1.size();
        int length2 = nums2.size();
        int mergeLen = length1 + length2;
        int mergeMed = mergeLen / 2;
        int left1 = 0;
        int right1 = length1 - 1;

        while (1)
        {
            int median1 = std::floor((left1 + right1) / 2.0f);
            int median2 = mergeMed - median1 - 2;

            int leftOfMedian1 = median1 >= 0 ? nums1[median1] : imin;
            int rightOfMedian1 = median1 < length1 - 1 ? nums1[median1 + 1] : imax;
            int leftOfMedian2 = median2 >= 0 ? nums2[median2] : imin;
            int rightOfMedian2 = median2 < length2 - 1 ? nums2[median2 + 1] : imax;

            if (leftOfMedian1 <= rightOfMedian2 && leftOfMedian2 <= rightOfMedian1)
            {
                if (isOdd(mergeLen) == true)
                    return std::min(rightOfMedian1, rightOfMedian2);
                else
                    return (std::max(leftOfMedian1, leftOfMedian2) + std::min(rightOfMedian1, rightOfMedian2)) / 2.0f;
            }
            else if (leftOfMedian1 > rightOfMedian2)
                right1 = median1 - 1;
            else
                left1 = median1 + 1;
        }
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
    vector<int> arr1{ 1, 3 };
    vector<int> arr2{ 2 };

    Solution sol;

    cout << sol.findMedianSortedArrays(arr1, arr2) << endl;
}