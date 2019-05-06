// Remove Duplicates from Sorted Array
#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.size() == 0)
			return 0;
		int storeIndex = 0;
		int nowdata = nums[0] - 1;
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] != nowdata) {
				nowdata = nums[i];
				nums[storeIndex] = nowdata;
				storeIndex++;
			}
		}
		return storeIndex;
	}
};

int main() {
	vector<int> nums;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		nums.push_back(temp);
	}
	Solution solu;
	int ans = solu.removeDuplicates(nums);
	cout << ans << endl;
	for (int i = 0; i < ans; i++) {
		cout<<nums[i]<<' ';
	}
	return 0;
}