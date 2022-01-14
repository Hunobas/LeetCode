#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.size() < 0 || nums.size() > 3 * pow(10, 4))
			return 0;
		for (int num : nums)
			if (num < -100 || num > 100)
				return 0;

		if (nums.size() < 2)
			return nums.size();

		for (int i = 1; i < nums.size(); ++i)
			if (nums[i] == nums[i - 1])
			{
				nums.erase(nums.begin() + i--);
				continue;
			}

		return nums.size();
	}
};

int main()
{
	vector<int> vec1{ 1, 1, 2 };
	vector<int> vec2{ 0, 0, 1, 1, 1, 2, 2, 3, 3, 4 };

	Solution sol;

	cout << sol.removeDuplicates(vec1) << endl;
	cout << sol.removeDuplicates(vec2) << endl;
}
