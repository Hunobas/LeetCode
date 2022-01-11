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

		int openPar = 0;
		int closPar = 0;
		string parenthese = "()";
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

		string res = "";
		recurseGetnerate(resVec, res, n);

		return resVec;
	}

	void recurseGetnerate(vector<string>& resVec, string& res, int n, int i = 1, int j = 0)
	{
		if (i > n)
		{
			res = res.insert(j, "()");
			return;
		}

		for (int k = 0; k < i; ++k)
		{
			if (k - j > 1)
				return;

			recurseGetnerate(resVec, res, n, i + 1, k);
		}
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

	vector<string> res1 = sol.generateParenthesis(4);

	printResVec(res1);

	return 0;
}