// Implement strStr()
#include <iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
	int strStr(string haystack, string needle) {
		if (needle.size() == 0)
			return 0;
		for (int k = 0; k < haystack.size(); k++) {
			if (haystack[k] == needle[0]) {
				bool isHere = true;
				for (int i = k, j = 0; isHere&&j < needle.size(); i++, j++) {
					if (haystack[i] != needle[j])
						isHere = false;
				}
				if (isHere)
					return k;
			}
		}
		return - 1;
	}
};

int main() {
	string p1, p2;
	getline(cin, p1);
	getline(cin, p2);

	Solution solu;
	int ans = solu.strStr(p1, p2);
	cout << ans;
	return 0;
}