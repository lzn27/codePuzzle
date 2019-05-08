#include<iostream>
using namespace std;

class Solution {
public:
	int divide(int dividend, int divisor) {
		//set d,r
		unsigned int d = dividend < 0 && dividend != INT_MIN ? (~dividend) + 1 : dividend;
		unsigned int r = divisor < 0 && divisor != INT_MIN ? (~divisor) + 1 : divisor;
		
		//compute 
		bool minus = (dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0) ? true : false;
		unsigned int res = 0;
		while (d >= r) {
			unsigned int temp = r;
			unsigned int base = 1;
			while ((temp << 1) < d&&temp < 0x80000000) {
				temp = temp << 1;
				base = base << 1;
			}
			d = d - temp;
			res += base;
		}

		//handle result
		if (res == 0x80000000 && !minus)
			return INT_MAX;
		else if (res != 0x80000000 && minus)
			return (~((int)res)) + 1;
		else
			return (int)res;
	}
};

int main() {
	int a, b;
	cin >> a >> b;
	Solution solu;
	int res = solu.divide(a, b);
	cout << res;
	return 0;
}