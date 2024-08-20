#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cout;
using std::endl;
using std::max_element;

class Solution {
public:
	int maxArea(vector<unsigned>& height) {
		int n = height.size();

		if (n < 2 || n > pow(10, 5))
			return 0;

		int res = 0;
		vector<unsigned>::iterator it = height.begin();
		vector<unsigned>::iterator rIt = --height.rbegin().base();

		while (it != rIt)
		{
			if (*it > pow(10, 4) || *rIt > pow(10, 4))
				return 0;

			int water = (rIt - it) * std::min(*it, *rIt);
			if (water > res)
				res = water;
			
			if (*it > *rIt)
				rIt--;
			else
				it++;
		}

		return res;
	}
};

int main()
{
	vector<unsigned> height1{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }; // 25
	vector<unsigned> height2{ 2, 3, 4, 5, 18, 17, 6 }; // 17
	vector<unsigned> height3{ 8, 10, 14, 0, 13, 10, 9, 9, 11, 11 }; // 80
	vector<unsigned> height4{ 1, 1 }; // 1
	Solution sol;

	cout << sol.maxArea(height1) << endl;
	cout << sol.maxArea(height2) << endl;
	cout << sol.maxArea(height3) << endl;
	cout << sol.maxArea(height4) << endl;
}