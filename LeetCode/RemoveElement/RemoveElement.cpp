#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

class Solution {
public:
    int removeElement(vector<int>& nums, int val)
    {
        int count = 0;
        for (int i = 0; i < nums.size(); ++i)
            if (nums[i] != val)
                nums[count++] = nums[i];
        return count;
    }
};

int main()
{
    vector<int> vec1{3, 2, 2, 3};
    Solution sol;

    cout << sol.removeElement(vec1, 3) << endl;
}