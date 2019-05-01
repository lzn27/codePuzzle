#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
	bool isMatch(string s, string p) {
		if (p.size() == 0) {
			if (s.size() == 0)
				return true;
			else {
				return false;
			}
		}
		if (p.size() == 1) {
			if (s.size() == 1)
				return p[0] == '.' || p[0] == s[0];
			else
				return false;
		}
		if (p[1] == '*') {
			if (s.empty())
				return isMatch(s, p.substr(2));
			else
				return isMatch(s, p.substr(2)) || ((s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p));
		}
		else {
			if (s.empty())
				return false;
			else
				return (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p.substr(1));
		}
	}
};

int main() {
	Solution solu;
	string s, p;
	cin >> s >> p;
	cout << solu.isMatch(s, p);
	return 0;
}