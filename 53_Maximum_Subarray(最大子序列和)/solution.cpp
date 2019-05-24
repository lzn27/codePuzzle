#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		if (nums.size() == 0)
			return 0;
		int max = INT_MIN;
		int now = 0;
		for (int num : nums) {
			if (now <= 0)
				now = num;
			else
				now = now + num;
			if (now > max)
				max = now;
		}
		return max;
	}
};

int main() {
	Solution solu;
	vector<int> vec = { -2,1,-3,4,-1,2,1,-5,4 };
	int ans = solu.maxSubArray(vec);
	cout << ans;
	return 0;
}