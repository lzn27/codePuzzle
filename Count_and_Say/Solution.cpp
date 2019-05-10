#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
	string countAndSay(int n) {
		string a = "1";
		while (--n) {
			string b = "";
			char c = a[0];//init
			int count = 1;

			for (int i = 1; i < a.size(); i++) {
				if (a[i] != a[i - 1]) {
					b += ('0' + count);
					b += c;
					count = 1;
					c = a[i];
				}
				else {
					count++;
				}
			}
			b += ('0' + count);
			b += c;
			a = b;
		}
		return a;
	}
};

int main() {
	Solution solu;
	cout << solu.countAndSay(1);
	return 0;
}