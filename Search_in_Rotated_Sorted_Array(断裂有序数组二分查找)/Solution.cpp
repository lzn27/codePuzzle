#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int search(vector<int>& nums, int target) {
		return recursion(nums, target, 0, nums.size() - 1);
	}
	int recursion(vector<int>& nums, int target, int l, int r) {
		if (l > r)
			return -1;
		int last = nums[r];
		int mid = (l + r) / 2;
		if (nums[mid] > target) {
			if (nums[mid] > last&&target > last)
				return recursion(nums, target, l, mid - 1);
			else if (nums[mid] <= last && target <= last)
				return recursion(nums, target, l, mid - 1);
			else
				return recursion(nums, target, mid + 1, r);
		}
		else if (nums[mid] < target) {
			if (nums[mid] > last&&target > last)
				return recursion(nums, target, mid + 1, r);
			else if (nums[mid] <= last && target <= last)
				return recursion(nums, target, mid + 1, r);
			else
				return recursion(nums, target, l, mid - 1);
		}
		else
			return mid;

	}
};

int main() {
	vector<int> nums = { 8,9,10,12,13,1,2,3,4,5 };
	Solution solu;
	int res = solu.search(nums, 8);
	cout << res;
	return 0;
}