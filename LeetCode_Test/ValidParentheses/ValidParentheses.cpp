#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

class Solution {
public:
	bool isValid(string s)
	{
		string temp = "";

		for (char c : s)
			switch (c)
			{
			case '(':
			case '{':
			case '[':
				temp.push_back(c);
				continue;
			case ')':
				if (temp.empty() || temp[temp.size() - 1] != '(')
					return false;
				else
					temp.pop_back();
				break;
			case '}':
				if (temp.empty() || temp[temp.size() - 1] != '{')
					return false;
				else
					temp.pop_back();
				break;
			case ']':
				if (temp.empty() || temp[temp.size() - 1] != '[')
					return false;
				else
					temp.pop_back();
				break;
			}

		return temp.empty();
	}
};

int main()
{
	string s1 = "(((){(]())}))";

	Solution sol;

	cout << sol.isValid(s1) << endl;
}