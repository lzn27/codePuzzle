// Generate Parentheses（leetcode_medium）
#include <iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
	vector<string> generateParenthesis(int n) {
		vector<string> vec;
		recursion(vec, "", n, 0);
		return vec;
	}

	void recursion(vector<string> &vec, string s, int ln, int rn) {//left'('number, right ')'number
		if (ln == 0 && rn == 0)
			vec.push_back(s);
		if (ln > 0) {
			recursion(vec, s + '(', ln - 1, rn + 1);
		}
		if (rn > 0) {
			recursion(vec, s + ')', ln, rn - 1);
		}
	}
};

int main() {
	Solution solu;
	vector<string> vec;
	vec = solu.generateParenthesis(3);
	for (vector<string>::iterator it = vec.begin(); it != vec.end(); it++) {
		cout << *it << endl;
	}
	return 0;
}