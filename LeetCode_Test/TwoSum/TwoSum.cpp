#include <iostream>
#include <math.h>
#include <vector>
#include <unordered_map>

using std::vector;
using vi = vector<int>;
using iimap = std::unordered_map<int, int>;

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

        iimap prevHash;

        for (int i = 0; i < length; ++i)
        {
            auto iter = prevHash.find(target - nums[i]);

            if (iter != prevHash.end())
            {
                result.push_back(iter->second);
                result.push_back(i);
                return result;
            }

            prevHash.insert(std::make_pair(nums[i], i));
        }

        return result;
    }

};

void main()
{
    using std::cout;
    using std::endl;

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