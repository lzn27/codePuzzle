#include<iostream>
using namespace std;

class Solution {
public:
	int mySqrt(int x) {
		unsigned int i = 0;
		for (i = 0; i*i <= x; i++);
		return i - 1;
	}
};

int main() {
	Solution solu;
	int x = 10;
	int ans = solu.mySqrt(x);
	cout << ans;
	return 0;
}