#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using std::vector;
using std::string;
using std::cout;
using std::endl;
using csmap = std::unordered_map<char, string>;

class Solution {
private:
	csmap letterPad;

public:
	Solution()
	{
		letterPad.insert(std::make_pair<char, string>('2', "abc"));
		letterPad.insert(std::make_pair<char, string>('3', "def"));
		letterPad.insert(std::make_pair<char, string>('4', "ghi"));
		letterPad.insert(std::make_pair<char, string>('5', "jkl"));
		letterPad.insert(std::make_pair<char, string>('6', "mno"));
		letterPad.insert(std::make_pair<char, string>('7', "pqrs"));
		letterPad.insert(std::make_pair<char, string>('8', "tuv"));
		letterPad.insert(std::make_pair<char, string>('9', "wxyz"));
	}

	vector<string> letterCombinations(string digits) {
		int n = digits.size();

		if (n < 1 || n > 4)
			return {};
		for (char c : digits)
			if (c - '0' < 2 || c - '0' > 9)
				return {};

		vector<string> table{};
		for (int i = 0; i < n; ++i)
			table.push_back(letterPad.find(digits[i])->second);

		vector<string> resVec{};
		recurseStrVec(resVec, table);
		return resVec;
	}

	void recurseStrVec(vector<string>& resVec, vector<string> table, string res = "", int length = 0)
	{
		if (table.begin() + length == table.end())
		{
			resVec.push_back(res);
			return;
		}

		for (int i = 0; i < table[length].size(); ++i)
		{
			res.push_back(table[length][i]);
			recurseStrVec(resVec, table, res, length + 1);
			res.pop_back();
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
	string s1 = "2379";
	string s2 = "2";
	string s3 = "";
	string s4 = "22";
	string s5 = "110";

	Solution sol;

	vector<string> res1 = sol.letterCombinations(s1);
	vector<string> res2 = sol.letterCombinations(s2);
	vector<string> res3 = sol.letterCombinations(s3);
	vector<string> res4 = sol.letterCombinations(s4);
	vector<string> res5 = sol.letterCombinations(s5);

	printResVec(res1);
	printResVec(res2);
	printResVec(res3);
	printResVec(res4);
	printResVec(res5);

	return 0;
}