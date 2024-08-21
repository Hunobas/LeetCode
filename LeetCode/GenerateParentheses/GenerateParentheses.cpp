#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::string;
using std::cout;
using std::endl;

class Solution {
public:
	vector<string> generateParenthesis(int n) {

		vector<string> resVec{};

		/*for (int h = 0; h < 1; ++h)
		{
			if (h - 0 > 1)
				break;

			for (int i = 0; i < 2; ++i)
			{
				if (i - h > 1)
					break;

				for (int j = 0; j < 3; ++j)
				{
					if (j - i > 1)
						break;

					for (int k = 0; k < 4; ++k)
					{
						if (k - j > 1)
							break;

						string res = "";
						res = res.insert(h, parenthese);
						res = res.insert(i, parenthese);
						res = res.insert(j, parenthese);
						res = res.insert(k, parenthese);
						resVec.push_back(res);
					}
				}
			}
		}*/

		recurseGetnerate(resVec, n);

		return resVec;
	}

	void recurseGetnerate(vector<string>& resVec, int n, string res = "", int m = 0)
	{
		if (!n && !m)
		{
			resVec.push_back(res);
			return;
		}

		if (m) { recurseGetnerate(resVec, n, res + ")", m - 1); }
		if (n) { recurseGetnerate(resVec, n - 1, res + "(", m + 1); }
	}
};

void printResVec(vector<string> resVec)
{
	cout << "[";
	for (auto s : resVec)
	{
		if (s != resVec[resVec.size() - 1])
			cout << "\"" << s << "\", ";
		else
			cout << "\"" << s << "\"";
	}
	cout << "]" << endl;
}

int main()
{
	Solution sol;

	vector<string> res1 = sol.generateParenthesis(6);

	printResVec(res1);

	return 0;
}