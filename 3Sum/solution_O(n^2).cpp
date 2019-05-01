#include <iostream>
#include <string>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		sort(nums.begin(), nums.end());//sort first
		vector<vector<int>> res;
		for (int i = 0; i < nums.size(); ) {
			int target = -nums[i];
			int left = i + 1;
			int right = nums.size() - 1;
			while (right > left) {
				int sum = nums[right] + nums[left];
				if (sum > target)
					right--;
				else if (sum < target)
					left++;
				else {
					vector<int> t = { nums[i],nums[left],nums[right] };
					res.push_back(t);

					//update left, right
					while (left < right&&nums[left] == t[1])left++;
					while (left < right&&nums[right] == t[2])right--;
				}
			}
			//update i
			i++;
			while (i < nums.size() && nums[i] == nums[i - 1] && nums[i] <= 0)
				i++;
		}
		return res;
	}

};

int main() {
	Solution solu;
	vector<int> in = { -1, 0, 1, 2, -1, -4 };
	vector<vector<int>> out = solu.threeSum(in);
	for (int i = 0; i < out.size(); i++) {
		for (int j = 0; j < out[i].size(); j++) {
			cout << out[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}
