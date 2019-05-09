#include<iostream>
#include<vector>
#include<utility>
using namespace std;

class Solution {
private:
	pair<int, int> ans;
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		recursion1(nums, target, 0, nums.size() - 1);
		recursion2(nums, target, 0, nums.size() - 1);
		vector<int> vec;
		vec.push_back(ans.first);
		vec.push_back(ans.second);
		return vec;
	}

	void recursion1(vector<int>& nums, int target, int l, int r) {
		if (l > r) {
			this->ans.first = -1;
			return;
		}
		int mid = (l + r) / 2;
		if (nums[mid] > target) {
			recursion1(nums, target, l, mid - 1);
			return;
		}
		else if (nums[mid] < target) {
			recursion1(nums, target, mid + 1, r);
			return;
		}
		else {
			if (mid == 0 || nums[mid] > nums[mid - 1]) {
				this->ans.first = mid;
				return;
			}
			else
				recursion1(nums, target, l, mid - 1);
		}
	}
	void recursion2(vector<int>& nums, int target, int l, int r) {
		if (l > r) {
			this->ans.second = -1;
			return;
		}
		int mid = (l + r) / 2;
		if (nums[mid] > target) {
			recursion2(nums, target, l, mid - 1);
			return;
		}
		else if (nums[mid] < target) {
			recursion2(nums, target, mid + 1, r);
			return;
		}
		else {
			if (mid == nums.size() - 1 || nums[mid] < nums[mid + 1]) {
				this->ans.second = mid;
				return;
			}
			else
				recursion2(nums, target, mid + 1, r);
		}
	}
};

int main() {
	vector<int> vec = { 5,5,7,8,8,8 };
	Solution solu;
	vector<int> res=solu.searchRange(vec, 5);
	cout << res[0] << endl << res[1];
	return 0;
}