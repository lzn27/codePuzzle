#include <iostream>
#include <string>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		sort(nums.begin(),nums.end());//sort first
		vector<vector<int>> res;
		if (nums.size() < 3)
			return res;
		//recursion(nums, res, 0, nums.size() - 1);
		int i = 0, j = nums.size() - 1;
		while (i < j-1 && nums[i] <= 0) {
			while (i < j-1 && nums[j] >= 0) {
				if (-1 * nums[i] == nums[j]) {
					//find number 0
					for (int temp = i + 1; temp < j; temp++) {
						if (nums[temp] == 0) {
							vector<int> t = { nums[i],0,nums[j] };
							res.push_back(t);
							temp = j;
						}
					}	
				}
				else if (-1*nums[i] > nums[j]) {
					//find x,x+[j]==-1*[i] 
					for (int temp = j - 1; temp > i&&nums[temp] > 0; temp--) {
						if (nums[temp] + nums[j] == -1 * nums[i]) {
							vector<int> t = { nums[i],nums[temp],nums[j] };
							res.push_back(t);
							temp = i;
						}
					}
				}
				else if (-1*nums[i] < nums[j]) {
					//find x,x+nums[i]==-1*[j]
					for (int temp = i + 1; temp < j && nums[temp] < 0; temp++) {
						if (nums[temp] + nums[i] == -1 * nums[j]) {
							vector<int> t = { nums[i],nums[temp],nums[j] };
							res.push_back(t);
							temp = j;
						}
					}
				}

				//update j
				int temp = nums[j];
				while (j > i && nums[j] == temp)
					j--;
			}
			//reset j
			j = nums.size() - 1;

			//update i
			int temp = nums[i];
			while (i <j && nums[i] == temp)
				i++;
			
			
		}
		return res;
	}

};

int main() {
	Solution solu;
	vector<int> in = {0,0,0,0,0,0};
	vector<vector<int>> out = solu.threeSum(in);
	for(int i = 0; i < out.size(); i++) {
		for (int j = 0; j < out[i].size(); j++) {
			cout << out[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}