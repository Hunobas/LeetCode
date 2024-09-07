#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	string strAllExploded(const string& word, const string& bomb) const {
		int bombLen = bomb.size();
		vector<char> stack;

		for (char c : word) {
			stack.push_back(c);

			if (stack.size() >= bombLen &&
				string(stack.end() - bombLen, stack.end()) == bomb) {
				for (int i = 0; i < bombLen; i++) stack.pop_back();
			}
		}

		string result(stack.begin(), stack.end());
		return result.empty() ? "FRULA" : result;
	}
};

int main() {
	string word, bomb, result;
	Solution sol;

	cin >> word;
	cin >> bomb;

	result = sol.strAllExploded(word, bomb);

	cout << result << endl;

	return 0;
}