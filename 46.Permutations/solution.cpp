#include<iostream>
#include<vector>
#include<set>
using namespace std;

class Solution {
private:
	vector<vector<int>> ans;
public:
	vector<vector<int>> permute(vector<int>& nums) {
		vector<int> v;
		recursion(v, nums, 0);
		return ans;
	}
	void recursion(vector<int>& v, vector<int>& nums,int begin) {
		if (begin >= nums.size()) {
			ans.push_back(v);
			return;
		}
		for (int i = begin; i < nums.size();i++) {
			v.push_back(nums[i]);
			swap(nums[i], nums[begin]);
			recursion(v, nums, begin + 1);
			v.pop_back();
			swap(nums[i], nums[begin]);
		}
	}
};

int main() {
	cout<<pair<int, string>(2, "qwe").second;
	Solution solu;
	vector<int> vec = {1,2,3 };
	vector<vector<int>> ans=solu.permute(vec);
	return 0;
}