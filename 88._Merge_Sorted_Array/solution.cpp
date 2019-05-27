#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int index = 0;
		for (int i = 0; i < n; i++) {
			while (nums1[index] < nums2[i] && index < m + i)
				index++;
			if (index > m - 1 + i)
				nums1[index] = nums2[i];
			else
				nums1.insert(nums1.begin() + index, nums2[i]);
		}
		nums1.resize(m + n);
	}
};

int main() {
	Solution solu;
	vector<int> nums1 = { 1,2,3,0,0,0 };
	vector<int> nums2 = { 2,5,6 };

	solu.merge(nums1, 3, nums2, 3);
	
	return 0;
}