#include<iostream>
#include<vector>
#include<set>
using namespace std;

class Solution {
private:
	set<int> hash;
	vector<vector<int>> ans;
public:
	vector<vector<int>> permute(vector<int>& nums) {
		vector<int> v;
		recursion(v, nums);
		return ans;
	}
	void recursion(vector<int>& v, vector<int>& nums) {
		if (v.size() == nums.size()) {
			ans.push_back(v);
			return;
		}
		for (auto it = nums.begin(); it != nums.end(); it++) {
			int temp = *it;
			if (hash.find(temp) == hash.end()) {// not found
				hash.insert(temp);
				v.push_back(temp);
				recursion(v, nums);
				v.pop_back();
				hash.erase(temp);
			}
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