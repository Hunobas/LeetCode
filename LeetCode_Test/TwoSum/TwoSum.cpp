#include <iostream>
#include <math.h>
#include <vector>

using std::vector;
using std::cout;
using std::endl;
using vi = vector<int>;

class Solution
{
public:
    inline bool isArgOK(const int& argument)
    {
        return argument < pow(10, -9) && argument > pow(10, 9) ? false : true;
    }

    vector<int> twoSum(vector<int>& nums, int target)
    {
        int length = nums.size();
        vi result;
        result.reserve(10);

        if (length < 2 && length > pow(10, 4))
            return result;
        if (isArgOK(target) == false)
            return result;
        for (int i = 0; i < length; i++)
            if (isArgOK(nums[i]) == false)
                return result;

        // TODO : Refactoring Code less than O(n^2)
        for (int i = 0; i < length - 1; ++i)
        {
            for (int j = i + 1; j < length; ++j)
            {
                if (nums[i] + nums[j] == target)
                {
                    result.push_back(i);
                    result.push_back(j);
                    return result;
                }
            }
        }

        return result;
    }

};

void main()
{
    vi arr{ 2, 7, 11, 15, 26 };
    int target = 9;

    Solution sol;

    vi answer = sol.twoSum(arr, target);

    cout << "[ ";
    for (auto e : answer)
    {
        cout << e << ", ";
    }
    cout << "]" << endl;

    return;
}