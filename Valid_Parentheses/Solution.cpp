//Valid Parentheses
//leetcode easy
#include <iostream>
#include<algorithm>
#include<stack>
#include<string>
using namespace std;

class Solution {
public:
	bool isValid(string s) {
		if (s.size() == 0)
			return true;
		stack<char> sta;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '(' || s[i] == '[' || s[i] == '{')
				sta.push(s[i]);
			else {
				if (s[i] == ')') {
					if (!sta.empty() && sta.top() == '(')
						sta.pop();
					else
						return false;
				}
				else if (s[i] == ']') {
					if (!sta.empty() && sta.top() == '[')
						sta.pop();
					else
						return false;
				}
				else if (s[i] == '}') {
					if (!sta.empty() && sta.top() == '{')
						sta.pop();
					else
						return false;
				}
			}
		}
		if (sta.empty())
			return true;
		else
			return false;
	}
};

int main() {
	Solution solu;
	string s;
	cin >> s;
	cout << solu.isValid(s);
	return 0;
}