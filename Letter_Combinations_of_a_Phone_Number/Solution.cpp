#include <iostream>
#include <string>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
private:
	map<char, string> dict;

public:
	Solution() {
		dict['2'] = "abc";
		dict['3'] = "def";
		dict['4'] = "ghi";
		dict['5'] = "jkl";
		dict['6'] = "mno";
		dict['7'] = "pqrs";
		dict['8'] = "tuv";
		dict['9'] = "wxyz"; 
	}
	void recursion(string digits, int id, string& s,vector<string>& res) {
		string str = dict[digits[id]];
		for (int i = 0; i < str.size(); i++) {
			s += str[i];
			if (id == digits.size() - 1)
				res.push_back(s);
			else
				recursion(digits, id + 1, s, res);
			s = s.substr(0, s.size() - 1);
		}
	}

	vector<string> letterCombinations(string digits) {
		vector<string> res;
		if (digits.size() == 0)
			return res;
		string s;
		recursion(digits, 0, s, res);
		return res;
	}
};

int main() {
	Solution solu;
	string in = "23";
	vector<string> out = solu.letterCombinations(in);
	for (int i = 0; i < out.size(); i++) {
		cout << out[i]<<' ';
	}
	return 0;
}