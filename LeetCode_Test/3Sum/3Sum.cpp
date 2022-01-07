#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using std::vector;
using std::cout;
using std::endl;
using iimap = std::unordered_map<int, int>;

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {

		int n = nums.size();
		vector<vector<int>> resVec{};
		std::sort(nums.begin(), nums.end());

		if (n < 3 || n > 3000 || nums[0] > 0)
			return resVec;

		for (int i = 0; i < n - 2 && nums[0] <= 0; ++i)
		{
			int target = nums[0];
			nums.erase(nums.begin());
			vector<vector<int>> twoOfThrees = twoSum(nums, -target);

			for (int j = 0; j < twoOfThrees.size(); ++j)
			{
				twoOfThrees[j].insert(twoOfThrees[j].begin(), target);
				if (isContain(resVec, twoOfThrees[j]))
					continue;
				resVec.push_back(twoOfThrees[j]);
			}
		}

		return resVec;
	}

	vector<vector<int>> twoSum(vector<int>& nums, int target)
	{
		int length = nums.size();
		iimap prevHash{};
		vector<vector<int>> resVec;

		for (int i = 0; i < length; ++i)
		{
			vector<int> res{};
			auto iter = prevHash.find(target - nums[i]);

			if (iter != prevHash.end())
			{
				res.push_back(iter->first);
				res.push_back(nums[i]);
				resVec.push_back(res);
			}

			prevHash.insert(std::make_pair(nums[i], i));
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
		cout << "[ ";
		for (auto i : v)
		{
			if (i != v[v.size() - 1])
				cout << i << ", ";
			else
				cout << i << " ";
		}
		if (v != resVec[resVec.size() - 1])
			cout << "], ";
		else
			cout << "]";
	}
	cout << "]" << endl;
}

int main()
{
	vector<int> nums1{ -1, 0, 1, 2, -1, -4 };
	vector<int> nums2{ 13, -11, -14, 4, -9, -10, -11, 7, -14, -9, 14, 0, -5, -7, 6, -9, 11, 6, -14, -12, -10, 9, -8, -7, 5, 6, 8, -12, -1, -4, 14, -3, 0, 7, 9, 7, 12, 13, -9, 13, 11, -10, -10, -9, -10, 12, -10, 8, -5, 13, 11, -8, 7, -12, 0, -11, 2, -14, -8, 8, -3, 13, -9, 5, 5, 7, -11, -6, 5, -13, -7, 1, 14, -10, -1, -11, -13, 4, 12, -11, 2, 0, -4, -14, 4, 4, -10, 13, -3, -10, 6, 1, -12, 4, -9, 1, -4, -13, 10, 8, -11, 10, -14, -12, -14, 1, -8, 10, -10, 11, -15, 0, -3, -12, 1, -14, -1, -1, 6, 11, -4, -3, -2, -1, -13 };
	vector<int> nums3{ 0 };
	vector<int> nums4{ 0, 0, 0, 0 };
	vector<int> nums5{ -2, 0, 0, 2, 2 };
	vector<int> nums6{ -1, 0, 1, 2, -1, -4 };

	Solution sol;

	vector<vector<int>> res1 = sol.threeSum(nums1);
	vector<vector<int>> res2 = sol.threeSum(nums2);
	vector<vector<int>> res3 = sol.threeSum(nums3);
	vector<vector<int>> res4 = sol.threeSum(nums4);
	vector<vector<int>> res5 = sol.threeSum(nums5);
	vector<vector<int>> res6 = sol.threeSum(nums6);

	printResVec(res1);
	printResVec(res2);
	printResVec(res3);
	printResVec(res4);
	printResVec(res5);
	printResVec(res6);
}