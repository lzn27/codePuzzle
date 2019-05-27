#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int mySqrt(int x) {
		return recursion(0, 64000, x);
	}

	int recursion(unsigned int i, unsigned int j, unsigned int x) {
  		unsigned int now = (i + j) / 2;
		unsigned int now2 = now * now, now_2 = (now + 1)*(now + 1);
		if (now2 <= x && now_2 > x) {
			return now;
		}
		else {
			if (now2 > x) {
				return recursion(0, now-1, x);
			}
			else {
				return recursion(now+1, j, x);
			}
		}
	}
};

int main() {
	Solution solu;
	int x = 2147395599;
	int ans = solu.mySqrt(x);
	cout << ans;
	return 0;
}