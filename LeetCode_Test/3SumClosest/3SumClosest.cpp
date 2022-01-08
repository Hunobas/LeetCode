#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cout;
using std::endl;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        int n = nums.size();
        std::sort(nums.begin(), nums.end());
        int res = pow(10, 4);

        for (int i = 0; i < n - 2; ++i)
        {
            int low = i + 1;
            int high = n - 1;

            while (low < high)
            {
                int sum = nums[low] + nums[high];
                if (std::abs(target - nums[i] - sum) < std::abs(target - res))
                    res = nums[i] + sum;

                if (target - nums[i] > sum)
                    low++;
                else if (target - nums[i] < sum)
                    high--;
                else
                    return nums[i] + sum;
            }
        }

        return res;
    }
};

int main()
{
    vector<int> vec1{ -1,2,1,-4 };
    vector<int> vec2{ 0, 0, 0 };
    vector<int> vec3{ 1, 1, 1, 1 };
    vector<int> vec4{ -3, -2, -5, 3, -4 };
    vector<int> vec5{ -100, -98, -2, -1 };

    Solution sol;

    cout << sol.threeSumClosest(vec1, 1) << endl;
    cout << sol.threeSumClosest(vec2, 1) << endl;
    cout << sol.threeSumClosest(vec3, 0) << endl;
    cout << sol.threeSumClosest(vec4, -1) << endl;
    cout << sol.threeSumClosest(vec5, -101) << endl;
}