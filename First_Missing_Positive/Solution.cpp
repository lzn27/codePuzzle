#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		for (int i = 0; i < nums.size(); i++) {
			while (nums[i] > 0 && nums[i] < nums.size() && nums[i] != nums[nums[i] - 1])
				swap(nums[nums[i] - 1], nums[i]);
		}
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] != i + 1)
				return i + 1;
		}
		return nums.size() + 1;
	}
};

int main() {
	Solution solu;
	vector<int> vec = {7,8,9,11,12 };
	cout << solu.firstMissingPositive(vec);
	return 0;
}