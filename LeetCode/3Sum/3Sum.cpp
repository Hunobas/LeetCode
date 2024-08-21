#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cout;
using std::endl;

class Solution {
public:
	vector<vector<int> > threeSum(vector<int>& num) {

		vector<vector<int> > res;
		int n = num.size();
		std::sort(num.begin(), num.end());

		for (int i = 0; i < n - 2; i++) {

			int target = -num[i];
			int front = i + 1;
			int back = n - 1;

			while (front < back) {

				int sum = num[front] + num[back];

				// Finding answer which start from number num[i]
				if (sum < target)
					front++;

				else if (sum > target)
					back--;

				else {
					vector<int> triplet = { num[i], num[front], num[back] };
					res.push_back(triplet);

					// Processing duplicates of Number 2
					// Rolling the front pointer to the next different number forwards
					while (front < back && num[front] == triplet[1]) front++;

					// Processing duplicates of Number 3
					// Rolling the back pointer to the next different number backwards
					while (front < back && num[back] == triplet[2]) back--;
				}

			}

			// Processing duplicates of Number 1
			while (i + 1 < n && num[i + 1] == num[i])
				i++;

		}

		return res;

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
	vector<int> nums1{ -1, 0, 1, 2, -1, -4, 2 };
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